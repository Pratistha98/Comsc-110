/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 8
Program: Pr08c-Leap-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Oct. 10, 2017

Purpose: Learn more about functions, including
         prototypes and parameters.

         Review data validation, iteration and
         nested conditions.

Problem: Identify leap years between beginning and
         ending years that a user specifies.

         Though similar to the earlier Pr06c
         assignment, there are a few differences.

         This program is divided into functions,
         and uses prototypes and parameters.

         This program treats the year Britain
         adopted Gregorian calendar, not when
         a pope introduced it, as the first valid
         year. 
     
         This program uses a for loop, not a while
         loop, to identify and output leap years. 
 
         Use a batch file to run the program and
         to display a count of leap years. 

         Watch and listen in class, and refer to a 
         console document for more information.
 
         When done, simultaneously submit both
         source (.cpp) and batch (.bat) files.

*/

//================================================
//Preprocessor directives
//------------------------------------------------

#include <iostream>
using namespace std;


//Function Prototypes

void putHead (int, int);
int  getBeg  (int, int);
int  getEnd  (int, int);
int  putYear (int, int);

//Main Routine

int main()

{
  //Declare variables (only these)

  int greg; //Britain's first Gregorian year
  int now ; //Current year

  int beg;  //Year to begin processing
  int end;  //Year to end processing

  int count;//Count of leap years


  //Initialize variables
  
  greg = 1752;
  now  = 2017;

  //To the console, output a program heading

  putHead (greg, now);
  
  //From the console, get and validate beginning
  //and ending years

  beg = getBeg (greg, now);
  
  end = getEnd (beg, now);

  //To the console, output results

  count = putYear (beg, end);

  return count;


}//End main


//Functions


void putHead (int greg, int now)
{
  //To the console, output a program heading

  cout << endl;
  cout << "Leap Year Program               "<< endl;
  cout << "--------------------------------"<< endl;
  cout << endl;
  cout << "This program determines whether" <<endl;
  cout << "years are leap years (Y means  " <<endl;
  cout << "yes, N means no).              " <<endl;
  cout << endl;
  cout << "Choose years for which to begin" <<endl;
  cout << "and end processing, between    " <<endl;
  cout << greg << " and " << now << "." << endl;
  cout << endl;
  
 

}

int getBeg (int greg, int now)
{
  //From the console, get and validate a beginning
  //year, and send it back to the main routine

  //Declare variables

  int beg;  //Beginning year  
  

  //Get and validate

  while (true)
  {
    cout << "Beg. year? " ;
    cin  >> beg;
    
    if (cin.peek() !='\n' )
    {
      cout << "Invalid: not an integer\a\n";

      cin.clear ();
      cin.ignore (1000, '\n');

    }//End if
  
    else if (beg < greg || beg > now)
    {
      cout << "Invalid: out of range \a\n";
    }//End else if
    
    else
    {
      break; 
    }//End else

  }//End while
  
  cout << endl;
  
  return beg;

  
}//End getBeg

int getEnd (int beg, int now)
{
  //From the console, get and validate an ending
  //year, and send it back to the main routine

  //Declare variables

  int end;  //Ending year  
  

  //Get and validate

  while (true)
  {
    cout << "End. year? " ;
    cin  >> end;
    
    if (cin.peek() !='\n' )
    {
      cout << "Invalid: not an integer\a\n";

      cin.clear ();
      cin.ignore (1000, '\n');

    }//End if
  
    else if (end < beg || end > now)
    {
      cout << "Invalid: out of range \a\n";
    }//End else if
    
    else
    {
      break; 
    }//End else

  }//End while
  
  cout << endl;
  
  return end;

  
}//End getend

int putYear (int beg, int end)
{
  //To the console, identify, output and count leap
  //years, and send back count to the main routine

  //Declare variables (only these)

  int i;     //Index for year loop
  int count; //Count of leap years
  
  char leap; //Leap year (Y or N)?
  
  //Initialize variables

  count = 0;
  
  //To the console, output column headings

  cout << "Year  Leap?   "<< endl;
  cout << "----  -----    "<< endl;
  cout << "              "<< endl;
  
  //Loop to process

  for ( i = beg; i <= end ; i++ )
  {
    leap = 'N';
    
    if  (i % 100 == 0 )
    {
      if (i % 400 == 0)
      {
        leap = 'Y';

      }//End nested if
    }//End if
 
    else if (i % 4 == 0)
    {
      leap = 'Y';
      
    }
    
    cout << i << "   " << leap << endl;
    
    if (leap == 'Y')
    {
      count++;
    }
  }//End for

  cout << endl;

  return count;

 
}//End putYear

























