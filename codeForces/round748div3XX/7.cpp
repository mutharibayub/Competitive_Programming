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
        string s;
        cin>>s;
        vector<int> cnt(s.size(),0);
        for(int i=0;s[i];i++)
        {
            bool yes = s[i]=='['||s[i]==']';
            cnt[i] = (i?cnt[i-1]:0)+(i%2?1:-1)*yes;
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int l,r;
            cin>>l>>r;
            l--,r--;
            int c = cnt[r]-(l?cnt[l-1]:0);
            cout << abs(c) << '\n'; 
        }
    }

    return 0;
}