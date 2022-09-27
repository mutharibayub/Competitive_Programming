#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int getSum(vector<int> &sums, int start, int stop)
{
    return sums[stop]-(start-1<0?0:sums[start-1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string num;
        int subStrLen, m;
        cin>>num>>subStrLen>>m;
        vector<int> sums(num.size(),0);
        int sum = 0;
        for(int i=0;i<num.size();i++)
        {
            sum+=num[i]-'0';
            sums[i] = sum;
        }
        vector<int> indexes[9];
        for(int i=0;i+subStrLen<=num.size();i++)
        {
            indexes[getSum(sums, i, i+subStrLen-1)%9].push_back(i);
        }
        for(int i=0;i<m;i++)
        {
            int l,r,k;
            cin>>l>>r>>k;
            l--, r--;
            int mult = getSum(sums, l, r)%9;
            vector<array<int,2>> ans;
            for(int j=0;j<9;j++)
            {
                int combo = (81+k-(j*mult))%9;
                if(combo==j)
                {
                    if(indexes[j].size()>=2)ans.push_back({indexes[j][0], indexes[j][1]});
                }
                else if(indexes[j].size() && indexes[combo].size())
                {
                    ans.push_back({indexes[j].front(), indexes[combo].front()});
                }
            }
            sort(ans.begin(), ans.end());
            if(ans.empty())
            {
                cout<<"-1 -1\n";
            }
            else
            {
                cout<<ans.front()[0]+1<<' '<<ans.front()[1]+1<<'\n'; 
            }
        }
    }

    return 0;
}