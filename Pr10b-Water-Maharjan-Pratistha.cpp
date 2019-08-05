/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 10
Program: Pr10b-Water-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Oct. 26, 2017

Purpose: Learn about writing data to an output file
         instead of to the console.

         Review creating and validating an input
         file, formatting output, functions,
         arithmetic, and the switch-case construct.

         
Problem: Create an input file that contains
         water bill data.

         Write a program that processes data in
         that file as described in the putHead 
         function.

         Watch and listen in class, and refer to a
         console document for more information.

Submit: Two files simultaneously:
        -- source program file (.cpp)
        -- input data

*/

//Preprocessor directives

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Function prototypes 

void putHead ();
string getNameIn ();
string getNameOut ();
void procData (string, string);
void putFoot (string);
string setAbbr (int);

//Main routine

int main ()

{
  
  //Declare variables

  string ifname;  //Input  file  name
  string ofname;  //Output file  name

  //To the console, write program headings

  putHead();

  //From the console, read input and output
  //file names

  ifname =   getNameIn();
  ofname = getNameOut ();

  //Process data, reading an input file,
  //calculating results, and writing an output file

  procData (ifname, ofname);

  //To the console, write a program footing, and
  //send back zero to the operating system

  putFoot(ofname);
  
  return 0;
    
}//End main routine

//Level 1 Functions

void putHead()
{

  cout << "Water Bill Program" << endl;
  cout << "-----------------------------------" << endl;
  cout << endl;
  cout << "This program prompts you to enter" << endl;
  cout << "the name of an existing input file," << endl;
  cout << "and the name of a new output file. " << endl;
  cout << endl;
  cout << "From the input file, this program" << endl;
  cout << "reads a service charge, two usage" << endl;
  cout << "rates, a prior meter reading, and" << endl;
  cout << "subsequent bi-monthly readings.  "  << endl;
  cout << endl;
  cout << "Based on such data, this program " << endl;
  cout << "calculates water usage and costs," << endl; 
  cout << "converts month numbers to names, " << endl;
  cout << "and writes results to a file.    " << endl;
  cout << endl;

 
}//End putHead        

string getNameIn ()

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

}//End string getIn

string getNameOut ()
{
  //Declare variables

  string ofname;  //Output file name
  
  //From the console, read the name of an output
  //file

  cout << "Output file name? ";
  cin  >>  ofname;

  cout << endl;

  return ofname;
  
}// End string getOut


void procData (string ifname, string ofname)

{
  //Declare variables

  ifstream fin;    //Input file object
  ofstream fout;   //Output file object

  float chrg;   //Service charge
  float rate1;  //Rate for units used <= 22
  float rate2;  //Rate for units used  > 22

  int    prev;  //Previous meter reading
  int    year;  //Year
  int    mint;  //Month number (integer)
  int    curr;  //Current meter reading
  int    unit;  //1 unit used = 100 cubic feet
                //            = 748 gallons
  
  float cost;   //Cost
  
  string mabbr; //Month name (abbreviation)  

  //Open input and output files

  fin.open(ifname);
  fout.open(ofname);
  
  //From the input file, read the first record and
  //store its contents into appropriate variables

  fin >> chrg;
  fin >> rate1;
  fin >> rate2;
  fin >> prev;

  //Read beyond or ignore a blank line,
  //if appropriate 

  fin.ignore (1000, '\n');

  //Format file output

  cout << fixed << showpoint << setprecision(2);
  
  //Read, calculate and write

  while (fin >> year)
  {
    //From an input record, read its first few
    //fields

    fin >> mint;
    fin >> curr;
    

    //Calculate units used    
    
        
    unit = curr - prev;

    //Calculate cost
  
    if ( unit <= 22 )
    {
      cost = chrg + unit * rate1 ; 

    }//End if

    else
    {
      cost = chrg + (unit - 22) * rate2
                  + (22 *rate1);
 
    }//End else

    //Set month abbreviation
 
    mabbr = setAbbr (mint);
    
    //To the output file, write results

    
    fout << setw (4) << year  << "  " ;
    fout << setw (4) << mabbr << "  " ;
    fout << setw (4) << curr  << "  " ;
    fout << setw (4) << unit  << "  " ;
    fout << setw (6) << cost  << "  " << endl;

    //Set previous meter reading to the current one
    prev = curr;

  } //End while
   
  //Output a blank line, and close both files
  
  
  cout << endl;

  fin.close  ();
  fout.close ();

} //End procData


void putFoot (string ofname)

{
  cout << "Done. To see results: " << endl;
  cout << "Type " <<  ofname << endl; 
 

}

//Level two functions

string setAbbr (int mint)

{
  string mabbr; //Month abbreviation
  
   
  switch (mint)

  {
    case  1: mabbr = "Jan."; break; 
    case  2: mabbr = "Feb.";  break; 
    case  3: mabbr = "Mar.";  break; 
    case  4: mabbr = "Apr.";  break;
    case  5: mabbr = "May ";  break;
    case  6: mabbr = "Jun.";  break;
    case  7: mabbr = "Jul.";  break;
    case  8: mabbr = "Aug.";  break;
    case  9: mabbr = "Sep.";  break;
    case 10: mabbr = "Oct.";  break;
    case 11: mabbr = "Nov.";  break;
    case 12: mabbr = "Dec.";  break;
    default: mabbr = "Inv.";

  }

  return mabbr;  

}





















   