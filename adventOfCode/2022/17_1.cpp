#include <iostream>
#include <vector>

using namespace std;

const int N = 1e4;
const int M = 7;
bool grid[N][M];

int main() {
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            grid[i][j] = 0;
        }
    }

    vector<vector<int>> rocks[] = {
        {{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
        {{0,1,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0}},
        {{1,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}},
        {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}},
        {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
    };

    freopen("17input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string pattern;
    cin >> pattern;
    int top = 0, pattern_idx = 0;
    for(int i = 0; i < 2022; i++) {
        int rock_index = i%5;
        int r_loc = top + 3;
        int c_loc = 2;
        auto &cur_rock = rocks[rock_index];
        while(1) {
            int new_c_loc = c_loc + (pattern[pattern_idx]=='>'? +1: -1);
            if (new_c_loc >= 0 && new_c_loc < M) {
                bool ok = true;
                for(int j = 0; j < 4 && ok; j++) {
                    for(int k = 0; k < 4 && ok; k++) {
                        if(cur_rock[j][k] && (new_c_loc + k >= M || grid[r_loc + j][new_c_loc + k])) {
                            ok = false;
                        }
                    }
                }
                if(ok) {
                    c_loc = new_c_loc;
                }
            }
            pattern_idx = (pattern_idx+1)%pattern.size();
            bool no_r_change = true;
            int new_r_loc = r_loc - 1;
            if (new_r_loc >= 0) {
                bool ok = true;
                for(int j = 0; j < 4 && ok; j++) {
                    for(int k = 0; k < 4 && ok; k++) {
                        if(cur_rock[j][k] && grid[new_r_loc + j][c_loc + k]) {
                            ok = false;
                        }
                    }
                }
                if(ok) {
                    r_loc = new_r_loc;
                    no_r_change = false;
                }
            }
            if(no_r_change) {
                break;
            }
        } 
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                grid[j+r_loc][k+c_loc] |= cur_rock[j][k];
                if(cur_rock[j][k]) {
                    top = max(top-1, j+r_loc) + 1;
                }
            }
        }
    }
    // for(int i = top-1; i >= 0; i--) {
    //     for(int j = 0; j < M; j++) {
    //         cout << (grid[i][j]?'x':'.');
    //     }cout << '\n';
    // }
    cout << top << '\n';

    return 0;
}