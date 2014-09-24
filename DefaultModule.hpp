/**
 * This file is protected under the KILLGPL license.
 * 
 * For more information, visit https://www.github.com/LukeLeber/KILLGPL
 * 
 */
#ifndef DEFAULT_MODULE_HPP
#define DEFAULT_MODULE_HPP

#include <cstdint> // for std::size_t

/// Forward declaration for our global friend relational operators
class DefaultModule;

/**
 * Equality operator for {@link DefaultModule DefaultModules}
 * 
 * @param arg0 the first module to compare
 * 
 * @param arg1 the other module to compare
 * 
 * @return true if the two modules are equal, otherwise false.  More formally, this operator returns true if 
 * and only if the two modules' 'on' flags and weights are equal.
 * 
 */
constexpr bool operator==(const DefaultModule& arg0, const DefaultModule& arg1) noexcept;

/**
 * Inequality operator for {@link DefaultModule DefaultModules}
 * 
 * @param arg0 the first module to compare
 * 
 * @param arg1 the other module to compare
 * 
 * @return true if the two modules are not equal, otherwise false.  More formally, this operator returns true if 
 * the two modules' 'on' flag or weights are not equal.
 * 
 */
constexpr bool operator!=(const DefaultModule& vm0, const DefaultModule& vm1) noexcept;

/**
 * A safe default for the Module concept which should handle most (if not all) specifications.
 * Nearly every use case in this library should be through aggregate initialization.  Furthermore, 
 * this class is 100% 'constexpr-compatible' -- perfect for lookup-tables and other optimization areas.
 * 
 * @code
 *  /// Aggregate initialization of a DefaultModule of weight 3 that represents a bar
 *  DefaultModule example {3, true};
 */
class DefaultModule
{
    /// Our friends (helps to elide calls to accessors within relational operators)
    friend constexpr bool operator==(const DefaultModule&, const DefaultModule&) noexcept;
    friend constexpr bool operator!=(const DefaultModule&, const DefaultModule&) noexcept;
    
    /// The weight of this module in units of 'x'
    std::size_t weight;
    
    /// Does this module represent a bar or a blank?
    bool on;
    
  public:

    /**
     * Constructs a DefaultModule
     * 
     * @param weight the weight of this module in units of 'x'
     * 
     * @param on does this module represent a bar or a blank?
     * 
     */
    constexpr DefaultModule(std::size_t weight, bool on) noexcept;
    
    /**
     * Retrieves the weight of this module
     * 
     * @return the weight of this module in units of 'x'
     * 
     */
    constexpr std::size_t getWeight() const noexcept;
    
    /**
     * Implicit conversion operator to bool
     * 
     * @return true if this module represents a bar, otherwise false (in which case, a blank is represented).
     * 
     * @note  this operator should be used to check whether this module is a bar or a blank
     * 
     * @code 
     *  bool bar = randomBoolGenerator();
     *  DefaultModule module {1, bar};
     *  if(bar)
     *  {
     *   // render a bar
     *  }
     *  else
     *  {
     *   // render a blank
     *  }
     * 
     */
    constexpr operator bool() const noexcept;
    
};

/// Implementation details
#include "DefaultModule.inl"

#endif