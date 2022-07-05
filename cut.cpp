#include "cut.h"
#include"ApplicationManager.h"

Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{

}
Cut::~Cut(void) {

}
void Cut::ReadActionParameters() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("CUT");





}
//Calculates the output according to the inputs



void Cut::Execute() {
	ReadActionParameters();
	pManager->cutfn();


}

//To undo this action (code depends on action type)
void Cut::Undo() {
}
//To redo this action (code depends on action type)
void Cut::Redo() {



}