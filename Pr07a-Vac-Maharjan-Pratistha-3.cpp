/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 7
Program: Pr07a-Vac-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Sep. 26, 2017

Purpose: Learn about conditional logic with 
         types of statements known as else if
         and nested if.

         Learn to sound an audible alert with the
         escape character '\a' when a user enters
         invalid data. 

         Review continuous looping, and the
         toupper () function.

Initial
Problem: Inform a user of vacation costs for 1 
         or 2 passengers, depending on the month
         of year, and prepare a tentative 
         reservation.

 
Next
Problem: Refine the process to confirm a 
         reservation.

*/

//Preprocessror directive


#include <iostream>
#include <string>

using namespace std;

#include <cctype>

int main()

{

  //Declare Variables

  string fname;   //First name
  string lname;   //Last  name
  string mabbr;   //Month abbreviation (Xxx.)

  int     mint;   //Month number (integer)
  int      pax;   //Passenger count
  int     cost;   //Vacation cost

  char    conf;   //Confirmation (Y or N)

  

  //To the console, output title and instructions

  cout << endl;
  cout << "Vacation Program " << endl;
  cout << "-------------------------------" <<endl;
  cout << endl;
  cout << "Welcome to Dream Vacation Cruises"   << endl;
  cout << "(DVC)! Please look at our prices "   << endl;
  cout << "the choose a month, and a number of" << endl;
  cout << "passengers, for which to possibly "  << endl;
  cout << "reserve a vacation. "                << endl;
  cout << endl;
  
  cout << "Mon.    1 Pax   2 Pax " << endl;
  cout << "----   ------  ------ " << endl;
  cout << endl; 

  cout << "  1   $  1400  $ 2100 " << endl;  
  cout << "  2      1400    2100 " << endl;
  cout << "  3      1400    2100 " << endl; 
  cout << "  4      2000    3000 " << endl;
  cout << "  5      2000    3000 " << endl;   
  cout << "  6      2000    3000 " << endl; 
  cout << "  7      2000    3000 " << endl;  
  cout << "  8      2000    3000 " << endl;  
  cout << "  9      2000    3000 " << endl;   
  cout << " 10      1400    2100 " << endl;
  cout << " 11      1400    2100 " << endl;
  cout << " 12      1400    2100 " << endl;
  cout << endl;

  //At the console, prompt for a passenger's last
  //and first names, then input them

  cout << "Last name   ? ";
  getline (cin, lname); 
  
  cout << "First name  ? ";
  getline (cin, fname);
  cout << endl;

  //At the console, prompt for a month number,
  //then input it , and validate it

  while (true)
  {
    cout <<"Month (1-12)? "; 
    cin  >> mint;

    if (cin.peek() != '\n')
    {
      cout << "Invalid: non-integer \a\n";
      
      cin.clear();
      cin.ignore(1000,'\n');   
      
    }//end if
  
    else if (mint < 1 || mint > 12)    
    {
      cout << "Invalid: out of range \a\n";
 
    }//End else if

    else
    {
      break;
   
    }//end Else
    
  }//End while

  cout << endl;

  //At the console, prompt for a passenger count,
  //then input it, and validate it
 
  while (true)
  {

  cout << "Pax  (1 - 2)? ";
  cin  >> pax;

    if (cin.peek() != '\n')
    {
      cout << "Invalid: non-integer \a\n";
      
      cin.clear();
      cin.ignore(1000,'\n');   

    }//end if
 
    else if (pax < 1 || pax > 2)    
    {
      cout << "Invalid: out of range \a\n";
 
    }//End else if

    else
    {
      break;
   
    }//end Else

  }//End while

  cout << endl;

  //Assign month abbreviation

  if      (mint ==  1)  mabbr = "Jan.";
  else if (mint ==  2)  mabbr = "Feb.";
  else if (mint ==  3)  mabbr = "Mar.";
  else if (mint ==  4)  mabbr = "Apr.";
  else if (mint ==  5)  mabbr = "May ";
  else if (mint ==  6)  mabbr = "Jun.";
  else if (mint ==  7)  mabbr = "Jul.";
  else if (mint ==  8)  mabbr = "Aug.";
  else if (mint ==  9)  mabbr = "Sep.";
  else if (mint == 10)  mabbr = "Oct.";
  else if (mint == 11)  mabbr = "Nov.";
  else if (mint == 12)  mabbr = "Dec.";
  else                  mabbr = "??? ";

  //Determine cost

  if ((mint >=  1 && mint <= 3)
  ||  (mint >= 10 && mint <=12))
  {
    if (pax == 1)
    {
      cost = 1400;

    }//end inside if

    else
    {
      cost = 2100;
    }//end else 

  }// end outside if
  
  else if (mint >= 4 && mint <=9 )
  {

    if (pax == 1)
    {
      cost = 2000;

    }//end inside if

    else
    {
      cost = 3000;
    }//end else 

   
  }//end if for 4
  else
  {
    cost = 0;
  }

  
  
  //At the consile, confirmation of reservation

  cout <<"Hello, "<< fname<< " " << lname << "." << endl;
  cout << endl;
  cout <<"Your vacation for " << pax  ;
  cout <<" passenger(s) in "<< mabbr  ;
  cout <<" would cost $" << cost << "."; 
  cout << endl;
  cout << endl;   

  while (true)
  {  
    cout << "Confirm (Y/N)? " ;
    cin >> conf;

    conf = toupper(conf);
  
    if ( conf == 'Y') 
    {
      cout << endl;
      cout << "Thank you for your reservation. " << endl;

    break;
    }

    else if ( conf == 'N')
    {
      cout << endl;
      cout << "Maybr another time " << endl;

    break;
    }
    else 

    {
    cout << " Invalid \a\n";
  
    cin.clear();
    cin.ignore (1000, '\n');
    }
  }

	
}





















