#include "Action.hh"

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::Build() const
{
    MyPrimaryGenerator* generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    EventAction* eventAction = new EventAction();
    SetUserAction(eventAction);

    MyRunAction* runAction = new MyRunAction();
    SetUserAction(runAction);
}
