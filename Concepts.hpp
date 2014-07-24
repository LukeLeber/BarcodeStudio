#ifndef CONCEPTS_HPP
#define CONCEPTS_HPP

#include <type_traits>
#include <utility>

/**
 * A macro that generates a field concept check.  The check that is generated shall have the following 
 * naming format: "[CONCEPT_NAME]_[FIELD_NAME]_concept_check", so for example...
 * 
 * @code
 *  GENERATE_CONCEPT_FIELD_CHECK(Example, test_field, bool);
 *  // generates...
 *  template<typename Symbology> class Example_test_field_concept_check { ... };
 * 
 * The check will ensure an easy to understand compile-time error if the specified field is missing from the 
 * template parameter or if the type of the field of the template parameter does not match the expected type.  
 * 
 * For example:
 * 
 * @code
 *  GENERATE_CONCEPT_FIELD_CHECK(Example, test_field, const bool);
 *  struct W { };
 *  struct X { int test_field; };
 *  struct Y { bool test_field; };
 *  struct Z { const bool test_field; };
 * 
 *  Example_test_field_concept_check<W>::value; // Compile-time error - missing field 'test_field'
 *  Example_test_field_concept_check<X>::value; // Compile-time error - incorrect type 'int', expected 'const bool'
 *  Example_test_field_concept_check<Y>::value; // Compile-time error - incorrect type 'bool', expected 'const bool'
 *  Example_test_field_concept_check<Z>::value; // Works - Z has a field 'test_field' of type 'const bool'
 * 
 * @param CONCEPT_NAME - the name of the concept that the check is being generated for
 * 
 * @param FIELD_NAME - the name of the field that is being checked
 * 
 * @param EXPECTED_TYPE - the type that the field is expected to be
 * 
 */
#define GENERATE_CONCEPT_FIELD_CHECK(CONCEPT_NAME, FIELD_NAME, EXPECTED_TYPE)\
    template<typename Symbology>\
    class CONCEPT_NAME ##_##FIELD_NAME ##_concept_check\
    {\
        template<typename T>\
        static constexpr decltype(std::declval<T>(). FIELD_NAME, void(), std::true_type()) test(int);\
\
        template<typename T>\
        static constexpr std::false_type test(...);\
\
        static_assert(decltype(test<Symbology>(0))::value, \
                      #CONCEPT_NAME " CONCEPT CHECK FAILED: [missing field: " #FIELD_NAME "]  "  \
                      "Hint: Did you forget to add the field '" #FIELD_NAME "' to your " #CONCEPT_NAME "template class?");\
\
        using ACTUAL_TYPE = decltype(Symbology::FIELD_NAME);\
        static_assert(std::is_same<EXPECTED_TYPE, ACTUAL_TYPE>::value, \
                    #CONCEPT_NAME " CONCEPT CHECK FAILED: [type mismatch: " #FIELD_NAME "]  " \
                    "Hint: Check the type of the '" #FIELD_NAME "' field in your " #CONCEPT_NAME " template class; \
                    it should be of type '" #EXPECTED_TYPE "'.");\
  public: \
\
        static constexpr bool value = decltype(test<Symbology>(0))::value && \
                                      std::is_same<EXPECTED_TYPE, ACTUAL_TYPE>::value;\
}

#define GENERATE_CONCEPT_STATIC_METHOD_CHECK(CONCEPT_NAME, METHOD_NAME, EXPECTED_RETURN_TYPE, ARGUMENT_TYPE)\
    template<typename Symbology>\
    class CONCEPT_NAME ##_##METHOD_NAME ##_concept_check\
    {\
        template<typename T>\
        static constexpr decltype(std::declval<T>(). METHOD_NAME, void(), std::true_type()) test(int);\
\
        template<typename T>\
        static constexpr std::false_type test(...);\
\
        static_assert(decltype(test<Symbology>(0))::value, \
                      #CONCEPT_NAME " CONCEPT CHECK FAILED: [missing method: " #METHOD_NAME "]  "  \
                      "Hint: Did you forget to add the method '" #METHOD_NAME "' to your " #CONCEPT_NAME " class?");\
\
        using STRIPPED_ARGUMENT_TYPE = typename std::remove_reference<ARGUMENT_TYPE>::type;\
        using ACTUAL_RETURN_TYPE = decltype(Symbology::METHOD_NAME((STRIPPED_ARGUMENT_TYPE())));\
\
        static_assert(std::is_same<EXPECTED_RETURN_TYPE, ACTUAL_RETURN_TYPE>::value, \
                      #CONCEPT_NAME " CONCEPT CHECK FAILED: [method return type mismatch: " #METHOD_NAME "] " \
                      "Hint: Check the method signature; it should be \
                      '" #EXPECTED_RETURN_TYPE " " #METHOD_NAME "(" #ARGUMENT_TYPE ");'");\
  public: \
\
        static constexpr bool value = decltype(test<Symbology>(0))::value && \
                                      std::is_same<EXPECTED_RETURN_TYPE, ACTUAL_RETURN_TYPE>::value;\
}

#define GENERATE_CONCEPT_OPERATOR_CHECK(CONCEPT_NAME, OPERATOR_NAME, EXPECTED_RETURN_TYPE, ARGUMENT_TYPE)\
    template<typename Symbology>\
    class CONCEPT_NAME ##_operator_ ##OPERATOR_NAME ##_concept_check\
    {\
        template<typename T>\
        static constexpr decltype(std::declval<T>(). operator ## OPERATOR_NAME, void(), std::true_type()) test(int);\
\
        template<typename T>\
        static constexpr std::false_type test(...);\
\
        static_assert(decltype(test<Symbology>(0))::value, \
                      #CONCEPT_NAME " CONCEPT CHECK FAILED: [missing method: " #OPERATOR_NAME "]  "  \
                      "Hint: Did you forget to add the method '" #OPERATOR_NAME "' to your Symbology class?");\
\
        using STRIPPED_ARGUMENT_TYPE = typename std::remove_reference<ARGUMENT_TYPE>::type;\
        using ACTUAL_RETURN_TYPE = decltype(Symbology::operator ##OPERATOR_NAME((STRIPPED_ARGUMENT_TYPE())));\
\
        static_assert(std::is_same<EXPECTED_RETURN_TYPE, ACTUAL_RETURN_TYPE>::value, \
                      #CONCEPT_NAME " CONCEPT CHECK FAILED: [method return type mismatch: " #OPERATOR_NAME "] " \
                      "Hint: Check the method signature; it should be \
                      '" #EXPECTED_RETURN_TYPE " " #OPERATOR_NAME "(" #ARGUMENT_TYPE ");'");\
  public: \
\
        static constexpr bool value = decltype(test<Symbology>(0))::value && \
                                      std::is_same<EXPECTED_RETURN_TYPE, ACTUAL_RETURN_TYPE>::value;\
}

#endif
