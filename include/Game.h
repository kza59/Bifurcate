#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;


class Game{
private:

    class Event{
        private:
        string Name;
        int Prio;
        public:
        Event() {
            Name = "Unknown Event";
            Prio = 0;
        }
        Event(string eventName, int eventPrio) : Name(eventName),Prio(eventPrio) {

        }
        void setPrio(int eventPrio) {
            Prio = eventPrio;
        }
        void setName(string eventName) {
            Name = eventName;
        }
        int getPrio() {
            return Prio;
        }
        string getName() {
            return Name;
        }
    };
public:
int capacity = 5;
int size = 0;
    Game() {

    }
    void createEvent(string eventName, int eventPrio) {
        cout << eventName << " " << eventPrio << endl;
        Event event(eventName,eventPrio);
        array[size] = event;
        size++;
        
    }
    void processEvent() {
        //Queue-like process.. After evaluation the event should be dequeued/removed to make space for the next event/set of events.
       
        for(int i{1};i<=size;++i) {
                cout << array[size-i].getName() << " " << array[size-i].getPrio() << endl;
        }

                delete[] array;
        
    }
    Event* array = new Event[5];
};


#endif

	
