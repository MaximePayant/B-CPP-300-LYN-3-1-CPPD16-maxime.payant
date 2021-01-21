/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** KoalaAction.hpp
*/

#ifndef __KOALAACTION_H__
#define __KOALAACTION_H__

#include <iostream>

class KoalaAction
{
    public:
        void eat(const std::string& param)
        {
            std::cout << "I go to: " << param << std::endl;
        }
        void goTo(const std::string& param)
        {
            std::cout << "I eat: " << param << std::endl;
        }
        void sleep(const std::string& param)
        {
            std::cout << "I attempt to reproduce with: " << param << std::endl;
        }
        void reproduce(const std::string& param)
        {
            std::cout << "I sleep, and dream of: " << param << std::endl;
        }
};

#endif // __KOALAACTION_H__