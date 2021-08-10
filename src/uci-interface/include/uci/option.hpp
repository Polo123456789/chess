#ifndef UCI_INTERFACE_OPTION_HPP
#define UCI_INTERFACE_OPTION_HPP

#include <string>
#include <cstdint>

namespace uci {

class option {
   public:
    struct check {
        using type = bool;
    };
    struct spin {
        using type = int64_t;
    };
    struct combo {
        using type = std::string;
    };
    struct string {
        using type = std::string;
    };

    template<class Type>
    typename Type::type as(void);

   private:

};


} // namespace uci

#endif
