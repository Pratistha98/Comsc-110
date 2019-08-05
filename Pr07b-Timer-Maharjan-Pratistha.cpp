/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 7
Program: Pr07b-Timer-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Sep. 28, 2017

Purpose: Learn about timer simulation. This will
         involve iterating with nested loops,
         and delaying output with some form of
         a sleep function.
  
         It will also involve outputting leading
         zeros with the cout.fill() method,
         and returning the cursor to column 1 on 
         the same line with an '\r' escape code.

         Review sounding an audible alert with the
         '\a' escape code, and advancing the cursor
         to a new line with the '\n' escape code.

         Also review validating input with the
         cin.peek() method, and setting the width
         of an output field with the setw()
         function.


Problem: Output a digital timer that counts down 
         seconds since the program started.

         Use a stationery format in which the time 
         is constantly overwritten.
      
         Sound an audible alert every 5 seconds,
         on seconds evenly divisible by 5.

         Also process minutes (in addition to 
         seconds).

*/

//Preprocessor directive

#include <iomanip>
#include <iostream>

using namespace std;
#include <cstdlib> //_sleep() (optional)

//Main routine

int main()
{
  //Declare variables

  int sec;   //Seconds
  int min;   //Minutes

  int i;     //Minute loop index
  int j;     //Second loop index


  //To the console, output title and instructions

  cout << endl;
  cout << "Timer Program                  "   <<endl;
  cout << "-------------------------------"   <<endl;
  cout << endl;
  cout << "This program counts down to zero"  <<endl;
  cout << "from the starting time you enter." <<endl;
  cout << endl;
  cout << "Enter a number of minutes between" <<endl;
  cout << "0 and 2."                           <<endl;
  cout << endl;
  cout << "Enter a number of seconds between" <<endl;
  cout << "0 and 59."                          <<endl;
  cout << endl;

  //At the console, get and validate minutes

  while (true)
  {
    cout << "Minutes  (0-2)? ";
    cin  >> min;
    
    if (cin.peek() != '\n')
    {
      cout << "Invalid: non-integer \a\n";

      cin.clear();
      cin.ignore(1000,'\n');
 
    }//End if
   
    else if (min < 0 || min > 2)
    {
      cout << "Invalid: out of range \a\n";

    }//End else if

    else
    {
      break;
    } //end else  
  }//End while

  cout << endl;

  //At the console, get and validate seconds
  
  while (true)
  {
    cout << "Seconds (0-59)? ";
    cin  >> sec;
    
    if (cin.peek() != '\n')
    {
      cout << "Invalid: non-integer \a\n";

      cin.clear();
      cin.ignore(1000,'\n');
 
    }//End if
   
    else if (sec < 0 || sec > 59)
    {
      cout << "Invalid: out of range \a\n";

    }//End else if

    else
    {
      break;
    } //end else  
  }//End while

  cout << endl;

  //Format output to show a leading zero

  cout.fill('0');

  
  //To the console, count down 

  cout << "Starting the countdown timer"<< endl;
  cout << endl;
  
  for (i =  min; i >= 0; i--)
  {

    for (j = sec; j >= 0; j--)
    {
      cout << setw(2) << i << ":";
      cout << setw(2) << j << " ";

      if ( j % 5 == 0)
      {
        cout << '\a';
      }//end if 

      _sleep(1000);

      cout << '\r';

    }//End for (inner loop)

    sec = 59;

  }//End for (outter loop)

  cout << "\n\n";
  cout << "Done! \a\n";  


}//End of main routine



























