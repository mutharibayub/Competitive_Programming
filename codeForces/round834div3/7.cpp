#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n/2), avlbl(n+1, -1), done(n+1, true);
        vector<array<int,2>> sorted(n/2);
        vector<vector<int>> rqrdArr;
        vector<int> rqrd(n+1, -1);
        for(int i=0;i<n/2;i++)
        {
            cin>>arr[i];
            sorted[i]={arr[i], i};
        }
        sort(sorted.begin(), sorted.end());
        int num=1, count=0;
        for(int i=0;i<n/2;i++)
        {
            while(num<sorted[i][0])
            {
                num++, count++;
            }
            done[num]=false;
            avlbl[sorted[i][1]]=count;
            num++;
        }
        for(int i=0;i<n/2;)
        {
            rqrdArr.push_back({});
            rqrdArr.back().push_back(sorted[i][1]);
            i++;
            while(i<n/2 && avlbl[sorted[i-1][1]]==avlbl[sorted[i][1]])
            {
                rqrdArr.back().push_back(sorted[i][1]);
                i++;
            }
        }
        for(int i=0;i<rqrdArr.size();i++)
        {
            rqrd[avlbl[rqrdArr[i][0]]]=i;
        }
        vector<int> assign(n/2, -1);
        int num = 1;
        int assigned=0;
        int i=0;
        while(num<n)
        {
            if(done[num])num++;
            else if(rqrd[])
        }
    }


    return 0;
}