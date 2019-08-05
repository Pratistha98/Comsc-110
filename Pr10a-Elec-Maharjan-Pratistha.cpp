/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 10
Program: Pr10a-Elec-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Oct. 24, 2017

Purpose: Lean about getting data from an input 
         file instead from the console.

         Review looping, validation, formatting 
         output, functions, and the switch-case
         construct.

Problem: Create an input file that contains
         electricity bill data.

         Write a program that processes data in
         that file as described in the putHead
         function.
 
         Watch and listen in class, and refer to a 
         console document for more information.

Submit: Two files simultaneously:
        -- source program file (.cpp)
        -- input data     file (.in )

*/

//Preprocessor directives

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Function Prototype

void   putHead ();
string getName  ();
void   procData (string);

//string setAbbr (int);

//Main routine

int main()

{
  //Declare variables

  string ifname; //Input file  name
  
  //To the console, output program headings

  putHead ();  

  //From the console, get and validate a file name

  ifname = getName ();

  //Process data
  procData (ifname);

  return 0;

  
}//End main

//Level 1 functions 

void putHead ()

{
cout << endl;
cout << "Electricity Bill Program " << endl;
cout << "------------------------------------"  << endl;
cout << endl;
cout << "This program gets electricity bill" << endl;
cout << "data from an input file, converts"  << endl;
cout << "month numbers to abbreviated month" << endl;
cout << "names, and outputs the data to the" << endl;
cout << "console, along with a count of    " << endl;
cout << "records processed. "                << endl;
cout << endl;
cout << "Enter the name of an input file that" << endl;
cout << "contains electricity bill data      " << endl;
cout << endl;

}//End putHead  

string getName ()

{
  //From the console, get and validate a file name

  //Declare variables

  string ifname;  //Input file name

  ifstream fin;  //Input file object

  //Get and validate

  while (true)
  
  {
    cout << "Input file name? ";
    cin  >> ifname;

    fin.open (ifname);
  
    if (fin.good() == true)
    {
      fin.close (); //When closing there is empty parenthesis
      break; 
    }//End if
    
    else
    {
      cout << "Invalid \a\n";
    }
        
  }//End while
  
  cout << endl;

  return ifname;

}//End string

void   procData (string ifname)
{
  //Process data

  //Declare variables

  ifstream fin;  //Input file object

  int   year;  //Year
  int   mint;  //Month number (integers)
  int    kwh; //Kilowatt hours

  float cost; //Cost
   
  string mabbr; //Month name (abbreviation)

  int    count; //Count of records processed

  //Initialize variables

  count = 0;

  cout << "Year  Mon.  KWh   $ Cost " << endl;
  cout << "----  ---  ----  -------" << endl;
  cout << endl;
  
  //Open input file, and format fixed-point output

  fin.open (ifname);
  
  cout << fixed << showpoint << setprecision(2);
  
  //Get and put data, out approach

  while (fin >> year)
  {
    fin >> mint;
    fin >>  kwh;
    fin >> cost;
     
    cout << setw(4) << year << " ";   
    cout << setw(4) << mint << "  ";
    cout << setw(4) << kwh  << "   ";
    cout << setw(6) << cost << " ";
    cout << endl;

    count ++;


  }//End while

  //Close file and to the console, output count
  fin.close ();
  
  cout << endl; 
  cout << "Count: " << count << endl;
 
}//End procData





























