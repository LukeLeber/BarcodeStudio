#ifndef RENDERER_HPP
#define RENDERER_HPP
/**/
#include "Barcode.hpp"
#include "Image.hpp"

template<typename T>
class Renderer
{
    
    template<typename Symbology>
    void renderBarcode(const Barcode<Symbology>& barcode, T top, T bottom, T left, T right)
    {
        std::cout << "(" << top << ", " << bottom << ", " << left << ", " << right << ")" << std::endl;
        T sum = 0, single_module_width;
        for(auto module : barcode.getEncoding())
        {
            sum += module.getWeight();
        }
        T x = left;
        single_module_width = (right - left) / sum;
        
        for(auto module : barcode.getEncoding())
        {
            if(module)
            {
                drawBar(x, top, single_module_width * module.getWeight(), (bottom - top));
            }
            x += single_module_width * module.getWeight();
        }
    }

  protected:

    virtual void drawBar(T x, T y, T width, T height) = 0;
    
  public:
    
    template<typename Symbology>
    void render(const Barcode<Symbology>& barcode, const Image<T>& media)
    {
        T x = media.getLeftMargin();
        T y = media.getTopMargin();
        for(std::size_t j = 0; j < media.getVerticalLabelCount(); ++j)
        {
            for(std::size_t i = 0; i < media.getHorizontalLabelCount(); ++i)
            {
                std::cout << "start y: " << y << std::endl;
                renderBarcode(barcode, y, y + media.getLabelHeight(), x, x + media.getLabelWidth());
                x += media.getLabelWidth() + media.getHorizontalPadding();
            }
            x = media.getLeftMargin();
            y += media.getLabelHeight() + media.getVerticalPadding();
        }
    }
};

#include <iostream>

class NullRenderer : public Renderer<float>
{
    void drawBar(float x, float y, float width, float height)    
    {
        std::cout << "Rendering bar (" << x << ", " << y << ") to (" << (x + width) << ", " << (y + height) << ")" << std::endl;
    }
};

#endif
