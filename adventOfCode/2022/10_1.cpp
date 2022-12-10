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

    int cr=1;
    int v=1;
    map<int,int> values;
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
    int ans=0;
    for(int i=0;i<6;i++)
    {
        auto it = values.lower_bound(20+i*40+1);
        it--;
        ans += (20+i*40)*it->second;
    }
    cout << ans << '\n';

    return 0;
}