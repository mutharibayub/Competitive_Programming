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
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;
 
typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;
 
double log_base(double num, double base) {
    return (log2(num) / log2(base)) * 100;   
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double logs[10];
    for(int i = 1; i < 10; i++) {
        logs[i] = (log_base(1+1.0/i, 10));
    }
    int tttt=1;
    cin>>tttt;
    while(tttt--) {
        double ans = 0;
        double total = 0;
        double ind[10];
        for(int i = 1; i <= 9; i++) {
            cin >> ind[i];
            total += ind[i];
        }
        for(int i = 1; i <= 9; i++) {
            ind[i] /= total;
            ind[i] *= 100;
            ans += abs(ind[i] - logs[i]);
        }
        stringstream ss("");
        ss << fixed << setprecision(10) << ans;
        string s = ss.str();
        int a = s.find('.');
        while((int)s.size() - a > 6)
            s.pop_back();
        cout << s << '\n';
    }
    return 0;
}