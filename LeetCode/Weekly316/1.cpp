#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        pair<pair<int,int>, pair<int,int>> ev1, ev2;
        ev1.first.first = ((event1[0][0]-'0')*10)+(event1[0][1]-'0');
        ev1.first.second = ((event1[0][3]-'0')*10)+(event1[0][4]-'0');
        ev1.second.first = ((event1[1][0]-'0')*10)+(event1[1][1]-'0');
        ev1.second.second = ((event1[1][3]-'0')*10)+(event1[1][4]-'0');
        ev2.first.first = ((event2[0][0]-'0')*10)+(event2[0][1]-'0');
        ev2.first.second = ((event2[0][3]-'0')*10)+(event2[0][4]-'0');
        ev2.second.first = ((event2[1][0]-'0')*10)+(event2[1][1]-'0');
        ev2.second.second = ((event2[1][3]-'0')*10)+(event2[1][4]-'0');
        if(ev1.first<=ev2.second && ev1.second>=ev2.first)return true;
        return false;
    }
};

int main()
{
    Solution s;

    return 0;
}
