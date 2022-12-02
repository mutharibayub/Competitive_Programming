#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string filename = "1input.txt";
    ifstream fin(filename);


    vector<int> sums;
    while(!fin.eof())
    {
        string s;
        fin >> s;
        if(sums.empty() || s=="|")
        {
            sums.push_back(0);
        }
        else
        {
            sums.back() += stoi(s);
        }
    }
    sort(sums.rbegin(), sums.rend());
    cout << sums[0]+sums[1]+sums[2] << '\n';


    return 0;
}