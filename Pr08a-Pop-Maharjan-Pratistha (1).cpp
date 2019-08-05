/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 8
Program: Pr08a-Pop-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Oct. 5, 2017

Purpose: Learn about functions, including return
         values (also known as error levels.)

         Review console input, validation,
         counting, accumulating, averaging,
         formatting and console output.

Problem: Use a function to output a program
         heading.

         Use another function to get an validate
         population figures. For a program
         description, see the main routine. 

         In that function, if a population figure
         is not zero, consider it invalid if it is
         less than or equal to one million or
         greater than four million. 

         In the main routine, format and output the
         sum and count of population figure.
 
         Use a function to calculate, format and
         output an average.
 
         To the operating system, send back either
         zero to indicate a positive count, or else
         a non-zero value.

        Use a batch file to run the program and to
        display the error level.

        Watch and listen in class, and refer to a 
        console document for more information.

        When done submit both source (.cpp) and 
        batch (.bat) files.

*/

// Preprocessor directives

#include <iomanip>
#include <iostream>

using namespace std;

//Functions

void putHead()

{

  //To the console output a program heading

  cout << endl;
  cout << "Population program                 "<< endl;
  cout << "-----------------------------------"<< endl;
  cout << endl;
  cout << "Research and enter the populations " << endl;
  cout << "of California's three most populous" << endl;
  cout << "cities, each rounded to the nearest" << endl;
  cout << "thousand. When done, enter 0.      " << endl; 
  cout << endl;
  cout << "This program then calculates and   " << endl;
  cout << "outputs a sum count average.       " << endl;
  cout << endl;


}

int getPop()
{
  //From the console, get and validate population

  int pop; //Population

  while (true)
  {
    cout << "Pop ? ";
    cin  >>  pop    ;

    if (cin.peek() != '\n')
    {
      cout << "Invalid: not an integer \a\n";
      
      cin.clear();
      cin.ignore (1000, '\n');

    }//End if

    else if (pop == 0 )
    {
      break;
   
    }//End elseif
   
    else if (pop <= 1000 || pop > 4000 )  
    {
      cout <<"Invalid: Out of range \a\n";
    } //End else

    else
    {
      break;
    }//end else

    
         
  }//End while

  return pop; //send the value inside the variable 
              //back to main routine

}// end Get

void calcAvg (int sum, int count)
{

  //Calculate and output average population

  double avg;    //Average population

  //Format output

  cout << fixed << showpoint << setprecision(1);

  //Output average

  if (count == 0)
  {
    avg = 0;
    
  }//End if
  
  else
  {
    avg = double (sum) / count;
 

    cout << "Avg  :" << setw(7) << avg << "\n";
  }

 
}//End void


//Main routine

int main()
{
  //Decalre variables

  int   pop;  //Population
  int   sum;  //Sum
  int count;  //Count 
 
  //Initialize accumulators and counters

  sum   = 0;
  count = 0;

  //To the console, output program headings

  putHead();

  //Get population, accumulate sum, increment count

  while (true)
  {
    pop = getPop();
    
    if (pop == 0 )

    {
      break;

    }//end if 

    sum = sum + pop; //Accumulate sum
    count++;         //Increment count
       
  }//End while
  
  //Format output for sum and count

  cout << fixed;

  //To the console, output sum and count

  cout << endl;
  cout << "Sum  : " << setw(4) << sum  << endl;
  cout << "Count: " << setw(4) << count << endl;
   
  //Calculate and output average

  calcAvg (sum, count);

  //To the operating system, return error level
  
  if (count > 0)
  {
    return 0;
  }
  else
  {
    return 4;
  }

  
  

}//End  main









  














