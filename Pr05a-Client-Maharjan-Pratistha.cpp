/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 5
Program: Pr05a-Client-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Sep. 7, 2017

Purpose: Create a program that interactively
         inputs data from the console, edits that
         data, and confirms the results to the 
         console.

         Learn about these commands and functions:
         cin, getline(), at(), and toupper().

Initial
Problem: At the console, prompt a user to input the
         name and address of a client, and actually
         input the data.

         Edit the data by concatenating the
         client's last and first names into a 
         combined field called name, with a comma
         and space between the two parts of the
         name. 
 
         At the console, output a confirmation of
         data that was input and edited.

         For more information, listen in class,
         watch the big screen, and refer to our
         course web site for a console sample.

Next
Problem: Declare a field called loc (for location)
         of a type that can hold letters, digits
         and punctuation marks.

         Further edit the data. Force the state
         code to uppercase.

         Also, concatenate city name, a comma and 
         space, state code, two spaces, and zip
         code, into the new field called loc.

         When confirming data, output the loc field
         for the client's address. Do NOT output
         city, state and zip as seperate fields.

*/

//Preprocessor directives

 
  #include <iostream>
  #include <string>

  using namespace std;
  #include <cctype>

  //Main routine

int main()
{
  //Declare variables

  string lname;   //Client last  name
  string fname;   //Client first name
  string name ;   //Client       name


  string street;  //Client street address
  string city  ;  //Client city   name
  string state ;  //Client state  code
  string zip   ;  //Client zip    code
  string loc   ;  //Client Location 

  //To the console, output a program title

  cout <<"                             " << endl;
  cout <<"Client Program               " << endl;
  cout <<"-----------------------------" << endl;

  //At the console, prompt the user to input data

  cout << "              \n";
  cout << "Input         \n"; 

  cout << "  Last  name  ? ";
//cin  >>   lname; 
  getline   (cin, lname);

  
  cout << "  First name  ? ";
//cin  >>   fname;
  getline   (cin, fname);
  
//cin.ignore (1000, 10);
  cout << " Street addr. ? ";
  getline   (cin, street);

  
  cout << "  City        ? ";
  getline   (cin, city);

  
  cout << "  State (XX)  ? ";
  cin  >>   state;
  cin.ignore (1000, 10);

  cout << "  Zip code    ? ";
  cin  >>   zip;

  
  //Edit data

  name = lname + ", " + fname;
  
  state.at(0) = toupper(state.at(0));
  state.at(1) = toupper(state.at(1));

  loc = city + ", " + state + "  " + zip;


  //Output a confirmation of edited data

  cout << "             \n";
  cout << "Confirmation \n";
  cout << "  Name        : "  << name << endl;
  cout << "  Location    : "  << loc  << endl;
 
  

  

}


  

 


    