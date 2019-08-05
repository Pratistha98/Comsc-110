/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 7
Program: Pr07c-Int-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Oct. 3, 2017

Purpose: Learn about the switch and case commands,
         and about an interest formula.

         Review event-controlled iteration and
         conditional statements to get and
         validate input data.

         Review count-controlled iteration to 
         repeatedly calculate and output results.


Problem: In the main routine, see the program 
         description.
      
         Watch and listen in class, and refer to a 
         console document on our course website.

*/

  
//Preprocessor directives

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#include <cmath>

//Main routine

int main()

{
  //Declare variables

  double prin;   //Principal (starting balance)
  double bal;    //Balance   (end of month)

  double r1;     //Rate of annual interest (pct.)
  double rx;     //Rate at 1x, or 2x or 3x (dec.)

  int  mint;     //Month integer (number)
  
  string mabbr;  //Month abbreviation (name)
 
  //To the console, output title, description and 
  //instructions

  cout << endl;
  cout <<"Interest Program " << endl;
  cout <<"----------------------------------"<< endl;
  cout << endl;
  cout <<"This program compounds interest"   << endl;
  cout <<"monthly to output ending balances" << endl;
  cout <<"for each month of a year."         << endl;
  cout << endl;
  cout <<"It does so for 1, 2 and 3 times the"<< endl;
  cout <<"original rate of interest."        << endl;
  cout << endl;
  cout <<"Enter a positive principal less than" <<endl;
  cout <<"or equal to 250000.00, and a       " <<endl;
  cout << "positive annual interest percentage" << endl;
  cout <<"less than or equal to 100.0."        <<endl;
  cout << endl; 
  
  //From the console, get and validate principal

  while (true)
  {
    cout << "Principal? ";
    cin >> prin;

    if (cin.peek() != '\n')
    {
      cout << "Invalid: nonnumeric \a\n";

      cin.clear ();
      cin.ignore (1000, '\n');

    }//End If
    
    else if (prin <=0 || prin >= 250000.00)
    {
      cout << "Invalid: out of range \a\n";
    }//End else if
     
    else
    {
      break;
    }//End else

  }//End while

  cout << endl;
  
  //From the comsole, get and validate interest

  while (true)

  {
    cout << "Interest ? ";
    cin >> r1;

    if (cin.peek() != '\n')
    {
      cout << "Invalid: nonnumeric \a\n";

      cin.clear ();
      cin.ignore (1000, '\n');

    }//End If
    
    else if (r1 <=0 || r1 >= 4 )
    {
      cout << "Invalid: out of range \a\n";
    }//End else if
     
    else
    {
      break;
    }//End else

  }//End while

  //To the console, output a column headings

  cout << endl;
  cout << "           Ending Balance    " << endl;
  cout << "       -------------------" << endl;
  cout << "Mon.          "<<r1<< "%" << endl;

  //cout << setw(3)  r1   << "%"<<  endl;
  //cout << setw(3)  r1*2 << "%"<<  endl;
  //cout << setw(3)  r1*3 << "%"<<  endl;
   cout <<"-----  ---------      " << endl;         
  
  
  //Format fixed-show point output

  cout << fixed << showpoint << setprecision (2); 

  //Convert the starting interest rate to a decimal


  r1 = r1/100.0;

  //Process data for 12 months
  
  for (mint=1; mint <13; mint++)
  {
    //Determine and output month abbreviation 

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

    }//End switch

    cout << '\n' << mabbr;

    //Calculate and output monthly ending balance
    
    //for (rx = r1; rx <=1 

    bal = prin * pow ( 1 + r1 / 12 , mint);
   
    cout << "  " << setw(10) << bal;

     

  }//End for

  cout << endl;
}




































