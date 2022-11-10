#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define ll long long

const int A = 1e6+1;
const int N = 5e5+1;

vector<int> divisors[A];
vector<int> pos[A];
int ind[A];

void addDiv(int num)
{
    auto &arr = divisors[num];
    for(int i=1;i*i<=num;i++)
    {
        if(num%i==0)
        {
            arr.push_back(i);
            if(i*i!=num)arr.push_back(num/i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            pos[arr[i]].push_back(i);
        }
        vector<int> stk, less_right(n), more_right(n), less_left(n), more_left(n);
        
        for(int i=n-1;i>=0;i--)
        {
            while(stk.size() && arr[stk.back()] >= arr[i])
            {
                stk.pop_back();
            }
            less_right[i] = stk.size()?stk.back():n;
            stk.push_back(i);
        }
        stk.clear();

        for(int i=n-1;i>=0;i--)
        {
            while(stk.size() && arr[stk.back()] <= arr[i])
            {
                stk.pop_back();
            }
            more_right[i] = stk.size()?stk.back():n;
            stk.push_back(i);
        }
        stk.clear();

        for(int i=0;i<n;i++)
        {
            while(stk.size() && arr[stk.back()] < arr[i])
            {
                stk.pop_back();
            }
            more_left[i] = stk.size()?stk.back():-1;
            stk.push_back(i);
        }
        stk.clear();

        for(int i=0;i<n;i++)
        {
            while(stk.size() && arr[stk.back()] >= arr[i])
            {
                stk.pop_back();
            }
            less_left[i] = stk.size()?stk.back():-1;
            stk.push_back(i);
        }
        stk.clear();

        int64_t count = 0;

        for(int i=0;i<n;i++)
        {
            if(divisors[arr[i]].empty())addDiv(arr[i]);
            for(auto &num2:divisors[arr[i]])
            {
                if(ind[num2])
                {
                    int j = pos[num2][ind[num2]-1];
                    if(j > more_left[i] && i < less_right[j])
                    {
                        count += (j-max(less_left[j], more_left[i])) * 1LL * (min(less_right[j], more_right[i])-i);
                    }
                }
                if(pos[num2].size() && ind[num2]<pos[num2].size())
                {   
                    int j = pos[num2][ind[num2]];
                    if(j < more_right[i] && i > less_left[j])
                    {
                        count += (i-max({more_left[i], less_left[j], ind[num2]?pos[num2][ind[num2]-1]:-1})) * 1LL * (min(more_right[i], less_right[j])-j);
                    } 
                }
            }
            ind[arr[i]]++;
        }
        cout << count << '\n';
        for(int i=0;i<n;i++)
        {
            pos[arr[i]].clear();
            ind[arr[i]]=0;
        }
    }

    return 0;
}