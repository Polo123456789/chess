#include <uci/engine_interface.hpp>

#include <gsl/gsl>
#include <catch2/catch.hpp>

static constexpr const char *expected_output =
    R"(option name Style type combo default Normal var Solid var Aggressive var Passive
option name NalimovPath type string default <empty>
option name CleanHash type button
option name OwnBook type check default false
option name HashSize type spin default 1 min 1 max 128)";

// Because there is no way of predicting the order in wich the lines will appear
// in the output, we will just check that they contain the same lines, it doesnt
// matter the order they appear in
static bool unordered_line_compare(const std::string& s1, const std::string& s2) {
    using istr_iter = std::istream_iterator<std::string>;

    std::stringstream ss1(s1);
    std::stringstream ss2(s2);

    std::vector<std::string> lines1(istr_iter(ss1), istr_iter{});
    std::vector<std::string> lines2(istr_iter(ss2), istr_iter{});

    if (lines1.size() != lines2.size()) {
        return false;
    }

    for (const std::string& line : lines1) {
        if (std::find(lines2.begin(), lines2.end(), line) == lines2.end()) {
            return false;
        }
    }

    return true;
}

TEST_CASE("Option Enlistment", "[uci] [uci::option] [uci::engine_interface]") {
    std::stringstream new_out;

    // Redirect std::cout
    auto *old_cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(new_out.rdbuf());

    auto restore_cout_buffer = gsl::finally([&]() {
        std::cout.rdbuf(old_cout_buffer);
    });

    auto clean_options = gsl::finally([&](void) -> void {
        REQUIRE(!uci::config.empty());
        uci::config.clear();
        REQUIRE(uci::config.empty());
    });

    auto do_nothing_button = []([[maybe_unused]] const uci::option &o) -> void {
    };

    INFO("Configuration should be empty during testing") // No ;, catch takes
                                                         // care of it
    REQUIRE(uci::config.empty());

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

    auto output = new_out.str();
    CHECK(unordered_line_compare(output, expected_output));
}
