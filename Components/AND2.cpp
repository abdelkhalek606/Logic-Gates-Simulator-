#include "AND2.h"
#include <iostream>
#include <fstream>
int AND2::d = 0;
AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
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


void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	//caclulate the output status as the ANDing of the two input pins
	bool and = 1;
	
	
	if((m_InputPins[1].getStatus() == STATUS::unsingn) || (m_InputPins[0].getStatus() == STATUS::unsingn))
		m_OutputPin.setStatus(unsingn);
	else
	{
		if ((m_InputPins[1].getStatus() == STATUS::HIGH) && (m_InputPins[0].getStatus() == STATUS::HIGH))
		{
			and = HIGH;
			m_OutputPin.setStatus(HIGH);
		}

		else
		{
			and = LOW;
			m_OutputPin.setStatus(LOW);
		}
	}
	//m_OutputPin.setStatus(and ? STATUS::HIGH : STATUS::LOW);
}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo);
	
}
 void AND2::Drawh(Output* pOut, bool s) {
	 if(s)
 pOut->DrawAND2(m_GfxInfo, true);
	 else
	 pOut->DrawAND2(m_GfxInfo);
}
//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}
void AND2::Savecomponent(ofstream& file, int u)///////////////////////////////////////////////
{
	file << "And" << " " << u << " " << "AND" << id << " " << x << " " << y << endl;
}
//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
