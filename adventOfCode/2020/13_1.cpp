#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("13input.txt");
    int startVal, minWait=1e9+7, minId;
    string inp;

    fin >> startVal;

    while(!fin.eof())
    {
        fin >> inp;
        if(inp[0]=='x')continue;
        int id = stoi(inp);
        int wait = (startVal%id)?id-startVal%id:0;
        if(wait < minWait)
        {
            minWait = wait;
            minId = id;
        }        
    }
    cout << minWait * minId << '\n';

    return 0;
}
