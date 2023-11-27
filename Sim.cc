#include <iostream>

#include "FTFP_BERT.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalParameters.hh"
#include "G4OpticalPhysics.hh"
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Construction.hh"
#include "Action.hh"
#include "EventAction.hh"
#include "Run.hh"

int main(int argc, char** argv)
{
    G4RunManager* runManager = new G4RunManager();

    G4VModularPhysicsList* physicsList = new FTFP_BERT;
    physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());

    G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
    auto opticalParams               = G4OpticalParameters::Instance();

    opticalParams->SetWLSTimeProfile("delta");

    opticalParams->SetScintTrackSecondariesFirst(true);

    opticalParams->SetCerenkovMaxPhotonsPerStep(100);
    opticalParams->SetCerenkovMaxBetaChange(10.0);
    opticalParams->SetCerenkovTrackSecondariesFirst(true);

    physicsList->RegisterPhysics(opticalPhysics);
    runManager->SetUserInitialization(physicsList);

    runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new MyActionInitialization());

    runManager->Initialize();

    G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    G4VisManager* visManager = new G4VisExecutive();
    
    visManager->Initialize();

    G4UImanager* UImanager =  G4UImanager::GetUIpointer();

    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/style surface");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 0 0 1");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");

    //batch mode
    G4String command  = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command + fileName);

    ui->SessionStart();

    return 0;
}
