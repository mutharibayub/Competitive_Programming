#include <iostream>
#include <vector>
using namespace std;

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int index = ruleKey=="type"?0:ruleKey=="color"?1:2;
    int count=0;
    for(int i=0;i<items.size();i++)
    {
        if(items[i][index]==ruleValue)
        {
            count++;
        }
    }
    return count;
}

int main()
{

    return 0;
}