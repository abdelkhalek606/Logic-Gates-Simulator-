#pragma once
#include "Actions/Action.h"
#include"..\Project Code Framework\ApplicationManager.h"

class crictsvaldiation :
    public Action
{
	window* pWind;

public:
	crictsvaldiation(ApplicationManager* pApp);
	virtual ~crictsvaldiation(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	void DrawExit();
	void ClearDrawingArea() const;

	virtual void Undo();
	virtual void Redo();
};

