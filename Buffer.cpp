#include "Buffer.h"
#include <iostream>
#include <fstream>
int Buffer::d = 0;

void Buffer::Savecomponent(ofstream& file, int u)///////////////////////////////////////////////
{
	file << "Buff" << " " << u << " " << "Buff" << id << " " << x << " " << y << endl;
}
Buffer::Buffer(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	d++;
	x = r_GfxInfo.x1;
	y = r_GfxInfo.y1;

	id = d;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void Buffer::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here
	if (m_InputPins[0].getStatus() == STATUS::unsingn )
	{
		m_OutputPin.setStatus(unsingn);
		return;
	}
	m_OutputPin.setStatus(m_InputPins[0].getStatus());
	
	//m_OutputPin.setStatus(m_InputPins[0].getStatus() == STATUS::LOW ? STATUS::LOW : STATUS::HIGH);
}

// Function Draw
// Draws 1-input NOT gate
void Buffer::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBUFFER(m_GfxInfo);
}
void Buffer::Drawh(Output* pOut, bool s) {


	pOut->DrawBUFFER(m_GfxInfo, true);

}

//returns status of outputpin
int Buffer::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Buffer::GetInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Buffer::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}

