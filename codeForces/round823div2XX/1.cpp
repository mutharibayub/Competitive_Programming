#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        int ans = 0;
        vector<int> count(100+1,0);
        cin>>n>>c;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            count[tmp]++;
        }
        for(int i=0;i<=100;i++)
        {
            ans += min(count[i], c);
        }
        cout << ans << '\n';
    }

    return 0;
}