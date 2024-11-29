#include<iostream>
#include <cstring>

namespace MyString
{
    class Stringv1
    {
    private: //* any members following these labels will have that level of protection
        char *data; //* points to string[]
        size_t length;
        //* size_t is utilized when working with the length or size of something
        //* the length of size_t corresponds to the architecture that is being compiled for
        //* 32 bit int unsigned for 32-bit machines, 64 bit int unsigned for 64-bit machines
    public:
        Stringv1(const char *str = "")
        {
            length = 0;
            //* Every string ends with \0 in memory
            while(str[length] != '\0')
            {
                length++;
            }

            //* malloc - Memory Allocate, returns a pointer to the space in memory that has been allocated
            //* 1 character is 1 byte, so we allocate the length + 1 for the null terminating character
            void* memory = std::malloc(length + 1);

            //* This tells the compiler that there should be characters here
            data = static_cast<char*>(memory);

            //* Copies a string into a slot in memory
            std:strcpy(data, str);
        }

        //* Copy Constructor
        //* Allows you to manipulate a new version of something without modifying the original data
        Stringv1(const Stringv1 &other)
        {
            length = other.length;

            void* memory = std::malloc(length + 1);
            data = static_cast<char*>(memory);

            std:strcpy(data, other.data);


        }

        //* Destructor
        ~Stringv1()
        {
            std::free(data);
        }

        //* Overriding the assignment operator
        Stringv1 & operator=(const Stringv1 &other)
        {
            //* When a user tries to assign a unique string over a string
            if(this != &other)
            {
                void* memory = std::malloc(other.length + 1);
                //* malloc will return a null ptr if it fails
                if(memory == nullptr)
                {
                    throw std::bad_alloc();
                }

                char* newData = static_cast<char*>(memory);

                std::strcpy(newData, other.data);

                //* Data is freed only after new data can be put into the new memory location
                if(data != nullptr)
                {
                    std::free(data);
                }

                data = newData;
                length = other.length;
            }

            return *this;
        }

        Stringv1 & operator=(const char * str)
        {
            //* User passed in a null ptr, so we clear out the string
            if(str == nullptr)
            {
                if(data != nullptr)
                {
                    std::free(data);
                    data = nullptr;
                }

                length = 0;
                return *this;

            }

            size_t newLength = 0;
            while(str[newLength] != '\0')
            {
                newLength++;
            }

            void* memory = std::malloc(newLength + 1);
            if(memory == nullptr)
            {
                throw std::bad_alloc();
            }

            char* newData = static_cast<char*>(memory);
            std::strcpy(newData, str);

            if(data != nullptr)
            {
                std::free(data);
            }

            data = newData;
            length = newLength;

            return *this;
        }



        //* Concatenation
        Stringv1 operator+(const Stringv1&other) const
        //* const here means that the state of the object won't be changed
        {
            Stringv1 newString;
            newString.length = length + other.length;

            void* memory = std::malloc(length + 1);
            newString.data = static_cast<char*>(memory);

            std::strcpy(newString.data, data);
            //* adds the data to the new string from the other string
            std::strcat(newString.data, other.data);

            return newString;
        }

        char operator[](const size_t index) const
        {
            if(index >= length)
            {
                throw std::invalid_argument("Index cannot exceed the length of the string.");
            }

            return data[index];

        }

        //* Friend function
        //* A function that is not a member of the class
        //* but should have access to the classes private and protected members
        //* This is necessary to be able to access the data of the string class

        friend std::ostream & operator<<(std::ostream &os, const Stringv1 &str)
        {
            os << str.data;
            return os;
        }

        //* Getter
        size_t getLength() const
        {
            return length;
        }
    };
}

