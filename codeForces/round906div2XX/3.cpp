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
 
int add(string &arr)
{
    int loc = -1;
    for(int i = 0; i < arr.size()/2; i++)
    {
        if(arr[i] == arr[arr.size() - i - 1])
        {
            loc = i;
            break;
        }
    }
    if(loc == -1)
        return -1;
    int addLoc = arr[loc] == '0'? arr.size() - loc: loc;
    string toAdd = "01";
    arr.insert(arr.begin() + addLoc, toAdd.begin(), toAdd.end());
    return addLoc;
}
 
int main()
{
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
 
        if(s.size()%2)
        {
            cout << -1 << '\n';
            continue;
        }
 
        bool found = false;
        vector<int> additions;
        for(int i = 0; i < 300; i++)
        {
            additions.push_back(add(s));
            if(additions.back() == -1)
            {
                additions.pop_back();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << additions.size() << '\n';
        for(int i = 0; i < additions.size(); i++)
            cout << additions[i] << " \n"[i==additions.size()-1];
 
    }
    return 0;
}