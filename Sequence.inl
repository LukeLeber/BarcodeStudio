template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
std::ostream& operator<<(std::ostream& stream, const Sequence<Module, Container>& sequence)
{
    std::copy(sequence.begin(), sequence.end(), std::ostream_iterator<char>(stream));
    return stream;
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
std::ostream& operator<<(std::ostream& stream, Sequence<Module, Container>&& sequence)
{
    stream << static_cast<uint64_t>(sequence.segments.size());
    std::move(sequence.segments.begin(), sequence.segments.end(), std::ostream_iterator<char>(stream));
    return stream;
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
std::istream& operator>>(std::istream& stream, Sequence<Module, Container>& sequence)
{
    uint64_t size;
    stream >> size;
    sequence.segments.reserve(sequence.segments.size() + size);
    std::copy(std::istream_iterator<Module>(stream), std::istream_iterator<Module>(), std::back_inserter(sequence.segments));
    return stream;
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
bool operator==(const Sequence<Module, Container>& sequence0, const Sequence<Module, Container>& sequence1)
{
    if(sequence0.segments.size() == sequence1.segments.size())
    {
        for(typename Sequence<Module, Container>::size_type i = 0; i < sequence0.segments.size(); ++i)
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

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
bool operator!=(const Sequence<Module, Container>& sequence0, const Sequence<Module, Container>& sequence1)
{
    if(sequence0.segments.size() == sequence1.segments.size())
    {
        for(typename Sequence<Module, Container>::size_type i = 0; i < sequence0.segments.size(); ++i)
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

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
Sequence<Module, Container> operator+(const Sequence<Module, Container>& sequence0, const Sequence<Module, Container>& sequence1)
{
    Sequence<Module, Container> rv = sequence0;
    rv += sequence1;
    return rv;
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
inline Sequence<Module, Container> operator+(Sequence<Module, Container>&& sequence0, Sequence<Module, Container>&& sequence1)
{
    return std::move(sequence0 += std::move(sequence1));
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
template<typename... E>
inline Sequence<Module, Container>::Sequence(Module&& first, E&& ...remaining) : 
    Sequence<Module, Container>( { first, remaining... })
{
    
}
    
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
template<typename... E>
inline Sequence<Module, Container>::Sequence(const Module& first, const E& ...remaining) : 
        Sequence<Module, Container>( {first, remaining... })
{
    
}
    
template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
inline Sequence<Module, Container>::Sequence(std::initializer_list<Module>&& segments) : 
    segments(segments)
{
    
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
inline typename Sequence<Module, Container>::iterator Sequence<Module, Container>::begin() noexcept
{
    return this->segments.begin();
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
inline typename Sequence<Module, Container>::const_iterator Sequence<Module, Container>::begin() const noexcept
{
    return this->segments.begin();
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
inline typename Sequence<Module, Container>::iterator Sequence<Module, Container>::end() noexcept
{
    return this->segments.end();
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
inline typename Sequence<Module, Container>::const_iterator Sequence<Module, Container>::end() const noexcept
{
    return this->segments.end();
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
inline typename Sequence<Module, Container>::size_type Sequence<Module, Container>::size() const noexcept
{
    return this->segments.size();
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
Sequence<Module, Container>& Sequence<Module, Container>::operator+=(const Sequence<Module, Container>& other)
{
    this->segments.reserve(this->segments.size() + other.size());
    std::copy(other.begin(), other.end(), std::back_inserter(this->segments));
    return *this;
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
Sequence<Module, Container>& Sequence<Module, Container>::operator+=(Sequence<Module, Container>&& other)
{
    this->segments.reserve(this->segments.size() + other.size());
    std::move(other.begin(), other.end(), std::back_inserter(this->segments));
    return *this;
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
Sequence<Module, Container>& Sequence<Module, Container>::operator+=(const Module& module)
{
    segments.push_back(module);
    return *this;
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
Sequence<Module, Container>& Sequence<Module, Container>::operator+=(Module&& module)
{
    segments.push_back(std::move(module));
    return *this;
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
inline typename Sequence<Module, Container>::const_reference Sequence<Module, Container>::operator [](unsigned index) const
{
    return this->segments[index];
}

template<typename Module, template<typename Element, typename = std::allocator<Element>> class Container>
inline typename Sequence<Module, Container>::reference Sequence<Module, Container>::operator [](unsigned index)
{
    return this->segments[index];
}
