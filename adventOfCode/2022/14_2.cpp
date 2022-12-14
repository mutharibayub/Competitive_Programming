#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <array>

using namespace std;

typedef long long ll;

int main()
{
    string filename = "14input.txt";
    ifstream fin(filename);

    int maxY = 0;
    vector<vector<array<int,2>>> paths(1);
    string x="",y,t;
    while(!fin.eof())
    {
        if(x=="")fin>>x;
        fin>>y>>t;
        paths.back().push_back({stoi(y),stoi(x)});
        maxY= max(maxY, stoi(y));
        if(t=="")break;
        else if(t[0]=='-')x="";
        else 
        {
            paths.push_back(vector<array<int,2>>());
            x=t;
        }
    }

    maxY+=1;
    vector<vector<char>> grid(maxY+1, vector<char>(1000, '.'));
    for(int i=0;i<paths.size();i++)
    {
        for(int j=0;j+1<paths[i].size();j++)
        {
            array<int,2> c1 = paths[i][j];
            array<int,2> c2 = paths[i][j+1];
            if(c1[0]==c2[0])
            {
                if(c1[1]>c2[1])swap(c1[1],c2[1]);
                for(int k=c1[1];k<=c2[1];k++)
                {
                    grid[c1[0]][k]='#';
                }
            }
            else
            {
                if(c1[0]>c2[0])swap(c1[0],c2[0]);
                for(int k=c1[0];k<=c2[0];k++)
                {
                    grid[k][c1[1]]='#';
                }
            }
        }
    }

    // for(int j=0;j<=maxY;j++)
    // {
    //     for(int i=480;i<520;i++)
    //     {
    //         cout << grid[j][i];
    //     }cout << '\n';
    // }

    int cnt=0;
    while(1)
    {
        array<int,2> lc = {0, 500};
        bool end=false;
        while(1)
        {
            if(grid[lc[0]+1][lc[1]]=='.')lc[0]++;
            else if(grid[lc[0]+1][lc[1]-1]=='.')
            {
                lc[0]++;
                lc[1]--;
            }
            else if(grid[lc[0]+1][lc[1]+1]=='.')
            {
                lc[0]++;
                lc[1]++;
            }
            else
            {
                grid[lc[0]][lc[1]]='o';
                cnt++;
                if(lc[0]==0&&lc[1]==500)end=true;
                break;
            }
            if(lc[0]==maxY)
            {
                grid[lc[0]][lc[1]]='o';
                cnt++;
                break;
            }
        }
        if(end)break;
    }

    cout << cnt << '\n';

    return 0;
}