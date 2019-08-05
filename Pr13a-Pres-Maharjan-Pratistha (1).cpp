/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 11 (section 11.3) and 13
Program: Pr13a-Pres-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Nov.16, 2017

Purpose: Learn about declaring an array that has a
         dynamic size, counting records in an
         input file, and passing by reference a dynamic
         array among the functions.

         Review creating a C++ structure, basing an
         array on structure, inputting data from
         a file into an array, using an if
         statement to adjust a value, and neatly 
         outputting data to the console. 

Problem: Process data regarding American presidents
         as described in class and in a sample
         console document on our course website.

Data   : A data file called Pr13a-Pres.in will be
         downloadable from our course website.

Submit: Just submit a source program (.cpp) file.
*/

//Preprocessor directives

#include  <fstream>
#include  <iomanip>
#include  <iostream>
#include  <string>

using namespace std;

//Structure

struct Pres 
{
  int      ord; //Order of team
  string  last; //Last name
  string first; //First name
  string   mid; //Middle name
  string    st; //Birth state ID
  int    birYr; //Birth year
  int    birMo; //Birth month
   
}; //end struc


//Level Function Prototypes

void   putHead  ();
string getName  ();
int    countRec (string);
void   getData  (string, int, Pres*);
void   putData  (int, Pres*);

//Main routine

int main()
{

  //Declare variables

  string ifname; //Name of the input file
  int    count ; // Count of input records
  Pres*      p ; //List of presidents
  
  //Call functions

  putHead ();
  ifname = getName();
  count = countRec(ifname);
  
  p = new Pres [count];  //Make list instance
  
  getData (ifname, count, p); //Get input data
  putData (count, p ); 

  return 0 ; 
  


}//End main

void putHead()
{
  cout << endl;
  cout << "President Program" << endl;
  cout << "------------------------------------" << endl;
  cout << endl;
  cout << "This program asks for the name of a " << endl;
  cout << "file of data about the American     " << endl;
  cout << "presidents, validates the file name," << endl;
  cout << "counts the file's records, inputs   " << endl;
  cout << "records into a dynamically-sized    " << endl;
  cout << "array and outputs results to the    " << endl;
  cout << "console"                              << endl;
  cout << endl;

}//End putHead

string getName ()


{
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

int countRec (string ifname)
{
  //From a file, count the number of records to 
  //process
 
  //Declare and initialize variables
  
  ifstream fin;  //Input file object

  string   rec;  //Input record (row)

  int     i;     //Loop index
  int count;     //Record count

  i = 0;
  
  //Count records

  fin.open(ifname);

  while (getline (fin, rec))
  {
    i++;
    
  }//End while

  fin.close();
  
  count = i;
  
  return count;
 
}//End countRec


void getData (string ifname, int count, Pres* p)
{
  //From a file, get records about American 
  //presidents

  //Declare variables

  ifstream fin;   //Input file object
  
  int i;          //Array index

  //Get Data

  fin.open(ifname);

  for ( i = 0 ; i < count; i++)
  {
    fin >> p[i].ord;
    fin >> p[i].last;
    fin >> p[i].first;
    fin >> p[i].mid;
    fin >> p[i].st;
    fin >> p[i].birYr;
    fin >> p[i].birMo;
   
  }//End for
  
  fin.close();

  
}//End getData

void putData (int count, Pres*p)
{
  //To the console, output records about American
  //presidents

  //Declare variables

  int i;  //Loop index


  //Output column headings

  cout << endl;
  cout << "Ord   Last Name  First Name  Mid  St  Year  Mo " << endl;
  cout << "---  ----------  ----------  ---  --  ----  -- " << endl;
  cout << endl;

  //Output data

  for (i = 0; i < count; i++)
  {
    cout << right; 
    cout << setw( 3) << p[i].ord << "  ";
  
    cout << left;
    cout << setw(12) << p[i].last;
    cout << setw(12) << p[i].first;

    if (p[i].mid == ".") 
    {
      cout << "     ";
    }
    else 
    {
      cout << setw(5)  << p[i].mid;
    }
  
    cout << setw(4)  << p[i].st;
    
    cout << left;
    cout << setw(6) << p[i].birYr;
    cout << right;
    cout << setw(2) << p[i].birMo << endl;
    
   
      
  }//End for

}//End putData
































