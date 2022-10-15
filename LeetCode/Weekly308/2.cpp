#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string ans="";
        int toRemove = 0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!='*' && toRemove)
            {
                toRemove--;
            }
            else if(s[i]!='*')
            {
                ans.push_back(s[i]);
            }
            else
            {
                toRemove++;
            }
        }     
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}