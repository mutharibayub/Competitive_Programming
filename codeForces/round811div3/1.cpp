#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int,int> diff(pair<int,int> sleepTime, pair<int,int> wakeTime)
{
    if(wakeTime<sleepTime)wakeTime.first+=24;
    wakeTime.second-=sleepTime.second;
    if(wakeTime.second<0)
    {
        wakeTime.first--;
        wakeTime.second+=60;
    }
    wakeTime.first -= sleepTime.first;
    return wakeTime;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        pair<int,int> minSleep = make_pair(23,59), sleepTime, wakeTime;
        int n;
        cin>>n>>sleepTime.first>>sleepTime.second;
        for(int i=0;i<n;i++)
        {
            cin>>wakeTime.first>>wakeTime.second;
            pair<int,int> temp = diff(sleepTime, wakeTime);
            minSleep = min(temp, minSleep);
        }
        cout << minSleep.first << ' ' << minSleep.second << '\n';
    }

    return 0;
}