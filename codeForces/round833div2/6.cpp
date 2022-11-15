#include <iostream>
#include <vector>

using namespace std;

int MOD;
int norm(int val)
{
    return (val%MOD+MOD)%MOD;
}

void prep(int l, int r, vector<int> &ans)
{
    for(int i=0;i<norm(r-l);i++)
    {
        ans.push_back(norm(l+i));
    }
}

void moveXOR(int l, int r, vector<int> &ans)
{
    for(int i=0;i<norm(r-l)-1;i++)
    {
        ans.push_back(norm(r-i-2));
    }
    for(int i=0;i<norm(r-l)-1;i++)
    {
        ans.push_back(norm(l+i+1));
    }
    if(norm(r-l)==1)return;
    if(norm(r-l)==2)
    {
        // ans.push_back(norm(l+1));
        return;
    }
    moveXOR(norm(l+1), norm(r-1), ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> ans;
    ans.reserve(250000);

    int n;
    cin>>n;
    MOD = n;
    prep(0,n-1,ans);
    moveXOR(0,n-1,ans);
    prep((n+1)/2,(n-2)/2,ans);
    moveXOR((n+1)/2,(n-2)/2,ans);
    prep(0,n-1,ans);
    moveXOR(0,n-1,ans);
    
    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++)
    {
        if(i)cout << ' ';
        cout << ans[i];
    }cout << '\n';


    

    return 0;
}