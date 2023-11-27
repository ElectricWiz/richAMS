#ifndef AERORADIATOR_HH
#define AERORADIATOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "G4RunManager.hh"

#include <set>

#include "Construction.hh"

class AeroRadiator : public G4VSensitiveDetector {
    public:
        AeroRadiator(G4String name);
        ~AeroRadiator();

    private:
        virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*) override;

        G4String fName;
};

#endif
