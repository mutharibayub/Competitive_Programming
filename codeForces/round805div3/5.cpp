#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <list>

using namespace std;

void addDomin(array<int,2> &arr, int val)
{
    if(arr[0]==-1)arr[0]=val;
    else arr[1]=val;
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
        list<array<int,3>> li;
        unordered_set<int> set1,set2;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            li.push_front({i,a,b});
        }
        bool yes=true;
        int skipStart = -1;
        while(!li.empty())
        {
            array<int,3> top = li.front();
            li.pop_front();
            if(top[1]==top[2] || (set1.count(top[1]) || set1.count(top[2]))&&(set2.count(top[1]) || set2.count(top[2])))
            {
                yes=false;
                break;
            }
            else if((set1.count(top[1]) || set1.count(top[2])))
            {
                // exist in only set1
                set2.insert(top[1]),set2.insert(top[2]);
                skipStart=-1;
            }
            else if((set2.count(top[1]) || set2.count(top[2])) || skipStart==top[0])
            {
                // exist in only set2
                set1.insert(top[1]),set1.insert(top[2]);
                skipStart=-1;
            }
            else
            {
                // exist in neither
                if(skipStart==-1)skipStart=top[0];
                li.push_back(top);
            }
        }
        if(yes)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}