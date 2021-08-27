#include <uci/engine_interface.hpp>
#include <uci/info.hpp>

#include <utility>

static std::vector<std::string> get_line(void);

void uci::engine_interface::run(void) {
    auto first_line = get_line();

    // If the engine doesn't start with a `uci` command, then it is not
    // following the uci protocol.
    if (first_line.front() != "uci") {
        std::cout
            << "To interact with this engine you need to use the UCI protocol";
        return;
    }

    // If options couldn't be loaded, then log the error and wait for quit
    if (!load_options()) {
        using uci::info::log;
        using uci::info::cstring;

        log(cstring{"There was an error loading the default options. Waiting "
                    "for `quit` command..."});
        do_nothing_loop();
        return;
    }
    enlist_options();
    std::cout << "uciok\n";

    if (!check_copy_protection_if_required()) {
        do_nothing_loop();
        return;
    }
    if (!check_registration_if_required()) {
        do_nothing_loop();
        return;
    }


}

static std::vector<std::string> get_line(void) {
    std::string buffer;
    std::getline(std::cin, buffer);
    std::stringstream line(buffer);

    return std::vector<std::string>(std::istream_iterator<std::string>(line),
                                    std::istream_iterator<std::string>());
}

bool uci::engine_interface::check_registration_if_required(void) {
    if (engine_requires_registration) {
        std::cout << "registration checking\n";
        if (!check_register()) {
            std::cout << "registration error\n";
            // TODO(pabsa): Check with code and user
        }
        std::cout << "registration ok\n";
    }
    return true;
}

bool uci::engine_interface::check_copy_protection_if_required(void) {
    if (engine_requires_copyprotection) {
        std::cout << "copyprotection checking\n";
        if (!check_copy_protection()) {
            std::cout << "copyprotection error\n";
            return false;
        }
        std::cout << "copyprotection ok\n";
    }
    return true;
}

void uci::engine_interface::do_nothing_loop(void) {
    while (true) {
        auto line = get_line();
        if (line.front() == "quit") {
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
            for (const auto& v : val.get_combo_values()) {
                std::cout << " var " << v;
            }
        }

        if (val.get_type() == uci::option_types::spin) {
            std::cout << " min " << val.get_spin_range().min << " max "
                      << val.get_spin_range().max;
        }

        std::cout << '\n';
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

