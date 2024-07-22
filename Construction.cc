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

    G4Material* Poly = nist->FindOrBuildMaterial("G4_POLYCARBONATE");

    G4double rindexAerogel[40]; 
    std::fill_n(rindexAerogel, 40, 1.05);
    G4double rindexNaF[40];
    std::fill_n(rindexNaF, 40, 1.34);
    G4double rindexBoro[40];
    std::fill_n(rindexBoro, 40, 1.51446);
    G4double rindexWorld[40];
    std::fill_n(rindexWorld, 40, 1.0);
    G4double rindexPoly[40];
    std::fill_n(rindexPoly, 40, 1.58);

    G4double reflecPoly[40];
    std::fill_n(reflecPoly, 40, 0.975);
    
    G4MaterialPropertiesTable* mptAerogel = new G4MaterialPropertiesTable();
   
    Aerogel->SetMaterialPropertiesTable(mptAerogel);
    
    G4Material *worldMat = Vacuum;

    G4MaterialPropertiesTable* mptWorld  = new G4MaterialPropertiesTable();

    worldMat->SetMaterialPropertiesTable(mptWorld);

    G4MaterialPropertiesTable* mptPoly = new G4MaterialPropertiesTable();
    mptPoly->AddProperty("RINDEX", energy, rindexPoly, 40);
    mptPoly->AddProperty("REFLECTIVITY", energy, reflecPoly, 40);
    mptPoly->AddProperty("TRANSMITTANCE", energy, transmittancePoly, 40);

    Poly->SetMaterialPropertiesTable(mptPoly);

    G4MaterialPropertiesTable* mptBoro = new G4MaterialPropertiesTable();

    Borosilicate->SetMaterialPropertiesTable(mptBoro);

    G4Box* solidWorld = new G4Box("solidWorld", 1.38*m, 1.38*m, 3.5*m);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, Vacuum, "logicWorld");
    logicWorld->SetVisAttributes(invisible);
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
   
    G4double tileWidth = 18*cm;
    G4double tileHeight = 18*cm;
    G4double padding = 2.5*cm;
    G4Box* gelTile = new G4Box("gelTile", tileWidth, tileHeight, 1.25*cm);

    G4double effectiveTileWidth = tileWidth + padding;
    G4double effectiveTileHeight = tileHeight + padding;

    G4double areaWidth = 104*cm;
    G4double areaHeight = 104*cm;

    // Adjusted dimensions for the fillings
    G4double fillingWidth = effectiveTileWidth; // Or specific width of the gap
    G4double fillingHeight = padding - tileHeight; // Assuming padding is the gap between tiles
    G4double fillingDepth = 5*cm; // Adjusted depth of the filling

    G4Box* largeSquareSolid = new G4Box("LargeSquareSolid", largeSquareWidth/2, largeSquareHeight/2, fillingDepth/2);

    G4MultiUnion* tilesUnion = new G4MultiUnion("TilesUnion");
    G4MultiUnion* tilesUnion1 = new G4MultiUnion("TilesUnion1");

    for (G4int x = 0; x < 5; x++) {
        for (G4int y = 0; y < 5; y++) {
            G4double posX = x * effectiveTileWidth - areaWidth/2 + tileWidth/2;
            G4double posY = y * effectiveTileHeight - areaHeight/2 + tileHeight/2;

            G4Box* vacanciesSolid = new G4Box("TileSolid", tileWidth/2, tileHeight/2, fillingDepth/2);
            G4Transform3D transform = G4Transform3D(G4RotationMatrix(), G4ThreeVector(posX, posY, 0));
            tilesUnion->AddNode(*vacanciesSolid, transform);

            G4Box* tileSolid = new G4Box("Tile1Solid", tileWidth/2*.98, tileHeight/2*.98, fillingDepth/4*.98);
            tilesUnion1->AddNode(*tileSolid, transform);
        }
    }
    tilesUnion->Voxelize();
    tilesUnion1->Voxelize();

    G4SubtractionSolid* subtractedSolid = new G4SubtractionSolid("SubtractedSolid", largeSquareSolid, tilesUnion);

    G4LogicalVolume* logicSubtractedSolid = new G4LogicalVolume(subtractedSolid, Poly, "logicSubtractedSolid");
    logicSubtractedSolid->SetVisAttributes(blueColor);

    G4LogicalVolume* logicTilesUnion1 = new G4LogicalVolume(tilesUnion1, Aerogel, "logicTilesUnion");
    logicTilesUnion1->SetVisAttributes(redColor);

    G4ThreeVector position = G4ThreeVector(0, 0, 75*cm); 
    G4VPhysicalVolume* subsSolid = new G4PVPlacement(0, position, logicSubtractedSolid, "SubtractedFilling", logicWorld, false, 0, true);
    G4VPhysicalVolume* unionSolid = new G4PVPlacement(0, position, logicTilesUnion1, "TilesFilling", logicWorld, false, 0, true);

    G4Box *solidDetector = new G4Box("solidDetector", 8.5*mm, 8.5*mm, 5*mm); 
    logicDetector = new G4LogicalVolume(solidDetector, Borosilicate, "logicDetector");

    for (G4int i = 0; i < 120; i++) {
        for (G4int j = 0; j < 120; j++) {
            G4double x = -68 * cm + (i + 0.425) * m / 100;
            G4double y = -68 * cm + (j + 0.425) * m / 100;
            G4double distance = std::sqrt(x * x + y * y);

            G4VPhysicalVolume* physDetector = new G4PVPlacement(0, G4ThreeVector(x, y, 0.*cm), logicDetector, "physDetector", logicWorld, true, j + i);
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

    logicDetector->SetSensitiveDetector(sensDet);
}
