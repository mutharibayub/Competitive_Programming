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
    if(abs(tx-hx)>1)
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
    int hx=1<<15; int hy=1<<15;
    int tx=1<<15; int ty=1<<15;
    visited.insert(((1ll*tx)<<30)+ty);
    while(!fin.eof())
    {
        string dir;
        int count;
        fin>>dir>>count;
        if(dir=="")break;
        for(int i=0;i<count;i++)
        {
            if(dir=="R")hx+=1;
            else if(dir=="L")hx-=1;
            else if(dir=="U")hy+=1;
            else if(dir=="D")hy-=1;
            if(!isNeighbour(tx,ty,hx,hy))
            {
                moveTail(tx,ty,hx,hy);
                visited.insert(((1ll*tx)<<30)+ty);
            }
        }
    }
    cout << visited.size() << '\n';

    return 0;
}