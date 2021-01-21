/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Event.hpp
*/

#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>

class Event
{

    private:
        unsigned int _time;
        std::string _event;

    public:
        Event();
        Event(unsigned int time, const std::string &event);
        Event(const Event &other);
        ~Event();

        Event &operator=(const Event &rhs);
        bool operator<(const Event &rhs);

        unsigned int getTime() const;
        const std::string &getEvent() const;
        void setTime(unsigned int time);
        void setEvent(const std::string &event);

};

#endif // EVENT_HPP