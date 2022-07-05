#include "AND3.h"
#include <iostream>
#include <fstream>
int AND3::d = 0;

void AND3::Savecomponent(ofstream& file, int u)///////////////////////////////////////////////
{
	file << "And3" << " " << u << " " << "AND3" << id << " " << x << " " << y << endl;
}
AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
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


void AND3::Operate()
{
	if (m_InputPins[0].getStatus() == STATUS::unsingn || m_InputPins[1].getStatus() == STATUS::unsingn || m_InputPins[2].getStatus() == STATUS::unsingn)
	{
		m_OutputPin.setStatus(unsingn);
		return;
	}
	//caclulate the output status as the ANDing of the two input pins
	STATUS and3 = HIGH;
		if ( (m_InputPins[0].getStatus() == STATUS::HIGH) &&(m_InputPins[1].getStatus() == STATUS::HIGH) &&(m_InputPins[2].getStatus() == STATUS::HIGH))
		{
			and3 = HIGH;
		}
		else
		{
			and3 = LOW;
		}	
		m_OutputPin.setStatus(and3 ? STATUS::HIGH : STATUS::LOW);

}


// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo);
}
void AND3::Drawh(Output* pOut, bool s) {


		pOut->DrawAND3(m_GfxInfo, true);
	
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}



