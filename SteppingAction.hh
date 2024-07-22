#ifndef SteppingAction_HH
#define SteppingAction_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "G4RunManager.hh"
#include "DataStore.hh"

#include <vector>

class SteppingAction : public G4UserSteppingAction
{
    public:
        SteppingAction(DataStore* dataStore);
        //SteppingAction();
        ~SteppingAction();

        virtual void UserSteppingAction(const G4Step*);
    
    private:
        G4int stepCount;
        DataStore* dataStore;
};

#endif