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
        int n;
        cin >> n;
        int q;
        cin >> q;
        vector<int> qq(q);
        for(int i = 0; i < q; i++) {
            cin >> qq[i];
        }
        vector<int> main_arm = {0};
        vector<int> side_arm;
        for(int i = 0; i < n - 1; i++) {
            cout << i+1 << ' ' << i+2 << '\n';
            main_arm.push_back(i+1);
        }
        for(int i = 0; i < q; i++) {
            if((int)main_arm.size() - 1 < qq[i]) {
                int diff = qq[i] - main_arm.size() + 1;
                int insert_at = main_arm.back();
                main_arm.insert(main_arm.end(), side_arm.end() - diff, side_arm.end());
                while(diff-- > 1) {
                    side_arm.pop_back();
                }
                int switched = side_arm.back();
                side_arm.pop_back();
                int cut_at = (side_arm.empty()? 1: side_arm.back());
                cout << switched + 1 << ' ' << cut_at + 1 << ' ' << insert_at + 1 << '\n';
            } else if((int)main_arm.size() - 1 > qq[i]) {
                int diff = main_arm.size() - 1 - qq[i];
                int insert_at = side_arm.empty()? 1: side_arm.back();
                side_arm.insert(side_arm.end(), main_arm.end() - diff, main_arm.end());
                while(diff-- > 1) {
                    main_arm.pop_back();
                }
                int switched = main_arm.back();
                main_arm.pop_back();
                int cut_at = main_arm.back();
                cout << switched + 1 << ' ' << cut_at + 1 << ' ' << insert_at + 1 << '\n';   
            } else {
                cout << "-1 -1 -1" << '\n';
            }
        }
    }
    return 0;
}