#include "Detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    G4AnalysisManager* man = G4AnalysisManager::Instance();

    //Get the position of the sensitive detector
    G4ThreeVector pos = aStep->GetPostStepPoint()->GetTouchableHandle()->GetVolume()->GetObjectTranslation();
    G4double ene = aStep->GetTotalEnergyDeposit();

    man->FillNtupleDColumn(3, 0, pos[0]);
    man->FillNtupleDColumn(3, 1, pos[1]);
    man->FillNtupleDColumn(3, 2, pos[2]);

    man->FillNtupleDColumn(3, 3, ene);

    G4int eventID = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

    man->FillNtupleIColumn(3, 4, eventID);

    man->AddNtupleRow(3);

    aStep->GetTrack()->SetTrackStatus(fStopAndKill);

    return true;
}
