#include "SteppingAction.hh"

SteppingAction::SteppingAction(DataStore* dataStore) : dataStore(dataStore), stepCount(0)
{}

SteppingAction::~SteppingAction()
{}

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
    const G4StepPoint* endPoint = aStep->GetPostStepPoint();
    const G4VProcess* process = endPoint->GetProcessDefinedStep();
    const G4String processName = process->GetProcessName();
    const G4StepStatus stepStatus = endPoint->GetStepStatus();

    const G4int trackID = aStep->GetTrack()->GetTrackID();  

    /*dataStore->AddProcessName(processName);
    dataStore->AddStepStatus(stepStatus);
    dataStore->AddTrackID(trackID);
    */

    // Increment the step count
    stepCount++;

    const int MAX_STEPS = 10000;

 // Check if the step count exceeds the threshold
    if(stepCount >= MAX_STEPS)
    {
            // Abort the current event
        G4RunManager::GetRunManager()->AbortEvent();

            // Reset step count for the next event
        stepCount = 0;
    }

}

