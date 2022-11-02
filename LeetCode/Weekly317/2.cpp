#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        unordered_map<string, int> pop;
        unordered_map<string, int> bestVid;
        pop.reserve(n);bestVid.reserve(n);views.reserve(n);
        int highestPop = -1;
        for(int i=0;i<n;i++)
        {
            auto &tmp = pop[creators[i]];
            tmp += views[i];
            if(bestVid.find(creators[i])==bestVid.end())
            {
                bestVid[creators[i]] = i;
            }
            else if(views[bestVid[creators[i]]] < views[i]
                    || (views[bestVid[creators[i]]] == views[i] && ids[i] < ids[bestVid[creators[i]]]))
            {
                bestVid[creators[i]] = i;
            }
            highestPop = max(highestPop, tmp);
        }
        vector<vector<string>> ans;
        for(auto it:bestVid)
        {
            if(pop[it.first]==highestPop)
            {
                ans.push_back({it.first, ids[it.second]});
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
