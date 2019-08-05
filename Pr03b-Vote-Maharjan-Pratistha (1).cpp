/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (With C++)

Program: Pr03b-Vote-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Aug. 29, 2017

Purpose: Continue getting familiar with concepts in 
         Chapter 3, including variables, values,
         and calculations.

Problem: Output a program title and some column
         headings, then output U.S. presidential
         election results for Democratic and 
         Republican (not third- party) candidates
         in years 2012 and 2016.

         For results, output popular (not
         electoral) vote counts expressed in 
         thousands, and their percentages of 
         all votes cast for the two major-party 
         candidates each year.

         For more informations, listen in class 
        and watch the big screen.

Data
Source:  https://www.270towin.com/2012_election/         
         https://www.270towin.com/2016_election/
 
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  
  // Declare variables

  string year;   //Election year
  
  string nameD;  //Candidate name, Democrat
  string nameR;  //Candidate name, Republican
  string nameA;  //Candidate name, all

  int countD;    //Popular vote count, Dem.
  int countR;    //Popular vote count, Rep.
  int countA;    //Popular vote count, all.
 
  float pctD;    //Popular vote percentage, Dem.
  float pctR;    //Popular vote percentage, Rep.

  //To the console, output a program title and
  //some column headings.
  
  cout << "                                " << endl;
  cout << "Popular Vote Program            " << endl;
  cout << "................................" << endl;
  cout << "                                " << endl;
  cout << "    U.S. Pres.    (000s)        " << endl;
  cout << "Year  Candidate Name  Count  Pct." << endl;
  cout << "----  --------------  -----  ---" << endl;
  cout << "                                " << endl;


  //First election year

  //Assign values

  year  ="2012";

  nameD = "Obama, Barack  ";
  nameR = "Romney, Mitt   ";
  
  countD = 65446;
  countR = 60589;

  //Calculate sum and percentages

  countA = countD + countR;

  //pctD = countD / countA;
  //pctR = countR / countA;

  pctD = countD * 100.0 / countA;
  pctR = countR * 100.0/  countA;

  //To the console, output results

  cout << year   << "  ";
  cout << nameD  << "  ";
  cout << countD << "  ";
  cout << pctD   << "  " << endl;


  cout << year   << "  ";
  cout << nameR  << "  ";
  cout << countR << "  ";
  cout << pctR   << "  " << endl << endl;
  


}
  