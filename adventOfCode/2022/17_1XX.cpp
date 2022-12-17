#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <algorithm>
#include <set>
#include <assert.h>

using namespace std;

typedef long long ll;

const int GRID_H = 10000;

// int Edge(const vector<string> &rock)
// {
//     int minx = 1e9+7;
//     for(int i=0;i<rock.size();i++)
//     {
//         for(int j=0;j<rock[i].size();j++)
//         {
//             if(rock[i][j]=='#')minx=min(minx,j);
//         }
//     }
// }

int main()
{
    string filename = "17input.txt";
    ifstream fin(filename);

    string jet = "";
    getline(fin, jet);
    fin.close();
    int jetCnt=0;
    vector<vector<string>> rocks = {{"####"},
                                        {".#.",
                                        "###",
                                        ".#."},
                                    {"..#",
                                    "..#",
                                    "###"},
                                        {"#",
                                        "#",
                                        "#",
                                        "#"},
                                    {"##",
                                    "##"}}; 
    int ROCK_COUNT = rocks.size();
    for(int i=0;i<rocks.size();i++)
    {
        for(int j=0;j<rocks[i].size()/2;j++)
        {
            for(int k=0;k<rocks[i][j].size();k++)
            {
                swap(rocks[i][j][k],rocks[i][rocks[i].size()-j-1][k]);
            }
        }
    }
    array<char,7> grid[GRID_H];;
    for(int i=0;i<GRID_H;i++)
    {
        for(int j=0;j<7;j++)
        {
            grid[i][j]='.';
        }
    }
    int heighest=0;
    int turn=0;
    int ITERATIONS=2022;
    for(int cnt=0;cnt<ITERATIONS;cnt++)
    {
        vector<string> rock = rocks[turn];
        array<int,2> loc = {heighest+3,2};
        while(1)
        {
            assert(jet[jetCnt]=='<'||jet[jetCnt]=='>');
            int jetDir = (jet[jetCnt]=='>'?1:-1);
            if(loc[1]+rock[0].size()-1+jetDir<7&&loc[1]+jetDir>=0)
            {
                bool move=true;
                for(int i=0;i<rock.size()&&move;i++)
                {
                    for(int j=0;j<rock[i].size()&&move;j++)
                    {
                        if((grid[i+loc[0]][j+loc[1]+jetDir]=='#')&&(rock[i][j]=='#'))
                        {
                            move=false;
                        }
                    }
                }
                if(move)loc[1]+=jetDir;
            }
            jetCnt=(jetCnt+1)%jet.size();
            if(loc[0]<=0)break;
            bool settle=false;
            for(int i=0;i<rock.size()&&!settle;i++)
            {
                for(int j=0;j<rock[i].size()&&!settle;j++)
                {
                    if((rock[i][j]=='#')&&(grid[i+loc[0]-1][j+loc[1]]=='#'))
                    {
                        settle=true;
                    }
                }
            }
            if(settle)break;
            loc[0]--;
        }
        for(int i=0;i<rock.size();i++)
        {
            for(int j=0;j<rock[i].size();j++)
            {
                grid[i+loc[0]][j+loc[1]]=rock[i][j];
            }
        }

        heighest = max(heighest, int(loc[0]+rock.size()));
        turn=(turn+1)%ROCK_COUNT;
    }

    // for(int i=20;i>=0;i--)
    // {
    //     for(int j=0;j<7;j++)
    //     {
    //         cout << grid[i][j];
    //     }cout << '\n';
    // }

    cout << heighest << '\n';

    return 0;
}