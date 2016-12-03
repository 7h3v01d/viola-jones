#include <cstdlib>

#include <string>
#include <iostream>

#include "Image.h"
#include "IntegralImage.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    Image& face = Image::loadFromFile(std::string("face.tga"));
    //face.scale(face.getWidth() / 2, face.getHeight() / 2);
    //face.scale(5, 5);

    // <test>
    IColor& firstColor = face.getColor(0, 0);
    IColor& lastColor = face.getColor(face.getWidth() - 1, face.getHeight() - 1);
    std::cout << face.getWidth()
            << "x"
            << face.getHeight()
            << "@"
            << face.getBpp()
            << "="
            << face.getSize() << std::endl;
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
    // </test>

    IntegralImage integral = IntegralImage::fromImage(face);

    // <test>
    int firstInt = integral.getIntegral(0, 0);
    int lastInt = integral.getIntegral(integral.getWidth() - 1, integral.getHeight() - 1);
    std::cout << integral.getWidth()
            << "x"
            << integral.getHeight() << std::endl;
    std::cout << firstInt << std::endl;
    std::cout << lastInt << std::endl;
    // </test>

    // <test>
    /*
    std::cout << std::endl
            << face.toString()
            << std::endl;
    std::cout << std::endl
            << integral.toString()
            << std::endl;
    */
    // </test>

    return EXIT_SUCCESS;
}
