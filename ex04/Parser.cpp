/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

Parser::Parser() :
_operators(),
_operands(),
_operations(),
_result(0)
{
    _operations['+'] = [](int a, int b) { return (a + b); };
    _operations['-'] = [](int a, int b) { return (a - b); };
    _operations['*'] = [](int a, int b) { return (a * b); };
    _operations['/'] = [](int a, int b) { return (a / b); };
    _operations['%'] = [](int a, int b) { return (a % b); };
}

static bool isOp(char c)
{
    if (c == '+' || c == '-'
    || c == '*' || c == '/'
    || c == '%')
        return (true);
    return (false);
}

static bool isNum(char c)
{
    if ('0' <= c && c <= '9')
        return (true);
    return (false);
}

void Parser::calcul()
{
    int b = _operands.top();
    _operands.pop();

    int a = _operands.top();
    _operands.pop();

    int tmp = _operations[_operators.top()](a, b);
    _operands.push(tmp);
    _operators.pop();
    _operators.pop();
}

void Parser::feed(const std::string &instance)
{
    for (std::size_t ctr = 0; ctr < instance.size(); ctr += 1) {
        if (instance[ctr] == '(')
            _operators.push(instance[ctr]);
        else if (instance[ctr] == ')')
            calcul();
        else if (isOp(instance[ctr]))
            _operators.push(instance[ctr]);
        else if (isNum(instance[ctr])) {
            _operands.push(std::atoi(&instance[ctr]));
            while (ctr < instance.size() && isNum(instance[ctr]))
                ctr += 1;
            ctr -= 1;
        }
    }
    _result += _operands.top();
}

int Parser::result() const
{
    return (_result);
}

void Parser::reset()
{
    _result = 0;
}