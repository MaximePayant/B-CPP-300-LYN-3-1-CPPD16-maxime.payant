/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** EventManager.hpp
*/

#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <iostream>
#include <list>

#include "Event.hpp"

class EventManager
{

    private:
        std::list<Event> _eventList;
        unsigned int _time;

    public:
        EventManager();
        EventManager(EventManager const &other);
        ~EventManager();

        EventManager &operator=(EventManager const &rhs);

        void addEvent(const Event &e);
        void removeEventsAt(unsigned int time);
        void dumpEvents() const;
        void dumpEventAt(unsigned int time) const;
        void addTime(unsigned int time);
        void addEventList(const std::list<Event> &events);

};

#endif // EVENT_MANAGER_HPP