#include "../codegen.h"

void handle_def_or_service(
    std::map<std::string, Types>& files,
    const std::string& file,
    const Memory& builtins,
    Task selected_task,
    std::string& task_report,
    const shared_ptr<Import>& imp,
    size_t& p,
    Types& types,
    bool& errors)
{
    auto start_p = p;
    auto brackets = std::stack<std::pair<std::string, int>>{};
    for (; p < imp->size(); ++p) {
        std::string next = imp->at(p);
        if (next == "(" || next == "{" || next == "[")
            brackets.push(std::make_pair(next, p));
        if (next == ")") {
            if (!brackets.size())
                imp->error(p, "Never opened parenthesis");
            if (brackets.top().first != "(")
                imp->error(brackets.top().second, "Never closed parenthesis");
            brackets.pop();
            continue;
        }
        if (next == "}") {
            if (!brackets.size())
                imp->error(p, "Never opened bracket ");
            if (brackets.top().first != "{")
                imp->error(brackets.top().second, "Never closed bracket");
            brackets.pop();
            continue;
        }
        if (next == "]") {
            if (!brackets.size())
                imp->error(p, "Never opened square bracket");
            if (brackets.top().first != "[")
                imp->error(brackets.top().second, "Never closed square bracket");
            brackets.pop();
            continue;
        }
        if (next == "def" || next == "service")
            break;
    }
    if (brackets.size() && brackets.top().first == "(")
        imp->error(brackets.top().second, "Never closed parenthesis");
    if (brackets.size() && brackets.top().first == "{")
        imp->error(brackets.top().second, "Never closed bracket");
    if (brackets.size() && brackets.top().first == "[")
        imp->error(brackets.top().second, "Never closed square bracket");
    if (brackets.size())
        imp->error(brackets.top().second, "Never closed");
    p = start_p;

    auto def = std::make_shared<Def>(types);
    all_types.push_back(def);
    def->imp = imp;
    def->parse(imp, p, types);
    std::vector<Type> lazy_options;
    if (def->lazy_compile) lazy_options = def->get_lazy_options(types);

    if (!types.contains(def->name))
        types.vars[def->name] = def;
    else if (!types.vars[def->name]->lazy_compile) {
        // move previous into a union
        auto prev = types.vars[def->name];
        types.vars[def->name] = std::make_shared<Def>(types);
        all_types.push_back(types.vars[def->name]);
        types.vars[def->name]->imp = imp;
        types.vars[def->name]->pos = p;
        types.vars[def->name]->lazy_compile = true;
        types.vars[def->name]->name = prev->name;
        for (const auto& d : prev->options)
            if (!std::ranges::contains(types.vars[def->name]->options, d))
                types.vars[def->name]->options.push_back(d);
    }

    if (def->lazy_compile) {
        Def::log_depth = 0;
        for (const auto& d : lazy_options) {
            if (d->lazy_compile)
                imp->error(--p, "Internal error: failed to compile " + d->signature(types));
            if (!std::ranges::contains(types.vars[def->name]->options, d))
                types.vars[def->name]->options.push_back(d);
        }
        p--;
        while (p < imp->size() - 1) {
            p++;
            if (imp->at(p) == "def"
                || imp->at(p) == "union"
                || imp->at(p) == "service"
                || (imp->at(p) == "@" && p < imp->size() - 1 && imp->at(p + 1) == "include")
                || (imp->at(p) == "@" && p < imp->size() - 1 && imp->at(p + 1) == "install")
                || (imp->at(p) == "@" && p < imp->size() - 1 && imp->at(p + 1) == "unsafe")
                || (imp->at(p) == "@" && p < imp->size() - 1 && imp->at(p + 1) == "about"))
                break;
        }
        --p;
    } else {
        types.vars[def->name]->options.push_back(def);
    }
    def->assert_options_validity(imp, p);
}
