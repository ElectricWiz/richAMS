#include "EventAction.hh"

EventAction::EventAction(DataStore* dataStore) : dataStore(dataStore)
{}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event* event)
{
    // Get the analysis manager
    G4AnalysisManager* man = G4AnalysisManager::Instance();

    man->OpenFile("output.root");

    // Get the primary particles of the event
 /* G4ThreeVector position = event->GetPrimaryVertex()->GetPosition();
    G4ThreeVector momentum = event->GetPrimaryVertex()->GetPrimary()->GetMomentum();
*/
    G4double kineticEnergy = event->GetPrimaryVertex()->GetPrimary()->GetKineticEnergy();

    // Convert the G4ThreeVector to a std::vector<double>
/*  std::vector<double> positionComponents = {position.x(), position.y(), position.z()};
    std::vector<double> momentumComponents = {momentum.x(), momentum.y(), momentum.z()};
*/

/*  // Fill the ntuple with the position of the primary particle
    for (size_t i = 0; i < positionComponents.size(); ++i)
    {
        man->FillNtupleDColumn(0, i, positionComponents[i]);
    }
*/
    // Obtain the event ID from the run manager
    G4RunManager* runManager = G4RunManager::GetRunManager();
    G4int eventID = runManager->GetCurrentEvent()->GetEventID();
    
    /*if(eventID % 10000 == 0)
        G4cout << "Event number: " << eventID << G4endl;*/

    // Insert the event ID into column number 6 of the NTuple
    man->FillNtupleDColumn(0, 0, kineticEnergy);
    man->FillNtupleIColumn(0, 1, eventID);

    man->AddNtupleRow(0);

}

void EventAction::EndOfEventAction(const G4Event* event)
{
    /*std::vector<double> photon_positions_x = dataStore->GetPhotonPositionsX();
    std::vector<double> photon_positions_y = dataStore->GetPhotonPositionsY();
    std::vector<double> photon_positions_z = dataStore->GetPhotonPositionsZ();
    G4ThreeVector proton_position = dataStore->GetProtonPosition();
    G4double radius = 201.93947956579464; // Define your threshold
    G4double threshold = 50; // Define your threshold
    G4int far_photons_count = 0;

    std::vector<G4int> photon_trackIDs = dataStore->GetTrackIDs(); // Assuming this method exists
    std::vector<G4int> far_photon_trackIds;

    for (size_t i = 0; i < photon_positions_x.size(); i++) {
        G4ThreeVector photon_position(photon_positions_x[i], photon_positions_y[i], photon_positions_z[i]);
        G4double distance = (photon_position - proton_position).mag();
        if (std::fabs(distance - radius) < threshold) {
            far_photons_count++;
            far_photon_trackIds.push_back(photon_trackIDs[i]);
        }
    }

    G4int second_threshold = photon_positions_x.size()/25; // Define your second threshold
    if (far_photons_count < second_threshold) {
        std::vector<G4String> processNames = dataStore->GetProcessNames();
        std::vector<G4StepStatus> stepStatuses = dataStore->GetStepStatuses();
        std::vector<G4int> trackIDs = dataStore->GetTrackIDs();

        std::vector<size_t> matching_indices;
        std::vector<G4int> matching_trackIDs;
        for (size_t i = 0; i < trackIDs.size(); i++) {
            if (std::find(far_photon_trackIds.begin(), far_photon_trackIds.end(), trackIDs[i]) == far_photon_trackIds.end()) {
                matching_indices.push_back(i);
                matching_trackIDs.push_back(trackIDs[i]);
            }
        }

        std::ofstream outfile("output.txt");
        for (size_t i = 0; i < matching_indices.size(); i++) {
            size_t index = matching_indices[i];
            if (index < processNames.size()) {
                outfile << "Process " << index+1 << ": " << processNames[index] << ", Track ID: " << matching_trackIDs[i] << std::endl;
            }
        }

        outfile.close();

        G4RunManager::GetRunManager()->AbortRun();
    }
    */
    
}

