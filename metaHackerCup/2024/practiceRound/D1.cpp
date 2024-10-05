#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <random>
#include <numeric>
#include <set>
#include <queue>

using namespace std;

int main() {

    // freopen("D1_input.txt", "r", stdin);
    // freopen("D1_output.txt", "w", stdout);

    freopen("D1_input_full.txt", "r", stdin);
    freopen("D1_output_full.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt;
    cin >> tttt;
    for (int ttt = 1; ttt <= tttt; ttt++) {

        int N, G;
        cin >> N >> G;
        vector<int> E(N);
        int closest = -1;
        int closest_loc = 0;
        for(int i = 0; i < N; i++) {
            cin >> E[i];
            if (!i || abs(closest_loc - G) > abs(E[i] - G) || (abs(closest_loc - G) == abs(E[i] - G) && E[i] > closest_loc)) {
                closest_loc = E[i];
            }
        }
        sort(E.begin(), E.end());
        closest = upper_bound(E.begin(), E.end(), closest_loc) - E.begin() - 1;

        cout << "Case #" << ttt << ": " << N - closest << ' ' << abs(E[closest] - G) << '\n';
    }

    return 0;
}