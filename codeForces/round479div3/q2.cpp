#include <iostream>

using namespace std;

int main()
{
    int n;
    int count[26][26];
    string s;
    cin>>n>>s;

    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            count[i][j]=0;
        }
    }

    for(int i=0;i<s.size()-1;i++)
    {
        count[s[i]-'A'][s[i+1]-'A']++;
    }

    string maxString="";
    int maxCount=0;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(count[i][j]>maxCount)
            {
                maxCount = count[i][j];
                maxString.clear();
                maxString.push_back('A'+i);
                maxString.push_back('A'+j);
            }
        }
    }
    cout<<maxString;

}