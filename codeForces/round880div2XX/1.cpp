#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bool MULTI = true;
    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> cnt(100, 0);
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            cnt[tmp]++;
        }
        bool ok = true;
        for(int i=1;i<100&&ok;i++)
        {
            if(cnt[i]>cnt[i-1])ok=false;
        }
        cout << (ok?"YES":"NO") << '\n';
    }
    return 0;
}