#include "Construction.hh"
#include <cmath>
#include <algorithm>

MyDetectorConstruction::MyDetectorConstruction(DataStore* dataStore) : dataStore(dataStore)
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

    G4Material* lead = nist->FindOrBuildMaterial("G4_Pb");
    G4Material* Silicon = nist->FindOrBuildMaterial("G4_Si");

    G4double energy[40] = {
    1.768*eV, 1.783*eV, 1.794*eV, 1.805*eV, 1.820*eV, 1.824*eV, 1.844*eV, 1.852*eV,
    1.872*eV, 1.880*eV, 1.893*eV, 1.910*eV, 1.923*eV, 1.945*eV, 1.958*eV, 1.967*eV,
    1.990*eV, 2.004*eV, 2.027*eV, 2.062*eV, 2.087*eV, 2.128*eV, 2.172*eV, 2.211*eV,
    2.282*eV, 2.338*eV, 2.417*eV, 2.531*eV, 2.649*eV, 2.796*eV, 2.981*eV, 3.181*eV,
    3.450*eV, 3.803*eV, 4.133*eV, 4.278*eV, 4.343*eV, 4.410*eV, 4.503*eV, 4.551*eV
    };

    G4double rindexAerogel[40]; 
    std::fill_n(rindexAerogel, 40, 1.05);
    G4double rindexNaF[40];
    std::fill_n(rindexNaF, 40, 1.34);
    G4double rindexBoro[40];
    std::fill_n(rindexBoro, 40, 1.51446);
    G4double rindexWorld[40];
    std::fill_n(rindexWorld, 40, 1.0);
    G4double scatteringLength[40];
    std::fill_n(scatteringLength, 40, 4.5*cm);

    G4double Boro_QE[40] = {
    0.00011, 0.00014, 0.00019, 0.00025, 0.00032, 0.00041, 0.00054, 0.00072,
    0.00095, 0.00121, 0.0016, 0.00212, 0.00288, 0.00367, 0.0048, 0.0062,
    0.00821, 0.01115, 0.01402, 0.01857, 0.02427, 0.03092, 0.04042, 0.05151,
    0.061908, 0.07691, 0.097934, 0.113756, 0.134657, 0.145684, 0.168514, 0.20429,
    0.1917, 0.16982, 0.1441, 0.1051804, 0.08382, 0.06457, 0.01158, 0.02958
    };

    G4double transmittanceNaF[40];
    std::fill_n(transmittanceNaF, 40, 0.95);
    G4double transmittance[40] = {
        0.15303030303030285,
        0.18333333333333335,
        0.21818181818181803,
        0.24545454545454548,
        0.2666666666666666,
        0.2893939393939393,
        0.31060606060606055,
        0.3363636363636363,
        0.3651515151515151,
        0.3878787878787878,
        0.4121212121212121,
        0.44545454545454544,
        0.4696969696969697,
        0.493939393939394,
        0.5242424242424243,
        0.5530303030303031,
        0.5803030303030304,
        0.6090909090909092,
        0.631818181818182,
        0.6545454545454547,
        0.6803030303030304,
        0.7090909090909092,
        0.7212121212121213,
        0.7333333333333334,
        0.7484848484848485,
        0.7606060606060607,
        0.7787878787878789,
        0.790909090909091,
        0.7984848484848486,
        0.8075757575757577,
        0.8181818181818183,
        0.8272727272727274,
        0.8378787878787881,
        0.8469696969696972,
        0.8606060606060608,
        0.8666666666666669,
        0.8742424242424244,
        0.8787878787878789,
        0.884848484848485,
        0.8924242424242426
    };
    
    G4MaterialPropertiesTable* mptAerogel = new G4MaterialPropertiesTable();
    mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 40);
    mptAerogel->AddProperty("SCATTERING_LENGTH", energy, scatteringLength, 40, true);
    mptAerogel->AddProperty("TRANSMITTANCE", energy, transmittance, 40);
    Aerogel->SetMaterialPropertiesTable(mptAerogel);
    
    G4Material *worldMat = Vacuum;

    G4MaterialPropertiesTable* mptWorld  = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy, rindexWorld, 40);
    worldMat->SetMaterialPropertiesTable(mptWorld);

    G4MaterialPropertiesTable* mptBoro = new G4MaterialPropertiesTable();
    mptBoro->AddProperty("EFFICIENCY", energy, Boro_QE, 40);
    mptBoro->AddProperty("RINDEX", energy, rindexBoro, 40);
    Borosilicate->SetMaterialPropertiesTable(mptBoro);

    G4MaterialPropertiesTable* mptNaF = new G4MaterialPropertiesTable();
    mptNaF->AddProperty("RINDEX", energy, rindexNaF, 40);
    mptNaF->AddProperty("TRANSMITTANCE", energy, transmittanceNaF, 40);
    NaF->SetMaterialPropertiesTable(mptNaF);

    G4Box* solidWorld = new G4Box("solidWorld", 1.38*m, 1.38*m, 3.5*m);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, Vacuum, "logicWorld");
    logicWorld->SetVisAttributes(invisible);
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
   
    G4Tubs* circularRadiator = new G4Tubs("circularRadiator", 0.*m, 50*cm, 1*cm, 0.*deg, 360.*deg);

    /*G4Box* cutNaF = new G4Box("cutNaF", 15.*cm, 15.*cm, 0.55*cm);
    G4Box* solidNaF = new G4Box("solidNaF", 14.*cm, 14.*cm, 0.5*cm);

    G4VSolid* solidAero = new G4SubtractionSolid("solidAero", circularRadiator, cutNaF, 0, G4ThreeVector(0., 0., 0.));*/

        // Define the dimensions of the box
    G4double halfX = 65.0 * cm / 2; // Half-lengths
    G4double halfY = 65.0 * cm / 2;
    G4double halfZ = 13.0 * cm / 2;

    logicAero = new G4LogicalVolume(circularRadiator, Aerogel, "logicAero");
    logicAero->SetVisAttributes(redColor);

    /*logicNaF = new G4LogicalVolume(solidNaF, NaF, "logicNaF");
    logicNaF->SetVisAttributes(blueColor);*/

    G4VPhysicalVolume* physAero = new G4PVPlacement(0, G4ThreeVector(0., 0., 77.5*cm), logicAero, "physAero", logicWorld, false, 0, true);
    //G4VPhysicalVolume* physNaF = new G4PVPlacement(0, G4ThreeVector(0., 0., 81*cm), logicNaF, "physNaF", logicWorld, false, 0, true);

    G4Box *solidDetector = new G4Box("solidDetector", 8.5*mm, 8.5*mm, 5*mm); 
    logicDetector = new G4LogicalVolume(solidDetector, Borosilicate, "logicDetector");


    for (G4int i = 0; i < 200; i++) {
        for (G4int j = 0; j < 200; j++) {
            G4double x = -68 * cm + (i + 0.425) * m / 100;
            G4double y = -68 * cm + (j + 0.425) * m / 100;
            G4double distance = std::sqrt(x * x + y * y);

            /*if (distance <= 65.0*cm && (std::abs(x) > 31.8*cm || std::abs(y) > 31.8*cm)) {
                G4VPhysicalVolume* physDetector = new G4PVPlacement(0, G4ThreeVector(x, y, 16.*cm), logicDetector, "physDetector", logicWorld, false, j + i * 100);
            }*/

            if (distance <= 65.0*cm ) {
                G4VPhysicalVolume* physDetector = new G4PVPlacement(0, G4ThreeVector(x, y, 0.*cm), logicDetector, "physDetector", logicWorld, false, j + i * 100);
            }
        }   
    }

    /*
    G4Box* eCal = new G4Box("eCal", halfX, halfY, halfZ);

    G4LogicalVolume* logicECal = new G4LogicalVolume(eCal, lead, "LogicECal");

    G4VPhysicalVolume* physECal = new G4PVPlacement(0, G4ThreeVector(0., 0., 6.5*cm), logicECal, "physECal", logicWorld, false, 0, true);

    //Silicon Tracker
    G4Tubs* siliconSolid = new G4Tubs("siliconSolid", 0.*m, 66.*cm, 3.*cm, 0.*deg, 360.*deg);

    G4LogicalVolume* logicSilicon = new G4LogicalVolume(siliconSolid, Silicon, "logicSilicon");

    G4VPhysicalVolume* physSilicon1 = new G4PVPlacement(0, G4ThreeVector(0., 0., 193.*cm), logicSilicon, "physSilicon1", logicWorld, false, 0, true);
    G4VPhysicalVolume* physSilicon2 = new G4PVPlacement(0, G4ThreeVector(0., 0., 164.2*cm), logicSilicon, "physSilicon2", logicWorld, false, 0, true);
    G4VPhysicalVolume* physSilicon3 = new G4PVPlacement(0, G4ThreeVector(0., 0., 135.*cm), logicSilicon, "physSilicon3", logicWorld, false, 0, true);
    G4VPhysicalVolume* physSilicon4 = new G4PVPlacement(0, G4ThreeVector(0., 0., 105.8*cm), logicSilicon, "physSilicon4", logicWorld, false, 0, true);


    //Rich Mirror
    // Find or build the Aluminum material
    G4Material* Aluminum = nist->FindOrBuildMaterial("G4_Al");

    // Create a G4Cons solid
    G4Cons* consSolid = new G4Cons("consSolid", 70.*cm, 72.*cm, 65.*cm, 67.*cm, 32.5*cm, 0.*deg, 360.*deg);

    // Create a G4LogicalVolume for the consSolid with Aluminum as the material
    G4LogicalVolume* logicCons = new G4LogicalVolume(consSolid, Aluminum, "logicCons");

    // Create a physical volume at the specified location
    G4VPhysicalVolume* physCons = new G4PVPlacement(0, G4ThreeVector(0., 0., 50*cm), logicCons, "physCons", logicWorld, false, 0, true);

    // Create an optical surface
    G4OpticalSurface* optSurf = new G4OpticalSurface("optSurf");
    optSurf->SetType(dielectric_metal);
    optSurf->SetFinish(polished);
    optSurf->SetModel(glisur);

    // Set the reflectivity
    const G4int NUM = 2;
    G4double PP[NUM] = {2.038*eV, 4.144*eV};
    G4double reflectivity[NUM] = {0.85, 0.85};
    G4MaterialPropertiesTable* optSurfProp = new G4MaterialPropertiesTable();
    optSurfProp->AddProperty("REFLECTIVITY", PP, reflectivity, NUM);
    optSurf->SetMaterialPropertiesTable(optSurfProp);
    

    // Apply the optical surface to the consSolid
    new G4LogicalSkinSurface("consSkin", logicCons, optSurf);*/

    G4bool checkOverlaps = true; // Change this to false to disable overlap checking

    if (checkOverlaps)
    {
        G4cout << "Checking for overlaps..." << G4endl;
        physWorld->CheckOverlaps();
        G4cout << "Done." << G4endl;
    }

    return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
    MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector", dataStore);
    //MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

    logicDetector->SetSensitiveDetector(sensDet);
}
