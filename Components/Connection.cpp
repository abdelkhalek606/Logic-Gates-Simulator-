#include "Connection.h"
#include <fstream>
#include <fstream>
#include "..\ApplicationManager.h"

int Connection::d = 0;

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin,int i,int i2):Component(r_GfxInfo)	
	
{
	

	x = i2;
	y = i;

	d++;
	id = d;
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}
void Connection::Drawh(Output* pOut, bool s) {

	pOut->DrawConnection(m_GfxInfo,true);
	
}

void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	/*C0nnection* p(r_GfxInfo, SrcPin, DstPin);
	SrcPin->ConnectTo(p);*/
	pOut->DrawConnection(m_GfxInfo);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}
void Connection::Savecomponent(ofstream& file, int u)///////////////////////////////////////////////
{
	file << id << " " <<  x << " " <<y << endl;
}