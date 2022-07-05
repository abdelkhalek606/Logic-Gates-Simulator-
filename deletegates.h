#pragma once
#include "Actions/Action.h"
class deletegates :
    public Action
{


	int x, y,x1,y1;
public:
	deletegates(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	virtual ~deletegates(void);
};

