#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        vector<int> ans = {q, q^1, q^(1<<1)};
        for(int i=0;i<3;i++)
        {
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }


    return 0;
}