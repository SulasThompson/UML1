//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// This example is provided by the Geant4-DNA collaboration
// Any report or published results obtained using the Geant4-DNA software 
// shall cite the following Geant4-DNA collaboration publications:
// Med. Phys. 37 (2010) 4692-4708
// Phys. Med. 31 (2015) 861-874
// The Geant4-DNA web site is available at http://geant4-dna.org
//
/// \file medical/dna/svalue/src/PhysicsList.cc
/// \brief Implementation of the PhysicsList class

#include "PhysicsList.hh"
#include "PhysicsListMessenger.hh"

#include "G4EmDNAChemistry.hh"	//DST 20Aug2023
#include "G4EmDNAChemistry_option1.hh"	//DST 20Aug2023

#include "G4EmDNAPhysics.hh"
#include "G4EmDNAPhysics_option1.hh"
#include "G4EmDNAPhysics_option2.hh"
#include "G4EmDNAPhysics_option3.hh"
#include "G4EmDNAPhysics_option4.hh"
#include "G4EmDNAPhysics_option5.hh"
#include "G4EmDNAPhysics_option6.hh"
#include "G4EmDNAPhysics_option7.hh"
#include "G4EmDNAPhysics_option8.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

#include "CommandLineParser.hh"			//DST 20Aug23
#include "G4EmParameters.hh"			//DST 20Aug23
#include "G4UnitsTable.hh"
#include "G4PhysicsConstructorRegistry.hh"	//DST 20Aug23
#include "G4SystemOfUnits.hh"
#include "G4UserSpecialCuts.hh"

// particles

#include "G4BosonConstructor.hh"
#include "G4LeptonConstructor.hh"
#include "G4MesonConstructor.hh"
#include "G4BosonConstructor.hh"
#include "G4BaryonConstructor.hh"
#include "G4IonConstructor.hh"
#include "G4ShortLivedConstructor.hh"
#include "G4DNAGenericIonsManager.hh"

// decay

#include "G4RadioactiveDecayPhysics.hh"
#include "G4SystemOfUnits.hh"
#include "G4NuclideTable.hh"
#include "G4LossTableManager.hh"
#include "G4UAtomicDeexcitation.hh"
#include "G4NuclearLevelData.hh"
#include "G4DeexPrecoParameters.hh"
#include "G4NuclideTable.hh"
#include "G4GenericIon.hh"
#include "G4Electron.hh"

//DST 20Aug23........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::PhysicsList() : 
	G4VModularPhysicsList(),
  	fEmPhysicsList(0), 
	fMessenger(0),
	fEmDNAPhysicsList(nullptr),
	fEmDNAChemistryList(nullptr),
	fEmDNAChemistryList1(nullptr),
	fPhysDNAName("")
{
  fMessenger = new PhysicsListMessenger(this);
  SetVerboseLevel(1);

  // EM physics
  // fEmPhysicsList = new G4EmDNAPhysics();
  defaultCutValue = 1. * CLHEP::nm;

  G4double lowLimit = 10. * CLHEP::eV;
  G4double highLimit = 100. * CLHEP::GeV;

  G4ProductionCutsTable::GetProductionCutsTable()->
	SetEnergyRange(lowLimit, highLimit);

  // Change time and other limits in G4NuclideTable
  //
  G4NuclideTable::GetInstance()->SetThresholdOfHalfLife(0.1*picosecond);
  G4NuclideTable::GetInstance()->SetLevelTolerance(1.0*eV);
  
  fRadDecay = new G4RadioactiveDecayPhysics();

  RegisterConstructor("G4EmDNAPhysics");
  if(CommandLineParser::GetParser()->GetCommandIfActive("-chemOFF")==0)
    {
      RegisterConstructor("G4EmDNAChemistry");
    }

}

//DST 20Aug23........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PhysicsList::~PhysicsList()
{
  delete fMessenger;
  delete fEmPhysicsList;
  delete fRadDecay;
  delete fEmDNAPhysicsList;
  delete fEmDNAChemistryList;
  delete fEmDNAChemistryList1;
}

//reviewed 20Aug23........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::ConstructParticle()
{
  G4BosonConstructor  pBosonConstructor;
  pBosonConstructor.ConstructParticle();

  G4LeptonConstructor pLeptonConstructor;
  pLeptonConstructor.ConstructParticle();

  G4MesonConstructor pMesonConstructor;
  pMesonConstructor.ConstructParticle();

  G4BaryonConstructor pBaryonConstructor;
  pBaryonConstructor.ConstructParticle();

  G4IonConstructor pIonConstructor;
  pIonConstructor.ConstructParticle();

  G4DNAGenericIonsManager* genericIonsManager;
  genericIonsManager=G4DNAGenericIonsManager::Instance();
  genericIonsManager->GetIon("alpha++");
  genericIonsManager->GetIon("alpha+");
  genericIonsManager->GetIon("helium");
  genericIonsManager->GetIon("hydrogen");  
}

//DST 20Aug23........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::ConstructProcess()
{
  // transportation
  //
  AddTransportation();
  if(fEmDNAPhysicsList)    { fEmDNAPhysicsList->ConstructProcess(); }
  if(fEmDNAChemistryList)  { fEmDNAChemistryList->ConstructProcess(); }
  if(fEmDNAChemistryList1) { fEmDNAChemistryList1->ConstructProcess(); }
  if(fEmPhysicsList)	   { fEmPhysicsList->ConstructProcess(); }
      
  // tracking cut
  //
  AddTrackingCut();

  // raddecay
  //
  fRadDecay->ConstructProcess();
}

//DST 20Aug2023........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::RegisterConstructor(const G4String& name)
{
  if(name == fPhysDNAName) {return; }
  if (verboseLevel>0) {
    G4cout << "===== Register constructor ===== " << name << ">" << G4endl;
  }
  
  if(name == "G4EmDNAPhysics") {
    delete fEmDNAPhysicsList;
    fEmDNAPhysicsList = new G4EmDNAPhysics(verboseLevel);
    fPhysDNAName = name;
  } 
  else if(name == "G4EmDNAPhysics_option1") {
    delete fEmDNAPhysicsList;
    fEmDNAPhysicsList = new G4EmDNAPhysics_option1(verboseLevel);
    fPhysDNAName = name;
  }
  else if(name == "G4EmDNAPhysics_option2") {
    delete fEmDNAPhysicsList;
    fEmDNAPhysicsList = new G4EmDNAPhysics_option2(verboseLevel);
    fPhysDNAName = name;
  } 
  else if(name == "G4EmDNAPhysics_option3") {
    delete fEmDNAPhysicsList;
    fEmDNAPhysicsList = new G4EmDNAPhysics_option3(verboseLevel);
    fPhysDNAName = name;
  }
  else if(name == "G4EmDNAPhysics_option4") {
    delete fEmDNAPhysicsList;
    fEmDNAPhysicsList = new G4EmDNAPhysics_option4(verboseLevel);
    fPhysDNAName = name;
  }
  else if(name == "G4EmDNAPhysics_option5") {
    delete fEmDNAPhysicsList;
    fEmDNAPhysicsList = new G4EmDNAPhysics_option5(verboseLevel);
    fPhysDNAName = name;
  } 
  else if(name == "G4EmDNAPhysics_option6") {
    delete fEmDNAPhysicsList;
    fEmDNAPhysicsList = new G4EmDNAPhysics_option6(verboseLevel);
    fPhysDNAName = name;
  }
  else if(name == "G4EmDNAPhysics_option7") {
    delete fEmDNAPhysicsList;
    fEmDNAPhysicsList = new G4EmDNAPhysics_option7(verboseLevel);
    fPhysDNAName = name; 
  } 
  else if(name == "G4EmDNAPhysics_option8") {
    delete fEmDNAPhysicsList;
    fEmDNAPhysicsList = new G4EmDNAPhysics_option8(verboseLevel);
    fPhysDNAName = name;
  }
  else if (name == "G4EmDNAChemistry") {
    if(fEmDNAChemistryList || fEmDNAChemistryList1) {return; }
    fEmDNAChemistryList = new G4EmDNAChemistry();
    fEmDNAChemistryList->SetVerboseLevel(verboseLevel);
  }
  else if (name == "G4EmDNAChemistry_option1") {
    if(fEmDNAChemistryList || fEmDNAChemistryList1) { return; }
    fEmDNAChemistryList1 = new G4EmDNAChemistry_option1();
    fEmDNAChemistryList1->SetVerboseLevel(verboseLevel);
  }
// original 
  else if(name == "G4EmStandardPhysics_option3") {
    if(fEmPhysicsList3 || fEmPhysicsList4) { return; }
    fEmPhysicsList3 = new G4EmStandardPhysics_option3();
    fEmPhysicsList3->SetVerboseLevel(verboseLevel);
  }
  else if(name == "G4EmStandardPhysics_option4") {
    if(fEmPhysicsList3 || fEmPhysicsList4){ return; }  
    fEmPhysicsList4 = new G4EmStandardPhysics_option4();
    fEmPhysicsList4->SetVerboseLevel(verboseLevel);
  }
  else {
    G4cout << "PhysicsList::RegisterConstructor: <" << name << ">"
           << " is not defined"
           << G4endl;
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PhysicsList::AddTrackingCut()
{
  G4PhysicsListHelper* ph = G4PhysicsListHelper::GetPhysicsListHelper();
  ph->RegisterProcess(new G4UserSpecialCuts(), G4Electron::Electron()); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
