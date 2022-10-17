#include <iostream>
#include <vector>

using namespace std;

#define ld long double

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<int> count(10, 0);
        int maxInd = -1;
        for(char c='0';c<='9';c++)
        {
            int ind = -1;
            for(int i=0;s[i];i++)
            {
                if(s[i]==c)
                {
                    ind = i;
                    if(c!='9' && i<maxInd)
                    {
                        count[c+1-'0']++;
                    }
                    else
                    {
                        count[c-'0']++;
                    }
                }  
            }
            maxInd = max(maxInd, ind);
        }
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<count[i];j++)
            {
                cout << char(i+'0');
            }
        }
        cout << '\n';
    }

    return 0;
}