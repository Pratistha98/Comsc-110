/*
School : Diablo Valley College
Term   : 2017 Fall
Course : ComSc-110-3120,
         Introduction to Programming (with C++)

Chapter: 9 (sec. 9.4), 11(sec. 11.3), and 13
Program: Pr13b-Pres-Maharjan-Pratistha.cpp
Author : Maharjan, Pratistha
Date   : Nov.21, 2017

Purpose: Similar to program Pr13a-Pres. but also:
         
         --lean to search an array, to identify
           maximum and minimum array values, and
           to set and use a Boolean indicator.

         --review the concatenation of string
           values.
        
Problem: Process data regarding American presidents
         as shown in class and in a sample
         console document on our course website.

Data   : From our course web site, download two
         data files:

         Pr13b-Pres-Real.in
         Pr13b-Pres-Fake.in

Submit: Just submit a source program (.cpp) file.
*/

//Preprocessor directives

#include  <fstream>
#include  <iomanip>
#include  <iostream>
#include  <string>

using namespace std;

//Structure

struct Pres 
{
  int      ord; //Order of term
  string  last; //Last name
  string  init; //Initials
  char     gen; //Gender
  int    birYr; //Birth year
  int    birMo; //Birth month
  int    trmYr; //Term year
  int    trmMo; //Term month
  int      age; //Age (at start of the term)   
}; //end struc


//Level Function Prototypes

void   putHead  ();
string getName  ();
int    countRec (string);
void   getData  (string, int, Pres*);
void   calcAge  (int, Pres*);
void   putData  (int, Pres*);
void   putFoot  (int, Pres*);
//Main routine

int main()
{

  //Declare variables

  string ifname; //Name of the input file
  int    count ; // Count of input records
  Pres*      p ; //List of presidents
  
  //Call functions

  putHead ();
  ifname = getName();
  count = countRec(ifname);
  
  p = new Pres [count];  //Make list instance
  
  getData (ifname, count, p); //Get input data
  calcAge (count, p);
  putData (count, p);
  putFoot (count, p); 

  return 0 ; 
  


}//End main

void putHead()
{
  //To the console, output program headings
  //(title and description)
  cout << endl;
  cout << "President Program" << endl;
  cout << "------------------------------------" << endl;
  cout << endl;
  cout << "This program asks for the name of a " << endl;
  cout << "file of data about  American        " << endl;
  cout << "presidents, validates the file name," << endl;
  cout << "counts the file's records, inputs   " << endl;
  cout << "records into a dynamically-sized    " << endl;
  cout << "array and outputs results to the    " << endl;
  cout << "console"                              << endl;  
  cout << endl;
  cout << "This program also identifies the    " << endl;
  cout << "maximum and minimum age of all      " << endl;
  cout << "presidents, determines whether any  " << endl;
  cout << "president has been female, and      " << endl;
  cout << "outputs these results, too.         " << endl;
  cout << endl;

}//End putHead

string getName ()


{
  string ifname;
  ifstream fin;
  
  while (true)
  {
    cout << "Input file name? " ;
    cin  >> ifname;
    
    fin.open (ifname);

    if (fin.good() == true )
    {
      fin.close();
      break;
    }//End If
     
    else
    {
      cout << "Invalid \a\n";

    }//End else
   
  }//End While

  return ifname;
  

}//End getName

int countRec (string ifname)
{
  //From a file, count the number of records to 
  //process
 
  //Declare and initialize variables
  
  ifstream fin;  //Input file object

  string   rec;  //Input record (row)

  int     i;     //Loop index
  int count;     //Record count

  i = 0;
  
  //Count records

  fin.open(ifname);

  while (getline (fin, rec))
  {
    i++;
    
  }//End while

  fin.close();
  
  count = i;
  
  return count;
 
}//End countRec


void getData (string ifname, int count, Pres* p)
{
  //From a file, get records about American 
  //presidents

  //Declare variables

  ifstream fin;   //Input file object
  
  int i;          //Array index

  //Get Data

  fin.open(ifname);

  for ( i = 0 ; i < count; i++)
  {
    fin >> p[i].ord;
    fin >> p[i].last;
    fin >> p[i].init;
    fin >> p[i].gen;
    fin >> p[i].birYr;
    fin >> p[i].birMo;
    fin >> p[i].trmYr;
    fin >> p[i].trmMo;
   
  }//End for
  
  fin.close();

  
}//End getData


void calcAge (int count, Pres*p)
{
  //Calculate presidents' ages at the start of 
  //their terms of office.

  //Declare variables

  int    i;   //Array index
  int  age;
  
  //Calculate
  for ( i = 0; i < count; i++)
  {
    if (p[i].trmMo > p[i].birMo)
    {
      p[i].age = p[i].trmYr - p[i].birYr; 

    }//End if 
    else
    {
      p[i].age = p[i].trmYr - p[i].birYr - 1 ;
    }//End else
   
  }
    

}//End calcAvg

void putData (int count, Pres*p)
{
  //To the console, output records about American
  //presidents

  //Declare variables

  int i;  //Loop index
  string conc;

  //Output column headings

  cout << endl;
  cout << "                              Birth       Term      " << endl;
  cout << "                           --------   --------      " << endl;   
  cout << "Ord  Name                G  Year  Mo  Year  Mo  Age " << endl;
  cout << "---  ------------------  -  ----  --  ----  --  --- " << endl;
  cout << endl;

  //Output data

  for (i = 0; i < count; i++)
  {
    cout << right; 
    cout << setw( 3) << p[i].ord << "  ";

    
    conc = p[i].last + "," + " " + p[i].init ;
    cout << left;
    cout << setw(20) << conc;
    
    cout << setw(3) << p[i].gen;
    
    cout << right;
    cout << setw(4) << p[i].birYr;
    cout << setw(4) << p[i].birMo;
   
    cout << setw(6) << p[i].trmYr;
    cout << setw(4) << p[i].trmMo;
    cout << setw(5)  << p[i].age << endl;
  
    
   
      
  }//End for

}//End putData


void putFoot (int count, Pres*p)
{

  //To the console, output a footing with maximum
  //and minimum ages, and with a gender indicator

  //Declare and initialize variables

  int i;        //Loop index
  int maxAge;   //Maximum age
  int minAge;   //Maximum age
  bool female;  //Any female presidents ?

  female = false;
  
  maxAge = p[0].age;
  minAge = p[0].age;
  
  //Output footings

  for (i = 0; i < count; i++ )
  {
    if ( maxAge < p[i].age )
    {
      maxAge = p[i].age  ;

    }//End if

    if ( minAge > p[i].age )
    {
      minAge = p[i].age  ;

    } //End if

    if (p[i].gen == 'F')
    {
      female = true ;
    }//End if


    
  }//End for 
  
  cout << endl;
  cout << setw(49) << "Max. age:  " << maxAge << endl;
  cout << setw(49) << "Min. age:  " << minAge << endl;
  cout << endl;
  
  if ( female == true)
  {
   cout << setw(49) << "Female  ?  " << "Yes" << endl;
  }
  
  else if (female  == false )
  {
   cout << setw(49) << "Female  ?  " << "No" << endl;
  }
  
}//End putFoot






























