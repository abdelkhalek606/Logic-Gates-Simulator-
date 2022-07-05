#pragma once
#include "Actions/Action.h"
class copyclass :
    public Action
{
private:
	int cx, cy;
public:
	copyclass(ApplicationManager* pApp);
	virtual ~copyclass(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

