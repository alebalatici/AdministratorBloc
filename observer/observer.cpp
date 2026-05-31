#include "observer.h"

void Observable::add_observer(Observer* observer)
{
    observers.push_back(observer);
}

void Observable::remove_observer(Observer* observer)
{
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Observable::notify()
{
    for (auto obs: observers)
    {
        obs->update();
    }
}