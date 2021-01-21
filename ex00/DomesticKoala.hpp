/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** DomesticKoala.hpp
*/

#ifndef DOMESTIC_KOALA_HPP
#define DOMESTIC_KOALA_HPP

#include <string>
#include <vector>

#include "KoalaAction.hpp"

class DomesticKoala
{

    private:
        using  methodPointer_t = void (KoalaAction::*)(const std::string&);

        KoalaAction _action;
        std::vector<char> _methodCode;
        std::vector<methodPointer_t> _methodPtr;

    public:
        DomesticKoala() = delete;
        DomesticKoala(KoalaAction& action);
        DomesticKoala(const DomesticKoala& copy);
        ~DomesticKoala();

        DomesticKoala &operator=(const DomesticKoala& other);

        const std::vector<methodPointer_t> *getActions() const;
        void learnAction(unsigned char command, methodPointer_t action);
        void unlearnAction(unsigned char command);
        void doAction(unsigned char command, const std::string &param);
        void setKoalaAction(KoalaAction& action);
};

#endif // DOMESTIC_KOALA_HPP