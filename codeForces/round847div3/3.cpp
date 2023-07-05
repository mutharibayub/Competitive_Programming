#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

string PI = "314159265358979323846264338327";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<vector<int>> perms(n, vector<int>(n-1));
        vector<int> offset(n, 0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                cin>>perms[i][j];
                perms[i][j]--;
            }
        }

        vector<int> done(n, false);
        vector<int> ans;
        for(int i=0;i<n-1;i++)
        {
            vector<int> cnts(n, 0);
            vector<int> last(n, -1);
            for(int j=0;j<n;j++)
            {
                cnts[perms[j][i+offset[j]]]++;
                last[perms[j][i+offset[j]]]=j;
            }
            int mxIndex = 0;
            int soloIndex = 0;
            for(int i=0;i<n;i++)
            {
                if(cnts[i]>cnts[mxIndex])mxIndex=i;
                if(cnts[i]==1)soloIndex=last[i];
            }
            ans.push_back(mxIndex);
            done[mxIndex]=true;
            offset[soloIndex]--;
        }
        for(int i=0;i<n;i++)
        {
            if(!done[i])ans.push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << ans[i]+1;
        }cout << '\n';
    }    

    return 0;
}