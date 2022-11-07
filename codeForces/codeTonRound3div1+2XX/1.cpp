#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,tmp;
        cin>>n;
        string ans="NO";
        cin >> tmp;
        if(tmp==1)ans="YES";
        for(int i=0;i<n-1;i++)
        {
            cin>>tmp;
        }
        cout << ans << '\n';
    }

    return 0;
}