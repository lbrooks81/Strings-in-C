//
// Created by Glog on 9/11/2024.
//

#include <iostream>
#include "String/MyStringv1.cpp"
#include "String/MyString.h"

int main()
{
  MyString::Stringv1 str1 = "Hello, ";
  MyString::Stringv1 str2 = "World!";
  MyString::Stringv1 str3 = str1 + str2;

  std::cout << "str1: " << str3 << std::endl;
  std::cout << "str2: " << str2 << std::endl;
  std::cout << "str3: " << str3 << std::endl;
  std::cout << "str3 length: " << str3.getLength() << std::endl;

  std::cout << "Character at index 7 in str 3: " << str3[7] << std::endl;

  return 0;

}
