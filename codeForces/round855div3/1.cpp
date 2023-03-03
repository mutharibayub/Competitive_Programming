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
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<char> nxt = {'m','e','o','w'};
        int cur = 1;
        bool ok = (s.front()=='m'||s.front()=='M');
        for(int i=0;i<n&&ok;i++)
        {
            char c = s[i]<'a'?s[i]+('z'-'Z'):s[i];
            if(cur<4)
            {
                if(c==nxt[cur])cur++;
                else if(c!=nxt[cur-1])ok=false;
            }
            else
            {
                if(c!=nxt[cur-1])ok=false;
            }
        }
        ok &= (cur==4);
        cout << (ok?"YES":"NO") << '\n';
        
    }

    return 0;
}