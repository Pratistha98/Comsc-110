/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 12
Program: Pr12a-Weather-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Nov. 9, 2017

Purpose: Introduce a C++ data structure.
   
         Pass by reference among the functions an array
         based on a C++ structure.

Problem: From a file on our courses website, input
         five columns of weather data for six
         years, and store that data in a single
         array based on a C++ structure.

         From the weather array, output the data to 
         the console.

Submit:  Just a source program file (.cpp).

*/
         
//Preprocessor directives

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Structure and Constant

struct Weather  //Weather record


{
  string loc;  //Location
  int   year; //Year
  int   mint; //Month integer
  float rain; //Rain
  float temp; //Temperature (month mean)

};  //notice the semi-colon

const int SIZE = 120; //Maximum ten years of
                      //monthly weather data


//Function Prototypes

void   putHead ();
string getName ();
int    getData (string, Weather []);
void   putData (int, Weather []);
void   putFoot (int, Weather []);


//Main routine

int main ()
{

  //Declare variables 

  string  ifname;  //Name of input file

  int      count;  //Count of input records

  Weather w[SIZE]; //Array of weather records
  
  //Call functions

  putHead ();
  ifname = getName ();
  count = getData (ifname, w);
  putData (count,  w);
  putFoot (count,  w);

  return 0;
}//End main routine

//Level 1 functions

void putHead()
{

  cout << endl;
  cout << "Weather Program" << endl;
  cout << "--------------------------------------"<<endl;
  cout << endl;
  cout << "For one weather reporting location" << endl;
  cout << "and for each year and month on file,"<< endl;
  cout << "this program displays a rainfall" << endl;
  cout << "amount and a mean temperature" << endl;
  cout << "followed by totals. " << endl;
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


int getData (string ifname, Weather w[])
{

  //From the input file, get records rowa0 of 
  //monthly weather data and store them in a 
  //single array with multiple fields (columns)

  //Declare and intialize variables

  ifstream fin;  //Input file object
  
  int i;         //Array index
  int count;     //Record count
  

  i = 0;
  
  //Get and store data

  fin.open (ifname);

  while (fin >> w[i].loc)
  {
    fin >> w[i].year;
    fin >> w[i].mint;
    fin >> w[i].rain;
    fin >> w[i].temp;

    //totRain += w[i].rain;
    //totTemp += w[i].temp;
    
    i++;

  }//End While

  fin.close ();

  count = i;

  return count;

}//End getData

void putData (int count, Weather w[])
{
  //To the console, output weather records (lines)
  //of monthly weather data from the weather array

  //Declare variables

  int i;

  cout << endl;
  cout << "Loc   Year   Mon   Rain    Temp" <<endl;
  cout << "---   ----   ---   ----    ----" << endl;
  cout << endl;

  //Format and output detail data lines

  cout << fixed << showpoint;

  //Total the console, output array values

  for (i = 0; i < count; i++)
  {
    cout << setw(6) << left  << w[i].loc;
    cout << setw(4) << left  << w[i].year;
    cout << setw(6) << right << w[i].mint;
    cout << setprecision (2);
    cout << setw(7) << right << w[i].rain;
    cout << setprecision (1);
    cout << setw(8) << right << w[i].temp << endl;
  }//End for
  

   

}//End putData

void putFoot(int count, Weather w[])
{
  double totrain;
  double tottemp;
  int i;

  totrain = 0;
  tottemp = 0;
  
  for (i = 0; i < count; i ++)
  {
    totrain += w[i].rain;
    tottemp += w[i].temp;

  }

  cout << endl;

  cout <<"Total" << setw(18) << setprecision(2)<<
         totrain << setw(8)<< setprecision(1) << tottemp << endl;
  
}  //End putFoot






















  