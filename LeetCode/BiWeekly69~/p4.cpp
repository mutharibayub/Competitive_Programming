#include <iostream>
#include <vector>
using namespace std;

bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
    vector<vector<int>> canPlace(grid.size(),vector<int>(grid[0].size(),0));
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j])
            {
                int y_start=i-stampHeight<0?0:i-stampHeight;
                int x_start=j-stampWidth<0?0:j-stampWidth;
                for(int k=y_start;k<=y+1;k++)
                {
                    canPlace
                }
            }
        }
    }
}

int main()
{

    return 0;
}