#ifndef UCI_INTERFACE_LIMITS_HPP
#define UCI_INTERFACE_LIMITS_HPP

#include <chrono>
#include <vector>
#include <string>

namespace uci {

struct limits {
    /**
     * Limit the search to the following moves
     */
    std::vector<std::string> search_moves;

    /**
     * Run the engine in ponder mode
     */
    bool ponder = false;

    /**
     * The time white has left on the clock
     */
    std::chrono::milliseconds wtime = std::chrono::milliseconds(0);

    /**
     * The time black has left on the clock
     */
    std::chrono::milliseconds btime = std::chrono::milliseconds(0);

    /**
     * The increment that white has
     */
    std::chrono::milliseconds winc = std::chrono::milliseconds(0);

    /**
     * The increment that black has
     */
    std::chrono::milliseconds binc = std::chrono::milliseconds(0);

    /**
     * The amount of moves till the next time control
     */
    size_t moves_to_go = 0;

    /**
     * The limit depth that the engine can search
     */
    size_t depth = 0;

    /**
     * The amount of nodes that can be searched
     */
    size_t nodes = 0;

    /**
     * Search for mate in `mate` moves
     */
    size_t mate = 0;

    /**
     * Search exactly `move_time` milliseconds
     */
    std::chrono::milliseconds move_time = std::chrono::milliseconds(0);

    /**
     * Search until the stop comamnd (Do not exit search alone)
     */
    bool infinite = true;
};

} // namespace uci

#endif
