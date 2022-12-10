#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
    string filename = "10input.txt";
    ifstream fin(filename);

    int cr=0;
    int v=1;
    map<int,int> values;
    values[cr]=v;
    while(!fin.eof())
    {
        string a;
        fin>>a;
        if(a=="")break;
        if(a=="noop")
        {
            values[cr+1]=v;
            cr++;
        }
        else
        {
            int b;
            fin>>b;
            values[cr+2]=v+b;
            v+=b;
            cr+=2;
        }
    }
    vector<string> op(6,string(40, '.')); 
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<40;j++)
        {
            cout << "i: " << i << " j: " << j << " -> " << (--values.lower_bound(i*40+j+1))->second << '\n';
            if(abs((--values.lower_bound(i*40+j+1))->second-j)<2)
            {
                op[i][j]='#';
            }
        }
    }
    for(int i=0;i<6;i++)cout << op[i] << '\n';


    return 0;
}