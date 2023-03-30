#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

const int N = 2e5+1;

vector<int> inds[2][N];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<int> arr[2];
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        arr[i&1].push_back(tmp);
        inds[i&1][tmp].push_back(i);
    }
    int firstCenter = k/2, lastCenter = n-k/2-1 ;
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        int num = arr[i&1][i/2];
        int ff = firstCenter;
        int ll = lastCenter;
        int r1 = i+1;
        if(i>=ll)continue;
        if(ff>i)r1=max(r1, ff+(ff-i));
        int r2 = i+k-1;
        r2=min(r2, ll+(ll-i));
        if(i%2!=r1%2)r1++;
        if(i%2!=r2%2)r2--;
        if(r2>=r1)
            ans += (r2/2-r1/2+1) - (lower_bound(inds[i&1][num].begin(), inds[i&1][num].end(), r2+1) - 
                lower_bound(inds[i&1][num].begin(), inds[i&1][num].end(), r1) );
    }
    cout << ans << '\n';
    return 0;
}