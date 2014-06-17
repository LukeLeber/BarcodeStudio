#ifndef BARCODE_HPP
#define BARCODE_HPP

#include <string>

template<typename Symbology>
class Barcode
{
    std::string data;
    
  public:
    const std::string& getData() const noexcept;
    void setData(const std::string& data);
    void setData(std::string&& data);
    
    
};

#endif