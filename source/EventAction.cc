#include "EventAction.hh"

EventAction::EventAction(DataStore* dataStore) : dataStore(dataStore)
{}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event* event)
{
    // Get the analysis manager
    G4AnalysisManager* man = G4AnalysisManager::Instance();

    man->OpenFile("output.root");

    // Get the primary particles of the event
    G4ThreeVector position = event->GetPrimaryVertex()->GetPosition();
    G4ThreeVector momentum = event->GetPrimaryVertex()->GetPrimary()->GetMomentum();

    G4double kineticEnergy = event->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy();

    // Obtain the event ID from the run manager
    G4RunManager* runManager = G4RunManager::GetRunManager();
    G4int eventID = runManager->GetCurrentEvent()->GetEventID();
    
    /*if(eventID % 10000 == 0)
        G4cout << "Event number: " << eventID << G4endl;*/

    // Insert the event ID into column number 6 of the NTuple
    man->FillNtupleDColumn(0, 0, kineticEnergy);
    man->FillNtupleIColumn(0, 1, eventID);

    man->AddNtupleRow(0);

}

void EventAction::EndOfEventAction(const G4Event* event)
{}

