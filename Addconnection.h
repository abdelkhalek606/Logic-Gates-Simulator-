
#pragma once
#include "..\Project Code Framework\Actions\Action.h"
#include "Components/Connection.h"
#include "ApplicationManager.h"
#include "Components/Gate.h"

class Addconnection :
    public Action
{
    private:

		bool mIsLoaded;					// Indicates if the action is loaded from the file
		int mDstPinIndex;				// The index of the destination pin
		GraphicsInfo mGfxInfo;			// The parameters (coordinates) required to draw the connection
			
		string mLabel;					// The label of the component
		Pin* mSrcPin;					// Pointer to the source pin
		Pin* mDstPin;					// Pointer to the destination pin
		Connection* mConnection;		// Pointer to the added connection
		OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
		InputPin* DstPin;

public:
	Addconnection(ApplicationManager* pApp);

	virtual void Execute() ;
	
	//To undo this action (code depends on action type)
	virtual void Undo() ;

	//To redo this action (code depends on action type)
	virtual void Redo() ;

    void ReadActionParameters();
	virtual void Operate();	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);
	void setSourcePin(OutputPin* pSrcPin);
	void setDestPin(InputPin* pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();
};