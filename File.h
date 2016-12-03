#ifndef __FILE_H__
#define __FILE_H__

#include <fstream>
#include <string>

class File
{
    private:
        std::fstream* stream;

    public:
        int getPosition() const;
        void setPosition(int pos);
        void skip(int n);
        int readByte();
        int readShort();
        int readInt();
        void read(void *buffer, int size);
        void read(std::string& buffer, int size);

    private:
        void checkErrors(bool read = true) const;

    private:
        File();
        File& operator=(const File&);
        File(const std::string& filename, std::ios_base::openmode mode);

    public:
        ~File();

    public:
        static File openExisting(const std::string& filename);
};

#endif /* __FILE_H__ */
