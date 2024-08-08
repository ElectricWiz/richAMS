#include "AeroRadiator.hh"

AeroRadiator::AeroRadiator(G4String name) : G4VSensitiveDetector(name), fName(name)
{}

AeroRadiator::~AeroRadiator()
{}

G4bool AeroRadiator::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    G4Track* aTrack = aStep->GetTrack();

    if (aTrack->GetParentID() == 0 )
    {
        // Set the properties of the hit based on the step
        G4double ene = aStep->GetTotalEnergyDeposit();
        G4ThreeVector pos = aStep->GetPreStepPoint()->GetPosition();
        G4ThreeVector mom = aStep->GetPreStepPoint()->GetMomentum();

        G4AnalysisManager* man = G4AnalysisManager::Instance();

        man->FillNtupleDColumn(1, 0, ene);
        man->FillNtupleDColumn(1, 1, mom.x());
        man->FillNtupleDColumn(1, 2, mom.y());
        man->FillNtupleDColumn(1, 3, mom.z());

        man->FillNtupleDColumn(1, 4, pos.x());
        man->FillNtupleDColumn(1, 5, pos.y());
        man->FillNtupleDColumn(1, 6, pos.z());

        man->AddNtupleRow(1);
    }

    return true;
}