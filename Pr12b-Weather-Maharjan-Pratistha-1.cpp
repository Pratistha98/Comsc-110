/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 12
Program: Pr12b-Weather-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Nov. 14, 2017

Purpose: Similar to program Pr12a.

         Also, learn to sort based on two data
         fields, not just one, and based on a 
         structure. 

         Review averaging, and the switch-case
         construct.

Problem: As a basis of this program, you may copy
         much of your own assignment Pr12a.

         For details about the current assignment,
         see below, watch and listen in class, and
         refer to our course website's sample
         console file, which also includes a 
         hierarchy chart of program functions.

Data:    For data, use the same input that program
         Pr12a used. If you wish, you may copy the
         file and rename it as
         Pr12b-Weather.in.

Submit:  Just submit a source program file (.cpp).

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


//Level 1 Function Prototypes

void   putHead ();
string getName ();
int    getData  (string, Weather []);
void   sortData (int, Weather []);
void   putData  (int, Weather []);
void   putFoot  (int, Weather []);

//Level 2 Function Prototype

string setAbbr (int);


//Main routine

int main ()
{

  //Declare variables 

  string  ifname;  //Name of input file

  int      count;  //Count of input records

  Weather w[SIZE]; //Array of weather records
  
  //Call Level 1 functions

  putHead ();
  ifname = getName ();
  count = getData (ifname, w);
  sortData (count, w);
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
  cout << "For one weather reporting location," << endl;
  cout << "this program sorts records in"<< endl;
  cout << "descending order by year and month," << endl;
  cout << "then displays a rainfall amount and"<< endl;
  cout << "mean temperature for each record,"  << endl;
  cout << "followed by totals and averages. "  << endl;
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

  //From the input file, get records rows of 
  //monthly weather data and store them in a 
  //single array with multiple fields (columns)

  //Declare and initialize variables

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

void sortData (int count, Weather w[])
{

  //Sort data in the weather array in descending
  //order by year and month


  //Declare variables

  int i;
  int j;

  Weather t;  //Temporary structure
 
  //Sort values

  for (i = 0; i < count; i++)
  {
    for (j = i + 1; j < count; j++)
    {
      if (w[i].year < w[j].year 
      || w[i].year >= w[j].year
      && w[i].mint < w[j].mint)  
      {
        t    = w[i];
        w[i] = w[j];
        w[j] = t   ; 

      }//End if
  
    }//End inner loop

  }//End outter loop     


}//End sortData 

void putData (int count, Weather w[])
{
  //To the console, output weather records (lines)
  //of monthly weather data from the weather array

  //Declare variables

  int i;

  string mabbr;

  cout << endl;
  cout << "Loc   Year   Mon    Rain    Temp" <<endl;
  cout << "---   ----   ---    ----    ----" << endl;
  cout << endl;

  //Format and output detail data lines

  cout << fixed << showpoint;

  //Total the console, output array values

  for (i = 0; i < count; i++)
  {
    
    mabbr = setAbbr (w[i].mint);
 
    cout << setw(6) << left  << w[i].loc;
    cout << setw(4) << left  << w[i].year;
    //cout << setw(6) << right << w[i].mint;
    cout << setw(7) << right << mabbr;
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
  double avgT;
  double avgR;

  totrain = 0;
  tottemp = 0;
  
  for (i = 0; i < count; i ++)
  {
    totrain += w[i].rain;
    tottemp += w[i].temp;

    avgR = totrain / count * 1.0;
    avgT = tottemp / count * 1.0;

  }

  cout << endl;

  cout <<"Total" << setw(19) << setprecision(2)<<
         totrain << setw(8)<< setprecision(1) << tottemp << endl;

  cout <<"Average" << setw(17) << setprecision(2)<<
         avgR << setw(8)<< setprecision(1) << avgT << endl;
  
}  //End putFoot

string setAbbr (int mint)
{
  string mabbr; //Month abbreviation
   
  switch (mint)

  {
    case  1: mabbr = "Jan.";  break; 
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


}//End setAbbr






















  