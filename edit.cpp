#include "edit.h"
#include"..\Project Code Framework\ApplicationManager.h"
edit::edit(ApplicationManager* pApp) :Action(pApp)
{

}
edit::~edit(void) {



}
void edit::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	
	pOut->PrintMsg("edit");
	string msg;

	pOut->ClearStatusBar();

	string s = pIn->GetSrting(pOut, msg);
	pOut->PrintMsg2(msg);
	 string ef = s;
	
	if (ef == "1")
	{

		
		

		pManager->makeedit(ef, x, y, x1, y1);
		pIn->GetPointClicked(x, y);
		pOut->ClearDrawingArea();
		int x2, y2, x3, y3;
		bool m = pManager->getcorpout(x1, y1, SrcPin, x2, y2);
		
		bool s = pManager->getcorpin(x, y, DstPin, x3, y3);
		
			
		if ((m == false) || (s == false))
		{
	

			return;
		}
		int i;
		int i2;
		m = pManager->getgate(x1-10,y1-10 , i);
		s = pManager->getgate(x, y, i2);
		
		

		if ((m == false) || (s == false))
		{

			return;

		}
		mGfxInfo.x1 = x2;
		mGfxInfo.y1 = y2;
		mGfxInfo.x2 = x3;
		mGfxInfo.y2 = y3;
		Connection* mConnections = new Connection(mGfxInfo, SrcPin, DstPin,  i2, i);
		SrcPin->ConnectTo(mConnections);
		pManager->AddComponent(mConnections);
		
		pManager->addconct(mConnections, i2, i, DstPin, SrcPin, mGfxInfo);


	}
	else  if (ef == "2")
	{
		pManager->makeedit(ef, x, y, x1, y1);
		pIn->GetPointClicked(x, y);
		pOut->ClearDrawingArea();

		int x2, y2, x3, y3;
		bool m = pManager->getcorpout(x, y, SrcPin, x2, y2);
		bool s = pManager->getcorpin(x1, y1, DstPin, x3, y3);
		if ((m == false) || (s == false))
		{
		return;	
		}
		int i;
		int i2;
		m = pManager->getgate(x1, y1, i2);
		s = pManager->getgate(x, y, i);
		if ((m == false) || (s == false))
		{
			return;
		}
		mGfxInfo.x1 = x2;
		mGfxInfo.y1 = y2;
		mGfxInfo.x2 = x3;
		mGfxInfo.y2 = y3;
		Connection* mConnections = new Connection(mGfxInfo, SrcPin, DstPin, i2, i);
		SrcPin->ConnectTo(mConnections);
		pManager->AddComponent(mConnections);

		pManager->addconct(mConnections, i2, i, DstPin, SrcPin, mGfxInfo);
		pOut->ClearDrawingArea();


		

	}
	else  if (ef == "3")
	{
		pIn->GetPointClicked(x, y);
		pManager->makeedit(ef, x, y, x1, y1);
		string msg;
		pOut->ClearStatusBar();
		string s = pIn->GetSrting(pOut, msg);
		pOut->PrintMsg2(msg);
		pIn->GetPointClicked(x, y);
		pOut->DrawLabel(x, y, s);
		pManager->getstr(s, x, y);


		pOut->ClearDrawingArea();

	}

}

//Execute action (code depends on action type)
void edit::Execute() {
	ReadActionParameters();
	
}

//To undo this action (code depends on action type)
void edit::Undo()
{
}

//To redo this action (code depends on action type)
void edit::Redo() {

}