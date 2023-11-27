#include "Generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleSource = new G4GeneralParticleSource; 
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleSource;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{
    //fParticleGun->GeneratePrimaryVertex(anEvent);
    fParticleSource->GeneratePrimaryVertex(anEvent);
}
