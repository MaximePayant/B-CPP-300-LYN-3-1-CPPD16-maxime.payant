/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** DomesticKoala.cpp
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction& action) :
_action(action)
{}

DomesticKoala::DomesticKoala(const DomesticKoala& copy) :
_action(copy._action)
{}

DomesticKoala::~DomesticKoala()
{}

const std::vector<DomesticKoala::methodPointer_t> *DomesticKoala::getActions() const
{
    return (&_methodPtr);
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    _methodCode.push_back(command);
    _methodPtr.push_back(action);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    for (std::size_t ctr = 0; ctr < _methodCode.size(); ctr += 1)
        if (_methodCode[ctr] == command) {
            _methodCode.erase(_methodCode.begin() + ctr, _methodCode.begin() + ctr);
            _methodPtr.erase(_methodPtr.begin() + ctr, _methodPtr.begin() + ctr);
        }
}

void DomesticKoala::doAction(unsigned char command, const std::string &param)
{
    std::size_t index = 0;

    for (std::size_t ctr = 0; _methodCode[ctr] != command; ctr += 1)
        if (ctr >= _methodCode.size())
            return;
    (_action.*_methodPtr[index])(param);
}

void DomesticKoala::setKoalaAction(KoalaAction& action)
{
    _action = action;
}