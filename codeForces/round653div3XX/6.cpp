#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <array>

using namespace std;

template<typename T>
void roll(vector<T> &arr, int idx)
{
    assert(idx<=arr.size()-3);
    T tmp = arr[idx];
    arr[idx]=arr[idx+2];
    arr[idx+2]=arr[idx+1];
    arr[idx+1]=tmp;
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
        vector<array<int,2>> arr(n); 
        vector<int> cnt(500+1, 0);
        bool repeater = false;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i][0];
            arr[i][1]=-1;
            if(++cnt[arr[i][0]] == 2)repeater=true;
        }
        for(int i=0;i<n;i++)
        {
            int minNum = 1e9+7, minIndex = -1;
            for(int j=0;j<n;j++)
            {
                if(arr[j][1]!=-1)continue;
                if(minNum>arr[j][0])
                {
                    minNum=arr[j][0];
                    minIndex=j;
                }
            }
            arr[minIndex][1]=i;
        }
        int inversions = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i][1]>arr[j][1])inversions++;
            }
        }
        if(inversions%2)
        {
            if(repeater)
            {
                bool end = false;
                for(int i=0;i<n&&!end;i++)
                {
                    for(int j=i+1;j<n&&!end;j++)
                    {
                        if(arr[i][0]==arr[j][0])
                        {
                            swap(arr[i][1], arr[j][1]);
                            end=true;
                        }
                    }
                }
            }
            else
            {
                cout << -1 << '\n';
                continue;
            }
        }
        vector<int> moves;
        for(int i=0;i<n-2;i++)
        {
            int mnIdx = -1;
            for(int j=i;j<n;j++)
            {
                if(arr[j][1]==i)
                {
                    mnIdx=j;
                    break;
                }
            }
            int ii = mnIdx;
            while(ii!=arr[ii][1])
            {
                if(ii-1==arr[ii][1])
                {
                    moves.push_back(ii-1);
                    moves.push_back(ii-1);
                    roll(arr, ii-1);
                    roll(arr, ii-1);
                    ii-=1;
                }
                else
                {
                    moves.push_back(ii-2);
                    roll(arr, ii-2);
                    ii-=2;
                }
            }
        }
        cout << moves.size() << '\n';
        for(int i=0;i<moves.size();i++)
        {
            if(i)cout << ' ';
            cout << moves[i]+1;
        }cout << '\n';
    }
    return 0;
}