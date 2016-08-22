#include <cstdlib>

#include <stdexcept>

#include "File.h"


/**
 * @throw std::runtime_error
 */
File::File(const std::string& filename, std::ios_base::openmode mode)
{
    file.open(filename.c_str(), mode);
    if (file.fail()) {
        throw std::runtime_error("unable to open file");
    }
}

File::~File()
{
    if (file.is_open()) {
        file.close();
    }
}

void File::checkErrors(bool read) const
{
    if (file.eof()) {
        throw std::out_of_range(std::string("end of file"));
    }
    else
    if (file.fail()) {
        if (read) {
            throw std::runtime_error(std::string("unable to read file"));
        }
        else {
            throw std::runtime_error(std::string("unable to write file"));
        }
    }
    else
    if (file.bad()) {
        throw std::runtime_error(std::string("file i/o error"));
    }
}

int File::getPosition()
{
    int pos = static_cast<int>(file.tellg());
    checkErrors();
    return pos;
}

void File::setPosition(int pos)
{
    file.seekg(static_cast<std::streampos>(pos));
    checkErrors(false);
}

void File::skip(int n)
{
    file.seekg(static_cast<std::streamoff>(n), std::ios_base::cur);
    checkErrors();
}


int File::readByte()
{
    unsigned char byte;

    file.read(reinterpret_cast<char *>(&byte), sizeof(char));
    checkErrors();

    return static_cast<int>(byte);
}

int File::readShort()
{
    short shrt;

    file.read(reinterpret_cast<char *>(&shrt), sizeof(short));
    checkErrors();

    return static_cast<int>(shrt);
}

int File::readInt()
{
    int intg;

    file.read(reinterpret_cast<char *>(&intg), sizeof(int));
    checkErrors();

    return intg;
}

void File::read(void *buffer, int size)
{
    file.read(reinterpret_cast<char *>(buffer), size);
    checkErrors();
}

void File::read(std::string& buffer, int size)
{
    buffer.clear();
    while (size-- >= 0) {
        buffer += static_cast<char>(readByte());
    }
}

File& File::openExisting(const std::string& filename)
{
    return *(new File(filename, std::ios_base::in | std::ios_base::binary));
}
