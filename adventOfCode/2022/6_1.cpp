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
    for(int i=0;i+3<s.size();i++)
    {
        set<char> st;
        for(int j=0;j<4;j++)st.insert(s[i+j]);
        if(st.size()==4)
        {
            cout << i+4 << '\n';
            break;
        }
    }

    return 0;
}