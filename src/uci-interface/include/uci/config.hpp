#ifndef UCI_INTERFACE_CONFIG_HPP
#define UCI_INTERFACE_CONFIG_HPP

#include <uci/option.hpp>

#include <string>
#include <unordered_map>

namespace uci {

extern std::unordered_map<std::string, option> config; // NOLINT

}

#endif
