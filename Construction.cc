#include "Construction.hh"
#include <cmath>

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    G4VisAttributes* redColor = new G4VisAttributes(G4Colour(1, 0, 0));
    G4VisAttributes* blueColor = new G4VisAttributes(G4Colour(0, 0, 1));
    G4VisAttributes* invisible = new G4VisAttributes();
    invisible->SetVisibility(false);

    G4NistManager *nist = G4NistManager::Instance();

    G4Material* Vacuum = new G4Material("Vacuum", 1.e-25*g/cm3, 2);
    Vacuum->AddElement(nist->FindOrBuildElement("N"), .7);
    Vacuum->AddElement(nist->FindOrBuildElement("O"), .3);

    G4Material* SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2);
    SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
    SiO2->AddElement(nist->FindOrBuildElement("O"), 2);

    G4Material* NaF = new G4Material("NaF", 2.56*g/cm3, 2);
    NaF->AddElement(nist->FindOrBuildElement("Na"), 1);
    NaF->AddElement(nist->FindOrBuildElement("F"), 1);

    G4Material* B2O3 = new G4Material("B2O3", 2.46*g/cm3, 2);
    B2O3->AddElement(nist->FindOrBuildElement("B"), 2);
    B2O3->AddElement(nist->FindOrBuildElement("O"), 3);

    G4Material* Al2O3 = new G4Material("Al2O3", 3.95*g/cm3, 2);
    Al2O3->AddElement(nist->FindOrBuildElement("Al"), 2);
    Al2O3->AddElement(nist->FindOrBuildElement("O"), 3);

    G4Material* Borosilicate = new G4Material("Borosilicate", 2.23*g/cm3, 3);
    Borosilicate->AddMaterial(SiO2, 75*perCent);
    Borosilicate->AddMaterial(B2O3, 20*perCent);
    Borosilicate->AddMaterial(Al2O3, 5*perCent);

    G4Material* H2O = new G4Material("H2O", 1.*g/cm3, 2);
    H2O->AddElement(nist->FindOrBuildElement("H"), 2);
    H2O->AddElement(nist->FindOrBuildElement("O"), 1);

    G4Element* C = nist->FindOrBuildElement("C");

    G4Material* Aerogel = new G4Material("Aerogel", 0.200*g/cm3, 3);
    Aerogel->AddMaterial(SiO2, 62.5*perCent);
    Aerogel->AddMaterial(H2O, 37.4*perCent);
    Aerogel->AddElement(C, 0.1*perCent);

    G4double energy[2] = {1.7712027571428572*eV, 4.1328064333333*eV};
    G4double rindexAerogel[2] = {1.05, 1.05};
    G4double rindexNaF[2] = {1.34, 1.34};
    G4double rindexBoro[2] = {1.51446, 1.51446};
    G4double rindexWorld[2] = {1.0, 1.0};
    G4double absorptionLength[2] = {35.*cm, 35.*cm};

    G4double Boro_QE[2] = {1, 1};
	    
    G4MaterialPropertiesTable* mptAerogel = new G4MaterialPropertiesTable();
    mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2);
    Aerogel->SetMaterialPropertiesTable(mptAerogel);
    
    G4Material *worldMat = Vacuum;

    G4MaterialPropertiesTable* mptWorld  = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);
    worldMat->SetMaterialPropertiesTable(mptWorld);

    G4MaterialPropertiesTable* mptBoro = new G4MaterialPropertiesTable();
    mptBoro->AddProperty("EFFICIENCY", energy, Boro_QE, 2);
    mptBoro->AddProperty("RINDEX", energy, rindexBoro, 2);
    Borosilicate->SetMaterialPropertiesTable(mptBoro);

    G4MaterialPropertiesTable* mptNaF = new G4MaterialPropertiesTable();
    mptNaF->AddProperty("RINDEX", energy, rindexNaF, 2);
    mptNaF->AddProperty("ABSLENGTH", energy, absorptionLength, 2);
    NaF->SetMaterialPropertiesTable(mptNaF);

    G4Box* solidWorld = new G4Box("solidWorld", 1.38*m, 1.38*m, 3.5*m);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, Vacuum, "logicWorld");
    logicWorld->SetVisAttributes(invisible);
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
   
    G4Tubs* circularRadiator = new G4Tubs("circularRadiator", 0.*m, 66.82*cm, 2.*cm, 0.*deg, 360.*deg);

    G4Box* cutNaF = new G4Box("cutNaF", 15.*cm, 15.*cm, 2.*cm);
    G4Box* solidNaF = new G4Box("solidNaF", 14.*cm, 14.*cm, 2.*cm);

    G4VSolid* solidAero = new G4SubtractionSolid("solidAero", circularRadiator, cutNaF, 0, G4ThreeVector(0., 0., 0.));

    logicAero = new G4LogicalVolume(solidAero, Aerogel, "logicAero");
    logicAero->SetVisAttributes(redColor);

    logicNaF = new G4LogicalVolume(solidNaF, NaF, "logicNaF");
    logicNaF->SetVisAttributes(blueColor);

    G4VPhysicalVolume* physAero = new G4PVPlacement(0, G4ThreeVector(0., 0., 47.8*cm), logicAero, "physAero", logicWorld, false, 0, true);
    G4VPhysicalVolume* physNaF = new G4PVPlacement(0, G4ThreeVector(0., 0., 47.8*cm), logicNaF, "physNaF", logicWorld, false, 0, true);

    G4Box *solidDetector = new G4Box("solidDetector", 0.017*m, 0.017*m, 0.01*m); 
    logicDetector = new G4LogicalVolume(solidDetector, Borosilicate, "logicDetector");


    for (G4int i = 0; i < 135; i++) {
        for (G4int j = 0; j < 135; j++) {
            G4double x = -68 * cm + (i + 1.7) * m / 100;
            G4double y = -68 * cm + (j + 1.7) * m / 100;
            G4double distance = std::sqrt(x * x + y * y);

            if (distance <= 65.0*cm && (std::abs(x) > 31.8*cm || std::abs(y) > 31.8*cm)) {
                G4VPhysicalVolume* physDetector = new G4PVPlacement(0, G4ThreeVector(x, y, 1.*cm), logicDetector, "physDetector", logicWorld, false, j + i * 100);
            }
        }   
    }

    return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
    MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
    logicDetector->SetSensitiveDetector(sensDet);

    AeroRadiator* aeroGel = new AeroRadiator("AeroGel"); 
    logicAero->SetSensitiveDetector(aeroGel);
    
    NaFRadiator* naF = new NaFRadiator("NaF");
    logicNaF->SetSensitiveDetector(naF); 
}
