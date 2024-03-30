//
// Created by nothrax on 15.05.21.
//

#ifndef MONITORRECEIVETCP_STRINGFORMATTING_H
#define MONITORRECEIVETCP_STRINGFORMATTING_H


#include <string>
#include <iomanip>
#include <bitset>

class StringFormatting {
public:
    template< typename T >
    static std::string value_to_hex_string(T i )
    {
        std::stringstream stream;
        stream << "0x"
               << std::setfill ('0') << std::setw(sizeof(T)*2)
               << std::hex << i;
        return stream.str();
    }

    template< typename T >
    static std::string value_to_bin_string(T i )
    {
        std::bitset<sizeof(T)*8> bits(i);
        std::stringstream stream;
        stream << bits;
        return stream.str();
    }
};


#endif //MONITORRECEIVETCP_STRINGFORMATTING_H
