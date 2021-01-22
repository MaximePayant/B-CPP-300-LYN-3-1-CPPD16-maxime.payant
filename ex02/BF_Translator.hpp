/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** BF_Translator.hpp
*/

#ifndef BF_TRANSLATOR_HPP
#define BF_TRANSLATOR_HPP

#include <map>
#include <string>
#include <stack>
#include <vector>
#include <fstream>

class BF_Translator
{

    private:
        std::map<char, std::string> _instructions;

    public:
        BF_Translator();
        ~BF_Translator();

        int translate(const std::string &in, const std::string &out);

};

#endif // BF_TRANSLATOR_HPP