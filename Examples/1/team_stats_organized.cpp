#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

struct teaminfo  // struct declaration
{       
        char teamname[40];
        int wins;
        int losses;
        bool playoff;
        int diff;
};

// Function prototype
void show(char filename[]);

int main()
{
        char filename[25];
        show(filename); 

        ifstream in1(filename);  // Open file here

        if (!in1)
        {   
                cout << "Error: Unable to open the file '" << filename << "'\n";
                return 1;
        }   

        int numteam;
        in1 >> numteam;
        in1.ignore();

        teaminfo* ptr = new teaminfo[numteam];

        for (int i = 0; i < numteam; i++)
        {   
                in1.getline(ptr[i].teamname, 40, ',');
                in1 >> ptr[i].wins;
                in1.ignore();
                in1 >> ptr[i].losses;
                in1.ignore();
                in1 >> ptr[i].playoff;
                in1.ignore(100, '\n');  // everything after the last value IS ignored
        }   

        for (int i = 0; i < numteam; i++)
        {   
                ptr[i].diff = ptr[i].wins - ptr[i].losses;
                cout << "Team " << ptr[i].teamname << " has win: " << ptr[i].wins
                         << " and " << ptr[i].losses << " losses, then win/loss differential is "
                         << ptr[i].diff << endl;
        }   

        delete[] ptr;
        in1.close();

        return 0;
}

void show(char filename[])
{
        ifstream in1;

        do
        {
                in1.clear();  // Clear status flags
                cout << "Please enter the name of the input file.\n";
                cout << "Filename:  ";
                cin >> filename;

                in1.open(filename);
                if (!in1)
                        cout << "That is not a valid file.  Try again!\n";

                in1.close();
        } while (!in1);
}

