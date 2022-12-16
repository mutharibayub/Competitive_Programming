#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int m;
        string s[2];
        cin>>m>>s[0]>>s[1];
        if(m==1)
        {
            cout << "YES" << '\n';
        }
        else
        {
            int options=3;
            bool possible=true;
            int bCount=0;
            for(int i=0;i<m;i++)
            {
                bCount+=s[0][i]=='B';
                bCount+=s[1][i]=='B';
            }
            for(int i=0;i<m&&bCount;i++)
            {
                int next = (s[1][i]=='B')*2+(s[0][i]=='B');
                if(options==3)
                {
                    options=next;
                }
                else
                {
                    if(!(next&options))
                    {
                        possible=false;
                        break;
                    }
                    if(next==3)
                    {
                        options^=3;
                    }
                    else
                    {
                        options=next;
                    }
                }
                bCount-=(bool)options&2;
                bCount-=(bool)options&1;
            }
            if(bCount==0)possible=true;
            cout << (possible?"YES":"NO") << '\n';
        }
    }


    return 0;
}