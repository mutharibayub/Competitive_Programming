#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define ll long long

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
        vector<int> arr(n), ind(n);
        unordered_map<int, vector<int>> pos;
        unordered_map<int, int> ind;
        ind.reserve(n);
        pos.reserve(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            pos[arr[i]].push_back(i);
        }
        vector<int> stk, less_right(n), more_right(n), less_left(n), more_left(n);
        
        for(int i=n-1;i>=0;i--)
        {
            while(stk.size() && arr[stk.back()] > arr[i])
            {
                stk.pop_back();
            }
            less_right[i] = stk.size()?stk.back():n;
            stk.push_back(i);
        }
        stk.clear();

        for(int i=n-1;i>=0;i--)
        {
            while(stk.size() && arr[stk.back()] < arr[i])
            {
                stk.pop_back();
            }
            more_right[i] = stk.size()?stk.back():n;
            stk.push_back(i);
        }
        stk.clear();

        for(int i=0;i<n;i++)
        {
            while(stk.size() && arr[stk.back()] <= arr[i])
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

        for(int i=0;i<n;i++)
        {
            cout << arr[i] << ' ';
        }cout << '\n';

        for(int i=0;i<n;i++)
        {
            cout << less_right[i] << ' ';
        }cout << '\n';

        int64_t count = 0;

        for(int i=0;i<n;i++)
        {
            for(int num2=arr[i];num2<int(1e6+1);num2+=arr[i])
            {
                if(ind[num2])
                {
                    int j = pos[num2][ind[num2]-1];
                    if(j > less_left[i] && i < more_right[j])
                    {
                        count += (j-max(more_left[j], less_left[i])) * 1LL * (min(more_right[j], less_right[i])-i);
                    }
                }
                if(ind[num2]<pos[num2].size())
                {   
                    int j = pos[num2][ind[num2]];
                    if(j > less_right[i] && i < more_left[j])
                    {
                        count += (i-max(more_left[i], less_left[j])) * 1LL * (min(more_right[i], less_right[j])-j);
                    } 
                }
            }
            ind[arr[i]]++;
        }

    }

    return 0;
}