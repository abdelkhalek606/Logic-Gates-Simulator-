#pragma once
#include "Actions/Action.h"
#include "Components/Connection.h"
#include "ApplicationManager.h"
#include "Components/Gate.h"
class edit :
    public Action
{
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;
	GraphicsInfo mGfxInfo;			// The parameters (coordinates) required to draw the connection

	int x, y,x1,y1;
	//string ef;
	
public:
	edit(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
	virtual ~edit(void);
};

