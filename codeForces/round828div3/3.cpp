#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        char color;
        string s;
        cin>>n>>color>>s;
        s = s+s;
        int maxV = -1;
        for(int i=0;i<n;i++)
        {
            if(s[i]==color)
            {
                int count = 0;
                while(s[i]!='g')
                {
                    count++;
                    i++;
                }
                maxV = max(count, maxV);
            }    
        }
        cout << maxV << '\n';
    }

    return 0;
}