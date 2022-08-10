#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int,int64_t> maxDollars;
int64_t maxDollarsFunc(int coins)
{
    if(coins==0)return 0;
    if(maxDollars.find(coins)==maxDollars.end())
    {
        int64_t dividedDollars = maxDollarsFunc(coins/2)+maxDollarsFunc(coins/3)+maxDollarsFunc(coins/4);
        maxDollars[coins] = coins>dividedDollars?coins:dividedDollars;
    }
    return maxDollars[coins];
}

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<maxDollarsFunc(n)<<'\n';
    }
}