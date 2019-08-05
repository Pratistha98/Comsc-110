/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 6
Program: Pr06b-Avg-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Sep. 19, 2017

Purpose: Learn about or review looping, console
         input, validation, initialization,
         incrementation, accumulation, sentinel
         processing, type casting, formatting and 
         console output.


Initial
Problem: Loop to input a series of integers.
         Validate that the integers are positive
         and less than or equal to 99.

         Count them and add their values.
         
         Format the console for floating-points
         results.

         Output the count and the sum of the 
         entered integers, though as floating-point
         results.

         See the course website for documents that 
         show sample console interaction, and coding
         conventions.

         For other details, watch the classroom 
         screen, and listen to instructions.


Next
Problem: Do several more things
         
         While validating entered values, make sure
         they are numeric, and integers
  
         When done inputting, and after outputting
         sum and count, calculate and output a 
         floating-point average of the entered
         values.

*/


//Preprocessor directives

#include <iomanip>
#include <iostream>

using namespace std;


//Main routine

int main()

{

  //Declare variables

  int   num;   //Number  (input)
  int   sum;   //Sum     (accumulated)
  int   count; //Count   (incremented)

  float avg;   //Average (calculated)

               
  //Initialize an accumulator and a counter
 
  sum   = 0;
  count = 0;
  

  //To the console, output title, descriptions and
  //instructions

  cout << "                             " <<endl;
  cout << "Averaging Program            " <<endl;
  cout << "-----------------------------" <<endl;
  cout << "                             " <<endl;

  cout << "This program adds and counts   " <<endl;
  cout << "positive integers less than or " <<endl;
  cout << "equal to 99. It then calculates" <<endl;
  cout << "their average.                 " <<endl;
  cout << "                               " <<endl;
  
  cout << "Enter values until ready to quit, "<<endl;
  cout << "then enter 0.                     "<<endl; 
  cout << "                                  "<<endl;

  
  //Loop to prompt, input, validate, add and count

  while (true)
  {
    //Prompt for a number, then input it
 
    cout << "Number ? ";
    cin  >> num; 
    
    //Guard against a non-numeric value,
    //Guard against a non-integer value,
    //Guard against a out-of-range value,
    //then either quit or calculate


    if (num < 0 || num >99 )
    {
      cout << "Invalid: out of range " << endl;
    }

    else if ( num == 0 )
    {
      break;
    } 

    else
    {
      sum   = sum   + num; //Accumulate
      count = count + 1;   //Increment
    }
    
  } //End while

  
  //Format floating-point console results
   
  cout << fixed << showpoint << setprecision(1);

  //To the console, output sum and count as 
  //floating-points values

  cout << "                         " << endl;
  cout << "Sum    : "                 << setw(4) << float(sum)   << endl;
  cout << "Count  : "                 << setw(4) << float(count) << endl;
  

  //Calculate average

  if (count == 0)
  {
    avg = 0.0;
  }

  else
  {

  avg = sum * 1.0 / count ;
  
  }

  cout << "Average: "  << setw(4) << avg   << endl;

     

  

}   