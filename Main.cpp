#include <cstdlib>

#include <string>
#include <iostream>

#include "Image.h"


int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    Image face = Image::loadFromFile(std::string("face.tga"));

    Color& firstColor = face.getColor(0, 0);
    Color& lastColor = face.getColor(face.getWidth() - 1, face.getHeight() - 1);
    std::cout << face.getWidth() << "x" << face.getHeight() << std::endl;
    std::cout << firstColor.getR() << ","
            << firstColor.getG() << ","
            << firstColor.getB() << ","
            << firstColor.getA() << ","
            << firstColor.getGray() << std::endl;
    std::cout << lastColor.getR() << ","
            << lastColor.getG() << ","
            << lastColor.getB() << ","
            << lastColor.getA() << ","
            << lastColor.getGray() << std::endl;

    return EXIT_SUCCESS;
}
