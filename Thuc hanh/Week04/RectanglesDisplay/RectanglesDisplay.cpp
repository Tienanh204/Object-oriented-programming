#include"RectanglesDisplay.h"

Rectangle::Rectangle()
{
	this->_height = 0;
	this->_width = 0;
}

Rectangle::Rectangle(int w, int h)
{
	this->_width = w;
	this->_height = h;
}

string Rectangle::toString()
{
    return "Rectangle Width=" + to_string(_width) + ", Height=" + to_string(_height);
}

string SolidRectangleConverter::convert( Rectangle info)
{
    string result;
    for (int i = 0; i < info.getWidth(); i++)
    {
        for (int j = 0; j < info.getHeight(); j++)
        {
            result += character;
        }
        result += '\n';
    }
    return result;
}

string HollowRectangleConverter::convert( Rectangle info)
{
    string result;
    for (int i = 0; i < info.getWidth(); i++)
    {
        if (i == 0 || i == info.getWidth() - 1)
        {
            for (int j = 0; j < info.getHeight(); j++)
            {
                result += character;
            }
        }
        else
        {
            for (int j = 0; j < info.getHeight(); j++)
            {
                if (j == 0 || j == info.getHeight() - 1)
                    result += character;
                else
                    result += ' ';
            }
        }
        result += '\n';
    }
    return result;
}
