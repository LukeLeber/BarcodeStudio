#ifndef IMAGE_HPP
#define IMAGE_HPP

template<typename T>
class Image
{

    /// The top margin of the printing media
    T topMargin;
    
    /// The bottom margin of the printing media
    T bottomMargin;
    
    /// The left margin of the printing media
    T leftMargin;
    
    /// The right margin of the printing media
    T rightMargin;
    
    /// The width of the printing media
    T pageWidth;
    
    /// The height of the printing media
    T pageHeight;

    /// The width of an individual label
    T labelWidth;
    
    /// The height of an individual label
    T labelHeight;

    /// The horizontal padding between labels
    T horizontalPadding;
    
    /// The vertical padding between labels
    T verticalPadding;

    /// The number of horizontal labels to print
    std::size_t horizontalLabelCount;
    
    /// The number of vertical labels to print
    std::size_t verticalLabelCount;
    
  public:
    void setVerticalLabelCount(std::size_t verticalLabelCount)
    {
        this->verticalLabelCount = verticalLabelCount;
    }

    std::size_t getVerticalLabelCount() const
    {
        return verticalLabelCount;
    }

    void setHorizontalLabelCount(std::size_t horizontalLabelCount)
    {
        this->horizontalLabelCount = horizontalLabelCount;
    }

    std::size_t getHorizontalLabelCount() const
    {
        return horizontalLabelCount;
    }

    void setVerticalPadding(T verticalPadding)
    {
        this->verticalPadding = verticalPadding;
    }

    T getVerticalPadding() const
    {
        return verticalPadding;
    }

    void setHorizontalPadding(T horizontalPadding)
    {
        this->horizontalPadding = horizontalPadding;
    }

    T getHorizontalPadding() const
    {
        return horizontalPadding;
    }

    void setLabelHeight(T labelHeight)
    {
        this->labelHeight = labelHeight;
    }

    T getLabelHeight() const
    {
        return labelHeight;
    }

    void setLabelWidth(T labelWidth)
    {
        this->labelWidth = labelWidth;
    }

    T getLabelWidth() const
    {
        return labelWidth;
    }

    void setPageHeight(T pageHeight)
    {
        this->pageHeight = pageHeight;
    }

    T getPageHeight() const
    {
        return pageHeight;
    }

    void setPageWidth(T pageWidth)
    {
        this->pageWidth = pageWidth;
    }

    T getPageWidth() const
    {
        return pageWidth;
    }

    void setRightMargin(T rightMargin)
    {
        this->rightMargin = rightMargin;
    }

    T getRightMargin() const
    {
        return rightMargin;
    }

    void setLeftMargin(T leftMargin)
    {
        this->leftMargin = leftMargin;
    }

    T getLeftMargin() const
    {
        return leftMargin;
    }

    void setBottomMargin(T bottomMargin)
    {
        this->bottomMargin = bottomMargin;
    }

    T getBottomMargin() const
    {
        return bottomMargin;
    }

    void setTopMargin(T topMargin)
    {
        this->topMargin = topMargin;
    }

    T getTopMargin() const
    {
        return topMargin;
    }
};

#endif