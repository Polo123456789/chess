#include <uci/info.hpp>

#include <catch2/catch.hpp>

#include <sstream>

TEST_CASE("uci::info", "[uci] [uci::info]") {
    std::stringstream new_out;

    // Redirect std::cout
    
    auto* old_cout = std::cout.rdbuf();

}
