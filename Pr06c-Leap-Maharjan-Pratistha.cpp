/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 6
Program: Pr06c-Leap-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Sep. 21, 2017

Purpose: Continue learning about looping, data
         validation and conditional logic.

Initial 
Problem: Since the advent of the Greogoria 
         calender, determine which years are leap
         years, except for a possible inacuuracy
         related to century years.
 
Next
Problem: Refine the program's logic to better
         validate input, and to more accurately 
         identify century years that are leap
         years.

         For more information, listen and watch in 
         class, refer to a console document on 
         our course website, search the
         internet.

Data
Source: http://en.wikipedia.org/wiki
              /Gregorian_calendar

*/


//Preprocessor directives

#include <iostream>
using namespace std;

//Main routine

int main ()

{
  //Declare variables

  int greg;  //Year Gregorian calendar was introduced
  int now ;  //Current year  

  int  beg;  //Year to begin processing
  int  end;  //Year to end   processing

  int  year; //Year to process
  
  char leap; //Leap year   ?
  char cent; //Century year?


  //Initialize variables

  greg = 1582;
  now  = 2017;

  //To the console output a program title, a 
  //program description, and some user instructions

  

  cout << endl;
  cout << "Leap Year Program             " <<endl;
  cout << "------------------------------" <<endl;
  cout << endl;

  cout << "This program determines whether"<<endl;
  cout << "years are leap years (Y means  "<<endl;
  cout << "yes, N means no).              "<<endl;
  cout << endl;

  cout << "Choose the years for which to    " <<endl;
  cout << "begin and end processing, between" <<endl;
  cout << "and including " << greg << " and "
                                << now << "." <<endl; 

  cout << endl;
  
  //Loop to prompt the user for a beginning year,
  //to input the year, and to validate it

  while (true)
  {

    cout << "Begin? ";
    cin  >> beg      ;

    if ( beg < greg || beg > now )

    {
      cout << "Invalid " << endl; 

    } 

    else 
    {
      break;
  
    }
  }//End While

  cout <<    endl;  

  //Loop to propmt the user for ending year,
  //to input the year, and to validate it

  while (true)
  {

    cout << "End  ? ";
    cin  >>  end   ;

    if ( end < greg || end > now )

    {
      cout << "Invalid " << endl; 

    } 

    else 
    {
      break;
  
    }

    
        

  }//End while

  //To the console, output two column headings

  cout << endl;
  cout << "Year   Leap? " << endl;
  cout << "----   -----"  << endl;
  cout << endl;
  
  //Initialize year

  year = beg;

  //Loop to output years and to indicate which
  //ones are leap years
   
  while (true)
  {
    leap = 'N';
    cent = 'N';

    if (year % 100 == 0) 
    {    
      cent = 'Y' ; 
    
    
    }
    
    if ( cent == 'Y' && year % 400 == 0 )
    {
      leap = 'Y';
    }

    if (cent == 'N' && year % 4 == 0 )
    {
      leap = 'Y';
    }

    cout << year << "   " << leap << endl;

    year = year + 1;
   

    if (year >end)
    {
     break;
    }
   
    

  }//End while
 

    
}




































