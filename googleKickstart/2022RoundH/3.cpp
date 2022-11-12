#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 2e5+1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;
        cin>>n;
        vector<array<int,2>> caps(n);
        vector<int> c(n);
        vector<int> dp(n);
        vector<vector<int>> adjList(n);
        int maxVal = 0;
        for(int i=0;i<n;i++)
        {
            cin>>caps[i][0];
            c[i]=caps[i][0];
            caps[i][1] = i;
        }
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        sort(caps.begin(), caps.end());
        for(int i=0;i<n;i++)
        {
            int total = 1;
            for(auto adj:adjList[caps[i][1]])
            {
                if(c[adj] < caps[i][0])
                {
                    total+=dp[adj];
                }
            }
            dp[caps[i][1]] = total;
            maxVal = max(maxVal, total);
        }

        cout << "Case #" << t << ": " << maxVal << '\n';
    }       


    return 0;
}