#include "EventAction.hh"

EventAction::EventAction()
{}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event* event)
{
    // Get the analysis manager
    G4AnalysisManager* man = G4AnalysisManager::Instance();

    // Get the primary particles of the event
    G4ThreeVector position = event->GetPrimaryVertex()->GetPosition();
    G4ThreeVector momentum = event->GetPrimaryVertex()->GetPrimary()->GetMomentum();

    // Convert the G4ThreeVector to a std::vector<double>
    std::vector<double> positionComponents = {position.x(), position.y(), position.z()};
    std::vector<double> momentumComponents = {momentum.x(), momentum.y(), momentum.z()};

    // Fill the ntuple with the position of the primary particle
    for (size_t i = 0; i < positionComponents.size(); ++i)
    {
        man->FillNtupleDColumn(0, i, positionComponents[i]);
        man->FillNtupleDColumn(0, i + 3, momentumComponents[i]);
    }

    man->AddNtupleRow(0);
}

void EventAction::EndOfEventAction(const G4Event* event)
{}
