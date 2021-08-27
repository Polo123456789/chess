#include <uci/option.hpp>
#include <utility>

using uci::option;
using uci::option_types;
using uci::spin_range;

// This code was generated automatically with `enum-describer`, dont modify it.
// If the enum changes, use it again.
std::string uci::describe(option_types o) {
    switch (o) {
    case option_types::check:
        return "check";
    case option_types::spin:
        return "spin";
    case option_types::combo:
        return "combo";
    case option_types::button:
        return "button";
    case option_types::string:
        return "string";
    }
    return "Value not part of the enum";
}

void option::throw_on_wrong_type(option_types expected) const {
    if (type != expected) {
        throw std::runtime_error("Expected option of type " + describe(expected)
                                 + " (Current type: " + describe(type) + ")");
    }
}

option option::check(bool val, call_back_t on_change) {
    option o;
    o.type = option_types::check;
    o.value = val ? "true" : "false";
    o.call_back = on_change;
    return o;
}

option option::spin(int64_t val, spin_range r, call_back_t on_change) {
    option o;
    o.type = option_types::spin;
    o.value = std::to_string(val);
    o.range = r;
    o.call_back = on_change;
    return o;
}

option option::combo(std::string                        default_value,
                     std::initializer_list<std::string> others,
                     call_back_t                        on_change) {

    option o;
    o.type = option_types::combo;
    o.value = std::move(default_value);
    o.combo_values = others;
    o.call_back = on_change;
    return o;
}


option option::button(call_back_t on_change) {
    option o;
    o.type = option_types::button;
    o.call_back = on_change;
    return o;
}

option option::string(std::string val, call_back_t on_change) {
    option o;
    o.type = option_types::string;
    o.value = std::move(val);
    o.call_back = on_change;
    return o;
}
