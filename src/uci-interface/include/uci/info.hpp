#ifndef UCI_INTERFACE_INFO_HPP
#define UCI_INTERFACE_INFO_HPP

#include <uci/globals.hpp>

#include <iostream>
#include <chrono>
#include <string>
#include <type_traits>

//
// A lot of this is repetetive, so lets use some macros
//

#define UCI_EXPAND_STRUCT(name, type) \
    struct name final { \
        type name; \
    };

#define UCI_EXPAND_FUNCTION(name, identifyier) \
    inline void imp_log(const name &message) { \
        ::std::cout << identifyier " " << message.name << ' '; \
    }

#define UCI_EXPAND_DEBUG_FUNCTION(name, identifyier) \
    inline void imp_log(const name &message) { \
        if (uci::debug) { \
            ::std::cout << identifyier " " << message.name << ' '; \
        } \
    }

#define UCI_EXPAND_NAMESPACED_FUNCTION(nmspace, name, identifyier) \
    inline void imp_log(const nmspace::name &message) { \
        ::std::cout << identifyier " " << message.name << ' '; \
    }

#define UCI_EXPAND_STUCT_AND_FUNCTION(name, type, identifyier) \
    UCI_EXPAND_STRUCT(name, type) \
    UCI_EXPAND_FUNCTION(name, identifyier)


namespace uci::info {

// ------------------- The direct ones -------------------------------

UCI_EXPAND_STUCT_AND_FUNCTION(depth, size_t, "depth")
UCI_EXPAND_STUCT_AND_FUNCTION(selective_depth, size_t, "seldepth")
UCI_EXPAND_STUCT_AND_FUNCTION(nodes, size_t, "nodes")
UCI_EXPAND_STUCT_AND_FUNCTION(pv, std::string, "pv")
UCI_EXPAND_STUCT_AND_FUNCTION(multipv, size_t, "multipv")
UCI_EXPAND_STUCT_AND_FUNCTION(current_move, std::string, "currmove")
UCI_EXPAND_STUCT_AND_FUNCTION(current_move_number, size_t, "currmovenumber")
UCI_EXPAND_STUCT_AND_FUNCTION(hashfull, size_t, "hashfull")
UCI_EXPAND_STUCT_AND_FUNCTION(nodes_per_second, size_t, "nps")
UCI_EXPAND_STUCT_AND_FUNCTION(table_base_hits, size_t, "tbhits")
UCI_EXPAND_STUCT_AND_FUNCTION(shredder_base_hits, size_t, "sbhits")
UCI_EXPAND_STUCT_AND_FUNCTION(cpu_load, size_t, "cpuload")
UCI_EXPAND_STUCT_AND_FUNCTION(string, std::string, "string")
UCI_EXPAND_STUCT_AND_FUNCTION(cstring, const char *, "string")
UCI_EXPAND_STUCT_AND_FUNCTION(refutation, std::string, "refutation")
UCI_EXPAND_STUCT_AND_FUNCTION(current_line, std::string, "currline")


// -------------------     Score     -------------------------------


struct score final {
    UCI_EXPAND_STRUCT(centipawns, long long)
    UCI_EXPAND_STRUCT(mate, size_t)

    // This two will need a special function
    UCI_EXPAND_STRUCT(lowerbound, long long)
    UCI_EXPAND_STRUCT(upperbound, long long)
};

UCI_EXPAND_NAMESPACED_FUNCTION(score, centipawns, "cp")
UCI_EXPAND_NAMESPACED_FUNCTION(score, mate, "mate")

inline void imp_log(const score::upperbound &message) {
    std::cout << "cp " << message.upperbound << " uperbound ";
}

inline void imp_log(const score::lowerbound &message) {
    std::cout << "cp " << message.lowerbound << " lowerbound ";
}

// -------------------      Debug     -------------------------------


UCI_EXPAND_STRUCT(debug, std::string)
UCI_EXPAND_DEBUG_FUNCTION(debug, "string")

UCI_EXPAND_STRUCT(cdebug, const char *)
UCI_EXPAND_DEBUG_FUNCTION(cdebug, "string")


// -------------------       Time      -------------------------------


UCI_EXPAND_STRUCT(time, std::chrono::milliseconds)

inline void imp_log(const std::chrono::milliseconds &message) {
    std::cout << "time " << message.count() << ' ';
}

// -------------------       Log      -------------------------------

template<class MessageType, class... Arg>
inline void imp_variadic_log(const MessageType &m, const Arg &...args) {
    imp_log(m);
    if constexpr (sizeof...(args) != 0) {
        imp_variadic_log(args...);
    }
}

template<class... Messages>
inline void log(const Messages&... messages) {
    std::cout << "info ";
    imp_variadic_log(messages...);
    std::cout << '\n';
}

} // namespace uci::info

#undef UCI_EXPAND_STRUCT
#undef UCI_EXPAND_FUNCTION
#undef UCI_EXPAND_DEBUG_FUNCTION
#undef UCI_EXPAND_NAMESPACED_FUNCTION
#undef UCI_EXPAND_STUCT_AND_FUNCTION

#endif
