#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        map<int, pair<int,int>> indexes;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            auto iter = indexes.find(tmp);
            if(iter==indexes.end())
            {
                indexes[tmp] = make_pair(i,i);
            }
            else
            {
                iter->second.second = i;
            }
        }
        for(int i=0;i<k;i++)
        {
            int a,b;
            cin>>a>>b;
            auto iter1 = indexes.find(a), iter2 = indexes.find(b);
            if(iter1!=indexes.end() && iter2!=indexes.end() && iter1->second.first<=iter2->second.second)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}