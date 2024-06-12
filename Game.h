#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;


class Game {
private:
bool gameState;
class Event{
public:
Event() {

}
};


public:

void processEvent(Event& event) {
cout << "processing Event" << endl;
}
void createEvent(string eventName, int eventPriority) {
Event e;
}

};




#endif

	
