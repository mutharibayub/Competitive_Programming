#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,x,y;
    cin>>N>>x>>y;

    int maxVal = 1<<N, halfVal = 1<<(N-1);
    int counts[2]={0,0};
    while(x!=halfVal)
    {
        if(x<halfVal)
        {
            x+=x;
        }
        else
        {
            x-=(maxVal-x);
        }
        counts[0]++;
    }
    while(y!=halfVal)
    {
        if(y<halfVal)
        {
            y+=y;
        }
        else
        {
            y-=(maxVal-y);
        }
        counts[1]++;
    }
    assert(abs(counts[0]-counts[1])%2==0);

    cout << max(counts[0], counts[1]) << '\n';

    return 0;
}