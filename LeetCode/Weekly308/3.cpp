#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int first[3] = {0,0,0};
        int count[3] = {0,0,0};
        for(int i=garbage.size()-1;i>=0;i--)
        {
            for(auto it:garbage[i])
            {
                if(it=='M')
                {
                    count[0]++;
                    if(first[0]==0)
                    {
                        first[0] = i;
                    }
                }
                else if(it=='P')
                {
                    count[1]++;
                    if(first[1]==0)
                    {
                        first[1] = i;
                    }
                }
                else if(it=='G')
                {
                    count[2]++;
                    if(first[2]==0)
                    {
                        first[2] = i;
                    }
                }
            }
        } 
        int ans=0;  
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<first[i];j++)
            {
                ans+=travel[j];
            }
        } 
        ans += count[0] + count[1] + count[2];
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}