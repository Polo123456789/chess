#ifndef UCI_ENGINE_INTERFACE_HPP
#define UCI_ENGINE_INTERFACE_HPP

#include <string>

#include <uci/limits.hpp>

namespace uci {

class engine_interface {
   public:
    /**
     * Return whether the automatic register check was passed
     */
    virtual bool check_register(void);

    /**
     * Return true if registration is successful
     */
    virtual bool check_register(const std::string &user,
                                const std::string &code) = 0;
    /**
     * Returns true if copy protection OK
     */
    virtual bool check_copy_protection(void);

    /**
     * Loads default options
     */
    virtual bool load_options(void);

    /**
     * The following are metadata functions
     */
    void set_author_name(const char *name);
    void set_engine_name(const char *name);
    void requires_registration(bool v);
    void requires_copy_protection(bool v);
    void can_ponder(bool v);

    /**
     * Updates the position the engine holds
     */
    virtual void update_position(const std::string &fen,
                                 const std::string &moves) = 0;
    /*
     * Returns the best move in UCI format
     */
    virtual std::string get_best_move(const limits &l) = 0;

    /*
     * Sets the engine to ponder mode
     */
    virtual bool ponder_mode(void) = 0;

    /*
     * Sets the engine to search mode
     */
    virtual bool search_mode(void) = 0;

   private:
    const char* author_name = nullptr;
    const char* engine_name = nullptr;
    bool engine_requires_registration = false;
    bool engine_requires_copyprotection = false;
    bool engine_can_ponder = false;
};

} // namespace uci

#endif

