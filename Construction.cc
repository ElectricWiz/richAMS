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

    G4double aeroAbs[75] = {
        0.2181104922530788, 0.2179474334068302, 0.21525023835525804, 0.21055069034634446,
        0.20438057262807156, 0.19727166844842134, 0.1897557610553759, 0.18191644046395822,
        0.17126896710192337, 0.15604524707012406, 0.14965110213203262, 0.16741999801666797,
        0.1806018174469025, 0.14161977077290308, 0.1007826239503456, 0.08348017288999834,
        0.07509779689951026, 0.07571589698932416, 0.07914379345037317, 0.0797349592216438,
        0.07763662404183278, 0.0764958900343558, 0.07837762775519003, 0.07805981754393495,
        0.07693190806075573, 0.07649833486344441, 0.07701869964495658, 0.07872124928218831,
        0.08111223399375764, 0.08255853333819132, 0.08228042643897671, 0.08178696416967515,
        0.08263743788603497, 0.08416916703384706, 0.08511163527257514, 0.08673909473693508,
        0.0912498936513192, 0.0999395515166527, 0.11206820652116123, 0.12307820265472147,
        0.13231894538297684, 0.13877424783812817, 0.13450346393723894, 0.1290616712594279,
        0.15883477271931053, 0.16907482106057614, 0.17234365246674074, 0.16283029230768083,
        0.15477586972531121, 0.14702039585803055, 0.13983045886226222, 0.13513175805422755,
        0.13340580640460955, 0.13502892685929934, 0.1403774423641882, 0.14981422172909106,
        0.1629400369071109, 0.17488221668762463, 0.1800831752603124, 0.25289755873584795,
        0.23765751144206384, 0.189681269612388, 0.15681722832000736, 0.14182464244349228,
        0.14052875586134189, 0.1469900569538468, 0.15525511580362641, 0.15932262684172803,
        0.15879314134340316, 0.16055665862430846, 0.17047234209057955, 0.17835463794499894,
        0.19402309713964648, 0.20705001082949593, 0.18684674961171247
    };

    G4double qEff[75] = {
            0.06036337304853092, 0.0554403726689102, 0.07755013177313627, 0.10721712736779986,
            0.13091310329424557, 0.14798031700502607, 0.15954357143151567, 0.16715051575933074,
            0.1724591878394609, 0.17712761591142176, 0.18238780838114987, 0.1879114396900934,
            0.19301305250094806, 0.19701220330396904, 0.1995590584969674, 0.20083412912177177,
            0.20106570537717193, 0.20049100835120548, 0.1994749395039714, 0.1984777309233421,
            0.19790646087267262, 0.1978606725935813, 0.1983338815867976, 0.1992594543838609,
            0.2002693834254343, 0.20090131786624244, 0.20070029129982412, 0.19941569301713475,
            0.1970229977205807, 0.19350525516959383, 0.18885151512360643, 0.1830580245560519,
            0.17635927936006144, 0.16921627283401765, 0.16209904373752217, 0.15547757708443312,
            0.14960585354692745, 0.1440307184430338, 0.13815453993295375, 0.13138003105100326,
            0.12345489745280954, 0.11511973352518075, 0.10729266827003778, 0.10065873614367634,
            0.09462886907094074, 0.08818085902104734, 0.08042356797295035, 0.07191084035404383,
            0.06406105189068677, 0.057458126446521085, 0.05173972797424921, 0.04655952520342255,
            0.04164108185053855, 0.036877465368716855, 0.032814208694492053, 0.030126721770009333,
            0.02686701140659026, 0.017975155365179716, 0.014101948571040595, 0.013117311141489678,
            0.009781344538414416, 0.007827162764334116, 0.00620603879305214, 0.0045827885676723307,
            0.0032882276351686063, 0.0021322658418033882, 0.0015465279224417522, 0.001261040522134119,
            0.0008609653322792138, 0.0005384897847005704, 0.0004529591250951721, 0.00034147076707899425,
            0.0002027391544937607, 0.00011222381582466183, 0.00014538996609165133
        };

    G4double S[75] = {
        0.17324406627758865, 0.13356882957257804, 0.1463205071655447, 0.15038427212841713,
        0.13997686782754565, 0.13928159224052365, 0.1544837152642323, 0.18067466822990884,
        0.19214104733954056, 0.18762141644628272, 0.1792680655937568, 0.1768951991833123,
        0.18241074137900775, 0.19526454327280135, 0.20616218802777162, 0.21206335240099886,
        0.2213269904362201, 0.23090338676775104, 0.236107329558705, 0.23769147159067803,
        0.23682757592655904, 0.23468740562923635, 0.2324427237615987, 0.23126374339633863,
        0.23162683410561517, 0.23222398810450247, 0.23147259461338017, 0.22853862242053157,
        0.22392152302880287, 0.21825839489647684, 0.21218610475198012, 0.2063021878018766,
        0.2011208078165686, 0.19714549722659935, 0.1947535563044182, 0.1926603931899541,
        0.18840903827917774, 0.1795182111573543, 0.1663134439165934, 0.15734196757788467,
        0.15381674757943076, 0.15330657040723128, 0.15337695236847654, 0.15169397057845117,
        0.14628844775146263, 0.13926447012451234, 0.13505341507171835, 0.13384910183698016,
        0.13447856558489663, 0.13576830776703353, 0.13655656025338237, 0.13619695549351501,
        0.13474918338057796, 0.13232761651411023, 0.12912578996494174, 0.1254144689483029,
        0.1218067732817601, 0.11968806165622428, 0.11872318328310339, 0.11742672320003571,
        0.1142990186174171, 0.11058143163987417, 0.11282938842374614, 0.11464695017894366,
        0.11235421621644509, 0.10983335948711085, 0.1083854297543656, 0.10722535383364379,
        0.10542356587672293, 0.10271856656620608, 0.10028032698361738, 0.09915726306685123,
        0.09830337676480571, 0.09645168095199066, 0.09401370040940412
    };

    G4double rindexAero[75] = {
        1.0306839752637118, 1.0305522510297842, 1.0304296213940294, 1.0303152480234419,
        1.0302083889723155, 1.0301083854550084, 1.0300146507192012, 1.0299266606424025,
        1.0298439457497528, 1.0297660844099894, 1.0296926970127007, 1.0296234409665932,
        1.029558006387635, 1.0294961123692623, 1.0294375037455916, 1.0293819482737707,
        1.0293292341739264, 1.0292791679752422, 1.0292315726249583, 1.0291862858238825,
        1.029143158557631, 1.029102053797478, 1.0290628453485884, 1.0290254168266522,
        1.0289896607466753, 1.028955477709966, 1.0289227756773076, 1.028891469317939,
        1.0288614794253643, 1.0288327323922029, 1.0288051597372967, 1.028778697679176,
        1.0287532867507125, 1.0287288714504492, 1.0287053999266347, 1.0286828236904795,
        1.0286610973555639, 1.028640178400686, 1.0286200269537522, 1.0286006055945935,
        1.0285818791748174, 1.0285638146530272, 1.028546380943918, 1.0285295487799175,
        1.0285132905841936, 1.0284975803539573, 1.0284823935531222, 1.0284677070134598,
        1.028453498843491, 1.0284397483444232, 1.0284264359325135, 1.0284135430673016,
        1.0284010521852038, 1.0283889466380185, 1.028377210635923, 1.028365829194596,
        1.0283547880861195, 1.0283440737933587, 1.0283336734675346, 1.0283235748887407,
        1.0283137664291646, 1.0283042370188114, 1.0282949761135285, 1.0282859736651613,
        1.028277220093674, 1.0282687062610925, 1.0282604234471302, 1.0282523633263754,
        1.028244517946926, 1.0282368797103658, 1.028229441352989, 1.028222195928183,
        1.0282151367898855, 1.0282082575770488, 1.028201552199032
    };
    G4double rindexBoro[75];
    std::fill_n(rindexBoro, 75, 1.51446);
    G4double rindexWorld[75];
    std::fill_n(rindexWorld, 75, 1.0);
    G4double rindexPoly[75];
    std::fill_n(rindexPoly, 75, 1.58);

    G4double reflecPoly[75];
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
