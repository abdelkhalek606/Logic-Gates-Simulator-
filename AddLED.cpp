#include "AddLED.h"
#include"ApplicationManager.h"
AddLED::AddLED(ApplicationManager* pApp) :Action(pApp)
{
}

AddLED::~AddLED(void)
{
}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("1-Input LED Component: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLED::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	if (Cx < 80 || Cy < 80 || Cx>1150)
		return;
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the NOT gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	pi[0] = new InputPin;
	LED* pA = new LED(GInfo, AND2_FANOUT,pi);
	pManager->AddComponent(pA);

	
	
	
	pManager->addgate(pA, pi, NULL, GInfo.x1, GInfo.y1, 1, 0,3);
}

void AddLED::Undo()
{}

void AddLED::Redo()
{}