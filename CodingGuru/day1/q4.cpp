#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> read_test_case() {
    int vals;
    cin >> vals;
    vector<int> flowers;
    for (int i = 0; i < vals; i++) {
        int flower_count;
        cin >> flower_count;
        flowers.push_back(flower_count);
    }
    return flowers;
}

int solve(vector<int> flowers) {
    vector<int> sum(flowers.size(), 0);
    int array_sum = 0;
    int removed = 0;
    sort(flowers.begin(), flowers.end());
    for (int i = 0; i < flowers.size(); i++) {
        if (flowers[i] < array_sum) {
            removed++;
            continue;
        }
        array_sum+=flowers[i];
        sum[i] = array_sum;
    }
    return flowers.size() - removed;
}

int main() {
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        auto val = read_test_case();
        cout << "Case #" << i + 1 << ": " << solve(val) << endl;
    }
}
