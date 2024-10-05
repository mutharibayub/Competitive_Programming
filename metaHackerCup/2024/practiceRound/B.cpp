#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

int main() {

    freopen("B_input.txt", "r", stdin);
    freopen("B_output.txt", "w", stdout);

    // freopen("B_input_full.txt", "r", stdin);
    // freopen("B_output_full.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt;
    cin >> tttt;
    for (int ttt = 1; ttt <= tttt; ttt++) {
        int N, P;
        cin >> N >> P;
        // NthRoot((P / 100) ^ (N - 1)) * 100 - P
        double to_increase = pow<double>(pow<double>(P / 100.0, N - 1), 1.0 / N) * 100 - P;
        cout << fixed << setprecision(numeric_limits<double>::max_digits10);
        cout << "Case #" << ttt << ": " << to_increase << '\n';
    }

    return 0;
}