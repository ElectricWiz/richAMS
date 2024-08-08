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

double energy[75] = {
    4.0845e-04, 4.0868e-04, 4.0934e-04, 4.0997e-04, 4.1229e-04,
    4.1569e-04, 4.2015e-04, 4.2417e-04, 4.2571e-04, 4.3237e-04,
    4.3829e-04, 4.4015e-04, 4.4702e-04, 4.4912e-04, 4.5686e-04,
    4.5921e-04, 4.6781e-04, 4.7988e-04, 4.9307e-04, 5.0738e-04,
    5.2271e-04, 5.3917e-04, 5.5676e-04, 5.7546e-04, 5.9528e-04,
    6.1623e-04, 6.3830e-04, 6.6151e-04, 6.8584e-04, 7.1129e-04,
    7.3787e-04, 7.6558e-04, 7.9442e-04, 8.2440e-04, 8.5551e-04,
    8.8776e-04, 9.2114e-04, 9.5567e-04, 9.9134e-04, 1.0378e-03,
    1.0865e-03, 1.1365e-03, 1.1889e-03, 1.2428e-03, 1.2981e-03,
    1.3548e-03, 1.4129e-03, 1.4725e-03, 1.5336e-03, 1.5961e-03,
    1.6601e-03, 1.7255e-03, 1.7925e-03, 1.8610e-03, 1.9310e-03,
    2.0025e-03, 2.0756e-03, 2.1502e-03, 2.2263e-03, 2.3039e-03,
    2.3829e-03, 2.4635e-03, 2.5456e-03, 2.6292e-03, 2.7143e-03,
    2.8008e-03, 2.8888e-03, 2.9783e-03, 3.0693e-03, 3.1618e-03,
    3.2558e-03, 3.3512e-03, 3.4481e-03, 3.5466e-03, 3.6465e-03,
};

    G4double R[75] = {
        0.06776260375407021, 0.07250505463097864, 0.07706165329291238, 0.08134603838400604, 
        0.0852718485483944, 0.08875272243021205, 0.09170229867359377, 0.09403443215835468, 
        0.09574988795844963, 0.0970689630025123, 0.09824608411269421, 0.098373401691414, 
        0.09140638884035494, 0.07353989494108314, 0.06388159658407894, 0.07225844260311536, 
        0.09030095628876406, 0.1088900010421039, 0.12026594835542696, 0.12701178532975937, 
        0.1341013710131415, 0.1411823818740704, 0.14696171305731073, 0.14873718811854855, 
        0.14583738606410132, 0.140468781880982, 0.13487002351552602, 0.1311186288695421, 
        0.13127902037112146, 0.1374156204483555, 0.15118462553724668, 0.16722070506981582, 
        0.17805293956668589, 0.1837896079908594, 0.1854740291690793, 0.18749926675856965, 
        0.2460299299992107, 0.3038665244214025, 0.33444714227211947, 0.3603318644829715, 
        0.39605655047211274, 0.40971879682433454, 0.41626047961954704, 0.4262697958319545, 
        0.43889771918784404, 0.4532952234135029, 0.4686132822352186, 0.484002869379278, 
        0.4986149585719683, 0.5116005235395766, 0.5220994443017845, 0.5291045235098863, 
        0.5315043001109887, 0.528185101053793, 0.5180332532870008, 0.5003070482823373, 
        0.47615285905335164, 0.446805127855331, 0.41342170597834127, 0.3771604447124487, 
        0.3391791953477186, 0.3006358091742176, 0.2626881374820121, 0.22649403156116726, 
        0.19321134270175006, 0.16399792219382575, 0.14001162132746078, 0.12241029139272139, 
        0.11235178367967323, 0.1109939494783826, 0.11949464007891548, 0.13901170677133776, 
        0.1707030008457159, 0.2157263735921153, 0.2752396763006029
    };

    G4double qEff[75] = {
        0.00014538996609165133, 0.00011222381582466183, 0.0002027391544937607, 0.00034147076707899425, 
        0.0004529591250951721, 0.0005384897847005704, 0.0008609653322792138, 0.001261040522134119, 
        0.0015465279224417522, 0.0021322658418033882, 0.0032882276351686063, 0.0045827885676723307, 
        0.00620603879305214, 0.007827162764334116, 0.009781344538414416, 0.013117311141489678, 
        0.014101948571040595, 0.017975155365179716, 0.02686701140659026, 0.030126721770009333, 
        0.032814208694492053, 0.036877465368716855, 0.04164108185053855, 0.04655952520342255, 
        0.05173972797424921, 0.057458126446521085, 0.06406105189068677, 0.07191084035404383, 
        0.08042356797295035, 0.08818085902104734, 0.09462886907094074, 0.10065873614367634, 
        0.10729266827003778, 0.11511973352518075, 0.12345489745280954, 0.13138003105100326, 
        0.13815453993295375, 0.1440307184430338, 0.14960585354692745, 0.15547757708443312, 
        0.16209904373752217, 0.16921627283401765, 0.17635927936006144, 0.1830580245560519, 
        0.18885151512360643, 0.19350525516959383, 0.1970229977205807, 0.19941569301713475, 
        0.20070029129982412, 0.20090131786624244, 0.2002693834254343, 0.1992594543838609, 
        0.1983338815867976, 0.1978606725935813, 0.19790646087267262, 0.1984777309233421, 
        0.1994749395039714, 0.20049100835120548, 0.20106570537717193, 0.20083412912177177, 
        0.1995590584969674, 0.19701220330396904, 0.19301305250094806, 0.1879114396900934, 
        0.18238780838114987, 0.17712761591142176, 0.1724591878394609, 0.16715051575933074, 
        0.15954357143151567, 0.14798031700502607, 0.13091310329424557, 0.10721712736779986, 
        0.07755013177313627, 0.0554403726689102, 0.06036337304853092
    };

    G4double rindexAero[75] = {
        1.028201552199032, 1.0282082575770488, 1.0282151367898855, 1.028222195928183,
        1.028229441352989, 1.0282368797103658, 1.028244517946926, 1.0282523633263754,
        1.0282604234471302, 1.0282687062610925, 1.028277220093674, 1.0282859736651613,
        1.0282949761135285, 1.0283042370188114, 1.0283137664291646, 1.0283235748887407,
        1.0283336734675346, 1.0283440737933587, 1.0283547880861195, 1.028365829194596,
        1.028377210635923, 1.0283889466380185, 1.0284010521852038, 1.0284135430673016,
        1.0284264359325135, 1.0284397483444232, 1.028453498843491, 1.0284677070134598,
        1.0284823935531222, 1.0284975803539573, 1.0285132905841936, 1.0285295487799175,
        1.028546380943918, 1.0285638146530272, 1.0285818791748174, 1.0286006055945935,
        1.0286200269537522, 1.028640178400686, 1.0286610973555639, 1.0286828236904795,
        1.0287053999266347, 1.0287288714504492, 1.0287532867507125, 1.028778697679176,
        1.0288051597372967, 1.0288327323922029, 1.0288614794253643, 1.028891469317939,
        1.0289227756773076, 1.028955477709966, 1.0289896607466753, 1.0290254168266522,
        1.0290628453485884, 1.029102053797478, 1.029143158557631, 1.0291862858238825,
        1.0292315726249583, 1.0292791679752422, 1.0293292341739264, 1.0293819482737707,
        1.0294375037455916, 1.0294961123692623, 1.029558006387635, 1.0296234409665932,
        1.0296926970127007, 1.0297660844099894, 1.0298439457497528, 1.0299266606424025,
        1.0300146507192012, 1.0301083854550084, 1.0302083889723155, 1.0303152480234419,
        1.0304296213940294, 1.0305522510297842, 1.0306839752637118
    }; 

    G4double absLengths[75] = {
        2.9395*cm, 2.9605*cm, 2.9816*cm, 3.0027*cm, 3.0239*cm,
        3.0452*cm, 3.0665*cm, 3.0880*cm, 3.1095*cm, 3.1310*cm,
        3.1527*cm, 3.1744*cm, 3.1962*cm, 3.2181*cm, 3.2401*cm,
        3.2621*cm, 3.2842*cm, 3.3064*cm, 3.3286*cm, 3.3509*cm,
        3.3733*cm, 3.3958*cm, 3.4184*cm, 3.4410*cm, 3.4637*cm,
        3.4865*cm, 3.5093*cm, 3.5322*cm, 3.5552*cm, 3.5783*cm,
        3.6014*cm, 3.6247*cm, 3.6480*cm, 3.6713*cm, 3.6948*cm,
        3.7183*cm, 3.7419*cm, 3.7656*cm, 3.7893*cm, 3.8131*cm,
        3.8370*cm, 3.8610*cm, 3.8850*cm, 3.9091*cm, 3.9333*cm,
        3.9576*cm, 3.9819*cm, 4.0064*cm, 4.0308*cm, 4.0554*cm,
        4.0800*cm, 4.1048*cm, 4.1295*cm, 4.1544*cm, 4.1793*cm,
        4.2043*cm, 4.2294*cm, 4.2545*cm, 4.2798*cm, 4.3051*cm,
        4.3305*cm, 4.3560*cm, 4.3816*cm, 4.4072*cm, 4.4330*cm,
        4.4588*cm, 4.4847*cm, 4.5107*cm, 4.5368*cm, 4.5630*cm,
        4.5893*cm, 4.6157*cm, 4.6422*cm, 4.6688*cm, 22.6815*cm
    };

    G4double scatLengths[75] = {
    0.9226*cm, 0.9359*cm, 0.9492*cm, 0.9627*cm, 0.9764*cm,
    0.9902*cm, 1.0041*cm, 1.0182*cm, 1.0324*cm, 1.0468*cm,
    1.0613*cm, 1.0760*cm, 1.0908*cm, 1.1058*cm, 1.1210*cm,
    1.1362*cm, 1.1517*cm, 1.1673*cm, 1.1831*cm, 1.1990*cm,
    1.2151*cm, 1.2313*cm, 1.2477*cm, 1.2643*cm, 1.2810*cm,
    1.2979*cm, 1.3150*cm, 1.3322*cm, 1.3496*cm, 1.3672*cm,
    1.3850*cm, 1.4029*cm, 1.4210*cm, 1.4392*cm, 1.4577*cm,
    1.4763*cm, 1.4951*cm, 1.5141*cm, 1.5332*cm, 1.5525*cm,
    1.5721*cm, 1.5918*cm, 1.6116*cm, 1.6317*cm, 1.6520*cm,
    1.6724*cm, 1.6931*cm, 1.7139*cm, 1.7349*cm, 1.7561*cm,
    1.7775*cm, 1.7991*cm, 1.8209*cm, 1.8429*cm, 1.8651*cm,
    1.8875*cm, 1.9101*cm, 1.9329*cm, 1.9559*cm, 1.9791*cm,
    2.0025*cm, 2.0261*cm, 2.0499*cm, 2.0739*cm, 2.0982*cm,
    2.1226*cm, 2.1473*cm, 2.1722*cm, 2.1973*cm, 2.2226*cm,
    2.2481*cm, 2.2739*cm, 2.2999*cm, 2.3261*cm, 2.3525*cm
    };

   G4double aeroTrans[75] = {
    0.0819, 0.0519, 0.0301, 0.0152, 0.0062, 
    0.0018, 0.0010, 0.0025, 0.0052, 0.0080, 
    0.0096, 0.0090, 0.0067, 0.0122, 0.0634, 
    0.0751, 0.1002, 0.1210, 0.1362, 0.1456, 
    0.1529, 0.1585, 0.1626, 0.1652, 0.1660, 
    0.1647, 0.1624, 0.1607, 0.1538, 0.1344, 
    0.1252, 0.1214, 0.1197, 0.1176, 0.1125, 
    0.1024, 0.0950, 0.0810, 0.0534, 0.0313, 
    0.0168, 0.0195, 0.0200, 0.0176, 0.0128, 
    0.0082, 0.0060, 0.0073, 0.0117, 0.0166, 
    0.0202, 0.0225, 0.0234, 0.0231, 0.0215, 
    0.0188, 0.0150, 0.0101, 0.0055, 0.0037, 
    0.0057, 0.0093, 0.0126, 0.0148, 0.0162, 
    0.0169, 0.0171, 0.0169, 0.0164, 0.0152, 
    0.0132, 0.0104, 0.0077, 0.0060, 0.0057
    };

    G4double rindexBoro[75];
    std::fill_n(rindexBoro, 75, 1.51446);
    G4double rindexWorld[75];
    std::fill_n(rindexWorld, 75, 1.0);
    //G4double rindexPoly[75];
    //std::fill_n(rindexPoly, 75, 1.58);

    //G4double reflecPoly[75];
    //std::fill_n(reflecPoly, 75, 0.975);
    
    //G4double transPoly[75];
    //std::fill_n(reflecPoly, 75, 0.33);

    G4MaterialPropertiesTable* mptAerogel = new G4MaterialPropertiesTable();
    mptAerogel->AddProperty("RINDEX", energy, rindexAero, 75);
    mptAerogel->AddProperty("ABSLENGTH", energy, absLengths, 75);
    mptAerogel->AddProperty("REFLECTIVITY", energy, R, 75);
    mptAerogel->AddProperty("TRANSMITTANCE", energy, aeroTrans, 75);
    mptAerogel->AddProperty("RAYLEIGH", energy, scatLengths, 75);
    Aerogel->SetMaterialPropertiesTable(mptAerogel);
    
    G4Material *worldMat = Vacuum;

    G4MaterialPropertiesTable* mptWorld  = new G4MaterialPropertiesTable();

    worldMat->SetMaterialPropertiesTable(mptWorld);

    //G4MaterialPropertiesTable* mptPoly = new G4MaterialPropertiesTable();
    //mptPoly->AddProperty("RINDEX", energy, rindexPoly, 75);
    //mptPoly->AddProperty("REFLECTIVITY", energy, reflecPoly, 75);
    //mptPoly->AddProperty("TRANSMITTANCE", energy, transPoly, 75);
    //Poly->SetMaterialPropertiesTable(mptPoly);

    G4MaterialPropertiesTable* mptBoro = new G4MaterialPropertiesTable();
    mptBoro->AddProperty("EFFICIENCY", energy, qEff, 75);
    Borosilicate->SetMaterialPropertiesTable(mptBoro);

G4Box* solidWorld = new G4Box("solidWorld", 1.38*m, 1.38*m, 3.5*m);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, Vacuum, "logicWorld");
    logicWorld->SetVisAttributes(invisible);
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
   
    G4Tubs* circularRadiator = new G4Tubs("circularRadiator", 0.*m, 50*cm, 2*cm, 0.*deg, 360.*deg);

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
