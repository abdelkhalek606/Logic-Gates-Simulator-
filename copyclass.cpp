#include "copyclass.h"
#include"ApplicationManager.h"
copyclass::copyclass(ApplicationManager* pApp) :Action(pApp)
{
}

copyclass::~copyclass(void)
{
}

void copyclass::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("copy");

	//Wait for User Input
	
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void copyclass::Execute()
{
	//Get Center point of the Gate
	pManager->copyfn();

	
	
}

void copyclass::Undo()
{}

void copyclass::Redo()
{}
