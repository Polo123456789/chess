#ifndef UCI_INTERFACE_OPTION_HPP
#define UCI_INTERFACE_OPTION_HPP

#include <algorithm>
#include <stdexcept>
#include <string>
#include <cstdint>
#include <vector>
#include <exception>
#include <limits>
#include <initializer_list>

namespace uci {

/**
 * The types the options can be
 */
enum class option_types { check, spin, combo, button, string };

/**
 * @return A string representation of the given option
 */
std::string describe(option_types o);

/**
 * Will hold the range of values that a spin option can hold.
 */
struct spin_range {
    [[nodiscard]] bool in_range(int64_t v) const {
        return std::clamp(v, min, max) == v;
    }

    int64_t min = std::numeric_limits<int64_t>::min(); // NOLINT
    int64_t max = std::numeric_limits<int64_t>::max(); // NOLINT
};

/**
 * The options that can be set by the GUI to configure the behavior of the
 * engine
 */
class option {
   public:
    using call_back_t = void (*)(const option &);

    template<option_types type>
    [[nodiscard]] auto as(void) const;

    /**
     * For an option of type `check`
     */
    explicit option(bool val, call_back_t on_change = nullptr);

    /**
     * For an option type `spin`
     */
    explicit option(int64_t val, spin_range r, call_back_t on_change = nullptr);

    /**
     * For an option type `combo`
     */
    option(std::string                        default_value,
           std::initializer_list<std::string> others,
           call_back_t                        on_change = nullptr);

    /**
     * For an option type `button`
     */
    explicit option(call_back_t on_change);

    /**
     * For an option type `string`
     */
    explicit option(std::string val, call_back_t on_change = nullptr);

    [[nodiscard]] option_types get_type(void) const {
        return type;
    }

    [[nodiscard]] const std::string &get_value(void) const {
        return value;
    }

    void set_value(std::string v) {
        value = std::move(v);
    }

    [[nodiscard]] const std::vector<std::string> &get_combo_values(void) const {
        return combo_values;
    }

    [[nodiscard]] const spin_range &get_spin_range(void) const {
        return range;
    }

    void run_callback(void) const {
        if (call_back != nullptr) {
            call_back(*this);
        }
    }

   private:
    option_types             type;
    std::string              value;
    std::vector<std::string> combo_values;
    spin_range               range;
    call_back_t              call_back = nullptr;

    void throw_on_wrong_type(option_types expected) const;
};

template<>
[[nodiscard]] inline auto option::as<option_types::check>(void) const {
    throw_on_wrong_type(option_types::check);
    return ((value == "True") || value == "true");
}

template<>
[[nodiscard]] inline auto option::as<option_types::spin>(void) const {
    throw_on_wrong_type(option_types::spin);
    return std::stoll(value);
}

template<>
[[nodiscard]] inline auto option::as<option_types::combo>(void) const {
    throw_on_wrong_type(option_types::combo);
    return value;
}

template<>
[[nodiscard]] inline auto option::as<option_types::string>(void) const {
    throw_on_wrong_type(option_types::string);
    return value;
}

} // namespace uci

#endif
