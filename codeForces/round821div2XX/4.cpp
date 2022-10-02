#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(const int &l, const int &r)
{
    return (l&1)<(r&1) || (((l&1)==(r&1)) && (l<=r));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int64_t n,x,y;
        cin>>n>>x>>y;
        string bin1,bin2;
        cin>>bin1>>bin2;
        vector<int64_t> diff;
        int64_t evenCount=0, oddCount=0;
        for(int i=0;i<n;i++)
        {
            if(bin1[i]!=bin2[i])
            {
                diff.push_back(i);
                if(i&1)
                {
                    oddCount++;
                }
                else
                {
                    evenCount++;
                }
            }
        }
        if((oddCount+evenCount)&1)
        {
            cout << "-1\n";
            continue;
        }
        if(oddCount+evenCount==0)
        {
            cout << "0\n";
            continue;
        }
        if(oddCount+evenCount==2)
        {
            cout << (abs(diff[0]-diff[1])==1?min(x,2*y):y) << '\n';
            continue;
        }
        cout << y*(evenCount+oddCount)/2 << '\n';
    }

    return 0;
}