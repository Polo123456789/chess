#include <uci/info.hpp>

int main(int /*argc*/, char * /*argv*/[]) {
    uci::info::log(
        uci::info::depth{10},
        uci::info::selective_depth{20},
        uci::info::multipv{1},
        uci::info::score::centipawns{10},
        uci::info::nodes{0},
        uci::info::pv{"e2e4 c7c5"}
    );
    return 0;
}
