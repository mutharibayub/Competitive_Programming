#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int cnts[3];
        for(int i = 0; i < 3; i++) {
            cin >> cnts[i];
        }
        int possible[3] = {0, 0, 0};
        for(int i = 0; i < 3; i++) {
            int cur_count = cnts[i];
            int other_count1 = cnts[(i+1)%3];
            int other_count2 = cnts[(i+2)%3];
            if(other_count1 > other_count2) {
                swap(other_count1, other_count2);
            }
            int diff = other_count2 - other_count1;
            cur_count += other_count1;
            if(diff % 2 == 0) {
                possible[i] = true;
            }
            cout << possible[i] << " \n"[i==2];
        }
    }
    return 0;
}