#include <iostream>
#include <vector>
#include <string>

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
        if(s.size()==1||s.front()=='0'||s.back()=='1')
        {
            cout << 1 << '\n';
        }
        else
        {
            int on=0,zr=s.size()-1;
            for(int i=0;s[i];i++)
            {
                if(s[i]=='1')on=i;
                if(s[i]=='0')zr=min(zr,i);
            }
            if(zr<on)
            {
                cout << 2 << '\n';
            }
            else
            {
                cout << zr-on+1 << '\n';
            }
        }
    }

    return 0;
}