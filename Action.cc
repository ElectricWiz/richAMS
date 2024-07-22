#include "Action.hh"

MyActionInitialization::MyActionInitialization(DataStore* dataStore) : dataStore(dataStore)
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::BuildForMaster() const
{
    MyRunAction* runAction = new MyRunAction();
    SetUserAction(runAction);
}

void MyActionInitialization::Build() const
{
    MyPrimaryGenerator* generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    EventAction* eventAction = new EventAction(dataStore);
    //EventAction* eventAction = new EventAction();
    SetUserAction(eventAction);

    MyRunAction* runAction = new MyRunAction();
    SetUserAction(runAction);

    SteppingAction* steppingAction = new SteppingAction(dataStore);
    //SteppingAction* steppingAction = new SteppingAction();
    SetUserAction(steppingAction);
}
