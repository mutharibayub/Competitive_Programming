#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    string filename = "3input.txt";
    ifstream fin(filename);

    int ans=0;
    while(!fin.eof())
    {
        string s[3];
        set<char> t[2];
        for(int i=0;i<3;i++)fin>>s[i];
        for(int i=0;i<3;i++)
        {
            t[1]=t[0];
            t[0].clear();
            for(int j=0;s[i][j];j++)
            {
                if(!i || t[1].find(s[i][j])!=t[1].end())
                {
                    t[0].insert(s[i][j]);
                }
            }
        }
        char c = *(t[0].begin());
        if(c>='a')
        {
            ans+=c-'a'+1;
        }
        else
        {
            ans+=c-'A'+27;
        }
    }
    cout << ans << '\n';

    return 0;
}