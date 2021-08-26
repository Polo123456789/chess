#include <uci/engine_interface.hpp>
#include <uci/config.hpp>
#include <uci/info.hpp>

#include <utility>

using line_iterators = std::pair<std::istream_iterator<std::string>,
                                 std::istream_iterator<std::string>>;

static std::stringstream get_line(void);
static line_iterators get_iterators(std::istream& stream);

void uci::engine_interface::run(void) {
    auto line = get_line();
    auto [begin, end] = get_iterators(line);

    // If the engine doesnt start with a `uci` command, then it is not following
    // the uci protocol.
    if (*begin != "uci") {
        std::cout
            << "Some error message"; // TODO(pabsa): Explain that the engine
                                     // needs to follow the uci protocol.
        return;
    }

    // If options couldt be loaded, then log the error and wait for quit
    if (!load_options()) {
        using uci::info::log;
        using uci::info::cstring;

        log(cstring{"There was an error loading the default options"});
        do_nothing_loop();
        return;
    }
    enlist_options();
    std::cout << "uciok\n";

    if (engine_requires_registration) {
        std::cout << "registration cheking\n";
        if (!check_register()) {
            std::cout << "registration error\n";
        }
    }

    if (engine_requires_copyprotection) {

    }
}

static std::stringstream get_line(void) {
    std::string buffer;
    std::getline(std::cin, buffer);
    return std::stringstream(buffer);
}

static line_iterators get_iterators(std::istream& stream) {
    return {std::istream_iterator<std::string>{stream},
            std::istream_iterator<std::string>{}};
}

void uci::engine_interface::do_nothing_loop(void) {
    while (true) {
        auto line = get_line();
        auto [begin, end] = get_iterators(line);

        if (*begin == "quit") {
            return;
        }
    }
}

void uci::engine_interface::enlist_options(void) {
    for (const auto& [key, val] : config) {
        std::cout << "option name " << key << " type "
                  << uci::describe(val.get_type());

        if (val.get_type() != uci::option_types::button) {
            std::cout << " default " << val.get_value();
        }

        if (val.get_type() == uci::option_types::combo) {

        }

        // TODO(pabsan): Print range for spin type options
        if (val.get_type() == uci::option_types::spin) {

        }
    }

}

//
// Default implementations
//

void uci::engine_interface::set_author_name(const char *name) {
    author_name = name;
}

void uci::engine_interface::set_engine_name(const char *name) {
    engine_name = name;
}


void uci::engine_interface::requires_registration(bool v) {
    engine_requires_registration = v;
}

void uci::engine_interface::requires_copy_protection(bool v) {
    engine_requires_copyprotection = v;
}

void uci::engine_interface::can_ponder(bool v) {
    engine_can_ponder = v;
}

bool uci::engine_interface::check_register(void) {
    return true;
}

bool uci::engine_interface::check_copy_protection(void) {
    return true;
}

[[nodiscard]] bool uci::engine_interface::load_options(void) {
    set_author_name("Unknown Author");
    set_engine_name("Unknown Engine");
    requires_registration(false);
    requires_copy_protection(false);
    can_ponder(false);
    return true;
}

