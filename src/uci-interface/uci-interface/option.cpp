#include <uci/option.hpp>
#include <utility>

using uci::option_types;

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
    return "Value is not an option type";
}

void uci::option::throw_on_wrong_type(option_types expected) const {
    if (type != expected) {
        throw std::runtime_error("Expected option of type " + describe(expected)
                                 + " (Current type: " + describe(type) + ")");
    }
}

uci::option::option(bool val, call_back_t on_change)
    : type(option_types::check), value(val ? "true" : "false"),
      call_back(on_change) {}

uci::option::option(int64_t val, call_back_t on_change)
    : type(option_types::spin), value(std::to_string(val)),
      call_back(on_change) {}


uci::option::option(std::string                        default_value,
                    std::initializer_list<std::string> others,
                    call_back_t                        on_change)
    : type(option_types::combo), value(std::move(default_value)),
      combo_values(others), call_back(on_change) {}


uci::option::option(call_back_t on_change)
    : type(option_types::button), call_back(on_change) {}

uci::option::option(std::string val, call_back_t on_change)
    : type(option_types::string), value(std::move(val)), call_back(on_change) {}
