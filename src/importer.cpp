#include "importer.h"

bool is_delim(char c) {
    return c == '(' || c == ')' || c == '[' || c == ']' || c == '@' || c == '.' || c == ',' || c=='/' || c=='"' || c=='=' || c=='<' || c=='>' || c=='+' || c=='-' || c=='*' || c=='>' || c=='<' || c=='{' || c=='}';
}

namespace ansi {
    const char* red = "\033[31m";
    const char* yellow = "\033[33m";
    const char* cyan = "\033[36m";
    const char* green = "\033[32m";
    const char* purple = "\033[35m";
    const char* gray = "\033[90m";
    const char* reset = "\033[0m";
}

static size_t parse_integer_suffix(std::string_view line, size_t i) {
    bool found_u = false;
    int l_count = 0;
    for(int n = 0; n < 3 && i < line.size(); ++n) {
        char c = line[i];
        if((c == 'u' || c == 'U') && !found_u) {
            found_u = true;
            ++i;
        } 
        else if((c == 'l' || c == 'L') && l_count < 2) {
            ++l_count;
            ++i;
        } 
        else break;
    }
    return i;
}

void Importer::rollback_token() {
    column = start;
}

const std::string_view Importer::_next_token() {
    const size_t n = current_line.size();
    while(column < n && (current_line[column] == ' ' || current_line[column] == '\t'))
        ++column;
    start = column;
    if(column >= n) {
        end = column;
        return {};
    }
    // --------------------------------------------------
    // Line comment
    // --------------------------------------------------
    if(column + 1 < n &&
       current_line[column] == '/' &&
       current_line[column + 1] == '/') {
        column = n;
        end = column;
        return {};
    }

    const char c = current_line[column];
    
    // --------------------------------------------------
    // String literal
    // --------------------------------------------------
    if(c == '"') {
        ++column;
        while(column < n) {
            if(current_line[column] == '"') {
                size_t backslashes = 0;
                for(size_t j = column; j > start && current_line[j - 1] == '\\'; --j)
                    ++backslashes;
                if(backslashes % 2 == 0)
                    break;
            }
            ++column;
        }
        if(column < n) ++column;
        end = column;
        return { current_line.data() + start, end - start };
    }

    // --------------------------------------------------
    // Number literal
    // --------------------------------------------------
    if(std::isdigit(c)) {
        size_t i = column;
        if(c == '0' && i + 1 < n) {
            char b = current_line[i + 1];
            if(b == 'x' || b == 'X') {
                i += 2;
                while(i < n && std::isxdigit(current_line[i])) ++i;
                i = parse_integer_suffix(current_line, i);
                column = end = i;
                return { current_line.data() + start, end - start };
            }
            if(b == 'b' || b == 'B') {
                i += 2;
                while(i < n && (current_line[i] == '0' || current_line[i] == '1')) ++i;
                i = parse_integer_suffix(current_line, i);
                column = end = i;
                return { current_line.data() + start, end - start };
            }
            if(b == 'o' || b == 'O') {
                i += 2;
                while(i < n && (current_line[i] >= '0' && current_line[i] <= '7')) ++i;
                i = parse_integer_suffix(current_line, i);
                column = end = i;
                return { current_line.data() + start, end - start };
            }
        }

        bool has_dot = false;
        while(i < n) {
            if(std::isdigit(current_line[i])) ++i;
            else if(current_line[i] == '.' && !has_dot &&
                    i + 1 < n && std::isdigit(current_line[i + 1])) {
                has_dot = true;
                ++i;
            } else break;
        }

        i = parse_integer_suffix(current_line, i);
        column = end = i;
        return { current_line.data() + start, end - start };
    }

    // --------------------------------------------------
    // Delimiter
    // --------------------------------------------------
    if(is_delim(c)) {
        if(start == column) {
            end = ++column;
            if(column<current_line.size()-11 && current_line[column]=='=') {
                ++column;
                ++end;
            }
        }
        else end = column;
        return { current_line.data() + start, end - start };
    }

    // --------------------------------------------------
    // Identifier
    // --------------------------------------------------
    start = column; 
    end = column; 
    while(true) { 
        if(column>=current_line.size()) { 
            end = column; 
            break; 
        } 
        const char c = current_line[column];
        if((c==' ' || c=='\t') && column==start) { 
            ++column; 
            ++start; 
            continue; 
        } 
        if(c==' ') { 
            ++column; 
            end = column-1; 
            break; 
        } 
        if(is_delim(c)) { 
            end = column; 
            break; 
        } 
        ++column; 
    } 
    return std::string_view(current_line.data()+start, end - start);
}


void Importer::error(const char* message, const char* description, const char* color) {
    std::ostringstream caret;
    for (size_t i = 0; i < start; ++i) caret << ' ';
    for (size_t i = start; i < end; ++i) caret << '^';
    const std::string header_text = std::string(" ")+message+" ";
    const std::string description_text = std::string(description);
    const std::string location = (current_line.size() || line || column)?"at " + path + " line " + std::to_string(line):path;
    size_t content_width = std::max({
        header_text.size(),
        description_text.size(),
        location.size(),
        current_line.size(),
        caret.str().size(),
        size_t{60}
    });
    auto repeat = [](const std::string& s, size_t n) {
        std::string out;
        out.reserve(s.size() * n);
        for (size_t i = 0; i < n; ++i) out += s;
        return out;
    };
    size_t left_pad  = 2;
    size_t right_pad = content_width - header_text.size();
    std::cout << color << "╭" << repeat("─", left_pad) << header_text << repeat("─", right_pad) << "╮\n";
    auto line_box = [&](const std::string& s, const char* text_color) {
        std::cout << color << "│ " << text_color << s << std::string(content_width - s.size(), ' ') << color << " │\n";
    };
    line_box(location, ansi::gray);
    if(current_line.size()) line_box(current_line, ansi::gray);
    if(current_line.size()) line_box(caret.str(), ansi::red);
    line_box(description_text, ansi::reset);
    std::cout << color << "╰" << repeat("─", content_width + 2) << "╯" << ansi::reset << "\n";
    throw std::runtime_error(message);
}