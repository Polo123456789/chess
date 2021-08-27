#include <uci/engine_interface.hpp>

#include <gsl/gsl>
#include <catch2/catch.hpp>

static constexpr const char* expected_output = 
R"()";

TEST_CASE("Option Enlistment", "[uci] [uci::option] [uci::engine_interface]") {
    auto clean_options = gsl::finally([&](void) -> void {
            REQUIRE(!uci::config.empty());
            uci::config.clear();
    });

    auto do_nothing_button = []([[maybe_unused]] const uci::option& o) -> void {};

    // Check option
    uci::config["OwnBook"] = uci::option(false);

    // Spin option
    uci::config["HashSize"] =
        uci::option(1, {1, 128}); // NOLINT Magic numbers for testing

    // Combo option
    uci::config["Style"] =
        uci::option("Normal", {"Solid", "Aggressive", "Passive"});

    // Button Option
    uci::config["CleanHash"] = uci::option(do_nothing_button);
    
    // String option
    uci::config["NalimovPath"] = uci::option(std::string("<empty>"));

}
