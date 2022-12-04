#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    string filename = "4input.txt";
    ifstream fin(filename);
    int cnt =0;
    while(!fin.eof())
    {
        int a,b,c,d;
        fin>>a>>b>>c>>d;
        if(a>=c && b<=d)cnt++;
        else if(c>=a && d<=b)cnt++;
    }
    cout << cnt << '\n';

    return 0;
}