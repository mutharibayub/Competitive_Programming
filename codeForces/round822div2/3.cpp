#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n, zeroCount=0;
        int64_t score=0;
        string s;
        cin >> n >> s;
        for(int i=0;s[i];i++)if(s[i]=='0')zeroCount++;
        for(int i=1;i<=n&&zeroCount;i++)
        {
            for(int j=i;j<=n;j+=i)
            {
                if(s[j-1]=='1')break;
                else if(s[j-1]=='x')continue;
                else
                {
                    s[j-1]='x';
                    zeroCount--;
                    score+=i;
                }
            }
        }
        cout << score << '\n';
    }


    return 0;
}