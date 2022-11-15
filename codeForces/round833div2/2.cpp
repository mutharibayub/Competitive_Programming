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
        int n;
        string s;
        cin>>n>>s;
        vector<int> count(10);
        int diverse=0;
        int distinct,maxCount;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<10;j++)count[j]=0;
            distinct=maxCount=0;
            for(int j=i;j<i+100&&j<n;j++)
            {
                int digit = s[j]-'0';
                count[digit]++;
                distinct += count[digit]==1;
                maxCount = max(maxCount, count[digit]);
                if(distinct>=maxCount)
                {
                    diverse++;
                }
            }
        }
        cout << diverse << '\n';
    }

    return 0;
}