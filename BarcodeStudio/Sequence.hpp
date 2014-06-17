#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <iostream>
#include <vector>

template<typename Segment>
class Sequence;

template<typename Segment>
std::ostream& operator<<(std::ostream& stream, const Sequence<Segment>& sequence);

template<typename Segment>
std::ostream& operator<<(std::ostream& stream, Sequence<Segment>&& sequence);

template<typename Segment>
std::istream& operator>>(std::istream& stream, Sequence<Segment>& sequence);

template<typename Segment>
bool operator==(const Sequence<Segment>& segment0, const Sequence<Segment>& segment1);

template<typename Segment>
bool operator!=(const Sequence<Segment>& segment0, const Sequence<Segment>& segment1);

template<typename Segment>
Sequence<Segment> operator+(const Sequence<Segment>& segment0, const Sequence<Segment>& segment1);

template<typename Segment>
Sequence<Segment> operator+(Sequence<Segment>&& segment0, Sequence<Segment>&& segment1);

template<typename Segment>
class Sequence
{
    friend std::ostream& ::operator<<<>(std::ostream&, const Sequence<Segment>&);
    friend std::ostream& ::operator<<<>(std::ostream&, Sequence<Segment>&&);
    friend std::istream& ::operator>><>(std::istream&, Sequence<Segment>&);
    friend bool ::operator==<>(const Sequence<Segment>&, const Sequence<Segment>&);
    friend bool ::operator!=<>(const Sequence<Segment>&, const Sequence<Segment>&);
    friend Sequence<Segment> operator+<>(const Sequence<Segment>&, const Sequence<Segment>&);
    friend Sequence<Segment> operator+<>(Sequence<Segment>&&, Sequence<Segment>&&);

    std::vector<Segment> segments;
    
  public:
    
    typedef typename std::vector<Segment>::allocator_type allocator_type;
    typedef typename std::vector<Segment>::const_iterator const_iterator;
    typedef typename std::vector<Segment>::const_pointer const_pointer;
    typedef typename std::vector<Segment>::const_reference const_reference;
    typedef typename std::vector<Segment>::const_reverse_iterator const_reverse_iterator;
    typedef typename std::vector<Segment>::difference_type difference_type;
    typedef typename std::vector<Segment>::iterator iterator;
    typedef typename std::vector<Segment>::pointer pointer;
    typedef typename std::vector<Segment>::reference reference;
    typedef typename std::vector<Segment>::reverse_iterator reverse_iterator;
    typedef typename std::vector<Segment>::size_type size_type;
    typedef typename std::vector<Segment>::value_type value_type;
    
    template<typename... E>
    Sequence(Segment&& first, E&& ...remaining);
    
    Sequence(std::initializer_list<Segment>&& segments);
   
    Sequence() = default;

    Sequence& operator=(const Sequence&) = default;
    Sequence& operator=(Sequence&&) = default;

    Sequence(const Sequence&) = default;
    Sequence(Sequence&&) = default;
    
    ~Sequence() = default;
    
    iterator begin() noexcept;
    const_iterator cbegin() const noexcept;
    iterator end() noexcept;
    const_iterator cend() const noexcept;
    
    size_type size() const noexcept;
    
    Sequence<Segment> operator+=(const Sequence<Segment>& other);
    Sequence<Segment> operator+=(Sequence<Segment>&& other);
    
};

#include <iterator>

template<typename Segment>
std::ostream& operator<<(std::ostream& stream, const Sequence<Segment>& sequence)
{
    std::copy(sequence.begin(), sequence.end(), std::ostream_iterator<char>(stream));
    return stream;
}

template<typename Segment>
std::ostream& operator<<(std::ostream& stream, Sequence<Segment>&& sequence)
{
    stream << static_cast<uint64_t>(sequence.segments.size());
    std::move(sequence.segments.begin(), sequence.segments.end(), std::ostream_iterator<char>(stream));
    return stream;
}

template<typename Segment>
std::istream& operator>>(std::istream& stream, Sequence<Segment>& sequence)
{
    uint64_t size;
    stream >> size;
    sequence.segments.reserve(sequence.segments.size() + size);
    std::copy(std::istream_iterator<Segment>(stream), std::istream_iterator<Segment>(), std::back_inserter(sequence.segments));
    return stream;
}

template<typename Segment>
bool operator==(const Sequence<Segment>& sequence0, const Sequence<Segment>& sequence1)
{
    if(sequence0.segments.size() == sequence1.segments.size())
    {
        for(typename Sequence<Segment>::size_type i = 0; i < sequence0.segments.size(); ++i)
        {
            if(sequence0.segments[i] != sequence1.segments[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template<typename Segment>
bool operator!=(const Sequence<Segment>& sequence0, const Sequence<Segment>& sequence1)
{
    if(sequence0.segments.size() == sequence1.segments.size())
    {
        for(typename Sequence<Segment>::size_type i = 0; i < sequence0.segments.size(); ++i)
        {
            if(sequence0.segments[i] == sequence1.segments[i])
            {
                return true;
            }
        }
        return false;
    }
    return true;
}

template<typename Segment>
Sequence<Segment> operator+(const Sequence<Segment>& sequence0, const Sequence<Segment>& sequence1)
{
    Sequence<Segment> rv = sequence0;
    rv += sequence1;
    return rv;
}

template<typename Segment>
Sequence<Segment> operator+(Sequence<Segment>&& sequence0, Sequence<Segment>&& sequence1)
{
    return std::move(sequence0 += std::move(sequence1));
}

template<typename Segment>
template<typename... E>
Sequence<Segment>::Sequence(Segment&& first, E&& ...remaining) : 
    Sequence<Segment>( { first, remaining... })
{
    
}
    
template<typename Segment>
Sequence<Segment>::Sequence(std::initializer_list<Segment>&& segments) : 
    segments(segments)
{
    
}

template<typename Segment>
typename Sequence<Segment>::iterator Sequence<Segment>::begin() noexcept
{
    return this->segments.begin();
}

template<typename Segment>
typename Sequence<Segment>::const_iterator Sequence<Segment>::cbegin() const noexcept
{
    return this->segments.cbegin();
}

template<typename Segment>
typename Sequence<Segment>::iterator Sequence<Segment>::end() noexcept
{
    return this->segments.end();
}

template<typename Segment>
typename Sequence<Segment>::const_iterator Sequence<Segment>::cend() const noexcept
{
    return this->segments.cend();
}

template<typename Segment>
typename Sequence<Segment>::size_type Sequence<Segment>::size() const noexcept
{
    return this->segments.size();
}

template<typename Segment>
Sequence<Segment> Sequence<Segment>::operator+=(const Sequence<Segment>& other)
{
    this->segments.reserve(this->segments.size() + other.size());
    std::copy(other.cbegin(), other.cend(), std::back_inserter(this->segments));
    return *this;
}

template<typename Segment>
Sequence<Segment> Sequence<Segment>::operator+=(Sequence<Segment>&& other)
{
    this->segments.reserve(this->segments.size() + other.size());
    std::move(other.begin(), other.end(), std::back_inserter(this->segments));
    return *this;
}

#endif