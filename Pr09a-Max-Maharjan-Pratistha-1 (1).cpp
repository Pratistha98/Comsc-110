/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 9
Program: Pr09a-Max-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Oct.17, 2017 (deferred from Oct.12 
         due to school closure)

Purpose: Learn about bits, bytes and the maximum
         capacity of short integer variables.
         
         Introduce a second level function.
         
         Review looping, validation, conditions,
         type casting, and arithmetic.

Problem: Use a level one function to input,
         validate and process short integers.

         Use a level two function to output program
         footings that include a sum, count and
         average.

         Watch and learn in class, and refer to a
         console document for more information.
 
         Submit just a source program (.cpp) file.

*/

//Preprocessor directives

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//Function prototypes
 
void putHead ();
void procData();
void calcAvg (short,short);

int main()

{

  //Call level one functions
  
  putHead ();
 
  procData();

  return 0;

}

  //Level One Functions

  
void putHead()
  
{

  cout << endl;
  cout << "Maximum Program" << endl;
  cout << "------------------------------" << endl;
  cout << endl;
  cout << "This program demonstrates the "<< endl;
  cout << "maximum capacity of positive  "<< endl;
  cout << "short integers.               "<< endl;
  cout << endl;
  cout << "Enter positive integers that  " << endl;
  cout << "are less than or equal to     " << endl;
  cout << SHRT_MAX << ". " << "To quit, enter 0." <<  endl;
  cout << endl;
       
}

void procData()

{
  //Process data: get, validate, accumulate and
  //count numbers, then call a function to output
  //footings

  //Declare variables

  short num;   //Number (input)
  short sum;   //Total  (accumulated)
  short count; //Count  (counted)

  //Initialize variables

  sum   = 0;
  count = 0;
 
  //Get, validate, accumulate and count

  while (true)

  {
    cout << "Number ? ";
    cin  >> num;
    
    if (cin.peek() != '\n')
    {
      cout << "Invalid: not a short integer \a\n";

      cin.clear ();
      cin.ignore (1000, '\n');

    }//end if

    else if( num < 0 ) 
    {
      cout << "Invalid: negative \a\n";
  
    }//End else if

    else if (num == 0)
    {
     break;  
    }//end else if
   
    else
    {
      sum = sum + num;  //sum += num
      count ++;
    } 
   
  }//End while 

  calcAvg (sum, count);
  

  

}//Endprocdata

//Level Two Functions

void calcAvg (short sum, short count)

{
  //Validate statistics and to the console, output
  //footings

  //Declare variables

  string msg;  //Message

  float avg;   //Average

  //Format Output

  cout << fixed << showpoint << setprecision(1);

  //Validate and output statistics

  if (count == 0)
  {
    msg =   "Warning: count is zero";
    msg = msg + ", so average set to zero \a";

    avg = 0.0;
  }//End if

  else if (sum < 0)
  {
    msg =  "Warning: sum overflowed";
    msg = msg+ ", so average set to zero \a";
  
    avg = 0.0;
  
  }//End else if
 
  else 
  {
    avg = float (sum)/ count;
    msg = "Done";
  }//End else
 
  cout << endl;
  cout << "Sum    : " << sum << endl;
  cout << "Count  : " << count << endl;
  cout << "Average: " << avg  << endl;
  cout << endl;
  cout << msg << endl; 
}    

  

  
































