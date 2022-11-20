#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class FWT
{
    vector<int> d;
public:
    FWT(const vector<int> &arr)
    {
        d.assign(arr.size()+1,0);
        for(int i=0;i<arr.size();i++)
        {
            updateVal(i, arr[i]);
        }
    }
    void updateVal(int i, int v)
    {
        int diff=v-getVal(i);
        i++;
        while(i<d.size())
        {
            d[i]+=diff;
            i+=(i&-i);
        }
    }
    int getVal(int i)
    {
        return getSum(i)-getSum(i-1);
    }
    int getSum(int i)
    {
        int sum=0;
        i++;
        while(i)
        {
            sum+=d[i];
            i-=(i&-i);
        }
        return sum;
    }
    
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r,c,q;
    cin>>r>>c>>q;
    swap(r,c);
    int n=r*c;
    vector<int> arr(n,0);
    for(int i=0;i<c;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<r;j++)
        {
            arr[j*c+i]=(s[j]=='*');
        }
    }
    FWT  fwt(arr);

    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>b>>a;
        a--,b--;
        int ind = a*c+b;
        fwt.updateVal(ind, !fwt.getVal(ind));
        int all = fwt.getSum(n-1);
        int start = all?fwt.getSum(all-1):0;
        cout << all-start << '\n';
    }

    return 0;
}