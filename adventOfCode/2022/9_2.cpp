#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef long long ll;

bool isNeighbour(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2)<2 && abs(y1-y2)<2;
}

void moveTail(int &tx, int &ty, int hx, int hy)
{
    if(abs(tx-hx)>1 && abs(ty-hy)>1)
    {
        tx=(tx+hx)/2;
        ty=(ty+hy)/2;
    }
    else if(abs(tx-hx)>1)
    {
        tx=(tx+hx)/2;
        ty=hy;
    }
    else
    {
        ty=(ty+hy)/2;
        tx=hx;
    }
}

int main()
{
    string filename = "9input.txt";
    ifstream fin(filename);

    set<ll> visited;
    vector<pair<int,int>> knots(10, {1<<15,1<<15});
    visited.insert((1ll*knots.back().first<<30)+knots.back().second);
    while(!fin.eof())
    {
        string dir;
        int count;
        fin>>dir>>count;
        if(dir=="")break;
        for(int i=0;i<count;i++)
        {
            if(dir=="R")knots[0].first+=1;
            else if(dir=="L")knots[0].first-=1;
            else if(dir=="U")knots[0].second+=1;
            else if(dir=="D")knots[0].second-=1;
            for(int j=0;j+1<10;j++)
            {
                if(!isNeighbour(knots[j+1].first,knots[j+1].second,knots[j].first,knots[j].second))
                {
                    moveTail(knots[j+1].first,knots[j+1].second,knots[j].first,knots[j].second);
                    if(j==8)visited.insert((1ll*knots.back().first<<30)+knots.back().second);
                }
                else break;
            }
        }
    }
    cout << visited.size() << '\n';

    return 0;
}