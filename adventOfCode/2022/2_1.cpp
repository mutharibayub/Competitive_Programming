#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string filename = "2input.txt";
    ifstream fin(filename);


    int totalScore=0;
    while(!fin.eof())
    {
        string a,b;
        fin>>a>>b;
        if(a.empty())break;
        a[0]-='A';
        b[0]-='X';
        int score = b[0]+1;
        if((a[0]+1)%3==b[0])
        {
            score+=6;
        }
        else if(a[0]==b[0])
        {
            score+=3;
        }
        totalScore+=score;
    }
    cout << totalScore << '\n';

    return 0;
}