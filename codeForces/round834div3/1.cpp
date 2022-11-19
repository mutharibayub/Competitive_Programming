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
        string s,m="Yes";
        cin>>s;
        int a;
        if(s[0]=='Y')a=0;
        else if(s[0]=='e')a=1;
        else if(s[0]=='s')a=2;
        else
        {
            cout << "NO\n";
            continue;
        }
        bool possible=true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=m[a])
            {
                possible=false;
                break;
            }
            a++;
            a%=3;
        }
        cout << (possible?"YES":"NO") << '\n';
    }


    return 0;
}