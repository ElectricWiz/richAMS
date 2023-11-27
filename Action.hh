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

class MyActionInitialization : public G4VUserActionInitialization
{

    public:
        MyActionInitialization();
        ~MyActionInitialization();

        virtual void Build() const;
};
#endif
