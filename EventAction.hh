#ifndef EVENTACTION_HH
#define EVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4AnalysisManager.hh"
#include "G4Event.hh"

#include "AeroRadiator.hh"
#include "NaFRadiator.hh"

#include <map>

class EventAction : public G4UserEventAction
{
    public:
	EventAction();
	~EventAction();

    virtual void BeginOfEventAction(const G4Event* aEvent);
    virtual void EndOfEventAction(const  G4Event* aEvent);
};

#endif