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

inline int getDist(array<int,2> &pt1, array<int,2> &pt2)
{
    return abs(pt1[0]-pt2[0])+abs(pt1[1]-pt2[1]);
}

int main()
{
    string filename = "15input.txt";
    ifstream fin(filename);

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

    ll pt1=0,pt2=0,pt3=0;

    array<int,2> ans;
    const int MAX_Y = 4000000;
    for(int y=0;y<=MAX_Y;y++)
    {
        bool end=false;
        vector<array<int,2>> ranges;
        ranges.reserve(100);
        for(int i=0;i<arr.size();i++)
        {
            auto &pt1=arr[i][0];
            auto &pt2=arr[i][1];
            int dist = getDist(pt1,pt2);
            array<int,2> closest = {pt1[0], y};
            int cDist = getDist(pt1, closest);
            if(cDist<=dist)
            {
                int diff=dist-cDist;
                ranges.push_back({pt1[0]-diff, pt1[0]+diff});
            }
        }
        sort(ranges.begin(), ranges.end());
        ll cnt=0;
        array<int,2> rng=ranges[0];
        for(int i=1;i<ranges.size();i++)
        {
            if(rng[1]<ranges[i][0]-1)
            {
                int open = ranges[i][0]-1;
                if(open>=0&&open<=MAX_Y)
                {
                    ans[0]=open;
                    ans[1]=y;
                    end=true;
                    break;
                }
                rng=ranges[i];
            }
            else
            {
                rng[1]=max(rng[1],ranges[i][1]);
            }
        }
        if(end)break;
    }

    cout << ans[0]*4000000ll+ans[1] << '\n';


    return 0;
}