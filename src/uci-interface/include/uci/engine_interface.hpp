#ifndef UCI_ENGINE_INTERFACE_HPP
#define UCI_ENGINE_INTERFACE_HPP

#include <string>

namespace uci {
	
	class engine_interface {
   public:
        /**
        * Return whether the automatic register check was passed
        */
        virtual bool check_register(void) = 0;
        /**
        * Return true if registration is successful
        */
		virtual bool check_register(const std::string &user,
                                    const std::string &code) = 0;
        /**
        * Returns true if copy protection OK 
        */
        virtual bool check_copy_protection(void) = 0;
        /**
        * Loads default options 
        */
        virtual bool load_options(void) = 0;
        /**
        * The following are metadata functions
        */
        virtual void set_author_name(const char *name) = 0;
        virtual void set_engine_name(const char *name) = 0;
        virtual void requires_registration(bool v) = 0;
        virtual void requires_copy_protection(bool v) = 0;
        virtual void can_ponder(bool v) = 0;
        /**
        * Updates the position the engine holds
        */
        virtual void update_position(const std::string &fen,
                                     const std::string &moves) = 0;
        /*
        * Returns the best move in UCI format
        */
        virtual std::string get_best_move(uci::limits l) = 0;
        /*
        * Sets the engine to ponder mode
        */
        virtual bool        ponder_mode(void) = 0;
        /*
        * Sets the engine to search mode
        */
        virtual bool        search_mode(void) = 0;
	};

}

#endif