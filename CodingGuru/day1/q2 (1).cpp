#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct tanks {
    int tank_a;
    int tank_b;
};

tanks read_test_case() {
    tanks val;
    cin >> val.tank_a;
    cin >> val.tank_b;
    return val;
}

int max_days(tanks val) {
    int days = 0;
    int refilled = 0; // 0 = a refilled, 1 = b refilled
    cout << endl;
    do {
        cout << "Tank A: " << val.tank_a << " Tank B: " << val.tank_b << endl;
        if (val.tank_a >= val.tank_b) {
            val.tank_a -= 2;
            val.tank_b += 1;
            refilled = 1;
        }
        else {
            val.tank_b -= 2;
            val.tank_a += 1;
            refilled = 0;
        }

        cout << "----Tank A: " << val.tank_a << " Tank B: " << val.tank_b << endl;

        if (refilled == 0 && val.tank_b == 1) {
            days++;
            break;
        }
        if (refilled == 1 && val.tank_a == 1) {
            days++;
            break;
        }
        days++;
    } while (val.tank_a > 0 && val.tank_b > 0);
    return days;
}

int main() {
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        tanks val = read_test_case();
        cout << "Case #" << i + 1 << ": " << max_days(val) << endl;
    }
}
