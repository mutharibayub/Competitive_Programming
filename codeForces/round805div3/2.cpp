#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        vector<bool> dict(26,false);
        int unqCount=0, days=1;
        cin>>s;
        for(int i=0;s[i];i++)
        {
            if(!dict[s[i]-'a'])
            {
                if(unqCount==3)
                {
                    days++;
                    i--;
                    unqCount=0;
                    for(int i=0;i<26;i++)dict[i]=false;
                }
                else
                {
                    dict[s[i]-'a']=true;
                    unqCount++;
                }
            }
        }
        cout << days << '\n';
    }

    return 0;
}