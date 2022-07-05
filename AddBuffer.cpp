#include "AddBuffer.h"
#include"ApplicationManager.h"
AddBuffer::AddBuffer(ApplicationManager* pApp) :Action(pApp)
{
}

AddBuffer::~AddBuffer(void)
{
}

void AddBuffer::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("1-Input Buffer Component: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBuffer::Execute()
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

	Buffer* pA = new Buffer(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
	po = new OutputPin(2);
	pi[0] = new InputPin;




	pManager->addgate(pA, pi, po, GInfo.x1, GInfo.y1, 1, 1,11);
}

void AddBuffer::Undo()
{}

void AddBuffer::Redo()
{}