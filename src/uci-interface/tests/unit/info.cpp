#include <uci/info.hpp>

#include <gsl/gsl>
#include <catch2/catch.hpp>

#include <sstream>

// NOTE: All messages end with a trailing whitespace, be sure your editor does
// not get rid of it.

// clang-format off
static constexpr const char *expected_output =
R"(info depth 10 seldepth 15 time 1000 nodes 20000 
info multipv 1 pv d2d4 g8f6 c2c4 c7c5 score cp 10 
info score mate 3 
info score cp 30 upperbound 
info score cp 10 lowerbound 
info currmove d2d4 currmovenumber 1 
info hashfull 500 nps 1000 tbhits 0 sbhits 0 
info cpuload 100 currline e2e4 c7c5 g1f3 d7d6 
info refutation e2e4 c7c5 g1f3 d7d6 f1b5 
info string Here is a message for you 
info string Of if you dont want to build a string use this one 
info string You should see this message 
info string And this one 
)";
// clang-format on

TEST_CASE("uci::info", "[uci] [uci::info]") {
    std::stringstream new_out;

    // Redirect std::cout
    auto *old_cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(new_out.rdbuf());

    auto restore_cout_buffer = gsl::finally([&]() {
        std::cout.rdbuf(old_cout_buffer);
    });

    {
        using namespace uci::info; // NOLINT
        using namespace std::chrono_literals;

        // Because just `time` is ambiguos
        using uci::info::time;

        // NOLINTNEXTLINE: The magic numbers are just for testing
        log(depth{10}, selective_depth{15}, time{1000ms}, nodes{20'000});

        // NOLINTNEXTLINE
        log(multipv{1}, pv{"d2d4 g8f6 c2c4 c7c5"}, score::centipawns{10});

        log(score::mate{3});
        log(score::upperbound{30}); // NOLINT
        log(score::lowerbound{10}); // NOLINT

        log(current_move{"d2d4"}, current_move_number{1});
        log(hashfull{500}, // NOLINT
            nodes_per_second{1000}, // NOLINT
            table_base_hits{0},
            shredder_base_hits{0}); // NOLINT

        log(cpu_load{100}, current_line{"e2e4 c7c5 g1f3 d7d6"}); // NOLINT
        log(refutation{"e2e4 c7c5 g1f3 d7d6 f1b5"});

        log(string{"Here is a message for you"});
        log(cstring{"Of if you dont want to build a string use this one"});

        // It should not be on by default during testing
        REQUIRE(!uci::debug);

        log(debug{"You should not see this message"});
        log(cdebug{"And this one"});

        uci::debug = true;
        auto reset_debug = gsl::finally([&]() {
            uci::debug = false;
        });

        log(debug{"You should see this message"});
        log(cdebug{"And this one"});
    }

    std::string result{expected_output};

    CHECK(result == new_out.str());
}
