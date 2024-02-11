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
#include <string>

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
        int n;
        cin >> n;
        vector<int> atk(n), def(n);
        for(int i = 0; i < n; i++) {
            cin >> atk[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> def[i];
        }
        set<int> alive;
        vector<int> left(n), right(n);
        for(int i = 0; i < n; i++) {
            alive.insert(i);
        }
        vector<int> to_die;
        for(int i = 0; i < n; i++) {
            int left_attack = alive.lower_bound(i) == alive.begin()? 0: atk[*prev(alive.lower_bound(i))];
            int right_attack = alive.lower_bound(i+1) == alive.end()? 0: atk[*alive.lower_bound(i+1)];
            if (left_attack + right_attack > def[i]) {
                to_die.push_back(i);
            }
        }
        for(int iter = 0; iter < n; iter++) {
            cout << (int)to_die.size() << " \n"[iter==n-1];
            set<int> to_check;
            for(auto num: to_die) {
                alive.erase(num);
            }
            for(auto num: to_die) {
                if (alive.lower_bound(num) != alive.begin()) {
                    if (alive.find(*prev(alive.lower_bound(num))) != alive.end())
                        to_check.insert(*prev(alive.lower_bound(num)));
                }
                if (alive.lower_bound(num+1) != alive.end()) {
                    if (alive.find(*alive.lower_bound(num+1)) != alive.end())
                        to_check.insert(*alive.lower_bound(num+1));
                }
            }
            to_die.clear();
            for(auto i: to_check) {
                int left_attack = alive.lower_bound(i) == alive.begin()? 0: atk[*prev(alive.lower_bound(i))];
                int right_attack = alive.lower_bound(i+1) == alive.end()? 0: atk[*alive.lower_bound(i+1)];
                if (left_attack + right_attack > def[i]) {
                    to_die.push_back(i);
                }
            }
        }
    }
    return 0;
}