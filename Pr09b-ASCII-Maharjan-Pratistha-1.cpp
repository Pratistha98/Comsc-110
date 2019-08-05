/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 9
Program: Pr09b-ASCII-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Oct. 19, 2017

Purpose: Learn about how a microcomputer typically
         stores and represents character data.

         Become familiar with the American Standard
         Code for Information Interchange (ASCII),
         and with related decimal, binary and 
         hexadecimal values.

Problem: To the console, output a table of ASCII
         characters, along with their equivalent
         binary, decimal and hexadecimal values.

         Watch and listen in class, and refer to a
         console document for more information.

         Submit just a source program (.cpp) file.

Source: http://www.asciitable.com/

*/

//Preprocessor directives


#include <bitset>
#include <iomanip>
#include <iostream>

using namespace std;

//Function Prototypes

void putHead ();
char getBeg  ();
char getEnd  (char);
void putRes  (char,char);

//Main Routine

int main()

{
 
  //Declare variables

  char beg;  //Beginning value
  char end;  //Ending value

  //Call functions

  putHead();   //Output headings
  
  beg = getBeg (); //Input beginning value
  end = getEnd (beg); //Input ending    value

  putRes (beg,end); //Output results

  return 0;


}

//Level One Functions

void putHead ()

{
  cout << endl;
  cout << "ASCII Program " << endl;
  cout << "-------------------------------" <<endl;
  cout << endl;
  cout << "This program outputs part of an" << endl;
  cout << "American Standard Code For "     << endl;
  cout << "Information Interchange table"   << endl;
  cout << endl;
  cout << "Enter a beginning value between" << endl;
  cout << "! and ~, and an ending value   " << endl;
  cout << "between the beginning value and ~."<< endl;
  cout << endl;
  
}

char getBeg()
{

  //Declare variables

  char beg;  //Beginning value

  //Get and validate

  while (true)
  {
    cout <<"Beg? ";
    cin  >> beg;

    if ( beg < '!' || beg > '~')
    {
      cout << "Invalid  \a\n"; 
    }//End if

    else
    {
      break;
    }//End else   
    
  }//End while

  cout << endl;

  return beg;
}//End getBeg

char getEnd (char beg)
{
  char end;

  //Get and validate
  
  while (true)
  {
    cout << "End? ";
    cin >> end;
    
    if ( end < beg || end > '~')
    {
      cout << " Invalid \a\n ";

    }//End if  
    
    else 
    {
      break;
    }//End else
  }//End while
  
  cout << endl;

  return end;
  
}//End getEnd

void putRes (char beg, char end)

{

  //Declare variables
  char c;   //Character loop index

  int count; //Count of characters
  
  //Initialize variables
  
  count = 0;
   
  //To the console output column headings

  cout << "Char  Dec       Bin  Hex " << endl;
  cout << "----  ---  --------  --- " << endl;
  cout << endl;
  
  //To the console, output ASCII table

  for ( c = beg; c<=end; c++ )
  {
    cout << setw(4)           <<         c;
    cout << setw(5)  << dec   <<    int(c);  
    cout << setw(10) << bitset<8> (int(c));
    cout << setw (5) << hex   <<    int(c)  << "\n";

    count++;
  }//End for 

  //To the console, output count
  
  cout << endl;
  cout << "Count : " << count << endl;
 

}








































 
