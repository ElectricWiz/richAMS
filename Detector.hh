#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "G4RunManager.hh"
#include "G4Gamma.hh"
#include "G4AnalysisManager.hh"
#include "DataStore.hh"

class MySensitiveDetector : public G4VSensitiveDetector
{
    public:
        MySensitiveDetector(G4String, DataStore* dataStore);
        //MySensitiveDetector(G4String);
        ~MySensitiveDetector();

        virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

    private:    
        DataStore* dataStore;
};

#endif
