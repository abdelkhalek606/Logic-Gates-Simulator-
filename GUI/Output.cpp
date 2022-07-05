#include "Output.h"
Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
void Output::PrintMsg2(string msg) const
{
	ClearStatusBar();
	int MsgX = 100;
	int MsgY = 100;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}

//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(90, UI.ToolBarHeight + 10, 1120, UI.height - UI.StatusBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::ClearDrawingArea2() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);

	pWind->DrawRectangle(0, 0, 1220, UI.ToolBarHeight + 10);
	pWind->DrawRectangle(0, 80, 90, 650);
	pWind->DrawRectangle(1120, 80, 1220, 650);
	pWind->SetPen(RED, 3);


	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item

	string MenuItemImages[ITM_DSN_CNT];


	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_NOT2] = "images\\Menu\\Menu_NOT2.jpg";
	MenuItemImages[ITM_NOR] = "images\\Menu\\NOR.jpeg";
	MenuItemImages[ITM_NAND] = "images\\Menu\\NAND.jpeg";
	MenuItemImages[ITM_XOR] = "images\\Menu\\XOR.jpeg";
	MenuItemImages[ITM_XNOR] = "images\\Menu\\XNOR.jpeg";
	MenuItemImages[ITM_BUFFER] = "images\\Menu\\BUFFER.jpeg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\AND3y.jpeg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\XOR3y.jpeg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\NOR3y.jpeg";
	MenuItemImages[ITM_LED] = "images\\Menu\\LED.jpeg";
	MenuItemImages[ITM_SWICH] = "images\\Menu\\SWCH.jpeg";
	MenuItemImages[ITM_MOVE] = "images\\Menu\\MOVE.jpeg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_TEXT] = "images\\Menu\\TEXT.jpeg";
	MenuItemImages[ITM_clear] = "images\\Menu\\clear.jpeg";
	MenuItemImages[ITM_save] = "images\\Menu\\save.jpeg";
	MenuItemImages[ITM_DElET] = "images\\Menu\\DELET.jpeg";
	MenuItemImages[ITM_SELECT] = "images\\Menu\\SELECT.jpeg";
	MenuItemImages[ITM_SIMU] = "images\\Menu\\SIMU.jpeg";
	MenuItemImages[ITM_cut] = "images\\Menu\\cut.jpeg";
	MenuItemImages[ITM_copy] = "images\\Menu\\copy.jpeg";
	MenuItemImages[ITM_paste] = "images\\Menu\\paste.jpeg";
	MenuItemImages[ITM_EDIT] = "images\\Menu\\edit.jpeg";
	MenuItemImages[ITM_load] = "images\\Menu\\load.jpeg";
	MenuItemImages[ITM_mulitple_selection] = "images\\Menu\\multiple_selection.jpeg";
	MenuItemImages[ITM_WIRE] = "images\\Menu\\wire.jpeg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\undo.jpeg";
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < 15; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);

	for (int i = 22; i < 29; i++)
		pWind->DrawImage(MenuItemImages[i], 0, (i - 21) * UI.ToolItemWidth, UI.ToolItemWidth, UI.ToolBarHeight);
	for (int i = 15; i < 22; i++)
		pWind->DrawImage(MenuItemImages[i], 1130, (i - 14) * UI.ToolItemWidth, UI.ToolItemWidth, UI.ToolBarHeight);
		
		//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	pWind->DrawLine(80, 80, 80, 650);
	pWind->DrawLine(1130, 80, 1130, 650);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	string MenuItemImages[ITM_DSN_CNT];



	MenuItemImages[Switch_back_to_Design_Mode] = "images\\Menu\\DESIGN.jpeg";
	MenuItemImages[Circuit_Probing] = "images\\Menu\\cricuit_probing.jpeg";

	MenuItemImages[Circuit_Validation] = "images\\Menu\\circuit_validation.jpeg";
	MenuItemImages[Simulate_circuit] = "images\\Menu\\SIMU.jpeg";
	MenuItemImages[Create_Truth_Table] = "images\\Menu\\TRUTH_TABLE.jpeg";


	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 29; i < 34; i++)
		pWind->DrawImage(MenuItemImages[i], (i - 29) * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);



	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\AND3r.jpeg";
	else
		GateImage = "Images\\Gates\\AND3.jpeg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\OR_h.JPEG";
	else
		GateImage = "Images\\Gates\\Gate_OR2n.JPEG";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOT2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NOT_h.JPEG";
	else
		GateImage = "Images\\Gates\\NOT_n.JPEG";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\buffer_h.jpeg";
	else
		GateImage = "Images\\Gates\\buffer_n.jpeg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawLabel(int x, int y, const string label) const {
	int w, h;
	pWind->SetPen(UI.MsgColor);
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->GetStringSize(w, h, label);


	pWind->DrawString(x, y, label);
}
void Output::DrawNOR(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NOR_h.jpeg";
	else
		GateImage = "Images\\Gates\\NOR_n.jpeg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NOR3r.jpeg";
	else
		GateImage = "Images\\Gates\\NOR3.jpeg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNAND(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NAND_h.jpeg";
	else
		GateImage = "Images\\Gates\\NAND_n.jpeg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\XOR_h.jpeg";
	else
		GateImage = "Images\\Gates\\XOR_n.jpeg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\XOR3r.jpeg";
	else
		GateImage = "Images\\Gates\\XOR3.jpeg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXNOR(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\XNOR_h.jpeg";
	else
		GateImage = "Images\\Gates\\XNOR_n.jpeg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
//TODO: Add similar functions to draw all components
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED.jpeg";
	else
		GateImage = "Images\\Gates\\LEDH.jpeg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::Drawswech(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\SWICHH.jpeg";
	else
		GateImage = "Images\\Gates\\SWCH.jpeg";


	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	if (selected)	//use image in the highlighted case
	{
		pWind->SetPen(RED, 3);

		if (r_GfxInfo.y1 == r_GfxInfo.y2)
		{
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
		}
		else
		{
			
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x2+ r_GfxInfo.x1)/2, r_GfxInfo.y1);
			pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2);
			pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2, r_GfxInfo.x2 , r_GfxInfo.y2);
		}
	}
	else
	{
		pWind->SetPen(BLACK, 3);
		if (r_GfxInfo.y1 == r_GfxInfo.y2)
		{
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
		}
		else
		{
			
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1);
			pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2);
			pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
		}
	}
	//TODO: Add code to draw connection
}


Output::~Output()
{
	delete pWind;
}