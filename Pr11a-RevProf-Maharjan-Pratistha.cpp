/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 11
Program: Pr11a-RevProf-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Nov. 2, 2017

Purpose: Introduce arrays and sorting.
  
         Review constant value, functions,
         and file input.

Problem: Create a data file called
        
         Pr11a-RevProf-lastname-firstname.in

         where you use your last and first name.

         Into that file, type the name of 15 top
         technology companies, along with their
         revenues and profits for one somewhat
         recent year. The data should appear in 
         descending order by revenues.
 
         For a source of this data, refer to a 
         NetworkWorld magazine article at

        https://www.networkworld.com/article/2940537

        Write a program that processes data from 
        the file you create, as described in a 
        related console document.

        Watch and listen in class, and refer to a
        console document for more information.

        Simultaneously submit:

        --source program file (.cpp)
        --input data     file (.in)

*/

//Preprocessor Directives
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Function Prototypes

void putHead();
string getName();
void procData(string);

//Constant Values

const int SIZE = 20;  //Array size

//Main Routine

int main ()

{
  //Declare variables

  string ifname;

  //Output headings
  putHead();

  //Validata input files
  ifname = getName();

  //Process Data
  procData(ifname);

  return 0;


}//End main

//Level 1 Functions

void putHead()
{
  cout << endl;
  cout <<"Revenue and Profit Program" << endl;
  cout << "---------------------------------" << endl;
  cout << endl;
  cout << "Regarding 15 top technology" << endl;
  cout << "companies, this program sorts" << endl;
  cout << "their names, revenues and profits," << endl;
  cout << "in descending order by profits," << endl;
  cout << "then outputs results to the" << endl;
  cout << "console." << endl;
  cout << endl;
 

}//End putHead

string getName()

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
  
  
}//Close string ifname


void procData(string ifname)
{
  
  //Process data
  //Declare variables

  ifstream fin;   //Input file object

  string comp [SIZE];  //Company name
  
  int    rev  [SIZE];  //Revenue ($ millions)
  int    prof [SIZE];  //Profit  ($ millions)

  int    i;            //Array index
  int    j;            //Array index
  int  count;          //Record count

  string stemp;        //Temporary string

  int    itemp;        //Temporary integer

  int    totrev;       //Total revenue
  int    totprof;      //Total profit

  //Initialize variables

  i = 0;

  totrev  = 0;
  totprof = 0;

  //Input values from the file, and store them 
  //in arrays


  fin.open (ifname);

  while (fin >> comp [i]) 
  {
    fin >> rev  [i];
    fin >> prof [i];
    
    totrev  += rev [i];
    totprof += prof[i];
  
    i++;
 
  }//End while    

  fin.close ();

  count = i;    

  //In arrays, sort values

  for (i = 0; i < count; i++)
  {

    for (j = i + 1; j < count; j++)
    {
      if (prof [i] < prof [j])
      {
        stemp   = comp[i]; 
        comp[i] = comp[j];
        comp[j] = stemp;
  

        itemp   = rev[i];
        rev[i] = rev[j]; 
        rev[j] = itemp; 


        itemp   = prof[i];
        prof[i] = prof[j]; 
        prof[j] = itemp; 

      }//End if      

    }//end for j

  }//End for i

  //To the console, output column headings
  
  cout << endl;  
  cout <<"Company     " << "Revenue      " <<"Profit  "<< endl;
  cout <<"-------     " << "-------      " <<"------  "<< endl;
  cout << endl;

  //To the console, output array values

  for (i = 0; i < count; i++)
  {
    cout << setw(11) << left  << comp [i] << "  ";
    cout << setw( 6) << right << rev  [i] << "  ";
    cout << setw(10) << right << prof [i] << "  "<< endl;       
  }//End for
  
  cout << endl;
  cout << "Total       " << totrev << "      " << totprof << endl;
  cout << endl; 
  
}//End procData






























