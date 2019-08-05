/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 6
Program: Pr06a-Tax-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Sep. 14, 2017

Purpose: Learn about branching statements that
         evaluate either simple or compound
         conditions.

         Review calculations, and the neat
         formatting of console output.

Initial
Problem: Based on an annual income amount that a 
         user enters, calculate an output an 
         estimated tax amount that the user may 
         owe the Internal Revenue Service (IRS).

         See the course website and/or the internet
         for documents that show sample console 
         interactions, year 2017 federal tax 
         brackets, and coding conventions.

         For other details, watch the classroom
         screen, and listen to the instructions.


Next 
Problem: Validate the income that a user enters.
         If it is too low or too high, output an
         error message, and end the program.

Data
Sources: https://taxfoundation.org/2017-tax-brackets


*/


//Preprocessor directives

#include <iomanip>
#include <iostream>

using namespace std;


//Main routine

int main()

{

  //Declare variables

  int   year;  //Tax year
  
  float inc;   //User's annual income (dollars)

  float high1; //High end income for bracket 1
  float high2; //High end income for bracket 2
  float high3; //High end income for bracket 3

  float btax1; //Base tax amount for bracket 1
  float btax2; //Base tax amount for bracket 2
  float btax3; //Base tax amount for bracket 3

  float rate1; //Tax rate for bracket 1 (percent)
  float rate2; //Tax rate for bracket 2 
  float rate3; //Tax rate for bracket 3

  float low;   //Low end income for user's bracket
  float high;  //High end income for user's bracket

  float exc;   //Excess income(above low end
               //of user's bracket)

  float rate;  //Tax rate(percent.) for user;s
               //excess income

  float btax;  //User's base tax amount 
  float etax;  //User's excess tax amount
  float ttax;  //User's total tax amount

  

  //Assign values

  year = 2017;

  high1 =  9325.00;
  high2 = 37950.00;
  high3 = 91900.00;

  btax1 =     0.00;
  btax2 =   932.50;
  btax3 =  5226.25;

  rate1 =     10.0;
  rate2 =     15.0;
  rate3 =     25.0;

  //To the cosole, output title, description and 
  //instructions

  cout << "                                  " <<endl;
  cout << "Tax Program                       " <<endl;
  cout << "----------------------------------" <<endl;
  cout << "                                  " <<endl;

  cout << "This program calculates a U.S.    " <<endl;
  cout << "federal income tax amount for     " <<endl;
  cout << "a single person of modest means.  " <<endl;
  cout << "                                  " <<endl;
  
  cout << "For year " << year; 
  cout << ", enter an annual "                 <<endl;
  cout << "income as a positive dollar amount" <<endl;
  cout << "less than or equal to " << high3;
  cout << ". "                                 <<endl;
  cout << "                                  " <<endl;

  //To the console, prompt the user for annual
  //income, and input it

  cout << "Income   ? ";
  cin  >>  inc;
  
  //Validate the user's income

  if  (inc <= 0 || inc > high3 )
  {
    cout << "Invalid:  Out of range          ";
    return 4;
  } 

  
  //Identify the user's tax bracket
  
  if (inc > 0 && inc <= high1)
  {
    low  = 0;
    high = high1;
    rate = rate1;
    btax = btax1;

  }

  if (inc > high1 && inc <= high2)
  {
    low  = high1;
    high = high2;
    rate = rate2;
    btax = btax2;
  }

  if (inc > high2 && inc <= high3)
  {
    low  = high2;
    high = high3;
    rate = rate3;
    btax = btax3;

  }

  //Calculate the user's tax amounts

  exc  = inc - low;

  etax = rate / 100.0 * exc;

  ttax = btax + etax;


  //Set the console formatting, then output results

  cout << fixed << showpoint << setprecision(2);

  cout << endl;

  cout << "Bracket    "                       <<endl;
  cout << " Low     : " << setw(8)  << low    <<endl;
  cout << " High    : " << setw(8)  << high   <<endl;       
  cout << "Base tax : " << setw(25) << btax   <<endl;
  cout << "Exc. inc : " << setw(8)  << exc   <<endl;
  cout << "Tax rate : " << setw(8)  << rate  << " %" <<  endl;
  cout << "Exc. tax : " << setw(25) << etax    <<endl;
  cout << "                             ------"<<endl;
  cout << "Tot. tax : " << setw(25) << ttax   <<endl;
  
  
           
}
















         

















 