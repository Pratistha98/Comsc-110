/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 4
Program: Pr04b-CV-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Sep. 5, 2017

Purpose: Use C++ to calculate the future value(FV)
         of a couple dollar amounts.

         While doing so, learn to raise a number
         to a power with the math function (pow)

         Neatly format output with appropriate 
         widths and number of digits to the right
         of each decimal point, as shown on the
         big screen.


First
Problem: Calculate the future value (FV) of a 
         stream of monthly deposits that earns
         monthly compound interest as:

         --Scenario 1, for 10 years at a yearly
           interest rate of 4% on monthly deposits 
           of $100


Second 
Problem: Do another calculation:

         --Scenario 2, for 20 years at a yearly
           interest rate of 8% on monthly deposits 
           of $200

         For the second scenario, use the SAME
         variables as for the first scenario.
         Assign new values to the same variables.

         Do NOT re-declare the same variables, 
         and do not declare new variables.
*/


//Preprocessor directives

#include <iomanip>
#include <iostream>

using namespace std;

#include <cmath>


int main()
{

  //Declare variables, but do NOT yet assign values

  //Double-type variables will hold more accurate
  //results than float-type variables

  double s; //Sum of the deposits and monthly
            //compound interest (future value)

  double y; //Years (number of)

  double r; //Rate of yearly interest
            //(percentage as decimal)

  double t; //Time periods (number of months)

  double p; //Rate of monthly interest
            //(percentage as decimal)

  double d; //Deposit amount per month (dollars)


  //To the console, output 

  cout << "                         "<< endl;
  cout << " Future Value program    "<< endl;
  cout << "------------------------ "<< endl;
  cout << "                         "<< endl;

 
  //Begin formatting floating-point results
  
  cout << fixed << showpoint;

  
  //Scenario 1

  //Assign values to variables

  y =  10.0 ;
  r =   0.04;
  d = 100.00;

  //Calculate results

  t = y * 12.0;
  p = r / 12.0;
  s = d * ((pow (1.0 + p, t) - 1.0 )/ p) ;


  //To the console, output headings

  cout << "                            " << endl;
  cout << "Scenario 1                  " << endl;
  cout << "----------------------------" << endl;
  cout << "                            " << endl;

  //Continue formatting floating-points results
  //and to the console, output results

  cout << "Years           : " << setprecision( 0)
                               << setw         (9)
                               << y << endl;

  cout << "Yeraly interest : " << setprecision( 4)
                               << setw        (13)
                               << r * 100 << " %\n";
 
  cout << "Months          : " << setprecision ( 0)
                               << setw         ( 9)
                               << t << endl;

  cout << "Monthly interest: "   << setprecision(4)
                                << setw       (13)
                                << p * 100 <<" %\n"; 

  cout << "Monthly deposit : $" << setprecision( 2)
                                << setw        (10)
                                << d  <<endl;

  cout << " Future Value   : $" <<setprecision ( 2)
                                <<setw         (10)
                                << s << endl;


//Scenario 2

  //Assign values to variables

  y =  20.0 ;
  r =   0.08;
  d = 200.00;

  //Calculate results

  t = y * 12.0;
  p = r / 12.0;
  s = d * ((pow (1.0 + p, t) - 1.0 )/ p) ;


  //To the console, output headings

  cout << "                            " << endl;
  cout << "Scenario 2                  " << endl;
  cout << "----------------------------" << endl;
  cout << "                            " << endl;

  //Continue formatting floating-points results
  //and to the console, output results

  cout << "Years           : "  << setprecision( 0)
                                << setw         (9)
                                << y << endl;

  cout << "Yeraly interest : "  << setprecision( 4)
                                << setw        (13)
                                << r * 100 << " %\n";
 
  cout << "Months          : "  << setprecision ( 0)
                                << setw         ( 9)
                                << t << endl;

  cout << "Monthly interest: "  << setprecision(4)
                                << setw       (13)
                                << p * 100 <<" %\n"; 

  cout << "Monthly deposit : $" << setprecision( 2)
                                << setw       (10)
                                << d  <<endl;

  cout << " Future Value   : $" <<setprecision ( 2)
                                <<setw         (10)
                                << s << endl;
 
  
}  


