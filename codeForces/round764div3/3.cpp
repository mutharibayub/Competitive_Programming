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
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.rbegin(), arr.rend());
        bool ok = true;
        vector<bool> done(n, false);
        for(int i=n;i>0&&ok;i--)
        {
            bool canForm=false;
            for(int j=0;j<n&&!canForm;j++)
            {
                if(done[j])continue;
                int tmp = arr[j];
                while(tmp&&!canForm)
                {
                    if(tmp==i)canForm=true;
                    tmp/=2;
                }
                if(canForm)done[j]=true;
            }
            if(!canForm)ok=false;
        }
        cout << (ok?"YES":"NO") << '\n';
    }    

    return 0;
}