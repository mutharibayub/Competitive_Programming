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
 
const int MOD = 1e9+7;
 
class SquareMatrix {
public:
    vector<vector<ll>> mat;
    SquareMatrix(int n) {
        mat = vector<vector<ll>>(n, vector<ll>(n, 0));
    }
    static SquareMatrix get_identity(int n) {
        SquareMatrix out(n);
        for(int i = 0; i < out.mat.size(); i++) {
            out.mat[i][i] = 1;
        }
        return out;
    }
    SquareMatrix operator*(const SquareMatrix &other) const {
        assert(mat.size() == other.mat.size());
        SquareMatrix ans(mat.size());
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat.size(); j++) {
                for(int k = 0; k < mat.size(); k++) {
                    ans.mat[i][j] += this->mat[i][k] * other.mat[k][j] % MOD;
                }
            }
        }
        return ans;
    }
    SquareMatrix operator%(int mod) const {
        SquareMatrix out = *this;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat.size(); j++) {
                out.mat[i][j] %= mod;
            }
        }
        return out;
    }
};
 
template <typename T>
T pwr(T n, ll e, T init) {
    while(e) {
        if(e&1) {
            init = init * n % MOD;
        }
        e >>= 1;
        n = n * n % MOD;
    }
    return init;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, k, x;
        cin >> n >> x >> k;
 
        ll val_1 = (x+k) * pwr<ll>(2*k+1, n-1, 1) % MOD;
        ll val_2 = 0;
        if(x) {
            SquareMatrix sq(x);
            for(int i = 0; i < x; i++) {
                for(int j = max(0, i-k); j <= min(x-1, i+k); j++) {
                    sq.mat[i][j]++;
                }
            }
            sq = pwr<SquareMatrix>(sq, n-1, SquareMatrix::get_identity(x));
            for(int i = 0; i < x; i++) {
                for(int j = 0; j < x; j++) {
                    val_2 += sq.mat[i][j];
                }
            }
            val_1 -= val_2 % MOD - MOD;
            if(val_1 >= MOD) {
                val_1 -= MOD;
            }
        }
        cout << val_1 << '\n';
    }
    return 0;
}