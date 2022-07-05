#include "crictsvaldiation.h"
#include "ApplicationManager.h"

crictsvaldiation::crictsvaldiation(ApplicationManager* pApp) :Action(pApp)
{
}

crictsvaldiation::~crictsvaldiation(void)
{
}
void  crictsvaldiation::ClearDrawingArea() const {
	pWind->SetPen(BLUE);
	pWind->SetBrush(BLUE);
	pWind->DrawRectangle(0, 0, 700, 600);
}
void crictsvaldiation::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pWind = new window(265 , 150 , 500, 100);
	pWind->ChangeTitle("Circts Valadiation");
	ClearDrawingArea();
	bool b=pManager->makevalid();
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(RED);
	if(b)
	pWind->DrawString(50, 50, "circts valid");
	else
	pWind->DrawString(50, 50, "circts not valid");
	DrawExit();
	int x, y;
	pWind->WaitMouseClick(x, y);
	while (!(x >= 80 && y <= 80)) {
		pWind->WaitMouseClick(x, y);
	}
	delete pWind;

}
void crictsvaldiation::DrawExit() {

	string GateImage;

	GateImage = "Images\\Menu\\Menu_Exit.jpg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info

	pWind->DrawImage(GateImage, 200, 0, UI.AND2_Width, UI.AND2_Height);

}

void crictsvaldiation::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	


	
}

void crictsvaldiation::Undo()
{}

void crictsvaldiation::Redo()
{}


