//
// Created by Glog on 9/11/2024.
//

#ifndef MYSTRING_H
#define MYSTRING_H
#include <ostream>


namespace MyString
{
    class String
    {
    private:
        char* data;
        size_t length;
    public:
        String(const char *str = "");
        String(const String &other);

        ~String();

        String &operator=(const String &other);
        String &operator=(const char *str);

        size_t getLength() const;

        String operator+(const String &other) const;

        char operator[](size_t index) const;

        friend std::ostream & operator<<(std::ostream &os, const String &str);

    };
}





#endif //* MYSTRING_H
//* These are directives
//* It checks if MYSTRING_H is defined
