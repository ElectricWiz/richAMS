#include "Detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name, DataStore* dataStore) : G4VSensitiveDetector(name), dataStore(dataStore)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    G4AnalysisManager* man = G4AnalysisManager::Instance();
    
    G4ThreeVector pos = aStep->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetObjectTranslation();
    man->FillNtupleDColumn(1, 0, pos[0]);
    man->FillNtupleDColumn(1, 1, pos[1]);

    G4int eventID = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    man->FillNtupleIColumn(1, 2, eventID);

    G4int trackID = aStep->GetTrack()->GetTrackID();
    man->FillNtupleIColumn(1, 3, trackID);

    G4double energy = aStep->GetTrack()->GetKineticEnergy();
    man->FillNtupleDColumn(1, 4, energy);
        
    man->AddNtupleRow(1);

    //dataStore->AddPhotonPosition(pos);
        
    aStep->GetTrack()->SetTrackStatus(fStopAndKill);

    if(aStep->GetTrack()->GetDefinition()->GetParticleName() == "proton")
    {       
        //Get the position of the sensitive detector
        G4ThreeVector pos = aStep->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetObjectTranslation();

        man->FillNtupleDColumn(2, 0, pos[0]);
        man->FillNtupleDColumn(2, 1, pos[1]);

        G4int eventID = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

        man->FillNtupleIColumn(2, 2, eventID);
        
        man->AddNtupleRow(2);

        //dataStore->SetProtonPosition(pos);
        
        aStep->GetTrack()->SetTrackStatus(fStopAndKill);
    }

    return true;

}
