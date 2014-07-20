#ifndef SEQUENCE_6_18_2014_HPP
#define SEQUENCE_6_18_2014_HPP

#include <iterator>
#include <iostream>
#include <vector>

/// Forward declare for our custom global operators
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container = std::vector>
class Sequence;

/**
 * Inserts the provided Sequence into the provided output stream
 * 
 * @param stream the output stream to insert into
 * 
 * @param sequence the Sequence to insert
 * 
 * @return the provided output stream
 * 
 */
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container = std::vector>
std::ostream& operator<<(std::ostream& stream, const Sequence<Module>& sequence);

/**
 * Inserts the provided Sequence into the provided output stream
 * 
 * @param stream the output stream to insert into
 * 
 * @param sequence the Sequence to insert
 * 
 * @return the provided output stream
 * 
 */
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container = std::vector>
std::ostream& operator<<(std::ostream& stream, Sequence<Module>&& sequence);

/**
 * Populates the provided Sequence from the data extracted from the provided input stream 
 * 
 * @param stream the stream to extract data from
 * 
 * @param sequence the Sequence to populate
 * 
 * @return the provided input stream
 * 
 */
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container = std::vector>
std::istream& operator>>(std::istream& stream, Sequence<Module>& sequence);

/**
 * Equality operator for Sequences
 * 
 * @param sequence0 the first Sequence to compare
 * 
 * @param sequence1 the second Sequence to compare
 * 
 * @return true if and only if the first Sequence is equivalent to the second
 * 
 * @note The provided Sequences may be subjected to epsilon-value floating point comparisons as required
 * 
 */
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container = std::vector>
bool operator==(const Sequence<Module, Container>& sequence0, const Sequence<Module, Container>& sequence1);

/**
 * Inequality operator for Sequences
 * 
 * @param sequence0 the first Sequence to compare
 * 
 * @param sequence1 the second Sequence to compare
 * 
 * @return true if and only if the first Sequence is not equivalent to the second
 * 
 * @note The provided Sequences may be subjected to epsilon-value floating point comparisons as required
 * 
 */
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container = std::vector>
bool operator!=(const Sequence<Module, Container>& sequence0, const Sequence<Module, Container>& sequence1);

/**
 * Creates a Sequence by adding the two provided Sequences
 * 
 * @param sequence0 the first Sequence to add
 * 
 * @param segment1 the second Sequence to add
 * 
 * @return a Sequence that represents the sum of the two provided Sequences
 * 
 */
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container = std::vector>
Sequence<Module> operator+(const Sequence<Module>& sequence0, const Sequence<Module>& sequence1);

/**
 * Creates a Sequence by adding the two provided Sequences
 * 
 * @param sequence0 the first Sequence to add
 * 
 * @param segment1 the second Sequence to add
 * 
 * @return a Sequence that represents the sum of the two provided Sequences
 * 
 * @note For an optimization, consider this operator when sequence0 and sequence1 are not referenced by the 
 * calling method after this method returns.
 * 
 * @code Sequence<int> seq0, seq1;
 * Sequence<int> seq3 = std::move(seq0) + std::move(seq1)
 * 
 */
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container = std::vector>
Sequence<Module> operator+(Sequence<Module>&& sequence0, Sequence<Module>&& sequence1);

/// Inject our 'Module' concept checks
//#include "ModuleConcepts.hpp"

/**
 * A Sequence is a complete series of barcode segments that represents the encoded form of a piece of data.  Sequences 
 * are designed to be STL-compatible such that they are compatible with iteration and various other standard 
 * operations.
 * 
 */
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
class Sequence
{
    /// Global operators that can bypass the indirection to the underlying STL container
    friend std::ostream& operator<<<>(std::ostream&, const Sequence<Module>&);
    friend std::ostream& operator<<<>(std::ostream&, Sequence<Module>&&);
    friend std::istream& operator>><>(std::istream&, Sequence<Module>&);
    friend bool operator==<>(const Sequence<Module>&, const Sequence<Module>&);
    friend bool operator!=<>(const Sequence<Module>&, const Sequence<Module>&);
    friend Sequence<Module> operator+<>(const Sequence<Module>&, const Sequence<Module>&);
    friend Sequence<Module> operator+<>(Sequence<Module>&&, Sequence<Module>&&);

    /// The collective Modules that make up this Sequence
    Container<Module> segments;
    
  public:

    /// Alias typedefs to the underlying STL container types
    typedef typename std::vector<Module>::allocator_type allocator_type;
    typedef typename std::vector<Module>::const_iterator const_iterator;
    typedef typename std::vector<Module>::const_pointer const_pointer;
    typedef typename std::vector<Module>::const_reference const_reference;
    typedef typename std::vector<Module>::const_reverse_iterator const_reverse_iterator;
    typedef typename std::vector<Module>::difference_type difference_type;
    typedef typename std::vector<Module>::iterator iterator;
    typedef typename std::vector<Module>::pointer pointer;
    typedef typename std::vector<Module>::reference reference;
    typedef typename std::vector<Module>::reverse_iterator reverse_iterator;
    typedef typename std::vector<Module>::size_type size_type;
    typedef typename std::vector<Module>::value_type value_type;
    
    /**
     * Retrieves an iterator to the beginning of this Sequence
     * 
     * @return an iterator to the beginning of this Sequence
     * 
     */
    iterator begin() noexcept;
    
    /**
     * Retrieves a const_iterator to the beginning of this Sequence
     * 
     * @return a const_iterator to the beginning of this Sequence
     */
    const_iterator begin() const noexcept;
    
    /**
     * Retrieves an iterator to the end of this Sequence
     * 
     * @return an iterator to the end of this Sequence
     * 
     */
    iterator end() noexcept;
    
    /**
     * Retrieves a const_iterator to the end of this Sequence
     * 
     * @return a const_iterator to the end of this Sequence
     * 
     */
    const_iterator end() const noexcept;
    
    /**
     * Retrives the number of Modules that make up this Sequence
     * 
     * @return the number of Modules that make up this Sequence
     * 
     */
    size_type size() const noexcept;
    
    /**
     * Retrieves the Module at the provided index
     * 
     * @param index the index to retrieve
     * 
     * @return the Module at the provided index
     * 
     * @note If index does not lie within the bounds of this Sequence, the behavior is undefined.
     */
    const_reference operator[](unsigned index) const;
    
    /**
     * Retrieves the Module at the provided index
     * 
     * @param index the index to retrieve
     * 
     * @return the Module at the provided index
     * 
     * @note If index does not lie within the bounds of this Sequence, the behavior is undefined.
     */
    reference operator[](unsigned index);
    
    /**
     * Adds the provided Sequence to this one
     * 
     * @param sequence the Sequence to add
     * 
     * @return *this
     * 
     */
    Sequence& operator+=(const Sequence& sequence);
    
    /**
     * Adds the provided Sequence to this one
     * 
     * @param sequence the Sequence to add
     * 
     * @return *this
     * 
     */
    Sequence& operator+=(Sequence&& sequence);

    /**
     * Adds the provided Module to the end of this Sequence
     * 
     * @param module the Module to add
     * 
     * @return *this
     * 
     */
    Sequence& operator+=(const Module& module);
    
    /**
     * Adds the provided Module to the end of this Sequence
     * 
     * @param module the Module to add
     * 
     * @return *this
     * 
     */
    Sequence& operator+=(Module&& module);
    
    /**
     * Constructs an empty Sequence
     * 
     */
    constexpr Sequence() = default;

    /**
     * Constructs a Sequence with the provided segments
     * 
     * @param first the first Module
     * 
     * @param remaining all subsequent Modules
     * 
     */
    template<typename... E>
    Sequence(Module&& first, E&& ...remaining);
    
    /**
     * Constructs a Sequence with the provided segments
     * 
     * @param first the first Module
     * 
     * @param remaining all subsequent Modules
     * 
     */
    template<typename... E>
    Sequence(const Module& first, const E& ...remaining);
    
    /**
     * Constructs a Sequence from the provided initializer list of Modules
     * 
     * @param segments the Modules that make up this Sequence
     * 
     * @code
     * Use Examples:
     * <t>Sequence<int> sequence {0, 1, 2, 3};
     * 
     */
    Sequence(std::initializer_list<Module>&& segments);
   
    /**
     * Default copy-assignment operator
     * 
     * @param sequence the Sequence to assign to this one
     * 
     * @return *this
     * 
     */
    Sequence& operator=(const Sequence& sequence) = default;
    
    /**
     * Default move-assignment operator
     * 
     * @param sequence the Sequence to assign to this one
     * 
     * @return *this
     * 
     */
    Sequence& operator=(Sequence&& sequence) = default;

    /**
     * Default copy-constructor
     * 
     * @param sequence the Sequence that is being copied
     * 
     */
    Sequence(const Sequence& sequence) = default;
    
    /**
     * Default move-constructor
     * 
     * @param sequence the Sequence that is being moved
     * 
     */
    Sequence(Sequence&& sequence) = default;
    
    /**
     * Default non-virtual destructor
     * 
     */
    ~Sequence() = default;
       
};

#include "Sequence.inl"

#endif
