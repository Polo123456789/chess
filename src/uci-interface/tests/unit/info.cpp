#include <uci/info.hpp>

#include <gsl/gsl>
#include <catch2/catch.hpp>

#include <sstream>

TEST_CASE("uci::info", "[uci] [uci::info]") {
    std::stringstream new_out;

    // Redirect std::cout
    auto* old_cout_buffer = std::cout.rdbuf();
    std::cout.rdbuf(new_out.rdbuf());

    auto restore_cout_buffer = gsl::finally([&]() {
        std::cout.rdbuf(old_cout_buffer);
    });

    // There are 20 message types, so lets 
}
