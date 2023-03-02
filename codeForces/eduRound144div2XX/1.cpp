#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string find = "FBFFBFFBFBFFBFFBFBFFBFFB";

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        bool ok = false;
        for(int i=0;i+n<find.size();i++)
        {
            bool match = true;
            for(int j=0;j<n;j++)
            {
                if(find[i+j]!=s[j])match=false;
            }
            if(match)
            {
                ok=true;
                break;
            }
        }
        cout << (ok?"YES":"NO") << '\n';
    }

    return 0;
}