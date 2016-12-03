#include <stdexcept>
#include <string>

#include "File.h"

/**
 * @throw std::bad_alloc
 * @throw std::runtime_error
 */
File::File(const std::string& filename, std::ios_base::openmode mode)
{
    stream = new std::fstream();
    if (!stream) {
        throw std::bad_alloc();
    }

    stream->open(filename.c_str(), mode);
    if (stream->fail()) {
        throw std::runtime_error("unable to open file");
    }
}

File::~File()
{
    if (stream) {
        if (stream->is_open()) {
            stream->close();
        }
        delete stream;
    }
}

void File::checkErrors(bool read) const
{
    if (stream->eof()) {
        throw std::out_of_range(std::string("end of file"));
    }
    else
    if (stream->fail()) {
        if (read) {
            throw std::runtime_error(std::string("unable to read file"));
        }
        else {
            throw std::runtime_error(std::string("unable to write file"));
        }
    }
    else
    if (stream->bad()) {
        throw std::runtime_error(std::string("file i/o error"));
    }
}

int File::getPosition()
{
    int pos = static_cast<int>(stream->tellg());
    checkErrors();
    return pos;
}

void File::setPosition(int pos)
{
    stream->seekg(static_cast<std::streampos>(pos));
    checkErrors(false);
}

void File::skip(int n)
{
    stream->seekg(static_cast<std::streamoff>(n), std::ios_base::cur);
    checkErrors();
}


int File::readByte()
{
    unsigned char byte;

    stream->read(reinterpret_cast<char *>(&byte), sizeof(char));
    checkErrors();

    return static_cast<int>(byte);
}

int File::readShort()
{
    short shrt;

    stream->read(reinterpret_cast<char *>(&shrt), sizeof(short));
    checkErrors();

    return static_cast<int>(shrt);
}

int File::readInt()
{
    int intg;

    stream->read(reinterpret_cast<char *>(&intg), sizeof(int));
    checkErrors();

    return intg;
}

void File::read(void *buffer, int size)
{
    stream->read(reinterpret_cast<char *>(buffer), size);
    checkErrors();
}

void File::read(std::string& buffer, int size)
{
    buffer.clear();
    while (size-- >= 0) {
        buffer += static_cast<char>(readByte());
    }
}

File File::openExisting(const std::string& filename)
{
    return File(filename, std::ios_base::in | std::ios_base::binary);
}
