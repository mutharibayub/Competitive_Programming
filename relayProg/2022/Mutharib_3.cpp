#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n),ll(n),rl(n),stk;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        while(stk.size() && arr[stk.back()]>=arr[i])stk.pop_back();
        ll[i]=stk.size()?stk.back():-1;
        stk.push_back(i);
    }
    stk.clear();
    for(int i=n-1;i>=0;i--)
    {
        while(stk.size() && arr[stk.back()]>=arr[i])stk.pop_back();
        rl[i]=stk.size()?stk.back():n;
        stk.push_back(i);
    }    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans, (rl[i]-1-(ll[i]+1)+1)*arr[i]);
    }
    cout << ans << '\n';


    return 0;
}