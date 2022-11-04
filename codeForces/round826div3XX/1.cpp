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
        string s[2];
        cin>>s[0]>>s[1];
        reverse(s[0].begin(), s[0].end());
        reverse(s[1].begin(), s[1].end());
        int points[2]; 
        for(int i=0;i<2;i++)
        {
            if(s[i][0]=='M')
            {
                points[i]=100;
            }
            else if(s[i][0]=='L')
            {
                points[i]=200;
                points[i]+=s[i].size();
            }
            else
            {
                points[i]=0;
                points[i]-=s[i].size();
            }
        } 
        if(points[0]<points[1])
        {
            cout << "<\n";
        }
        else if(points[0]>points[1])
        {
            cout << ">\n";
        }
        else
        {
            cout << "=\n";
        }
    }

    return 0;
}
