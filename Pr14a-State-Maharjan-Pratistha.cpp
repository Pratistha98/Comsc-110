/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 14
Program: Pr14a-State-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Nov.28, 2017

Purpose: Learn about an Excel formatted text (.prn) 
         print data file, a C++ list of nodes, and 
         a program debugging technique.

         Review declaring and using a Boolean
         variable.

Problem: Process data regarding American States
         as described and shown in a sample console
         document on our course website.

Submit: Simultaneously submit:

        --C++ source program (.cpp) file:
  
          Pr14a-State-lastname-firstname.cpp
       
        -- Excel formatted text (.prn) print data
           file (version 2 that is edited to work):
 
          Pr14a-State-lastname-firstname-Ver2.prn

*/

//Preprocessor Directives

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Structure

struct State   //State admission record
{
  int ord;     //Order of admission to the union
  
  string ID;   //State identification code
  string name; //State name

  int admYr;   //Admission year
  int admMo;   //Admission month

  State* next; //Pointer to next node in list
};

//Prototypes


void putHead   ();
string getName ();
State* getData (string);
void putData   (State*);

//Global variables


bool debug = false; 

//Main routine

int main ()
{
  if (debug == true)
  {
    cout << "**main" << endl;
  }

  //Declare variables

  string ifname;  //Name of an input file

  State* start;   //Start of a state list

  //Call functions

  putHead();                 //Output Heading
  
  ifname = getName();        //Get file name

  start  = getData (ifname); //Get data into list

  putData (start);           //Output data

  return 0;  

}//end main  

void putHead ()
{
  //To the console, output program headings

  if (debug == true)
  {
    cout << "**putHead" << endl;
  }
  
  cout << endl;
  cout << "State Program " << endl;
  cout << "-------------------------------------" << endl;
  cout << endl;
  cout << "This program asks for the name of a "<< endl;
  cout << "formatted text (.prn) print file    "<< endl;
  cout << "about American states, validates the"<< endl;
  cout << "file's existence, inputs records    "<< endl;
  cout << "from the file, inserts them as nodes"<< endl;
  cout << "at the head of a linked list, then  "<< endl;
  cout << "outputs the list to the console.    "<< endl;
  cout << endl;

}//End putHead


string getName()
{
  //From the console, get the name of an input file
  //and validate the file's existence

  if (debug == true)
  {
    cout << "**getName" << endl;
  }
  string ifname;
  ifstream fin;
  
  while (true)
  {
    cout << "Input file name? " ;
    cin  >> ifname;
    
    fin.open (ifname);

    if (fin.good() == true )
    {
      fin.close();
      break;
    }//End If
     
    else
    {
      cout << "Invalid \a\n";

    }//End else
   
  }//End While

  return ifname;
  

}//End getName

State* getData (string ifname)
{
  //From a file, input state records, and insert
  //them as nodes in a linked list

  if (debug == true)
  {
    cout << "**getData" << endl;
  }
  
  //Declare and initialize variables

  ifstream fin;      //Input file object
  
  State* start;      //Pointer to starting node

  State* s;          //Pointer to new State node

  start = 0;         //Start node is initially null

  s     = new State; //New State node

  //Input and insert

  fin.open (ifname);

  while (fin >> s->ord)
  {
    fin >> s->ID;
    fin >> s->name;
    fin >> s->admYr;
    fin >> s->admMo;
  
   
  if (debug == true)
  {
    cout << "**s->ord  : " << s->ord
         << ", s->ord  : " << s->ID
         << ", s->name : " << s->name
         << ", s->admYr: " << s->admYr
         << ", s->admMo: " << s->admMo  << endl;
 
  }//End If

  s->next = start; //Save start pointer
  
  start   = s;     //Place current node at start

  s = new State;   //Make new State node

  }//End While

  fin.close();

  return start;
  
 
}//End getData
  

void putData (State* start) 
{
  //To the console, output column headings, then
  //output nodes from the linked list of state data

  if (debug == true)
  {
    cout << "**putData" << endl;
  }
  
  //Declare variables

  State* s;  //State node pointer
  
  //Output column headings

  cout <<  endl;
  cout << "                             Admission " << endl;
  cout << "                             --------- " << endl;
  cout << " Ord  ID  Name                Year  Mo " << endl;
  cout << " ---  --  ------------------  ----  -- " << endl;
  cout << endl;

  //Output nodes

  for (s = start; s; s = s->next)
  {
    cout << setw( 4) << right << s->ord  << "  ";
    cout << setw( 4) << left  << s->ID;
    cout << setw(18) << left  << s->name;
    cout << setw( 6) << right << s->admYr;
    cout << setw( 4) << right << s->admMo << endl;
 
   
  }//End For

cout << endl;
}//End putData
