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
    cin>>tttt;
    while(tttt--)
    {
        vector<int> threads(3);
        for(int i=0; i<3; i++)
            cin>>threads[i];
        bool yes = false;
        sort(threads.begin(), threads.end());
        for(int i=0;i<4;i++)
        {
            bool ok = true;
            int val = threads.front();
            for(auto &thread: threads)
            {
                ok &= (val==thread);
            }
            if(ok)
            {
                yes = true;
                break;
            }
            threads.push_back(threads.front());
            threads[(int)threads.size()-2] -= threads.back(); 
            sort(threads.begin(), threads.end());
        }
        cout << (yes?"YES":"NO") << '\n';
    }
    return 0;
}