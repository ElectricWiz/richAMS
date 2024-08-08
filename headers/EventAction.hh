#ifndef EVENTACTION_HH
#define EVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "SteppingAction.hh"
#include "DataStore.hh"
#include "G4UnitsTable.hh"

#include <fstream>
#include <numeric>
#include <cmath>
#include <algorithm>

class EventAction : public G4UserEventAction
{
    public:
        EventAction(DataStore* dataStore);
        //EventAction();
        ~EventAction();

        virtual void BeginOfEventAction(const G4Event* aEvent);
        virtual void EndOfEventAction(const G4Event* aEvent);
    
    private:
        DataStore* dataStore;
};

#endif