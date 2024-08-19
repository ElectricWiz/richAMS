#include "Generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleSource = new G4GeneralParticleSource();

    fParticleGun = new G4ParticleGun(1);

    G4ThreeVector position(0., 0., 150.*cm);
    fParticleGun->SetParticlePosition(position);

    G4ThreeVector momentumDirection(0., 0., -1.);
    fParticleGun->SetParticleMomentumDirection(momentumDirection);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleSource;
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{
    fParticleSource->GeneratePrimaryVertex(anEvent);
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
