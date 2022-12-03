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
        string s;
        set<char> t;
        fin>>s;
        for(int i=0;i<s.size()/2;i++)
        {
            t.insert(s[i]);
        }
        for(int i=s.size()/2;s[i];i++)
        {
            if(t.find(s[i])!=t.end())
            {
                if(s[i]>='a')
                {
                    ans+=s[i]-'a'+1;
                }
                else
                {
                    ans+=s[i]-'A'+27;
                }
                break;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}