#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> actDist(26);
        for(char c='a';c<='z';c++)
        {
            int dist=-1;
            for(int i=0;s[i];i++)
            {
                if(dist==-1 && s[i]==c)
                {
                    dist = 0;
                }
                else if(dist!=-1 && s[i]==c)
                {
                    break;
                }
                else if(dist!=-1 && s[i]!=c)
                {
                    dist++;
                }
            }
            actDist[c-'a'] = dist;
        }      
        for(int i=0;i<26;i++)
        {
            if(actDist[i]!=-1 && actDist[i]!=distance[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    return 0;
}