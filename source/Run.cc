#include "Run.hh"

MyRunAction::MyRunAction()
{
    G4AnalysisManager* man = G4AnalysisManager::Instance();

    man->CreateNtuple("PrimaryParticle", "Primary particle data");

    man->CreateNtupleDColumn("energyPrimary");
    man->CreateNtupleIColumn("eventNumber");

    man->FinishNtuple();

    man->CreateNtuple("Detectors", "Cerenkov Photons Detected");

    man->CreateNtupleDColumn("detectorPositionX");
    man->CreateNtupleDColumn("detectorPositionY");
    man->CreateNtupleIColumn("eventNumber");
    man->CreateNtupleIColumn("trackID");
    man->CreateNtupleDColumn("energy");

    man->FinishNtuple();

    man->CreateNtuple("CircleCenter", "Center for Likelihood");

    man->CreateNtupleDColumn("centerX");
    man->CreateNtupleDColumn("centerY");
    man->CreateNtupleIColumn("eventNumber");

}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
    G4AnalysisManager* man = G4AnalysisManager::Instance();
   
    man->SetVerboseLevel(2);

    man->OpenFile("output.root");
}

void MyRunAction::EndOfRunAction(const G4Run* run)
{
    G4AnalysisManager* man = G4AnalysisManager::Instance();
    
    // Write and close the ntuples
    man->Write();
    man->CloseFile();
}
