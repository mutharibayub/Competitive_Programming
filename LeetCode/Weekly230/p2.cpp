#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
    unordered_set<int> toppingSums;
    toppingSums.insert(0);
    for(int i=0;i<toppingCosts.size();i++)
    {
        unordered_set<int> temp(toppingSums);
        for(auto iter:temp)
        {
            toppingSums.insert(iter+toppingCosts[i]);
            toppingSums.insert(iter+2*(toppingCosts[i]));
        }
    }    
    int closest=9999999;
    for(int i=0;i<baseCosts.size();i++)
    {
        for(auto iter:toppingSums)
        {
            if(abs(target-(baseCosts[i]+iter))<abs(target-closest))
            {
                closest = baseCosts[i]+iter;
            }
            else if(abs(target-(baseCosts[i]+iter))==abs(target-closest))
            {
                closest = closest<(baseCosts[i]+iter)?closest:(baseCosts[i]+iter);
            }
        }
    }
    return closest;
}

int main()
{
    vector<int> a({10});
    vector<int> b({1});
    int target = 1;
    cout<<closestCost(a,b,target);
    return 0;
}