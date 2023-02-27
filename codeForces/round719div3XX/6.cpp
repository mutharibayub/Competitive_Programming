#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

typedef long long ll;

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1, 0);
    }
    int get(int i)
    {
        int sm=0;
        i++;
        while(i)
        {
            sm+=arr[i];
            i-=i&-i;
        }
        return sm;
    }
    void update(int i, int upd)
    {
        i++;
        while(i<arr.size())
        {
            arr[i]+=upd;
            i+=i&-i;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int cntLim = 6e4;

    int n, t, cnt=0, bit=20;
    cin>>n>>t;
    vector<int> sum(n, -1);
    FenwickTree fwt(n);
    for(int i=0;i<t;i++)
    {
        int k;
        cin>>k;
        int cur = -1;
        for(int j=bit;j>=0;j--)
        {
            if(cur+(1<<j)>=n)continue;
            if(sum[cur+(1<<j)]==-1)
            {
                assert(cnt<cntLim);

                cout << "? " << 1 << ' ' << (cur+1+(1<<j)) << endl;
                int tmp;
                cin>>tmp;
                tmp = cur+1+(1<<j) - tmp;
                sum[cur+(1<<j)]=tmp-fwt.get(cur+(1<<j));

                cnt++;
            }
            if(sum[cur+(1<<j)]+fwt.get(cur+(1<<j))<k)
            {
                cur+=(1<<j);
            }
        }
        cout << "! " << cur+2 << endl;
        fwt.update(cur+1, -1);
    }

    return 0;
}