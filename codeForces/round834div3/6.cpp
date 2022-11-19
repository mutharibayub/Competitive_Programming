#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <set>

using namespace std;

typedef long long ll;

void rl(vector<int> &arr, int b, set<int> &done)
{
    int carry=1;
    for(int i=arr.size()-2;i>=0&&carry;i--)
    {
        arr[i]+=carry;
        carry=0;
        if(arr[i]==b)
        {
            arr[i]=0;
            carry=1;
        }
        done.insert(arr[i]);
    }
    if(carry)done.insert(1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n, b, last;
        cin>>n>>b;
        vector<int> arr(n);
        set<int> done;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            done.insert(arr[i]);
        }
        last = arr.back();
        int num=(arr.back()+b-1)%b;
        bool roll = false;
        int notFound = -1;
        while(1)
        {
            if(num==arr.back())break;
            if(done.find(num)!=done.end())
            {
                num=(num+b-1)%b;
            }
            else
            {
                if(num<arr.back() && !roll)
                {
                    roll=true;
                    rl(arr, b, done);
                }
                else
                {
                    notFound = num;
                    break;
                }
            }
        }
        if(roll)
        {
            if(notFound==-1 || notFound>last)
            {
                cout << b-last << '\n';
            }    
            else
            {
                cout << b-last+notFound << '\n';
            }
        }
        else
        {
            if(notFound==-1)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << notFound-last << '\n';
            }
        }



    }


    return 0;
}