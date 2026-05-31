#ifndef ADMINISTRATORBLOC_OBSERVER_H
#define ADMINISTRATORBLOC_OBSERVER_H

#include <vector>
#include <algorithm>
using std::vector;
using std::remove;
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

class Observable
{
private:
    vector<Observer*> observers;
public:
    void add_observer(Observer* observer);
    void remove_observer(Observer* observer);
    void notify();
};

#endif //ADMINISTRATORBLOC_OBSERVER_H