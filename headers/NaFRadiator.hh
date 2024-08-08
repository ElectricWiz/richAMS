#ifndef RADIATOR_HH
#define RADIATOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "G4RunManager.hh"

#include <set>

#include "Construction.hh"

class NaFRadiator : public G4VSensitiveDetector {
    public:
        NaFRadiator(G4String name);
        ~NaFRadiator();

    private:
        virtual G4bool ProcessHits(G4Step*, G4TouchableHistory*) override;

        G4String fName;
};

#endif
