#include <iostream>
#include <vector>
using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    int dict[26];
    for(int i=0;i<26;i++)
    {
        dict[order[i]-'a'] = i;
    }
    for(int i=0;i<words.size()-1;i++)
    {
        bool pass = false;
        for(int j=0;words[i][j] && words[i+1][j];j++)
        {
            if(dict[words[i][j]-'a']>dict[words[i+1][j]-'a'])
            {
                return false;
            }
            else if(dict[words[i][j]-'a']<dict[words[i+1][j]-'a'])
            {
                pass = true;
                break;
            }
        }
        if(!pass && words[i].length()>words[i+1].length())return false;
    }
    return true;
}

int main()
{
    vector<string> a({"kuvp","q"});
    string s = "ngxlkthsjuoqcpavbfdermiywz";
    cout<<isAlienSorted(a,s);
    return 0;
}