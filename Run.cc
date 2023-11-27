#include "Run.hh"

MyRunAction::MyRunAction()
{
    G4AnalysisManager* man = G4AnalysisManager::Instance();

    // Create an ntuple for the primary particle data
    man->CreateNtuple("PrimaryParticle", "Primary particle data");

    // Create a DColumn for vectors of doubles
    man->CreateNtupleDColumn("positionPrimaryX");
    man->CreateNtupleDColumn("positionPrimaryY");
    man->CreateNtupleDColumn("positionPrimaryZ");

    man->CreateNtupleDColumn("momentumPrimaryX");
    man->CreateNtupleDColumn("momentumPrimaryY");
    man->CreateNtupleDColumn("momentumPrimaryZ");

    // Finish ntuple creation
    man->FinishNtuple();

    // Create an ntuple
    man->CreateNtuple("Aerogel", "Aerogel particle data");

    // Create columns for the ntuple
    man->CreateNtupleDColumn("energy");

    man->CreateNtupleDColumn("momentumDirectionX");
    man->CreateNtupleDColumn("momentumDirectionY");
    man->CreateNtupleDColumn("momentumDirectionZ");

    man->CreateNtupleDColumn("positionAeroX");
    man->CreateNtupleDColumn("positionAeroY");
    man->CreateNtupleDColumn("positionAeroZ");

    // Finish ntuple creation
    man->FinishNtuple();

    // Create another ntuple
    man->CreateNtuple("NaF", "NaF particle data");

    // Create columns for the new ntuple
    man->CreateNtupleDColumn("energy");

    man->CreateNtupleDColumn("momentumDirectionX");
    man->CreateNtupleDColumn("momentumDirectionY");
    man->CreateNtupleDColumn("momentumDirectionZ");

    man->CreateNtupleDColumn("positionNaFX");
    man->CreateNtupleDColumn("positionNaFY");
    man->CreateNtupleDColumn("positionNaFZ");

    // Finish ntuple creation
    man->FinishNtuple();

    man->CreateNtuple("Detectors", "Cerenkov Photons Detected");

    man->CreateNtupleDColumn("detectorPositionX");
    man->CreateNtupleDColumn("detectorPositionY");
    man->CreateNtupleDColumn("detectorPositionZ");

    man->CreateNtupleDColumn("photonEnergy");

    man->CreateNtupleIColumn("eventNumber");

    man->FinishNtuple();
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
