/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** EventManager.cpp
*/

#include "EventManager.hpp"

EventManager::EventManager() :
_eventList(),
_time(0)
{}

EventManager::EventManager(EventManager const &other) :
_eventList(other._eventList),
_time(other._time)
{}

EventManager::~EventManager()
{
    _eventList.clear();
}

EventManager& EventManager::operator=(EventManager const &rhs)
{
    _eventList = rhs._eventList;
    _time = rhs._time;
    return (*this);
}

void EventManager::addEvent(const Event &e)
{
    if (e.getTime() < _time)
        return;
    _eventList.push_back(e);
    _eventList.sort();
}

void EventManager::removeEventsAt(unsigned int time)
{
    for (auto it = _eventList.begin(); it != _eventList.end();) {
        if (it->getTime() < time) {
            ++it;
            continue;
        }
        if (it->getTime() > time)
            break;
        if (it->getTime() == time)
            it = _eventList.erase(it);
        else
            ++it;
    }
}

void EventManager::dumpEvents() const
{
    for (auto it = _eventList.begin(); it != _eventList.end(); ++it)
        std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (auto it = _eventList.begin(); it != _eventList.end(); ++it) {
        if (it->getTime() < time)
            continue;
        else if (it->getTime() > time)
            break;
        std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
    }
}

void EventManager::addTime(unsigned int time)
{
    _time += time;
    for (auto it = _eventList.begin(); it != _eventList.end();) {
        if (it->getTime() > _time)
            break;
        if (it->getTime() <= _time) {
            std::cout << it->getEvent() << std::endl;
            it = _eventList.erase(it);
        }
        else
            ++it;
    }
}

void EventManager::addEventList(std::list<Event> &events)
{
    for (auto it = events.begin(); it != events.end(); ++it)
        addEvent(*it);
}