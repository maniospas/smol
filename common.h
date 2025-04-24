#ifndef COMMON_H
#define COMMON_H

inline void ERROR(const std::string& message) {
    size_t newline_pos = message.find('\n');
    std::string first_line = (newline_pos == std::string::npos) ? message : message.substr(0, newline_pos);
    std::string rest = (newline_pos == std::string::npos) ? "" : message.substr(newline_pos + 1);
    std::string formatted_message = "\033[33m" + first_line + "\033[0m";
    if (!rest.empty()) formatted_message += "\n" + rest;
    throw std::runtime_error(formatted_message);
}

#endif // COMMON_H
