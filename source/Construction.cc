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

    G4double energy[75] = {
        1.77112 *eV, 1.78343 *eV, 1.79583 *eV, 1.80833 *eV, 1.82092 *eV,
        1.83361 *eV, 1.84639 *eV, 1.85927 *eV, 1.87225 *eV, 1.88533 *eV,
        1.89851 *eV, 1.91179 *eV, 1.92517 *eV, 1.93866 *eV, 1.95226 *eV,
        1.96596 *eV, 1.97977 *eV, 1.99369 *eV, 2.00773 *eV, 2.02188 *eV,
        2.03614 *eV, 2.05053 *eV, 2.06503 *eV, 2.07966 *eV, 2.09441 *eV,
        2.10928 *eV, 2.12428 *eV, 2.13941 *eV, 2.15467 *eV, 2.17006 *eV,
        2.18559 *eV, 2.20125 *eV, 2.21705 *eV, 2.23299 *eV, 2.24907 *eV,
        2.26530 *eV, 2.28168 *eV, 2.29821 *eV, 2.31489 *eV, 2.33172 *eV,
        2.34871 *eV, 2.36586 *eV, 2.38318 *eV, 2.40066 *eV, 2.41830 *eV,
        2.43612 *eV, 2.45411 *eV, 2.47227 *eV, 2.49062 *eV, 2.50915 *eV,
        2.52786 *eV, 2.54676 *eV, 2.56585 *eV, 2.58513 *eV, 2.60461 *eV,
        2.62429 *eV, 2.64417 *eV, 2.66426 *eV, 2.68456 *eV, 2.70507 *eV,
        2.72580 *eV, 2.74675 *eV, 2.76793 *eV, 2.78934 *eV, 2.81098 *eV,
        2.83286 *eV, 2.85498 *eV, 2.87735 *eV, 2.89997 *eV, 2.92284 *eV,
        2.94597 *eV, 2.96936 *eV, 2.99302 *eV, 3.01695 *eV, 3.04116 *eV
    };

    G4double rindexAerogel[75]; 
    std::fill_n(rindexAerogel, 75, 1.05);
    G4double rindexNaF[75];
    std::fill_n(rindexNaF, 75, 1.34);
    G4double rindexBoro[75];
    std::fill_n(rindexBoro, 75, 1.51446);
    G4double rindexWorld[75];
    std::fill_n(rindexWorld, 75, 1.0);
    G4double scatteringLength[75];
    std::fill_n(scatteringLength, 75, 4.5*cm);

    /*G4double Boro_QE[40] = {
    0.00011, 0.00014, 0.00019, 0.00025, 0.00032, 0.00041, 0.00054, 0.00072,
    0.00095, 0.00121, 0.0016, 0.00212, 0.00288, 0.00367, 0.0048, 0.0062,
    0.00821, 0.01115, 0.01402, 0.01857, 0.02427, 0.03092, 0.04042, 0.05151,
    0.061908, 0.07691, 0.097934, 0.113756, 0.134657, 0.145684, 0.168514, 0.20429,
    0.1917, 0.16982, 0.1441, 0.1051804, 0.08382, 0.06457, 0.01158, 0.02958
    };*/
    G4double Boro_QE[75];
    std::fill_n(Boro_QE, 75, 1.0);

    G4double transmittanceNaF[75];
    std::fill_n(transmittanceNaF, 75, 0.95);

    G4double transmittance[75];
    std::fill_n(transmittance, 75, 1.0);
    /*G4double transmittance[40] = {
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
    };*/
    
    G4MaterialPropertiesTable* mptAerogel = new G4MaterialPropertiesTable();
    mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 75);
    //mptAerogel->AddProperty("SCATTERING_LENGTH", energy, scatteringLength, 40, true);
    mptAerogel->AddProperty("TRANSMITTANCE", energy, transmittance, 75);
    Aerogel->SetMaterialPropertiesTable(mptAerogel);
    
    G4Material *worldMat = Vacuum;

    G4MaterialPropertiesTable* mptWorld  = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy, rindexWorld, 75);
    worldMat->SetMaterialPropertiesTable(mptWorld);

    G4MaterialPropertiesTable* mptBoro = new G4MaterialPropertiesTable();
    mptBoro->AddProperty("EFFICIENCY", energy, Boro_QE, 75);
    mptBoro->AddProperty("RINDEX", energy, rindexBoro, 75);
    Borosilicate->SetMaterialPropertiesTable(mptBoro);

    G4Box* solidWorld = new G4Box("solidWorld", 1.38*m, 1.38*m, 3.5*m);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, Vacuum, "logicWorld");
    logicWorld->SetVisAttributes(invisible);
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
   
    G4Tubs* circularRadiator = new G4Tubs("circularRadiator", 0.*m, 50*cm, 1*cm, 0.*deg, 360.*deg);

    G4double halfX = 65.0 * cm / 2; // Half-lengths
    G4double halfY = 65.0 * cm / 2;
    G4double halfZ = 13.0 * cm / 2;

    logicAero = new G4LogicalVolume(circularRadiator, Aerogel, "logicAero");
    logicAero->SetVisAttributes(redColor);

    G4VPhysicalVolume* physAero = new G4PVPlacement(0, G4ThreeVector(0., 0., 75*cm), logicAero, "physAero", logicWorld, false, 0, true);

    G4Box *solidDetector = new G4Box("solidDetector", 8.5*mm, 8.5*mm, 5*mm); 
    logicDetector = new G4LogicalVolume(solidDetector, Borosilicate, "logicDetector");


    for (G4int i = 0; i < 200; i++) {
        for (G4int j = 0; j < 200; j++) {
            G4double x = -68 * cm + (i + 0.425) * m / 100;
            G4double y = -68 * cm + (j + 0.425) * m / 100;
            G4double distance = std::sqrt(x * x + y * y);

            if (distance <= 65.0*cm ) {
                G4VPhysicalVolume* physDetector = new G4PVPlacement(0, G4ThreeVector(x, y, 0.*cm), logicDetector, "physDetector", logicWorld, false, j + i * 100);
            }
        }   
    }

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