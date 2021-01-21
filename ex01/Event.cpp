/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Event.cpp
*/

#include "Event.hpp"

Event::Event() :
_time(0),
_event("")
{}

Event::Event(const Event &other) :
_time(other._time),
_event(other._event)
{}

Event::Event(unsigned int time, const std::string &event) :
_time(time),
_event(event)
{}

Event::~Event()
{}

Event& Event::operator=(const Event &rhs)
{
    _time = rhs._time;
    _event = rhs._event;
    return (*this);
}

bool Event::operator<(const Event &rhs)
{
    if (_time < rhs._time)
        return (true);
    return (false);
}

unsigned int Event::getTime() const
{
    return (_time);
}

const std::string& Event::getEvent() const
{
    return (_event);
}

void Event::setTime(unsigned int time)
{
    _time = time;
}

void Event::setEvent(const std::string &event)
{
    _event = event;
}
