#pragma once
#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\truthtable.h"
#include"AddORgate2.h"
#include"Addconnection.h"
#include"Components\Connection.h"
#include"selectgate.h"
#include"deletegates.h"
#include"lable.h"
#include"edit.h"
#include"AddLED.h"
#include"AddSWITCH.h"
#include"simulate.h"
#include "crictsvaldiation.h"
#include "AddNANDgate2.h"
#include "AddNORgate2.h"
#include "AddANDgate3.h"
#include "AddNORgate3.h"
#include "AddXNORgate2.h"
#include "AddXORgate2.h"
#include "AddXORgate3.h"
#include "AddBuffer.h"
#include "AddNOTgate.h"
#include"Save.h"
#include "propclass.h"
#include"load.h"
#include <iostream>
#include <fstream>
#include "Components/Connection.h"
#include"copyclass.h"
#include"pasteclass.h"
#include"cut.h"
ApplicationManager::ApplicationManager()
{
	coporpate = false;
	sm = 0;
	swcount = 0;
	ledcount = 0;
	CompCount = 0;
	countpin = 0;
	countstring = 0;
	countpout = 0;
	ccg = 0;
	cconct = 0;
	cs = -55;
	is = -55;
	igdelete = 500;
	indpin = new int* [50];
	truth = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		swch[i] = -5;
		led[i] = -5;
		truth[i] = new int[32];
	}
	for (int i = 0; i < 50; i++) {
		inp[i] = 0;
		iop[i] = 0;
		x1con[i] = 0;
		y1con[i]=0;
		x2con[i]=0;
		y2con[i]=0;
		p1[i]=-55;
		p2[i] = -55;
			conct[i] = NULL;
			indpin[i] = new int [50];
			
			nsw[i] = 0;
			nlw[i] = 0;
	}

	
	is = 5454;
	for (int i = 0; i < MaxCompCount; i++)
	{
		CompList[i] = NULL;
		gates[i] = NULL;
	}

	for (int i = 0; i < 50; i++)
	{
		pi[i] = NULL;

		po[i] = NULL;
		for (int y = 0; y < 50; y++)
			indpin[y][i] = 0;

	}
	//Creates the Input / Output Objects & Initialize the GUI

	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
	
	
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
				break;
		case ADD_CONNECTION:
			OutputInterface->PrintMsg("addconnction");
			pAct = new Addconnection(this) ;
			
			//TODO: Create AddConection Action here
			break;
		case SIM_MODE:
			UI.AppMode = MODE::SIMULATION;
			OutputInterface->ClearDrawingArea2();
			OutputInterface->CreateSimulationToolBar();
			sm++;
			pAct = new simulate(this);
			break;
		case  ADD_NOT_GATE_2:
			pAct = new AddNOTgate(this);
			break;
		case  ADD_Buff:
			pAct = new AddBuffer(this);
			break;

		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case save:
			pAct = new Save(this);
			
			break;
		case cut:
			pAct = new Cut(this);

			break;
		case copyx:
			pAct = new copyclass(this);

			break;
		case paste:
			pAct = new pasteclass(this);

			break;
		case load:
			pAct = new 	Load(this);
		
			break;

		case  ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);

			break;
		case  ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);

			break;
		case  ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);

			break;
		case  ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);

			break;
		case  ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);

			break;
			case ADD_XOR_GATE_3:
				pAct = new AddXORgate3(this);

				break;

		case TEXT:
			pAct = new lable(this);
			break;
		case ADD_Switch:
			pAct = new AddSWITCH(this);
			ns++;
			break;
		case ADD_LED:
			pAct = new AddLED(this);
			nl++;
			break;
		case Circuit_Probingx:
			pAct = new propclass(this);
			break;
		case DSN_MODE:
			UI.AppMode = MODE::DESIGN;
			OutputInterface->ClearDrawingArea2();
			OutputInterface->CreateDesignToolBar();
			sm = 0;
			break;
		case deletex:
			pAct = new deletegates(this);
			break;
		case Circuit_Validationx:
			pAct = new crictsvaldiation(this);

			break;
		case Create_Truth_Tablex:
			pAct = new truthtable(this);
			
			break;
		case EDIT:
			pAct = new edit(this);
			break;
		case selectx :
			pAct = new selectgate(this);
			
			
			break;
		case EXIT:
			UI.AppMode = MODE::SIMULATION;
			OutputInterface->ClearDrawingArea();
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	
	if (UI.AppMode == MODE::SIMULATION)
		return;

	for (int i = 0; i < ccg; i++)
	{
		if (i ==is)
		{
			
			gates[i]->Drawh(OutputInterface, true);
			
		}
		else
		{
			gates[i]->Draw(OutputInterface);

		}
	}
	for (int i = 0; i < cconct; i++) {
		if (i==cs)
			conct[i]->Drawh(OutputInterface,true);
		else
		conct[i]->Draw(OutputInterface);
	}

	makestring();


}
void  ApplicationManager::makeselect(int i,int c) {

	is = i;
	cs=c;
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

bool ApplicationManager::getcorpin(int x, int y, InputPin*&p ,int &x2,int &y2) {

	for (int i = 0; i < countpin+1; i++)
	{
		if ((x >= xpi[i] - 20) && (x <= xpi[i] + 30) && (y >= ypi[i] - 7) && (y <= ypi[i] + 7))
		{

			p = pi[i];
			x2 = xpi[i];
			y2 = ypi[i];
			
			return true;
	    }
		
		
	}
	
	return false;
}
bool ApplicationManager::getcorpout(int x, int y, OutputPin *&p,int& x2, int& y2) {
	for (int i = 0; i < countpout; i++  )
	{
		if((x<=xpo[i]+20)&&(x>=xpo[i]-20)&&(y>=ypo[i]-10)&&(y<=ypo[i]+20))
		{
			p = po[i];
			x2 = xpo[i];
			y2 = ypo[i];
			return true;

		}
     }
	
	return false;

}
void ApplicationManager::addgate(Component*p, InputPin** l, OutputPin* r,int x,int y,int c,int o,int nom) {
	gates[ccg] = p;
	xg[ccg] = x;
	yg[ccg] = y;
	
	inp[ccg] = c;
	iop[ccg] = o;
	nim[ccg] = nom;
	for (int i = 0; i < o; i++) {
		po[countpout] = r;
		xpo[countpout] = x + 50;
		ypo[countpout] = y + 25;
		countpout++;
	}
	if (c == 0 && o == 1)
	{
		
		swch[swcount] = ccg;
		swcount++;

	}
	
	for (int i = 0; i < c;i++) {
		indpin[ccg][i] = countpin+i;

		}
	
	for (int i = 0; i < c; i++)
	{
		if (c == 1 && o == 0)
		{
			pi[countpin] = l[i];
			xpi[countpin] = x + 20;
			ypi[countpin] = y + 40;
			led[ledcount] = ccg;
			ledcount++;
			countpin++;


		}
		
		else {
			pi[countpin] = l[i];
			if (i == 0 && c == 1)
			{
				xpi[countpin] = x + 10;
				ypi[countpin] = y + 25;
			}
			else if (i == 0) {
				xpi[countpin] = x + 10;
				ypi[countpin] = y + 10;
			}
			else if (i == 1) {
				xpi[countpin] = x + 10;
				ypi[countpin] = y + 40;
			}
			else {
				xpi[countpin] = x + 10;
				ypi[countpin] = y + 25;
			}
			countpin++;

		}

	}
	ccg++;

}
void ApplicationManager::addconct(Component* p,int i,int i2,InputPin*&c, OutputPin*&j, const GraphicsInfo& r_GfxInfo) {
	conct[cconct] = p;

	
	p1[cconct] = i;
	p2[cconct] = i2;
	x1con[cconct]= r_GfxInfo.x1;
	y1con[cconct]= r_GfxInfo.y1;
	x2con[cconct]= r_GfxInfo.x2;
    y2con[cconct]= r_GfxInfo.y2;
	iop[i2]++;
	for (int k = 0; k < swcount;k++)
		if (swch[k] == i2)
			nsw[k] ++;
	cconct++;
	

}
bool ApplicationManager::getconct(int x, int y, int& i) {
	for (int k = 0; k < cconct; k++)
	{
		if (y1con[k] == y2con[k])
		{
			if((x<x2con[k]&&x>x1con[k])|| (x>x2con[k] && x<x1con[k]))
				if (y<y2con[k] + 5 && y>y2con[k] - 5)
				{
					i = k;
					return true;

				}
		}
		else {
			if ((x<x1con[k]+(x2con[k]-x1con[k])/2 && x>x1con[k]) || (x>x1con[k] + (x2con[k] - x1con[k]) / 2 && x<x1con[k]))
				if ((y<y1con[k] + 5 && y>y1con[k] - 5)|| (y<y2con[k] + 5 && y>y2con[k] - 5))
				{
					i = k;
					return true;

				}
			if ((x>x2con[k] - (x2con[k] - x1con[k]) / 2 && x<x2con[k]) || (x <x2con[k] - (x2con[k] - x1con[k]) / 2 && x > x2con[k]))
				if ((y<y1con[k] + 20 && y>y1con[k] - 5) || (y<y2con[k] + 20 && y>y2con[k] - 5))
				{
					i = k;
					return true;

				}
			if ((y > y2con[k]  && y < y1con[k]) || (y <y2con[k]  && y > y1con[k]))
				if (x> (x1con[k] + (x2con[k] - x1con[k]) / 2) - 5 && x< x2con[k] - ((x2con[k] - x1con[k]) / 2) + 5)
				{
					i = k;
					return true;

				}

		}

	}
	return false;
}
bool ApplicationManager::getgate(int x, int y, int& i2) {
	bool m = false;
	for (int i = 0; i < ccg; i++)
	{
		if ((x >= xg[i] ) && (x <= xg[i] + 50) && (y >= yg[i]) && (y <= yg[i] + 50))
		{
			i2 = i;
			igdelete = i;
			m = true;
			break;
		}
	}

	return m;
}
STATUS  ApplicationManager::prop(int x, int y) {
	InputPin *pp;
	OutputPin *ppo;
	int c, d;
	bool b= getcorpin(x, y, pp, c, d);
	bool b1=getcorpout(x, y, ppo, c, d);
	if(b)
	return pp->getStatus();
	if (b1)
	return ppo->getStatus();
	return unsingn;

}

void  ApplicationManager::makedelete() {
	

	if (is < 0&&cs<0)
	{
		return;
	}
	if (cs >= 0)
	{
		for (int i = 0; i < swcount; i++)
			if (p2[cs] == swch[i])
				nsw[i]--;
		for (int i = 0; i < cconct; i++)
		{
			if(i==cs)
			{
				for (int k = i; k < cconct; k++)
				{
					conct[k] = conct[k + 1];
					p1[k] = p1[k + 1];
					p2[k] = p2[k + 1];
					x1con[k] = x1con[k + 1];
					x2con[k] = x2con[k + 1];
                	y2con[k] = y2con[k + 1];
					y1con[k] = y1con[k + 1];


				}
				cconct--;
				break;
				
			}
		}
		
		cs = -55;
		return;
	}
	int c;
	
		 c = is;
		igdelete = is;
		
	for (int i = is; i < ccg ; i++)
	{

		gates[i] = gates[i + 1];
		xg[i] = xg[i + 1];
		yg[i] = yg[i + 1];
		nim[i] = nim[i + 1];
		
		
		int b;
			
		     b = indpin[c][0];
			for (int k = b; k < b + inp[c]; k++) {

				xpi[k] = 0;
				ypi[k] = 0;
				
			}
		
			
	}
	for (int l = 0; l < inp[igdelete + 1]; l++)
	indpin[igdelete][l] = indpin[igdelete + 1][l];
	
	
	igdelete = -5;
	
	
		for (int k = 0; k < ledcount; k++)
			if (c < led[k])
			{
				led[k]--;
			}
	
		for (int k = 0; k < swcount; k++)
			if (c< swch[k])
			{
				swch[k]--;
			}
		

		
		
		
   for (int i = 0; i < cconct; i++)
	{

		if (p1[i] == is || p2[i] == is)
		{
			for (int k = i; k < cconct; k++)
			{
				conct[k] = conct[k + 1];
				p1[k] = p1[k +1];
				p2[k] = p2[k+1];
				x1con[k] = x1con[k + 1];
				x2con[k] = x2con[k + 1];
				y2con[k] = y2con[k + 1];
               y1con[k] = y1con[k + 1];	
			}
			i--;
			cconct--;
		}
	}
   
   for (int k = is; k < ccg; k++)
   {
	   inp[k] = inp[k + 1];
	   iop[k] = iop[k + 1];

   }
   is = -55;
   makestring();
   ccg--;
}

void ApplicationManager::makeedit(string ed ,int x,int y,int &x1,int &y1 ) {
	if (ed == "1") {
		

		if (cs < 0)
			return;

		
		x1 = x1con[cs];
		y1 = y1con[cs];
		makedelete();
		
		cs = -55;
	
	}
	else if (ed == "2") {
		if (cs < 0)
			return;

		
		x1 = x2con[cs];
		y1 = y2con[cs];
		makedelete();
	}
	else if (ed == "3") {
		for (int i = 0; i < countstring; i++)
		{
			if ((xs[i] < x) && (xs[i] + 50 > x) && (ys[i] < y) && (ys[i] + 20 > y))
			{
				lab[i] = "\0";
				xs[i] = 0;
				ys[i] = 0;
			}

		}
	}
	
}
void ApplicationManager::makestring() {
	for (int i = 0; i < countstring; i++)
		OutputInterface->DrawLabel(xs[i],ys[i],lab[i]);
}
void ApplicationManager::getstr(string d,int x,int y) {
	lab[countstring] = d;
	xs[countstring] = x;
	ys[countstring] = y;
		countstring++;

}
bool ApplicationManager::getswch(int x, int y, int& i2) {
	int e=-5;
	getgate(x, y, e);
	for (int i = 0; i < swcount; i++)
		if (e == swch[i])
		{
			i2 = e;
			return true;
		}
	return false;

}
void ApplicationManager::makesim(int sch) {
	int c = 0;
	int n = 0;
	int s[5];
	int sd;
	bool bol;
	bol = makevalid();
	if (!bol)
		return;
	int secc = 0;
	for (int sin = 0; sin < ccg; sin++) {
		if (swch[0] == sin || swch[1] == sin || swch[2] == sin || swch[3] == sin || led[0] == sin || led[1] == sin || led[2] == sin)
		{
		}
		else
		{

			for (int i = 0; i < inp[sin]; i++)
				gates[sin]->setInputPinStatus(i + 1, unsingn);
			gates[sin]->Operate();
		}
	}
	for (int i = 0; i < cconct; i++)
	{
		conct[i]->setInputPinStatus(2, unsingn);
		conct[i]->Operate();
	}
	secc = 0;
		for (int k = 0; k < swcount; k++)
		{
			
				
				if (gates[swch[k]]->GetOutPinStatus() == HIGH)
				{
					gates[swch[k]]->Drawh(OutputInterface, true);
				}
				else {

					gates[swch[k]]->Draw(OutputInterface);
				}
				
			    for (int r = secc; r < cconct; r++)
				        if (p2[r] == swch[k])
						{
							conct[r]->setInputPinStatus(2, (STATUS)gates[swch[k]]->GetOutPinStatus());
							if ((STATUS)gates[swch[k]]->GetOutPinStatus() == HIGH)
								conct[r]->Drawh(OutputInterface, true);
							else
								conct[r]->Draw(OutputInterface);
							conct[r]->Operate();
							secc = r + 1;
							
						
				        }

					secc = 0;

				
			
		}
	for (int o = 0; o < swcount; o++) {

		if (swch[o] == sch) {
			gates[sch]->Operate();
			if (gates[swch[o]]->GetOutPinStatus() == HIGH)
			{
				gates[swch[o]]->Drawh(OutputInterface, true);
			}
			else {

				gates[swch[o]]->Draw(OutputInterface);
			}

			
				for (int r = secc; r < cconct; r++)
					if (p2[r] == sch)
					{
						conct[r]->setInputPinStatus(2, (STATUS)gates[swch[o]]->GetOutPinStatus());
						conct[r]->Operate();

						if ((STATUS)conct[r]->GetOutPinStatus() == HIGH)
							conct[r]->Drawh(OutputInterface, true);
						else
							conct[r]->Draw(OutputInterface);
						secc = r + 1;
						
						
					}
				secc = 0;

			
		}


	}

	
	for (int sin = 0; sin < ccg; sin++) {
		if (swch[0] == sin || swch[1] == sin || swch[2] == sin || swch[3] == sin || led[0] == sin || led[1] == sin || led[2] == sin)
		{
		}
		else
			while (gates[sin]->GetOutPinStatus() == unsingn)
            	for (int j = 0; j < ccg; j++)
				{

					if (swch[0] == j || swch[1] == j || swch[2] == j || swch[3] == j || led[0] == j || led[1] == j || led[2] == j)
					{
					}
					else {
						secc = 0;
						for (int a = 0; a < inp[j]; a++)
						{
							for (int r = secc; r < cconct; r++) {
								if (p1[r] == j) {
									if (conct[r]->GetOutPinStatus() != unsingn)

									
										gates[j]->setInputPinStatus(a + 1, (STATUS)conct[r]->GetOutPinStatus());
										secc = r + 1;

										break;
									


								}
							}
						}
						secc = 0;
						gates[j]->Operate();

						if (gates[j]->GetOutPinStatus() != unsingn) {


							for (int f = 0; f < iop[j]; f++)
							{
								for (int r = secc; r < cconct; r++)
									if (p2[r] == j) {
										conct[r]->setInputPinStatus(2, (STATUS)gates[j]->GetOutPinStatus());
										conct[r]->Operate();

										if ((STATUS)conct[r]->GetOutPinStatus() == HIGH)
											conct[r]->Drawh(OutputInterface, true);
										else
											conct[r]->Draw(OutputInterface);
										secc = r + 1;
										c++;
										break;
									}
							}
							secc = 0;
						}
					}
				}
	}
	for (int k = 0; k < ledcount; k++) {
		gates[led[k]]->Operate();
	}
	for (int k = 0; k < ledcount; k++) {


		if (gates[led[k]]->GetInputPinStatus(0) == 0)
		{
			gates[led[k]]->Draw(OutputInterface);

		}
		else {

			gates[led[k]]->Drawh(OutputInterface, true);

		}
	}
	
}
bool ApplicationManager::makevalid() {
	int cinput=0;
	for (int i = 0; i < ccg; i++)
		for (int j = 0; j < inp[i]; j++)
			cinput++;
	if (cconct == cinput)
	{
		return true;

	}
	else
	{
		return false;

	}

}
int** ApplicationManager::maketruthtable(int** comp) {
	bool bol;
	bol = makevalid();
	if (!bol)
		return 0;
	compin = comp;
	for (int tr = 0; tr < pow(2, swcount); tr++)
	{

		
		int secc = 0;
		for (int sin = 0; sin < ccg; sin++) {
			if (swch[0] == sin || swch[1] == sin || swch[2] == sin || swch[3] == sin || led[0] == sin || led[1] == sin || led[2] == sin)
			{
			}
			else
			{

				for (int i = 0; i < inp[sin]; i++)
					gates[sin]->setInputPinStatus(i + 1, unsingn);
				gates[sin]->Operate();
			}
		}
		for (int i = 0; i < cconct; i++)
		{
			conct[i]->setInputPinStatus(2, unsingn);
			conct[i]->Operate();
		}
		for (int k = 0; k < swcount; k++)
		{
			STATUS gh;
			if (comp[k][tr] == 0)
				gh = LOW;
			else if(comp[k][tr] == 1)
				gh = HIGH;

			gates[swch[k]]->setInputPinStatus(2,gh);
		}
		for (int k = 0; k < swcount; k++)
		{
			

			
			for (int r = secc; r < cconct; r++)
				if (p2[r] == swch[k])
				{
					conct[r]->setInputPinStatus(2, (STATUS)gates[swch[k]]->GetOutPinStatus());
					
					conct[r]->Operate();
					secc = r + 1;


				}

			secc = 0;



		}
		

		for (int sin = 0; sin < ccg; sin++) {
			if (swch[0] == sin || swch[1] == sin || swch[2] == sin || swch[3] == sin || led[0] == sin || led[1] == sin || led[2] == sin)
			{
			}
			else
				while (gates[sin]->GetOutPinStatus() == unsingn)
					for (int j = 0; j < ccg; j++)
					{

						if (swch[0] == j || swch[1] == j || swch[2] == j || swch[3] == j || led[0] == j || led[1] == j || led[2] == j)
						{
						}
						else {
							secc = 0;
							for (int a = 0; a < inp[j]; a++)
							{
								for (int r = secc; r < cconct; r++) {
									if (p1[r] == j) {
										if (conct[r]->GetOutPinStatus() != unsingn)


											gates[j]->setInputPinStatus(a + 1, (STATUS)conct[r]->GetOutPinStatus());
										secc = r + 1;

										break;



									}
								}
							}
							secc = 0;
							gates[j]->Operate();

							if (gates[j]->GetOutPinStatus() != unsingn) {


								for (int f = 0; f < iop[j]; f++)
								{
									for (int r = secc; r < cconct; r++)
										if (p2[r] == j) {
											conct[r]->setInputPinStatus(2, (STATUS)gates[j]->GetOutPinStatus());
											conct[r]->Operate();

											
											secc = r + 1;
											
											break;
										}
								}
								secc = 0;
							}
						}
					}
		}
		for (int k = 0; k < ledcount; k++) {
			gates[led[k]]->Operate();
		}
		for (int k = 0; k < ledcount; k++) {


			if (gates[led[k]]->GetInputPinStatus(1) == LOW)
			{
				truth[k][tr] = 0;
				

			}
			else if(gates[led[k]]->GetInputPinStatus(1) == HIGH){

				truth[k][tr] = 1;


			}
		}
	}
	if(truth[0][1]==1|| truth[0][1] == 0)
	

	return truth;

}
void ApplicationManager::getcount(int& s, int&l) {
	s = swcount;
	l = ledcount;
}
void ApplicationManager::copyfn() {
	coped = gates[is];
	ic = is;
	coporpate = false;

}
void ApplicationManager::cutfn() {
	coped = gates[is];
	ic = is;
	coporpate = true;

}

void ApplicationManager::peste(int Cx,int Cy) {
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	if (ic<0)
		return;
	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (Cx < 80 || Cy < 80 || Cx>1150)
		return;
	OutputPin* poo;
	InputPin* pii[3];
	for (int i = 0; i < iop[ic]; i++)
		poo = new OutputPin(1);
	if (iop[is] == 0)
		poo = NULL;
	for (int i = 0; i < inp[ic]; i++)
	{
		pii[i] = new InputPin;

	}
	if (nim[is] == 1)
		coped = new AND2(GInfo, AND2_FANOUT);
	else if (nim[is] == 2) {
		coped = new OR2(GInfo, AND2_FANOUT);

	}
	else if (nim[is] == 3) {
		coped = new LED(GInfo, AND2_FANOUT,pii);

	}
	else if (nim[is] == 4) {
		coped = new SWITCH(GInfo, AND2_FANOUT,poo);

	}
	else if (nim[is] == 5) {
		coped = new NAND2(GInfo, AND2_FANOUT);

	}
	else if (nim[is] == 11) {
		coped = new Buffer(GInfo, AND2_FANOUT);

	}
	else if (nim[is] == 12) {
		coped = new NOT(GInfo, AND2_FANOUT);

	}
	else if (nim[is] == 13) {
		coped = new AND3(GInfo, AND2_FANOUT);

	}
	else if (nim[is] == 14) {
		coped = new NOR3(GInfo, AND2_FANOUT);

	}
	else if (nim[is] == 15) {
		coped = new XOR3(GInfo, AND2_FANOUT);

	}
	else if (nim[is] == 6) {
		coped = new NOR2(GInfo, AND2_FANOUT);

	}
	else if (nim[is] == 8) {
		coped = new XNOR2(GInfo, AND2_FANOUT);

	}
	else if (nim[is] == 9) {
		coped = new XOR2(GInfo, AND2_FANOUT);

	}
	else if (nim[is] == 10) {
		coped = new Buffer(GInfo, AND2_FANOUT);

	}
	AddComponent(coped);
	


	addgate(coped, pii, poo, GInfo.x1, GInfo.y1, inp[ic], iop[ic],nim[ic]);
	coped = NULL;
	if (coporpate)
		makedelete();
	is = -55;
	ic = -55;
	OutputInterface->ClearDrawingArea();
}

void ApplicationManager::Savecircute(ofstream& file)/////////////////////////////////////////////////////////////////////////////////////////////
{
	file << CompCount << endl;
	for (int i = 0; i < ccg; i++)
	{
		gates[i]->Savecomponent(file, i);

	}
	file << "connction" << endl;

	for (int i = 0; i < cconct; i++)
	{
		conct[i]->Savecomponent(file, i);

	}
}
void ApplicationManager::loadcircute(ifstream& file)
{

	int count;

	file >> count;
	cout << count << '\n';
	int c = 0;
	string name;

	for (int x = 0; x < 5; x++)
	{

		file >> name;

		if (name == "And")
		{
			GraphicsInfo m_GfxInfo;
			int Len = UI.AND2_Width;
			int Wdth = UI.AND2_Height;
			int y, z, f;

			string Name2;
			file >> c >> Name2 >> z >> f;
			

			m_GfxInfo.x1 = z - 25;
			m_GfxInfo.y1 = f - 25;
			m_GfxInfo.x2 = z + 25;
			m_GfxInfo.y2 = f + 25;

			Component* p = new AND2(m_GfxInfo, AND2_FANOUT);
			AddComponent(p);

			InputPin * DstPin[2];
			for (int i = 0; i < 2; i++)
			{
			
				DstPin[i] = new InputPin;

			}			
			OutputPin* SrcPin;
			SrcPin = new OutputPin(5);
			addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 2, 1,1);

			c++;
		}
		if (name == "And3")
		{
			GraphicsInfo m_GfxInfo;
			int Len = UI.AND2_Width;
			int Wdth = UI.AND2_Height;
			int y, z, f;

			string Name2;
			file >> c >> Name2 >> z >> f;
		

			m_GfxInfo.x1 = z - 25;
			m_GfxInfo.y1 = f - 25;
			m_GfxInfo.x2 = z + 25;
			m_GfxInfo.y2 = f + 25;

			Component* p = new AND3(m_GfxInfo, AND2_FANOUT);
			AddComponent(p);

			InputPin* DstPin[3];
			for (int i = 0; i < 3; i++)
			{

				DstPin[i] = new InputPin;

			}
			OutputPin* SrcPin;
			SrcPin = new OutputPin(5);
			addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 3, 1,13);

			c++;
		}
		else if (name == "Buff") {
			GraphicsInfo m_GfxInfo;
			int Len = UI.AND2_Width;
			int Wdth = UI.AND2_Height;
			int y, z, f;

			string Name2;
			file >> c >> Name2 >> z >> f;
			//cout << name << " " << c << " " << Name2 << " " << y << " " << z << " " << f << endl;

			m_GfxInfo.x1 = z - 25;
			m_GfxInfo.y1 = f - 25;
			m_GfxInfo.x2 = z + 25;
			m_GfxInfo.y2 = f + 25;

			Component* p = new Buffer(m_GfxInfo, AND2_FANOUT);
			AddComponent(p);

			InputPin* DstPin[1];
			for (int i = 0; i < 1; i++)
			{

				DstPin[i] = new InputPin;

			}
			OutputPin* SrcPin;
			SrcPin = new OutputPin(5);
			addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 1, 1,11);

			c++;
		}
		else if (name == "OR") 
		{
			GraphicsInfo m_GfxInfo;
			int Len = UI.AND2_Width;
			int Wdth = UI.AND2_Height;
			int y, z, f;

			string Name2;
			file >> c >> Name2 >> z >> f;

			m_GfxInfo.x1 = z - 25;
			m_GfxInfo.y1 = f - 25;
			m_GfxInfo.x2 = z + 25;
			m_GfxInfo.y2 = f + 25;

			Component* p = new OR2(m_GfxInfo, AND2_FANOUT);
			AddComponent(p);

			InputPin* DstPin[2];
			for (int i = 0; i < 2; i++)
			{

				DstPin[i] = new InputPin;

			}
			OutputPin* SrcPin;
			SrcPin = new OutputPin(5);
			addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 2, 1,2);

			c++;
		}
		else if (name == "XOR")
		{
			GraphicsInfo m_GfxInfo;
			int Len = UI.AND2_Width;
			int Wdth = UI.AND2_Height;
			int y, z, f;

			string Name2;
			file >> c >> Name2 >> z >> f;

			m_GfxInfo.x1 = z - 25;
			m_GfxInfo.y1 = f - 25;
			m_GfxInfo.x2 = z + 25;
			m_GfxInfo.y2 = f + 25;

			Component* p = new XOR2(m_GfxInfo, AND2_FANOUT);
			AddComponent(p);

			InputPin* DstPin[2];
			for (int i = 0; i < 2; i++)
			{

				DstPin[i] = new InputPin;

			}
			OutputPin* SrcPin;
			SrcPin = new OutputPin(5);
			addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 2, 1,9);

			c++;
		}
		else if (name == "XOR3")
		{
		GraphicsInfo m_GfxInfo;
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;
		int y, z, f;

		string Name2;
		file >> c >> Name2 >> z >> f;

		m_GfxInfo.x1 = z - 25;
		m_GfxInfo.y1 = f - 25;
		m_GfxInfo.x2 = z + 25;
		m_GfxInfo.y2 = f + 25;

		Component* p = new XOR3(m_GfxInfo, AND2_FANOUT);
		AddComponent(p);

		InputPin* DstPin[3];
		for (int i = 0; i < 3; i++)
		{

			DstPin[i] = new InputPin;

		}
		OutputPin* SrcPin;
		SrcPin = new OutputPin(5);
		addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 3, 1,15);

		c++;
		}
		else if (name == "NOT")
		{
		GraphicsInfo m_GfxInfo;
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;
		int y, z, f;

		string Name2;
		file >> c >> Name2 >> z >> f;
		m_GfxInfo.x1 = z - 25;
		m_GfxInfo.y1 = f - 25;
		m_GfxInfo.x2 = z + 25;
		m_GfxInfo.y2 = f + 25;

		Component* p = new NOT(m_GfxInfo, AND2_FANOUT);
		AddComponent(p);
		InputPin* DstPin[2];
		for (int i = 0; i < 2; i++)
		{

			DstPin[i] = new InputPin;

		}
		OutputPin* SrcPin;
		SrcPin = new OutputPin(5);
		addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 1, 1,12);

		c++;
		}
		else if (name == "Nand")
		{
		GraphicsInfo m_GfxInfo;
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;
		int y, z, f;

		string Name2;
		file >> c >> Name2 >> z >> f;

		m_GfxInfo.x1 = z - 25;
		m_GfxInfo.y1 = f - 25;
		m_GfxInfo.x2 = z + 25;
		m_GfxInfo.y2 = f + 25;

		Component* p = new NAND2(m_GfxInfo, AND2_FANOUT);
		AddComponent(p);

		InputPin* DstPin[2];
		for (int i = 0; i < 2; i++)
		{

			DstPin[i] = new InputPin;

		}
		OutputPin* SrcPin;
		SrcPin = new OutputPin(5);
		addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 2, 1,5);

		c++;
		}
		else if (name == "XNOR")
		{
		GraphicsInfo m_GfxInfo;
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;
		int y, z, f;

		string Name2;
		file >> c >> Name2 >> z >> f;
		m_GfxInfo.x1 = z - 25;
		m_GfxInfo.y1 = f - 25;
		m_GfxInfo.x2 = z + 25;
		m_GfxInfo.y2 = f + 25;

		Component* p = new XNOR2(m_GfxInfo, AND2_FANOUT);
		AddComponent(p);

		InputPin* DstPin[2];
		for (int i = 0; i < 2; i++)
		{

			DstPin[i] = new InputPin;

		}
		OutputPin* SrcPin;
		SrcPin = new OutputPin(5);
		addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 2, 1,8);

		c++;
		}
		else if (name == "NOR")
		{
		GraphicsInfo m_GfxInfo;
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;
		int y, z, f;

		string Name2;
		file >> c >> Name2 >> z >> f;

		m_GfxInfo.x1 = z - 25;
		m_GfxInfo.y1 = f - 25;
		m_GfxInfo.x2 = z + 25;
		m_GfxInfo.y2 = f + 25;

		Component* p = new NOR2(m_GfxInfo, AND2_FANOUT);
		AddComponent(p);

		InputPin* DstPin[2];
		for (int i = 0; i < 2; i++)
		{

			DstPin[i] = new InputPin;

		}
		OutputPin* SrcPin;
		SrcPin = new OutputPin(5);
		addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 2, 1,6);

		c++;
		}
		else if (name == "NOR3")
		{
		GraphicsInfo m_GfxInfo;
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;
		int y, z, f;

		string Name2;
		file >> c >> Name2 >> z >> f;

		m_GfxInfo.x1 = z - 25;
		m_GfxInfo.y1 = f - 25;
		m_GfxInfo.x2 = z + 25;
		m_GfxInfo.y2 = f + 25;

		Component* p = new NOR3(m_GfxInfo, AND2_FANOUT);
		AddComponent(p);

		InputPin* DstPin[3];
		for (int i = 0; i < 3; i++)
		{

			DstPin[i] = new InputPin;

		}
		OutputPin* SrcPin;
		SrcPin = new OutputPin(5);
		addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 3, 1,14);

		c++;
		}
		else if (name == "led")
		{
		GraphicsInfo m_GfxInfo;
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;
		int y, z, f;

		string Name2;
		file >> c >> Name2 >> z >> f;

		m_GfxInfo.x1 = z - 25;
		m_GfxInfo.y1 = f - 25;
		m_GfxInfo.x2 = z + 25;
		m_GfxInfo.y2 = f + 25;
		OutputPin* SrcPin;
		InputPin* DstPin[1];
		DstPin[0] = new InputPin();
		Component* p = new LED(m_GfxInfo, AND2_FANOUT, DstPin);

		AddComponent(p);




		addgate(p, DstPin, NULL, m_GfxInfo.x1, m_GfxInfo.y1, 1, 0,3);

		c++;
		}

		else if (name == "swich")
		{
		GraphicsInfo m_GfxInfo;
		int Len = UI.AND2_Width;
		int Wdth = UI.AND2_Height;
		int y, z, f;

		string Name2;
		file >> c >> Name2 >> z >> f;

		m_GfxInfo.x1 = z - 25;
		m_GfxInfo.y1 = f - 25;
		m_GfxInfo.x2 = z + 25;
		m_GfxInfo.y2 = f + 25;
		OutputPin* SrcPin;
		SrcPin = new OutputPin(5);
		Component* p = new SWITCH(m_GfxInfo, AND2_FANOUT, SrcPin);

		AddComponent(p);

		InputPin* DstPin[2];
		
		

		addgate(p, DstPin, SrcPin, m_GfxInfo.x1, m_GfxInfo.y1, 0, 1,4);

		c++;
		}
	
		else if (name == "connction") {
		int secpin[50];
		for (int k = 0; k <50; k++) 
			secpin[k] = 0;
		        

		for (int k = 0; k < count-ccg;  k++) {


				int y, z, f, x1, y1;
				GraphicsInfo m_GfxInfo;

				string Name2;
				file >> c >> z >> f ;
				secpin[f]++;
				m_GfxInfo.x1 = xg[z] + 50;
				m_GfxInfo.y1 = yg[z] + 25;
				if (f==led[0]|| f == led[1]|| f == led[2])
				{
					m_GfxInfo.x2 = xg[f] + 20;
					m_GfxInfo.y2 = yg[f] + 40;
				}
				else if (secpin[f] == 1) {
					m_GfxInfo.x2 = xg[f] + 10;
					m_GfxInfo.y2 = yg[f] + 10;
				}
				else if (secpin[f] == 2)
				{
					m_GfxInfo.x2 = xg[f] + 10;
					m_GfxInfo.y2 = yg[f] + 40;
				}
				else if (secpin[f] == 3)
				{
					m_GfxInfo.x2 = xg[f] + 10;
					m_GfxInfo.y2 = yg[f] + 25;
				}
				InputPin* DstPin;
				OutputPin* SrcPin;
				bool b=getcorpout(m_GfxInfo.x1-5, m_GfxInfo.y1-5, SrcPin, z, f);
				bool m=getcorpin(m_GfxInfo.x2, m_GfxInfo.y2, DstPin,x1 , y1);
				if (b == false || m == false)
				 return;
				int i1, i2;
				b=getgate(z, f, i1);
				m=getgate(x1, y1, i2);
				if (b == false || m == false)
					return;

				
				
				Component* p = new  Connection(m_GfxInfo, SrcPin, DstPin, i2, i1);
				AddComponent(p);
				addconct(p, i2, i1, DstPin, SrcPin, m_GfxInfo);
			}
		}
	}
	



}

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	for (int i = 0; i < countpin; i++)
		delete pi[i];
	for (int i = 0; i < countpout; i++)
	{
		delete po[i];
		po[i] = NULL;
	}

	for (int i = 0; i < 50; i++)
		delete [] indpin[i];
	delete[] indpin;
	for (int i = 0; i < 5; i++)
		delete[] truth[i];
	delete[] truth;

	delete OutputInterface;
	delete InputInterface;
	
}