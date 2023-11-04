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
    // cin>>tttt;
    while(tttt--)
    {
        int n;
        cin >> n;
        map<int, int> count[6];
        map<pair<int, int>, int> count1[6];
        vector<string> tickets(n);
        for(int i = 0; i < n; i++) {
            cin >> tickets[i];
            int sum = 0, tSum = 0;
            for(int j = 0; j < tickets[i].size(); j++) {
                tSum += tickets[i][j]-'0';
            }
            for(int j = 0; j < tickets[i].size(); j++) {
                sum += tickets[i][j]-'0';
                tSum -= tickets[i][j]-'0';
                count1[tickets[i].size()][{j+1, tSum-sum}]++;
            }
            count[tickets[i].size()][sum]++;
        }
        long long ans = 0;
        for(int i = 0; i < tickets.size(); i++) {
            int sum = 0;
            for(int j = 0; j < tickets[i].size(); j++) {
                sum += tickets[i][j]-'0';
            }
            int otherSum = 0;
            for(int j = tickets[i].size() - 1; j >= 0; j--) {
                int len = j + 1 - (tickets[i].size() - j - 1);
                if (len > 0) {
                    ans += count[len][sum-otherSum];
                }
                sum -= tickets[i][j]-'0';
                otherSum += tickets[i][j]-'0';
            }
            for(int j = max(1, (int)tickets[i].size()+1); j <= 5; j++) {
                if((tickets[i].size() + j) % 2) {
                    continue;
                }
                int req = (tickets[i].size() + j) / 2 - tickets[i].size();
                ans += count1[j][{req, otherSum}];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}