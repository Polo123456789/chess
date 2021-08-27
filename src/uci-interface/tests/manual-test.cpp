/**
 * This file is just used for quick manual testing, feel free to ignore it.
 */

#include <uci/engine_interface.hpp>

#include <gsl/gsl>

static constexpr const char *expected_output = R"()";

int main(void) {
    auto clean_options = gsl::finally([&](void) -> void {
        std::cout << "Loaded options: " << uci::config.size() << '\n';
        uci::config.clear();
        std::cout << "Options cleared \n";
    });

    auto do_nothing_button = []([[maybe_unused]] const uci::option &o) -> void {
    };

    // Check option
    uci::config["OwnBook"] = uci::option::check(false);

    // Spin option
    uci::config["HashSize"] =
        uci::option::spin(1, {1, 128}); // NOLINT Magic numbers for testing

    // Combo option
    uci::config["Style"] =
        uci::option::combo("Normal", {"Solid", "Aggressive", "Passive"});

    // Button Option
    uci::config["CleanHash"] = uci::option::button(do_nothing_button);

    // String option
    uci::config["NalimovPath"] = uci::option::string("<empty>");


    uci::engine_interface::enlist_options();

    return 0;
}
