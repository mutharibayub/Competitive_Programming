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
        string num;
        cin >> num;
        string first = num.substr(0, 1);
        string second = num.substr(1);
        bool found = false;
        for(int i = 1; i < num.size(); i++) {
            string nums[] = {first, second};
            bool ok = true;
            for(int j = 0; j < 2; j++) {
                ok &= (nums[j].front() != '0');
                ok &= stoi(nums[j]) > 0;
            }
            ok &= stoi(nums[0]) < stoi(nums[1]);
            if(ok) {
                found = true;
                break;
            }
            first.push_back(num[i]);
            second = second.substr(1);
        }
        if(!found) {
            cout << -1 << '\n';
            continue;
        }
        cout << first << ' ' << second << '\n';
    }
    return 0;
}