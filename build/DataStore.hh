#ifndef DATASTORE_HH
#define DATASTORE_HH

#include <vector>
#include <G4StepStatus.hh>
#include <G4String.hh>
#include <G4ThreeVector.hh>
#include <mutex>

class DataStore
{
    public:
        DataStore() {}
        ~DataStore() {}

        void AddPhotonPosition(G4ThreeVector photonPosition) 
        { 
            photonPositionsX.push_back(photonPosition.x());
            photonPositionsY.push_back(photonPosition.y());
            photonPositionsZ.push_back(photonPosition.z()); 
        }

        void ClearData() 
        {
            processNames.clear();
            stepStatuses.clear();
            trackIDs.clear();

            photonPositionsX.clear();
            photonPositionsY.clear();
            photonPositionsZ.clear();

        }

        void SetProtonPosition(G4ThreeVector protonPosition) { this->protonPosition = protonPosition; }

        void AddProcessName(G4String processName)
        { processNames.push_back(processName); }
        void AddStepStatus(G4StepStatus stepStatus) 
        { stepStatuses.push_back(stepStatus); }
        void AddTrackID(G4int trackID) { trackIDs.push_back(trackID); }

        const std::vector<G4String>& GetProcessNames() const { return processNames; }
        const std::vector<G4StepStatus>& GetStepStatuses() const { return stepStatuses; }

        const std::vector<double>& GetPhotonPositionsX() const { return photonPositionsX; }
        const std::vector<double>& GetPhotonPositionsY() const { return photonPositionsY; }
        const std::vector<double>& GetPhotonPositionsZ() const { return photonPositionsZ; }

        const G4ThreeVector& GetProtonPosition() const { return protonPosition; }

        const std::vector<G4int>& GetTrackIDs() const { return trackIDs; }

    private:
        std::vector<double> photonPositionsX;
        std::vector<double> photonPositionsY;
        std::vector<double> photonPositionsZ;

        G4ThreeVector protonPosition;

        std::vector<G4String> processNames;
        std::vector<G4StepStatus> stepStatuses;
        std::vector<G4int> trackIDs;
};

#endif

