#include "NaFRadiator.hh"

NaFRadiator::NaFRadiator(G4String name) : G4VSensitiveDetector(name), fName(name)
{}

NaFRadiator::~NaFRadiator()
{}

G4bool NaFRadiator::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    // Check if the particle is not a photon
    G4Track* aTrack = aStep->GetTrack();

    if (aTrack->GetParentID() == 0)
    {
        // Set the properties of the hit based on the step
        G4double ene = aStep->GetTotalEnergyDeposit();
        G4ThreeVector pos = aStep->GetPreStepPoint()->GetPosition();
        G4ThreeVector mom = aStep->GetPreStepPoint()->GetMomentum();

        G4AnalysisManager* man = G4AnalysisManager::Instance();

        man->FillNtupleDColumn(2, 0, ene);
        man->FillNtupleDColumn(2, 1, mom.x());
        man->FillNtupleDColumn(2, 2, mom.y());
        man->FillNtupleDColumn(2, 3, mom.z());

        man->FillNtupleDColumn(2, 4, pos.x());
        man->FillNtupleDColumn(2, 5, pos.y());
        man->FillNtupleDColumn(2, 6, pos.z());

        man->AddNtupleRow(2);
    }

    return true;
}