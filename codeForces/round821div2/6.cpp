#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int64_t t;
        int x,y;
        cin>>t>>x>>y;
        if(t<x+y)
        {
            cout << "NO\n";
            continue;
        }
        vector<int64_t> count1(240),count2(240);
        count1[0] = t-x-y;
        count2[0] = t-x-y+1;
        for(int l=0;l<x+y;l++)
        {
            for(int i=l;i>=0;i--)
            {
                count1[i+1] += count1[i]/2;
                count1[i] -= count1[i]/2;
                count2[i+1] += count2[i]/2;
                count2[i] -= count2[i]/2;                
            }
        }
        int px=-1,py=-1;
        for(int i=0;i<240;i++)
        {
            if(count1[i]!=count2[i])
            {
                px=i,py=x+y-i;
            }
        }
        if(px == x && py == y)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}