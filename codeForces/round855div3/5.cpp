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
        int n, k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout << "YES" << '\n';
        }
        else
        {
            vector<int> cnt1(26,0), cnt2(26,0);
            for(int i=0;i<n;i++)
            {
                cnt1[a[i]-'a']++,cnt2[b[i]-'a']++;
            }
            if(cnt1!=cnt2)
            {
                cout << "NO" << '\n';
            }
            else
            {
                vector<bool> yes(n, false);
                for(int i=0;i<n;i++)
                {
                    yes[i]=(i-k>=0)||(i+k<n);
                }
                bool ok = true;
                for(int i=0;i<n&&ok;i++)
                {
                    if(!yes[i]&&a[i]!=b[i])ok=false;
                }
                cout << (ok?"YES":"NO") << '\n';
            }
        }
        
    }

    return 0;
}