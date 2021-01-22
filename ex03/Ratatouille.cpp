/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Ratatouille.cpp
*/

#include "Ratatouille.hpp"

Ratatouille::Ratatouille() :
_result()
{}

Ratatouille::Ratatouille(Ratatouille const &other)
{
    _result << other._result.str();
}

Ratatouille::~Ratatouille()
{
    _result.clear();
}

Ratatouille& Ratatouille::operator=(const Ratatouille &rhs)
{
    _result.str("");
    _result << rhs._result.str();
    return (*this);
}

Ratatouille& Ratatouille::addVegetable(unsigned char vegetable)
{
    _result << vegetable;
    return (*this);
}

Ratatouille& Ratatouille::addCondiment(unsigned int condiment)
{
    _result << condiment;
    return (*this);
}

Ratatouille& Ratatouille::addSpice(double spice)
{
    _result << spice;
    return (*this);
}

Ratatouille& Ratatouille::addSauce(const std::string &sauce)
{
    _result << sauce;
    return (*this);
}

std::string Ratatouille::kooc()
{
    return (_result.str());
}