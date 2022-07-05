#ifndef _Buffer_H
#define _Buffer_H
#include"Components/Gate.h"
class Buffer:public Gate
{
	static int d;
	int id;
	int x, y;
public:
	Buffer(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the LED gate
	virtual void Draw(Output* pOut);	//Draws LED
	virtual void Drawh(Output* pOut, bool s);
	virtual void Savecomponent(ofstream& file, int x);

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
};
#endif
