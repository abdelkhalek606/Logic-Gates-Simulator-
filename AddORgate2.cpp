#include "AddORgate2.h"

#include "..\Project Code Framework\ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddORgate2::~AddORgate2(void)
{
}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (Cx < 80 || Cy < 80 || Cx>1150)
		return;
	OR2* pA = new OR2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
	po = new OutputPin(1);
	pi[0] = new InputPin;
	pi[1] = new InputPin;
	
	pManager->addgate(pA, pi, po, GInfo.x1, GInfo.y1, 2,1,2);
}

void AddORgate2::Undo()
{}

void AddORgate2::Redo()
{}
