#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(3),b(3);
    for(int i=0;i<3;i++)cin>>a[i];
    for(int i=0;i<3;i++)cin>>b[i];
    int mx = 0, mn = 1e9+7;
    for(int i=0;i<3;i++)mx+=min(a[i], b[(i+1)%3]);
    vector<array<int,2>> bf;
    for(int i=0;i<3;i++)
    {
        bf.push_back({i, i});
        bf.push_back({i, (i+2)%3});
    }
    sort(bf.begin(), bf.end());
    do
    {
        vector<int> ta=a, tb=b;
        int tmn=0;
        for(int i=0;i<bf.size();i++)
        {
            int sub = min(ta[bf[i][0]], tb[bf[i][1]]);
            ta[bf[i][0]]-=sub;
            tb[bf[i][1]]-=sub;
        }
        for(int i=0;i<3;i++)tmn+=min(ta[i], tb[(i+1)%3]);
        mn=min(mn, tmn);
    } while (next_permutation(bf.begin(), bf.end()));
    
    cout << mn << ' ' << mx << '\n';
    return 0;
}