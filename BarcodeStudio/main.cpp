//#define HEADER_ONLY 1

#include "Barcode.hpp"
#include "Code39.hpp"
#include "Renderer.hpp"

#include "lodepng.h"

class PNGRenderer : public Renderer<float>
{
	using size_t = float;
	
	size_t imageWidth;
	size_t imageHeight;
	std::vector<unsigned char> imageData;
	  
  protected:
	  
	void drawBar(size_t x, size_t y, size_t width, size_t height)
	{
		x = static_cast<std::size_t>(x + 0.5f);
		y = static_cast<std::size_t>(y + 0.5f);
		for(size_t j = 0; j < height; ++j)
		{
			for(size_t i = 0; i < width; ++i)
			{

			  size_t index = 4 * ((y + j) * imageHeight + (x + i));
			  imageData[index] = imageData[index + 1] = imageData[index + 2] = 0; // R, G, B = 0 (black)
			  imageData[index + 3] = 0xFF; // alpha to full opacity
			}
		}
	  }
  public:
	
	PNGRenderer(size_t width, size_t height) : 
		imageWidth(width),
		imageHeight(height)
	{
		/// Initialize each RGBA pixel to (0, 0, 0, 0)
		imageData.resize(imageWidth * imageHeight * 4, 0);
	}
		
	void save(const std::string& file)
	{
		lodepng::encode(file, imageData, imageWidth, imageHeight);
	}
};

int main()
{
	Barcode<Code39> bc0("TEST");
	std::cout << bc0.getData() << std::endl;
	PNGRenderer renderer(500, 500);
	Image<float> image;
	image.setLeftMargin(0);
	image.setRightMargin(0);
	image.setTopMargin(0);
	image.setBottomMargin(0);
	image.setHorizontalPadding(10);
	image.setVerticalPadding(5);
	image.setLabelWidth(90);
	image.setLabelHeight(45);
	image.setHorizontalLabelCount(5);
	image.setVerticalLabelCount(10);
	renderer.render(bc0, image);
	renderer.save("barcode.png");
}
