#ifndef UCI_ENGINE_INTERFACE_HPP
#define UCI_ENGINE_INTERFACE_HPP

#include <string>

namespace uci {
	
	class engine_interface {
   public:
        virtual bool check_register(void) = 0;
		virtual bool check_register(const std::string &user,
                                    const std::string &code) = 0;
        virtual bool check_copy_protection(void) = 0;
        virtual bool load_options(void) = 0;
        virtual void set_author_name(const char *name) = 0;
        virtual void set_engine_name(const char *name) = 0;
        virtual void requires_registration(bool v) = 0;
        virtual void requires_copy_protection(bool v) = 0;
        virtual void can_ponder(bool v) = 0;
        virtual void update_position(const std::string &fen,
                                     const std::string &moves) = 0;
        virtual std::string get_best_move(uci::limits l) = 0;
        virtual bool        ponder_mode(void) = 0;
        virtual bool        search_mode(void) = 0;
	};

}

#endif