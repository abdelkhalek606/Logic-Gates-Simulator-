#include "Output.h"
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pOut, string msg) const
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar
	string s = "";
	char c;
	const int ESCAPE = 27;
	const int ENTER = 13;
	const int BACKSPACE = 8;
	pWind->FlushKeyQueue();
	do {
		pOut->PrintMsg(msg + " " + s);
		pWind->WaitKeyPress(c);
		switch (c)
		{
		case BACKSPACE:
			if (!s.empty()) s.pop_back();
			break;
		case ENTER:
			break;
		case ESCAPE:
			s.clear();
			break;
		default:
			s.push_back(c);
			break;
		}

	} while (c != ENTER && c != ESCAPE);

	return s;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NOT2: return ADD_NOT_GATE_2;
			case ITM_BUFFER: return ADD_Buff;
			case ITM_NAND: return ADD_NAND_GATE_2;
			case ITM_NOR: return ADD_NOR_GATE_2;
			case ITM_XOR: return ADD_XOR_GATE_2;
			case ITM_XNOR: return ADD_XNOR_GATE_2;
			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;
			case ITM_LED: return ADD_LED;
			case ITM_SWICH: return ADD_Switch;
			case ITM_WIRE: return ADD_CONNECTION;
			case ITM_SIMU: return SIM_MODE;
			case ITM_EXIT: return EXIT;
			case ITM_save:return SAVE;
			case ITM_DElET:return DEL;
			case ITM_copy: copyx;
			case ITM_paste: paste;

				//A click on empty place in desgin toolbar
			}

		}
		if (x >= 0 && x <= 90)
		{
			int ClickedItemOrder = (y / UI.ToolBarHeight) + 21;
			switch (ClickedItemOrder)
			{

			case ITM_EDIT: return EDIT;
			case ITM_UNDO: return UNDO;
			case ITM_cut: return cut;
			case ITM_copy: return copyx;
			case ITM_paste: return paste;
			case ITM_load: return load;

			case ITM_mulitple_selection: return mulitple_selection;



			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
			return SELECT;	//user want to select/unselect a component
		}
		if (x >= 1130)
		{
			int ClickedItemOrder = (y / UI.ToolBarHeight) + 14;
			switch (ClickedItemOrder)
			{

			case ITM_MOVE: return movex;
			case ITM_save: return save;
			case ITM_clear: return clear;
			case ITM_TEXT: return TEXT;
			case ITM_DElET: return deletex;
			case ITM_SELECT: return selectx;

			case ITM_EXIT: return EXIT;



			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
			return SELECT;	//user want to select/unselect a component
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		//application is in design mode

		//[1] If user clicks on the Toolbar
		if (y >= 0 && y <= UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / 80) + 29;
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder)
			{
			case Simulate_circuit: return SIM_MODE;
			case Create_Truth_Table:return Create_Truth_Tablex;
			case Circuit_Validation:return Circuit_Validationx;
			case Circuit_Probing:return Circuit_Probingx;
			case Switch_back_to_Design_Mode:return DSN_MODE;

			default: return DSN_TOOL;
				//A click on empty place in desgin toolbar
			}

			//This should be changed after creating the compelete simulation bar 


		}
		return SELECT;
	}
}

Input::~Input()
{
}
