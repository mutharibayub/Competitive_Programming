#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<string> bis(n-2);
        for(int i=0;i<n-2;i++)
        {
            cin>>bis[i];
        }
        if(n==3)
        {
            cout << 'b' << bis[0] << '\n';
            continue;
        }
        int cut = 1;
        for(int i=0;i+1<n-2;i++)
        {
            if(bis[i][1]!=bis[i+1][0])
            {
                cut=i+1;
                break;
            }
        }
        for(int i=0;i<cut;i++)
        {
            if(!i)cout << bis[i].front();
            cout << bis[i].back();
        }
        for(int i=cut;i<n-2;i++)
        {
            if(i==cut)cout << bis[i].front();
            cout << bis[i].back();
        }cout << '\n';
    }    

    return 0;
}