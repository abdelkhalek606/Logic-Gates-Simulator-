#include "Addconnection.h"
#include"ApplicationManager.h"
#include"Components\AND2.h"
Addconnection::Addconnection(ApplicationManager* pApp) :Action(pApp)
{

}
void Addconnection::ReadActionParameters() {
	
	
	

	
}
void Addconnection::Operate() {
}	//Calculates the output according to the inputs
void Addconnection::Draw(Output* pOut) {
	

	
 }
void Addconnection::setSourcePin(OutputPin* pSrcPin)
{
	SrcPin = pSrcPin;
}

OutputPin* Addconnection::getSourcePin()
{
	return SrcPin;
}


void Addconnection::setDestPin(InputPin* pDstPin)
{
	DstPin = pDstPin;
}

InputPin* Addconnection::getDestPin()
{
	return DstPin;
}

void Addconnection::Execute() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("connection");
	int x, y, z, w;
	pIn->GetPointClicked(x, y);
	pIn->GetPointClicked(z, w);
	int x2, y2,x3,y3 ;
	bool m= pManager->getcorpout(x, y, SrcPin, x2, y2);
	bool s = pManager->getcorpin(z, w, DstPin, x3, y3);
	if ((m == false) || (s == false))
	{
		return;
	}
    int i;
	int i2;
    m = pManager->getgate(z, w, i2);
	s = pManager->getgate(x, y, i);
	if ((m == false) || (s == false))
	{
		return;
	}
    mGfxInfo.x1 = x2;
	mGfxInfo.y1 = y2;
	mGfxInfo.x2 = x3;
	mGfxInfo.y2 = y3;
	Connection *mConnections = new Connection(mGfxInfo, SrcPin, DstPin,i2,i);
	SrcPin->ConnectTo(mConnections);
	pManager->AddComponent(mConnections);
    
	pManager->addconct(mConnections,i2,i,  DstPin, SrcPin, mGfxInfo);
	
	
	
}

//To undo this action (code depends on action type)
void Addconnection::Undo(){
}
//To redo this action (code depends on action type)
void Addconnection::Redo() {



 }