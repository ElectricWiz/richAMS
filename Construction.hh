#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VisAttributes.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Tubs.hh"
#include "G4SubtractionSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericMessenger.hh"
#include "G4Cons.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"

#include <cstdlib>

#include "Detector.hh"
#include "DataStore.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        MyDetectorConstruction(DataStore *dataStore);
        ~MyDetectorConstruction();
        
        virtual G4VPhysicalVolume* Construct();

    private:
        G4LogicalVolume *logicDetector;
        G4LogicalVolume *logicAero;
        G4LogicalVolume *logicNaF;

	    virtual void ConstructSDandField();

        G4int nCols, nRows;

	    G4GenericMessenger* fMessenger;

        DataStore *dataStore;  
};			       

#endif
