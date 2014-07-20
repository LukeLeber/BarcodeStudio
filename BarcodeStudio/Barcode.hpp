/**
 * This file is protected under the KILLGPL license.
 * 
 * For more information, visit https://www.github.com/LukeLeber/KILLGPL
 * 
 */

#ifndef BARCODE_HPP
#define BARCODE_HPP

#include <string>
#include <type_traits>

#include "Sequence.hpp"
#include "SymbologyConcepts.hpp"

/**
 * The Barcode class is responsible for taking a symbology specification and applying it to encode and decode 
 * arbitrary data.  
 */
template<typename Symbology>
class Barcode
{
    /// Concept Checks! (vastly improve compiler diagnostics if a symbology template has an error)
    /// Clang stops compiling after the first static_assert fails, so this message isn't printed out...
    /// however other compilers *might*, so I have left it in for good measure.
    static_assert(symbology_concept_check<Symbology>::value, 
            "One or more 'Symbology' concept check(s) have failed!  "
            "Review the compiler diagnostics for more information.");
    
    /// Alias type for referring to the underlying dependent type
    using SequenceType = typename Symbology::SequenceType;
    
    /// The decoded representation of this barcode
    std::string decoded;
    
    /// The encoded representation of this barcode
    SequenceType encoded;
    
  public:
    
    /**
     * Constructs a Barcode with the provided string data
     * 
     * @param data the string to encode
     * 
     * @note Use this constructor when the caller still has use for the provided string.
     * 
     */
    Barcode(const std::string& data);

    /**
     * Constructs a Barcode with the provided string data
     * 
     * @param data the string to encode
     * 
     * @note [optimization] Use this constructor when the caller has no further use for the provided string.
     * 
     * @code
     *  /// Avoid internal allocations by utilizing move semantics
     *  std::string data = "example";
     *  Barcode<SomeSymbology> barcode(std::move(data));
     * 
     */
    Barcode(std::string&& data);

    /**
     * Constructs a Barcode with the provided encoding sequence
     * 
     * @param sequence the encoding sequence to decode
     * 
     * @note Use this constructor when the caller still has use for the provided encoding sequence
     * 
     */
    Barcode(const SequenceType& sequence);

    /**
     * Constructs a Barcode with the provided encoding sequence
     * 
     * @param sequence the encoding sequence to decode
     * 
     * @note [optimization] Use this constructor when the caller has no further use for the provided encoding sequence
     * 
     * @code
     *  /// Avoid internal allocations by utilizing move semantics
     *  SequenceType someSequence = generateFakeSequence();
     *  Barcode<SomeSymbology> barcode(std::move(someSequence));
     * 
     */
    Barcode(SequenceType&& sequence);

    /**
     * Sets the data of this Barcode
     * 
     * @param data the string data to set and encode
     * 
     * @note Use this method when the caller still has use for the provided string
     * 
     */
    void setData(const std::string& data);

    /**
     * Sets the data of this Barcode
     * 
     * @param data the string data to set and encode
     * 
     * @note [optimization] Use this method when the caller has no further use for the provided string
     * 
     * @code
     *  /// Avoid internal allocations by utilizing move semantics
     *  std::string data = "example";
     *  Barcode<SomeSymbology> barcode = generateFakeBarcode();
     *  barcode.setData(std::move(data));
     * 
     */
    void setData(std::string&& data);

    /**
     * Sets the data of this Barcode
     * 
     * @param data the encoding sequence to set and decode
     * 
     * @note Use this method when the caller still has use for the provided encoding sequence
     * 
     */
    void setData(const SequenceType& data);
    
    /**
     * Sets the data of this Barcode
     * 
     * @param data the encoding sequence to set and decode
     * 
     * @note [optimization] Use this method when the caller has no further use for the provided encoding sequence
     * 
     * @code
     *  /// Avoid internal allocations by utilizing move semantics
     *  SequenceType someSequence = generateFakeSequence();
     *  Barcode<SomeSymbology> barcode = generateFakeBarcode();
     *  barcode.setData(std::move(someSequence));
     * 
     */
    void setData(SequenceType&& data);
    
    /**
     * Retrieves the decoded (plain-text) data of this Barcode
     * 
     * @return the decoded (plain-text) data of this Barcode
     * 
     */
    const std::string& getData() const noexcept;

    /**
     * Retrieves the encoded data of this Barcode
     * 
     * @return Retrieves the encoded data of this Barcode
     * 
     */
    const SequenceType& getEncoding() const noexcept;
    
};

/// Implementation details
#include "Barcode.inl"

#endif
