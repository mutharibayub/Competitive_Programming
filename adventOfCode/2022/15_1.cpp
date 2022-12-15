#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int getDist(array<int,2> &pt1, array<int,2> &pt2)
{
    return abs(pt1[0]-pt2[0])+abs(pt1[1]-pt2[1]);
}

bool inRange(int a, int b, int v)
{
    if(a>b)swap(a,b);
    return v>=a&&v<=b;
}

ll countInRange(array<int,2> &rng, int y, set<array<int,2>> &items)
{
    ll cnt=rng[1]-rng[0]+1;
    for(auto item:items)
    {
        auto &pt = item;
        if(pt[1]==y && inRange(rng[0],rng[1],pt[0]))
        {
            cnt--;
        }
    }
    return cnt;
}

int main()
{
    string filename = "15input.txt";
    ifstream fin(filename);

    set<array<int,2>> items;
    vector<array<array<int,2>,2>> arr;
    while(!fin.eof())
    {
        string s;
        getline(fin, s);
        if(s=="")break;
        arr.push_back(array<array<int,2>,2>());
        int cnt=0;
        for(int i=0;s[i];i++)
        {
            string tmp="";
            if(s[i]=='-'||(s[i]>='0'&&s[i]<='9'))
            {
                while(s[i]=='-'||(s[i]>='0'&&s[i]<='9'))
                {
                    tmp.push_back(s[i]);
                    i++;
                }
                i--;
                arr.back()[cnt/2][cnt%2]=stoi(tmp);
                cnt++;
            }
        }
    }

    int y = 2000000;
    vector<array<int,2>> ranges;
    for(int i=0;i<arr.size();i++)
    {
        auto &pts=arr[i];
        items.insert(pts[0]);
        items.insert(pts[1]);
        int dist = getDist(pts[0],pts[1]);
        array<int,2> closest = {pts[0][0], y};
        int cDist = getDist(pts[0], closest);
        if(cDist<=dist)
        {
            int diff=dist-cDist;
            ranges.push_back({pts[0][0]-diff, pts[0][0]+diff});
        }
    }
    sort(ranges.begin(), ranges.end());
    ll cnt=0;
    array<int,2> rng=ranges[0];
    for(int i=1;i<ranges.size();i++)
    {
        if(rng[1]<ranges[i][0]-1)
        {
            cnt+=countInRange(rng, y, items);
            rng=ranges[i];
        }
        else
        {
            rng[1]=max(rng[1],ranges[i][1]);
        }
    }
    cnt+=countInRange(rng, y, items);
    cout << cnt << '\n';


    return 0;
}