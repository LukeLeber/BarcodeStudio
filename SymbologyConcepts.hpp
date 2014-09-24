/**
 * This file is protected under the KILLGPL license.
 * 
 * For more information, visit https://www.github.com/LukeLeber/KILLGPL
 * 
 */

#include "Concepts.hpp"

namespace detail
{
#pragma clang diagnostic push
    /// clang complains about having a declared, but not defined inline function in our SFINAE tricks
    /// This shouldn't be an issue, since we only use this for static-analysis.
#pragma clang diagnostic ignored "-Wundefined-inline"

    /// Use our macros to bang out each concept check
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, alphanumeric, const bool);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, numeric, const bool);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, discrete, const bool);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, continuous, const bool);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, multi_width, const bool);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, dual_width, const bool);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, fixed_length, const bool);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, variable_length, const bool);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, self_checking, const bool);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, uses_checksum, const bool);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, charset, const std::string);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, start_sequence, const typename Symbology::SequenceType);
    GENERATE_CONCEPT_FIELD_CHECK(Symbology, stop_sequence, const typename Symbology::SequenceType);
    
    GENERATE_CONCEPT_STATIC_METHOD_CHECK(Symbology, checksum, unsigned char, const std::string&);
    GENERATE_CONCEPT_STATIC_METHOD_CHECK(Symbology, encode, typename Symbology::SequenceType, const std::string&);
    GENERATE_CONCEPT_STATIC_METHOD_CHECK(Symbology, decode, std::string, const typename Symbology::SequenceType&);
}

/**
 * @internal
 *  Trigger 'Symbology' concept checks to run
 * 
 */
template<typename Symbology>
struct symbology_concept_check
{
    static constexpr bool value = 
            detail::Symbology_encode_concept_check<Symbology>::value && 
            detail::Symbology_decode_concept_check<Symbology>::value && 
            detail::Symbology_checksum_concept_check<Symbology>::value && 
            detail::Symbology_alphanumeric_concept_check<Symbology>::value && 
            detail::Symbology_discrete_concept_check<Symbology>::value && 
            detail::Symbology_continuous_concept_check<Symbology>::value && 
            detail::Symbology_multi_width_concept_check<Symbology>::value && 
            detail::Symbology_dual_width_concept_check<Symbology>::value && 
            detail::Symbology_fixed_length_concept_check<Symbology>::value && 
            detail::Symbology_variable_length_concept_check<Symbology>::value && 
            detail::Symbology_self_checking_concept_check<Symbology>::value && 
            detail::Symbology_uses_checksum_concept_check<Symbology>::value && 
            detail::Symbology_charset_concept_check<Symbology>::value && 
            detail::Symbology_numeric_concept_check<Symbology>::value && 
            detail::Symbology_start_sequence_concept_check<Symbology>::value;

    
};

#pragma clang diagnostic pop