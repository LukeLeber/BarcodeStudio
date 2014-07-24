#ifndef INTERLEAVED_2_OF_5_HPP
#define INTERLEAVED_2_OF_5_HPP

#include <algorithm>
#include <array>

#include "Sequence.hpp"
#include "DefaultModule.hpp"

/**
 * Policy class for the Interleaved 2 of 5 symbology
 * 
 */
class Interleaved2of5
{
  public:
    using ModuleType = DefaultModule;
  private:
    Interleaved2of5() = delete;
    
    static const std::array<const Sequence<ModuleType>, 10> lookup_table;
    
  public:

    static const std::string charset;
    static const Sequence<ModuleType> start_sequence;
    static const Sequence<ModuleType> stop_sequence;

    static constexpr bool alphanumeric = false;
    static constexpr bool numeric = true;
    static constexpr bool discrete = false;
    static constexpr bool continuous = !discrete;
    static constexpr bool multi_width = true;
    static constexpr bool dual_width = !multi_width;
    static constexpr bool fixed_length = false;
    static constexpr bool variable_length = !fixed_length;
    static constexpr bool self_checking = true;
    static constexpr bool checksum = true;
  
    static Sequence<ModuleType> encode(const std::string& data);
    static std::string decode(const Sequence<ModuleType> sequence);
};

#include "Interleaved2of5.inl"


#endif