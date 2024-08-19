#include <iostream>
#include <ctime>

#include "FTFP_BERT.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalParameters.hh"
#include "G4OpticalPhysics.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Construction.hh"
#include "Action.hh"
#include "EventAction.hh"
#include "Run.hh"
#include "DataStore.hh"

int main(int argc, char** argv)
{
    std::time_t now = std::time(0);

    CLHEP::HepRandom::setTheSeed(now);

    DataStore* dataStore = new DataStore();

    auto runManager = new G4MTRunManager();
    runManager->SetNumberOfThreads(12);

    G4VModularPhysicsList* physicsList = new FTFP_BERT;
    physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());

    G4OpticalPhysics* opticalPhysics = new G4OpticalPhysics();
    auto opticalParams               = G4OpticalParameters::Instance();

    opticalParams->SetWLSTimeProfile("delta");

    opticalParams->SetScintTrackSecondariesFirst(true);

    opticalParams->SetCerenkovMaxPhotonsPerStep(3);
    opticalParams->SetCerenkovMaxBetaChange(10.0);
    opticalParams->SetCerenkovTrackSecondariesFirst(true);

    physicsList->RegisterPhysics(opticalPhysics);
    runManager->SetUserInitialization(physicsList);

    runManager->SetUserInitialization(new MyDetectorConstruction(dataStore));
    runManager->SetUserInitialization(new MyActionInitialization(dataStore));

    runManager->Initialize();

    G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    G4VisManager* visManager = new G4VisExecutive();
    
    visManager->Initialize();

    G4UImanager* UImanager =  G4UImanager::GetUIpointer();

    if (argc > 1) {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    } else {
        UImanager->ApplyCommand("/vis/open OGL 800x800-0+0");
        UImanager->ApplyCommand("/vis/scene/handler/create OGLIX");
        UImanager->ApplyCommand("/vis/viewer/create !! 800x800-0+0");
        UImanager->ApplyCommand("/vis/viewer/set/style1surface");
        UImanager->ApplyCommand("/vis/viewer/set/viewpointVector -1 -1 0");
        UImanager->ApplyCommand("/vis/drawVolume");
        UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
        UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
        UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");  

        UImanager->ApplyCommand("/vis/viewer/flush");
        UImanager->ApplyCommand("/vis/viewer/refresh");

        ui->SessionStart();
    }

    delete ui;
    delete visManager;
    delete runManager;
    delete dataStore;

    return 0;
}
