#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

int main()
{
    string filename = "6input.txt";
    ifstream fin(filename);
    string s;
    fin>>s;
    for(int i=0;i+13<s.size();i++)
    {
        set<char> st;
        for(int j=0;j<14;j++)st.insert(s[i+j]);
        if(st.size()==14)
        {
            cout << i+14 << '\n';
            break;
        }
    }

    return 0;
}