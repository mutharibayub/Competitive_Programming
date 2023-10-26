#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <iomanip>
#include <tuple>
#include <cassert>
using namespace std;

template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tttt;
    cin>>tttt;
    for(int ttt=1;ttt<=tttt;ttt++)
    {
        int n;
        cin>>n;
        vector<string> words(n);
        for(auto &word: words)
            cin >> word, reverse(word.begin(), word.end());
        vector<vector<int>> trie(1, vector<int>(26, -1));
        vector<int> depth(1, 0);
        vector<vector<int>> who(1);
        for(int i = 0; i < words.size(); i++)
        {
            int ptr = 0;
            for(auto &c: words[i])
            {
                if(trie[ptr][c-'a'] == -1)
                {
                    trie[ptr][c-'a'] = (int)trie.size();
                    depth.push_back(depth[ptr] + 1);
                    trie.emplace_back(26, -1);
                    who.push_back({});
                }
                ptr = trie[ptr][c-'a'];
                who[ptr].push_back(i);
            }
        }
        map<int, vector<int>> groupsAtDepth;
        for(int i = 1; i < trie.size(); i++)
        {
            groupsAtDepth[depth[i]].push_back(i);
        }
        int q;
        cin >> q;
        map<int, vector<array<int, 2>>> queries;
        for(int i = 0; i < q; i++)
        {
            array<int, 3> tmp;
            for(int j = 0; j < 3; j++)
            {
                cin >> tmp[j];
                tmp[j] -= (j < 2);
            }
            queries[tmp[2]].push_back({tmp[0], tmp[1]});
        }
        int ans = 0;
        for(auto query: queries)
        {
            vector<int> compr;
            for(int i = 0; i < query.second.size(); i++)
            {
                compr.push_back(query.second[i][0]);
                compr.push_back(query.second[i][1]);
            }
            vector<array<int, 2>> nodeGroups;
            int groupCount = 0;
            for(auto &group: groupsAtDepth[query.first])
            {
                groupCount++;
                for(auto node: who[group])
                {
                    nodeGroups.push_back({node, groupCount});
                    compr.push_back(node);
                }
            }
            sort(compr.begin(), compr.end());
            vector<int> arr(compr.size(), 0);
            for(int i = 0; i < nodeGroups.size(); i++)
            {
                int idx = lower_bound(compr.begin(), compr.end(), nodeGroups[i][0]) - compr.begin();
                arr[idx] = nodeGroups[i][1];
            }
            for(int i = 0; i < query.second.size(); i++)
            {
                query.second[i][0] = lower_bound(compr.begin(), compr.end(), query.second[i][0]) - compr.begin();
                query.second[i][1] = lower_bound(compr.begin(), compr.end(), query.second[i][1]) - compr.begin();
            }
            int root = sqrt((double)compr.size());
            assert(root > 0);
            sort(query.second.begin(), query.second.end(), [&](auto &a, auto &b){return make_pair(a[0]/root, a[1]) < make_pair(b[0]/root, b[1]);});
            int l = 0, r = 0;
            vector<int> count(groupCount+1, 0);
            vector<int> cc(2000+1, 0);
            auto remove = [&](int groupId) {
                if (!arr[groupId])
                    return;
                cc[min(2000, count[arr[groupId]])]--;
                count[arr[groupId]]--;
                cc[min(2000, count[arr[groupId]])]++;
            };
            auto add = [&](int groupId) {
                if (!arr[groupId])
                    return;
                cc[min(2000, count[arr[groupId]])]--;
                count[arr[groupId]]++;
                cc[min(2000, count[arr[groupId]])]++;
            };
            add(0);
            for(auto q: query.second)
            {
                while(l > q[0])
                    add(--l);
                while(r < q[1])
                    add(++r);
                while(r > q[1])
                    remove(r--);
                while(l < q[0])
                    remove(l++);
                int val = 0;
                for(int i = 1; i <= 2000; i++)
                {
                    val = min(i, val + cc[i]);
                }
                ans += val;
            }

        }
        
        cout << "Case #" << ttt << ": " << ans << '\n';

    }

    return 0;
}
