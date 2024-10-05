#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    // freopen("A_input.txt", "r", stdin);
    // freopen("A_output.txt", "w", stdout);

    freopen("A_input_full.txt", "r", stdin);
    freopen("A_output_full.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt;
    cin >> tttt;
    for (int ttt = 1; ttt <= tttt; ttt++) {
        int N, K;
        cin >> N >> K;
        vector<int> S(N);
        int smallest = 1e9+7;
        for(int i = 0; i < N; i++) {
            cin >> S[i];
            smallest = min(smallest, S[i]);
        }
        bool possible = 1ll * (max(1, N - 1) + max(0, N - 2)) * smallest <= K;
        cout << "Case #" << ttt << ": " << (possible? "YES": "NO") << '\n';
    }

    return 0;
}