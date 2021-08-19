#include <uci/engine_interface.hpp>

void uci::engine_interface::set_author_name(const char *name) {
    author_name = name;
}

void uci::engine_interface::set_engine_name(const char *name) {
    engine_name = name;
}


void uci::engine_interface::requires_registration(bool v) {
    engine_requires_registration = v;
}

void uci::engine_interface::requires_copy_protection(bool v) {
    engine_requires_copyprotection = v;
}

void uci::engine_interface::can_ponder(bool v) {
    engine_can_ponder = v;
}
