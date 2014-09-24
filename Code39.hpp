/**
 * This file is protected under the KILLGPL license.
 * 
 * For more information, visit https://www.github.com/LukeLeber/KILLGPL
 * 
 * Copyright 2014 Luke A. Leber <LukeLeber@gmail.com>
 * 
 */
#ifndef CODE_39_HPP
#define CODE_39_HPP

#include <map>
#include "DefaultModule.hpp"
#include "Sequence.hpp"
#include "noncopyable.hpp"
#include "uninstantiatable.hpp"

/**
 * An implementation of the Code39 specification that meets all general 'Symbology' template concepts.
 * 
 */
class Code39 : 
    private noncopyable, 
    private uninstantiatable
{
  public:
    
    /// The type of Module used in this implementation
    using ModuleType = DefaultModule;
    
    /// The type of Sequence used in this implementation
    using SequenceType = Sequence<ModuleType>;
       
  private:
    
    /// A quick and dirty mapping of the Code39 standard character set to their respective Sequence representations
    static const std::map<unsigned char, const SequenceType> charset_map;
        
  public:

    /// Code 39 is an alphanumeric symbology
    static constexpr bool alphanumeric = true;
    
    /// Code39 is a numeric symbology
    static constexpr bool numeric = true;
    
    /// Code39 is a discrete symbology
    static constexpr bool discrete = true;
    
    /// Code39 is not a continuous symbology
    static constexpr bool continuous = !discrete;
    
    /// Code39 is not a multi-width symbology
    static constexpr bool multi_width = false;
    
    /// Code39 is a dual-width symbology
    static constexpr bool dual_width = !multi_width;
    
    /// Code39 is not a fixed-length symbology
    static constexpr bool fixed_length = false;
    
    /// Code39 is a variable-length symbology
    static constexpr bool variable_length = !fixed_length;
    
    /// Code39 is not a self-checking symbology
    static constexpr bool self_checking = true;
    
    /// Code39 utilizes a checksum
    static constexpr bool uses_checksum = true;
    
    /// The standard character set of the Code39 specification
    static const std::string charset;
    
    /// The start-sequence of the Code39 specification
    static const Sequence<ModuleType> start_sequence;
    
    /// The stop-sequence of the Code39 specification
    static const Sequence<ModuleType> stop_sequence;
  
    /**
     * Encodes the provided input string into a Sequence
     * 
     * @param data the input string to encode
     * 
     * @return a Sequence formed by encoding the provided input string
     * 
     */
    static auto encode(const std::string& data) -> SequenceType;
    
    /**
     * Decodes the provided Sequence into a string
     * 
     * @param sequence the Sequence to decode
     * 
     * @return a string formed by decoding the provided Sequence
     * 
     */
    static auto decode(const SequenceType sequence) -> std::string;
    
    /**
     * Calculates the checksum digit for the provided input string
     * 
     * @param data the input string to calculate a checksum for
     * 
     * @return the checksum digit calculated from the provided input string
     * 
     */
    static auto checksum(const std::string& data) -> unsigned char;
};

#include "Code39.inl"

#endif
