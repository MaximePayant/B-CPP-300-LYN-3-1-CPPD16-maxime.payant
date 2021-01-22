/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Ratatouille.hpp
*/

#ifndef RATATOUILLE_HPP
#define RATATOUILLE_HPP

#include <iostream>
#include <sstream>

class Ratatouille
{

    private:
        std::ostringstream _result;

    public:
        Ratatouille();
        Ratatouille(Ratatouille const &other);
        ~Ratatouille();
        Ratatouille &operator=(const Ratatouille &rhs);

        //  Member  functions  allowing  to add  ingredients  in the  cooking  pot
        Ratatouille &addVegetable(unsigned char vegetable);
        Ratatouille &addCondiment(unsigned int condiment);
        Ratatouille &addSpice(double spice);
        Ratatouille &addSauce(const std::string &sauce);

        // The  member  function  to  extract  the  dish.
        // The  result  will be the  concatenation  of all  the  added  ingredients.
        std::string kooc();

};

#endif // RATATOUILLE_HPP