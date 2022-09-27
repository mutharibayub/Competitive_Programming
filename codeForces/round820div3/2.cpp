#include <iostream>
#include <vector>
#include <algorithm>

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
        string s,out="";
        cin>>n>>s;
        reverse(s.begin(), s.end());
        for(int i=0;s[i];i++)
        {
            if(s[i]=='0')
            {
                out.push_back((s[i+2]-'0')*10+(s[i+1]-'0'-1)+'a');
                i += 2;
            }
            else
            {
                out.push_back(s[i]-'0'+'a'-1);
            }
        }
        reverse(out.begin(), out.end());
        cout<<out<<'\n';
    }

    return 0;
}