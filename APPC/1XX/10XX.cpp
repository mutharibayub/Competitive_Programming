#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int N, M, P;
        cin>>N>>M>>P;
        vector<vector<int>> dists(N, vector<int>(N, 1e9+7));
        for(int i=0;i<N;i++)
        {
            dists[i][i] = 0;
        }
        for(int i=0;i<M;i++)
        {
            int v1,v2,e;
            cin>>v1>>v2>>e;
            v1--,v2--;
            dists[v1][v2]=e;
            dists[v2][v1]=e;
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(i==j)continue;
                for(int k=0;k<N;k++)
                {
                    dists[i][j] = min(dists[i][j], dists[i][k]+dists[k][j]);
                }
            }
        }
        vector<double> sums(N,0);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                sums[i]+=dists[i][j];
            }
            sums[i]/=(N-1);
        }
        double ans = 0;
        if(P%2==0 || (N>2 && P>20))
        {
            for(int i=0;i<N;i++)
            {
                ans += (sums[i]*P)/N;
            }
        }
        else if(N==2)
        {
            ans = sums[0]*N;
        }
        else
        {
            double secondary = ((pow(N-1, P-1)-1)/N);
            ans += (secondary+1)/(pow(N-1, P-1))*sums[0];
            for(int i=1;i<N;i++)
            {
                ans += secondary/(pow(N-1, P-1))*sums[i];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}