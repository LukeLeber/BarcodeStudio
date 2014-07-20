#ifndef MODULE_CONCEPTS_HPP
#define MODULE_CONCEPTS_HPP

#include "Concepts.hpp"


namespace detail
{
#pragma clang diagnostic push
    /// clang complains about having a declared, but not defined inline function in our SFINAE trick
    /// This shouldn't be an issue, since we only use this for static-analysis.
#pragma clang diagnostic ignored "-Wundefined-inline"

    // TODO: non-static concept checking
    
/*    GENERATE_CONCEPT_STATIC_METHOD_CHECK(Module, getWeight, std::size_t, void);
    GENERATE_CONCEPT_OPERATOR_CHECK(Module, bool, bool, void);

#pragma clang diagnostic pop
    
}
template<typename Module>
struct module_concept_check
{
    static constexpr bool value = detail::Module_getWeight_concept_check<Module>::value;

};*/

#endif