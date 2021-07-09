#ifndef UCI_INTERFACE_GLOBALS
#define UCI_INTERFACE_GLOBALS

#include <atomic>

namespace uci {

extern std::atomic<bool> debug;
extern std::atomic<bool> stop_searching;

} // namespace uci

#endif
