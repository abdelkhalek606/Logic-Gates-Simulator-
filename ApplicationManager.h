#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include"Components/Connection.h"
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	Component* coped;
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	InputPin* pi[50];   //array of pointer input
	OutputPin* po[50];   ///array of pointer output
	int xpi[50],ypi[50];  // array of coordinate for input pin
	int xpo[50], ypo[50];  // array of coordinate for output pin
	int countpin;           //counter for input pin
	int countpout;            ////counter for output pin
	int cg[100];             //counter for gates
	int ccg;                   //counter for gates
	Component* gates[MaxCompCount];  //array for gates, swich and led 
	int xg[100], yg[100];             //coordinate of gates
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface      
	int is;                  //indix of gate selected
	int cs;                   //indix of connction selected
	int igdelete;            //gate deleted
	int inp[50];              //number of inputpin of all gates
	Component *conct[50];      //array of conection
	int cconct;                 //counter of conection              
	int p1[50], p2[50];           //p1 for inputpin p2 for outputpin 
	int x1con[50], y1con[50], x2con[50], y2con[50];  //corrdinate of two pin conction
	string lab[50];                // array of lable      
	int xs[50], ys[50];             //coordinate of lable 
	int countstring;                //counter for lable
	int** indpin;                   // 2d array for input pin 
	int* indpout[50];               // array for output pin
	int ns;                         //
	int nl;
	int swch[5];                   //array that contain the indix of swich in gates 
	int swcount;                   // counter for swichs
	int led[5];                         //array that contain the indix of led in gates 
	int ledcount;                       //counter for led
	int nsw[50];                    //number of conection from swichs
	int nlw[50];                      //number of conection to led
	int sm;                             
	int iop[50];                        //number of output conction for all gate
	int** truth;                           //the other side of truthtable 
	int** compin;                         //copmination of truth table
	bool coporpate;                      //if there copy or pate 
	int nim[50];                         //id of gate use in copy paste cut
	int ic;                            //gate that will be paste 

public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//to save componant
	void ApplicationManager::Savecircute(ofstream& file);
	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//for load saved circtis 
	void ApplicationManager::loadcircute(ifstream& file);

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	//to get coordinate of inputpin
	bool getcorpin(int x,int y,InputPin*&,int &x2,int &y2 );

	//to get coordinate of outputpin
	bool getcorpout(int x, int y, OutputPin*&, int& x2, int& y2);

	//to add gate
	void addgate(Component*p, InputPin**l,OutputPin *r,int x,int y,int c,int o,int num );

	//to add conction 
	void addconct(Component* p,int ,int,InputPin*&m ,OutputPin*&b, const GraphicsInfo& r_GfxInfo);

	// to get indix of conction
    bool getconct(int x, int y, int& i);

	// to get indix of gate
	bool getgate(int x, int y, int& i);

	//to make paste
	void peste(int x,int y);

	//to make cut
	void cutfn();

	//to make select
	void makeselect(int i,int c);
	
	//to make delete
	void makedelete();

	//to make edite
	void makeedit(string,int,int,int&,int&);

	//to get string 
	void getstr(string st,int x,int y);

	//in simulate to sure the user click in switch
	bool getswch(int x, int y, int& i2);

	//to add leble
	void makestring();

	//to make simulation
	void makesim(int i);

	//to chick if circts valid or not
	bool makevalid();

	//to make truth table
	int** maketruthtable(int**p);
	
	//to get number of swich and led to make combination and truthtable
	void getcount(int&, int&);

	//to make copy
	void copyfn();
	STATUS prop(int x,int y);
	//destructor
	~ApplicationManager();
};

#endif