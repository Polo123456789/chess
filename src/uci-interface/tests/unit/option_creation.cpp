#include <uci/option.hpp>

#include <catch2/catch.hpp>

//
// Here we will check only that they are corretly constructed and interpreted
//

TEST_CASE("Option creation", "[uci] [uci::option]") { // NOLINT
    using uci::option;
    using uci::option_types;
    using uci::spin_range;

    SECTION("Check") {
        option true_one = option::check(true);
        option false_one = option::check(false);

        CHECK(true_one.as<option_types::check>());
        CHECK(!false_one.as<option_types::check>());
    }

    SECTION("Spin") {
        constexpr int64_t no_test_cases = 10; // Dont go too big here
        constexpr int64_t half = no_test_cases / 2;
        constexpr int64_t upper_limit = half;
        constexpr int64_t lower_limit = -half;

        spin_range test_range = {-no_test_cases, no_test_cases};

        static_assert(lower_limit < upper_limit);

        for (auto i = lower_limit; i != upper_limit; i++) {
            option a_number = option::spin(i, test_range);

            CHECK(a_number.as<option_types::spin>() == i);
        }
    }

    SECTION("Combo") {
        option a_combo =
            option::combo("Default Value",
                          {"Other value", "And another one", "And a last one"});

        CHECK(a_combo.as<option_types::combo>() == "Default Value");
    }

    SECTION("String") {
        std::string val = "This one is easy";
        option      a_string = option::string(val);

        CHECK(a_string.as<option_types::string>() == val);
    }

    SECTION("Throws on wrong type") {
        option a_string = option::string(std::string("Hello"));

        CHECK_THROWS_AS(a_string.as<option_types::check>(), std::runtime_error);
        CHECK_THROWS_AS(a_string.as<option_types::spin>(), std::runtime_error);
        CHECK_THROWS_AS(a_string.as<option_types::combo>(), std::runtime_error);
    }
}
