#include "deletegates.h"
#include"..\Project Code Framework\ApplicationManager.h"
deletegates::deletegates(ApplicationManager* pApp) :Action(pApp)
{

}
deletegates::~deletegates(void) {



}
void deletegates::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMsg("delete gate");
	

}

//Execute action (code depends on action type)
void deletegates::Execute() {
	ReadActionParameters();
	int i=0;
	bool b;
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	
		
		
		
	
		//pIn->GetPointClicked(x, y);
		//b = pManager->getgate(x, y, i);
		

			pManager->makedelete();
		
			pOut->ClearDrawingArea();

}

//To undo this action (code depends on action type)
void deletegates::Undo()
{
}

//To redo this action (code depends on action type)
void deletegates::Redo() {

}