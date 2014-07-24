/**
 * This file is protected under the KILLGPL license.
 * 
 * For more information, visit https://www.github.com/LukeLeber/KILLGPL
 * 
 */

template<typename Symbology>
Barcode<Symbology>::Barcode(const std::string& data) : 
    decoded(data), 
    encoded(Symbology::encode(data))
{
    
}

template<typename Symbology>
Barcode<Symbology>::Barcode(std::string&& data) : 
    decoded(std::move(data)), 
    encoded(Symbology::encode(this->decoded))
{
}

template<typename Symbology>
Barcode<Symbology>::Barcode(const SequenceType& data) : 
decoded(Symbology::decode(data)),
        encoded(data)
{
    
}

template<typename Symbology>
Barcode<Symbology>::Barcode(SequenceType&& data) : 
    decoded(Symbology::decode(data)),
    encoded(std::move(data))
{
    
}

template<typename Symbology>
void Barcode<Symbology>::setData(const std::string& data)
{
    this->decoded = data;
    this->encoded = Symbology::encode(data);
}

template<typename Symbology>
void Barcode<Symbology>::setData(std::string&& data)
{
    this->decoded = std::move(data);
    this->encoded = Symbology::encode(this->decoded);
}

template<typename Symbology>
void Barcode<Symbology>::setData(const SequenceType& data)
{
    this->decoded = Symbology::decode(data);
    this->encoded = data;
}

template<typename Symbology>
void Barcode<Symbology>::setData(SequenceType&& data)
{
    this->decoded = Symbology::decode(data);
    this->encoded = std::move(data);
}

template<typename Symbology>
const std::string& Barcode<Symbology>::getData() const noexcept
{
    return decoded;
}

template<typename Symbology>
auto Barcode<Symbology>::getEncoding() const noexcept -> const SequenceType&
{
    return this->encoded;
}