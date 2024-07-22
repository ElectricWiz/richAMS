#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"
#include "G4Event.hh"
#include "G4Track.hh"
#include "G4MTRunManager.hh"
#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"

#include "Generator.hh"
#include "Run.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "DataStore.hh"

class MyActionInitialization : public G4VUserActionInitialization
{

    public:
        MyActionInitialization(DataStore* dataStore);
        ~MyActionInitialization();

        virtual void Build() const;
        virtual void BuildForMaster() const;
        
    private:
        DataStore* dataStore;
};
#endif
