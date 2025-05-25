/* About this project: (This assignment will consist of writing a couple
 functions and allowing the student to gain practice and understanding of random number generation,
 pass by reference, and general coding skills dealing with functions, loops, and conditionals.)  */

# include<iostream>
#include <cstring>
# include <fstream>
#include <iomanip>

using namespace std;


struct teaminfo  // struct decleration
{

	char teamname[40];
	int wins;
	int losses;
	bool playoff;
	int diff;
};

  void show ();


int main ()
{
	show ();
    ifstream in1;
    // open the input file and read the records into 
   //an array of teaminfo sstructures.
   int numteam;
   in1>> numteam;

   teaminfo * ptr;
   ptr = new teaminfo [numteam];
   

   //while (!in1.eof())
   //{
	   for (int i=0; i< numteam; i++)
	   {
          in1.getline(ptr[i].teamname,40,',');
		  in1>> ptr[i].wins;
		  in1.ignore();
		  in1>> ptr[i].losses;
		  in1.ignore();
		  in1>> ptr[i].playoff;
		  in1.ignore(100,'\n'); // ignore everything after the numbers all the way to new line
		   
		  //in1.getline(ptr[i].teamname,40,'\n');
	   }
 //  }

	 //  
	

     for (int i=0; i< numteam; i++)
	 {
		ptr[i].diff= ptr[i].wins- ptr[i].losses;
		cout << "Team " << ptr[i].teamname << " has win: " <<ptr[i].wins << " and  " << ptr[i].losses << " losses, then win/loss differential is " << ptr[i].diff<< endl;	
	 }



	 delete [] ptr;

	 in1.close();

	return 0;
}

void show ()
{
char filename[25];
	ifstream in1;   
	ofstream out1;

	  do
   {
		in1.clear();	// to clear status flags in the stream

       	cout << "Please enter the name of the input file.\n";
       	cout << "Filename:  ";
       	cin >> filename;

       	in1.open(filename);
       	if (!in1)
            cout << "That is not a valid file.  Try again!\n";
		 //   cerr << "Attempt to create file failed\n";


   } while (!in1);
   
   }