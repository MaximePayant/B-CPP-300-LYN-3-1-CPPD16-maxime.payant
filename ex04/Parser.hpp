/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Parser.hpp
*/

#ifndef PARSER_HPP
#define PARSER_HPP

#include <stack>
#include <string>
#include <unordered_map>

class Parser
{

    private:
        std::stack<char> _operators;
        std::stack<int> _operands;
        std::unordered_map<char, int (*)(int a, int b)> _operations;
        int _result;

        const std::string operatorsValue = "+-*/%";
        const std::string numbersValue = "0123456789";

        void calcul();

    public:
        Parser();

        void feed(const std::string &instance);
        int result() const;
        void reset();

};

#endif // PARSER_HPP