#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <random>
#include <numeric>
#include <set>

using namespace std;

const int TRIALS = 100;
using ll = long long;

inline bool all_in_line(int x1, int y1, int x2, int y2, int x3, int y3) {
    return 1ll * (y1-y2) * (x1-x3) == 1ll * (y1-y3) * (x1-x2);
}

int main() {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator

    // freopen("C_input.txt", "r", stdin);
    // freopen("C_output.txt", "w", stdout);

    freopen("C_input_full.txt", "r", stdin);
    freopen("C_output_full.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt;
    cin >> tttt;
    for (int ttt = 1; ttt <= tttt; ttt++) {

        int N;
        cin >> N;
        vector<pair<ll, ll>> points(N);
        for(auto &point: points) {
            cin >> point.first >> point.second;
        }

        int ans = N;

        for(int i = 0; i < TRIALS; i++) {
            auto p1 = std::uniform_int_distribution<>(0, N)(gen);
            auto p2 = std::uniform_int_distribution<>(0, N)(gen);
            while (p1 == p2) {
                p2 = std::uniform_int_distribution<>(0, N)(gen);
            }

            int count = 0;
            for(int j = 0; j < N; j++) {
                if (all_in_line(
                    points[p1].first, points[p1].second,
                    points[p2].first, points[p2].second,
                    points[j].first, points[j].second)
                ) {
                    count++;
                }
            }
            ans = min(ans, N - count);
        }

        cout << "Case #" << ttt << ": " << ans << '\n';
    }

    return 0;
}