#include "EventAction.hh"

EventAction::EventAction(DataStore* dataStore) : dataStore(dataStore)
{}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event* event)
{
    G4AnalysisManager* man = G4AnalysisManager::Instance();

    man->OpenFile("output.root");

    G4ThreeVector position = event->GetPrimaryVertex()->GetPosition();
    G4ThreeVector momentum = event->GetPrimaryVertex()->GetPrimary()->GetMomentum();

    G4double kineticEnergy = event->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy();

    // Obtain the event ID from the run manager
    G4RunManager* runManager = G4RunManager::GetRunManager();
    G4int eventID = runManager->GetCurrentEvent()->GetEventID();
    
    if(eventID % 50000 == 0)
        G4cout << "Event number: " << eventID << G4endl;

    man->FillNtupleDColumn(0, 0, kineticEnergy);
    man->FillNtupleIColumn(0, 1, eventID);

    man->AddNtupleRow(0);

}

void EventAction::EndOfEventAction(const G4Event* event)
{}

