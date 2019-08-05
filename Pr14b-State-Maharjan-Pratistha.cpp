/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 14
Program: Pr14b-State-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Nov.30, 2017

Purpose: Similar to program Pr14a but learn to:
    
         -- create and examine a comma separated
            values (.csv) file
   
         -- input records from a comma separated
            value file with the getline command

         -- use the built-in tm structure to get
            today's date from the computer
 
         -- use the built-in stoi function to 
           convert string values to integers

Problem: Similar to program Pr14a but:
        
         -- calculate and output each state's age
            in years since its admission to the
            union

         
Submit: Simultaneously submit:

        --this source program:
  
          Pr14b-State-lastname-firstname.cpp
       
        -- a comma separated values file:
 
          Pr14a-State-lastname-firstname.csv

*/

//Preprocessor Directives

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#include <ctime> 

//Structure

struct State   //State admission record
{
  string ord;  //Order of admission to the union
  
  string ID;   //State identification code
  string name; //State name

  string admYr;   //Admission year
  string admMo;   //Admission month

  State* next; //Pointer to next node in list
};

/* Leave the following structure about time in a 
   comment block just for reference

struct tm            //System time
{
  int tm_sec;        //Seconds of minutes
  int tm_min;        //Minutes of hour
  int tm_hour;       //Hours of day 
  int tm_mday;       //Day of month
  int tm_mon;        //Month of year
  int tm_year;       //Year since 1900
  int tm_wday;       //Days since Sunday
  int tm_yday;       //Days since January 1st
  int tm_isdst;      //Hours of daylight savings 
};
*/

//Function Prototypes


void putHead   ();
string getName ();
State* getData (string);
void putData   (State*);
int calcAge    (State*);

//Global constant


const bool debug = false; 

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
  cout << "comma separated values (.csv) file  "<< endl;
  cout << "of data about American states,      "<< endl;
  cout << "validates the file's existence,    "<< endl;
  cout << "inputs records from the file, into  "<< endl;
  cout << "a linked list, converts some string "<< endl;
  cout << "values to integers, determines     "<< endl;
  cout << "current year and month, calculates  "<< endl;
  cout << "ages if stated since joining the    "<< endl;
  cout << "union, then outputs results to the  "<< endl;
  cout << "console.                            "<< endl;
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

  start = NULL;      //Set Start to null

  s     = new State; //New State node

  //Input and insert

  fin.open (ifname);

  while (getline (fin, s->ord, ','))
  {
    getline (fin, s->ID,     ',');
    getline (fin, s->name,   ',');
    getline (fin, s->admYr,  ',');
    getline (fin, s->admMo, '\n');
    
   
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
  int stAge;  //State age

  
  //Output column headings

  cout <<  endl;
  cout << "                             Admission      " << endl;
  cout << "                             ---------      " << endl;
  cout << " Ord  ID  Name                Year  Mo   Age" << endl;
  cout << " ---  --  ------------------  ----  --   ---" << endl;
  cout << endl;

  //Output nodes

  
//for (s = start; s !     0; s = s->next)
//for (s = start; s != Null; s = s->next)

  for (s = start; s; s = s->next)
  {
    stAge = calcAge (s); 

    cout << setw( 4) << right << s->ord  << "  ";
    cout << setw( 4) << left  << s->ID;
    cout << setw(18) << left  << s->name;
    cout << setw( 6) << right << s->admYr;
    cout << setw( 4) << right << s->admMo;
    cout << setw( 6) << right << stAge << endl;
 
   
  }//End For

  
cout << endl;
}//End putData

//Level 2 functions

int calcAge (State* s)
{
  //Calculate state age at the time of admission 
  //to the union

  if ( debug == true)
  {
    cout << "**calcAge" << endl;
  
  }

  //Declare and initialize variables

  time_t sec = time (0);          //Current seconds
  tm*    cur = localtime (&sec);  //Current time

  int curYr  = cur->tm_year + 1900;  //Current year
  int curMo  = cur->tm_mon;          //Current month

  int tmpYr;     //Temporary year
  int tmpMo;     //Temporary month

  int stAge;     //State age

  //Convert and calculate 

  tmpYr = stoi (s->admYr);  //Convert year to int
  
  tmpMo = stoi (s->admMo);  //Convert month to int

  stAge = curYr- tmpYr; 

  if ( curMo < tmpMo )
  {
    //stAge -= 1 ;
    stAge = stAge - 1;

  }    

  return stAge;

}//End calcAge
