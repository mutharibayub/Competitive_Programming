#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t digitSum(int64_t num)
{
    int64_t sum = 0;
    while(num)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int maxSum = 9*9;

    int64_t m,n,o;
    cin>>m>>n>>o; 

    vector<int64_t> ans;

    for(int64_t i=1;i<=maxSum;i++)
    {
        int64_t val=1;
        for(int j=0;j<m;j++)
        {
            val*=i;
        }
        val = val*n+o;
        if(val>0 && val<int64_t(1e9) && digitSum(val) == i)
        {
            ans.push_back(val);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++)
    {
        if(i) cout << ' ';
        cout << ans[i];
    }if(ans.size())cout << '\n';

    return 0;
}