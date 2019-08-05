/*
School: Diablo Valley College
Term  : 2017 Fall
Course: ComSc-110-3120,
        Introduction to Programming (With C++)

Chapter: 3
Program: Pr03a-Patient-maharjan-pratistha.cpp
Author : Maharjan, Pratistha
Date   : Aug.24,2017

Purpose: Get familiar with:
         -- declaring variables of different types
         -- assigning values to variables
         -- outputting labels and variables values
         -- coding conventionns( see a seperate document on the course web site)
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  //Declare variables

  string name;         //Patient name    (last, First)
  char   gender;       //Patient gender  (M or F)
  int    age;          //Patient age     (years)
  int    height;       //Patient height  (inches)
 
  //Assign values to variables for patient 1

  name   = "Washington, Goerge";
  gender ='M';
  age    = 57;
  height = 74;
  
  //To the console, output labels and
  //output values for patient 1 variables

  cout << endl;
  cout << "Name  : " << name   << endl;
  cout << "Gender: " << gender << endl;
  cout << "Age   : " << age    << endl;
  cout << "Height: " << height << endl;
 
}
 