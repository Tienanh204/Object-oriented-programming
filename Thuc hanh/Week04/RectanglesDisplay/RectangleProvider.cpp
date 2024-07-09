#include"RectangleProvider.h"
#include"RectanglesDisplay.h"

vector<Rectangle> RectangleProvider::getAll() {
    return {
        Rectangle(3, 4),
        Rectangle(4, 5),
        Rectangle(4, 8)
    };
}