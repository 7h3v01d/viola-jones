#ifndef __XMLDOM_H__
#define __XMLDOM_H__

#include <string>

#include "File.h"

class XmlDom
{
    private:
        //int member;

    public:
        //int method();
        std::string toString() const;

    public:
        static XmlDom parse(File& file);

    private:
        XmlDom();
        XmlDom(const XmlDom&);
        XmlDom& operator=(const XmlDom&);

    public:
        ~XmlDom();
};

#endif /* __XMLDOM_H__ */
