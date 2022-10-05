#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> toSort;
        vector<string> ans;
        toSort.reserve(names.size());
        for(int i=0;i<names.size();i++)
        {
            toSort.emplace_back(heights[i], names[i]);
        }
        sort(toSort.rbegin(), toSort.rend());
        for(int i=0;i<names.size();i++)
        {
            ans.emplace_back(toSort[i].second);
        }
        return ans;
    }
};