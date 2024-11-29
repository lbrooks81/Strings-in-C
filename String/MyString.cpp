#include "MyString.h"

#include <cstring>

using namespace MyString;

namespace MyString
{
    String::String(const char *str)
    {
        if(str == nullptr)
            return;

        length = strlen(str);
        data = new char[length + 1]; //* new is used to allocate memory

        strcpy(data, str);
    }

    String::String(const String &other)
    {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    String::~String()
    {
        //* Delete is the keyword to remove data from memory
        delete[] data;
    }

    String & String::operator=(const String &other)
    {
        if(this != &other)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    String & String::operator=(const char *str)
    {
        if(str == nullptr)
        {
            delete[] data;
            data = nullptr;
            length = 0;
            return *this;
        }

        size_t newLength = strlen(str);
        char *newData = new char[newLength + 1];
        strcpy(newData, str);

        delete[] data;
        data = newData;
        length = newLength;

        return *this;
    }

    size_t String::getLength() const
    {
        return length;
    }

    String String::operator+(const String &other) const
    {
        String newString;

        newString.length = length + other.length;
        newString.data = new char[newString.length + 1];

        strcpy(newString.data, data);
        strcat(newString.data, other.data);

        return newString;
    }

    char String::operator[](const size_t index) const
    {
        if(index >= length)
        {
            throw std::invalid_argument("Index cannot exceed length of the string.");
        }

        return data[index];
    }

    std::ostream & operator<<(std::ostream &os, const String &str)
    {
        os << str.data;
        return os;
    }
}