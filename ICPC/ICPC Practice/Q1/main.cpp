#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

void initGrid(vector<vector<int>>& grid, int rows, int cols)
{
    for(int i=0;i<rows;i++)
    {
        grid.push_back(vector<int>());
        for(int j=0;j<cols;j++)
        {
            grid[i].push_back(i*cols+j+1);
        }
    }
}

void printGrid(const vector<vector<int>>& grid)
{
    for(auto i=grid.begin();i!=grid.end();i++)
    {
        for(auto j=i->begin();j!=i->end();j++)
        {
            cout<<*j<<"\t";
        }
        cout<<endl;
    }
}

void executeAlgo(vector<vector<int>>& grid, int rows, int cols, int selectedNumber, int colOrder)
{
    int colNumber = -1;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if (grid[i][j]==selectedNumber)
            {
                colNumber = j;
                break;
            }
        }
        if(colNumber!=-1)
        {
            break;
        }
    }
    vector<vector<int>> newGrid;
    initGrid(newGrid, rows, cols);    
    vector<int> colsLeft(cols-1,0);
    for(int i=0;i<cols-1;i++)
    {
        if (i>=colNumber)
        {
            colsLeft[i] = i+1;
        }
        else
        {
            colsLeft[i] = i;
        }
    }
    int index = 0;
    int thisCol;
    for(int i=0;i<cols;i++)
    {
        if(i!=colOrder)
        {
            int randNum = rand()%colsLeft.size();
            thisCol = colsLeft[randNum];
            colsLeft.erase(colsLeft.begin()+randNum);
        }
        else
        {
            thisCol = i;
        }
        for(int i=0;i<rows;i++)
        {
            newGrid[index/cols][index%cols]=grid[i][thisCol];
            index++;
        }
    }
    grid = newGrid;
}

bool test1(int rows, int cols, int loc, int colOrder)
{
    vector<vector<int>> grid;
    initGrid(grid, rows, cols);
    for(int i=0;i<3;i++)
    {
        executeAlgo(grid, rows, cols, loc+1, colOrder);
    }
    if (grid[loc/cols][loc%cols] == loc+1)
    {
        return true;
    }
    else
    {
        return false;
    }   
} 

// int test2(int rows, int cols, int loc, int colOrder)
// {
//     vector<vector<int>> grid;
//     initGrid(grid, rows, cols);
//     int randNum = loc+1;
//     while(randNum == loc+1)
//     {
//         randNum = rand()%(rows*cols)+1;
//     }
//     for(int i=0;i<rows*cols;i++)
//     {
//         executeAlgo(grid, rows, cols, randNum, colOrder);
//         if (grid[loc/cols][loc%cols] == randNum)
//         {
//             return true;
//         }
//     }
//     return 1;   
// } 

bool checkWorks(int rows, int cols, int loc, int colOrder)
{
    return test1(rows,cols,loc,colOrder);
}

int getLocScore(int rows, int cols, int loc)
{
    int i = loc/cols;
    int j = loc%cols;
    int iScore = abs(rows/2-i);
    if(rows%2==0 && abs(rows/2-i-1)<iScore)
    {
        iScore = abs(rows/2-i-1);
    }
    int jScore = abs(cols/2-j);
    if(cols%2==0 && abs(cols/2-j-1)<jScore)
    {
        jScore = abs(cols/2-j-1);
    }
    return iScore+jScore;
}

void exec(int rows, int cols)
{
    vector<vector<int>> toTest;
    for(int i=0;i<cols;i++)
    {
        for(int j=0;j<rows*cols;j++)
        {
            toTest.push_back(vector<int>());
            toTest[toTest.size()-1].push_back(j);
            toTest[toTest.size()-1].push_back(i);
        }
    }
    for(int i=0;i<toTest.size();i++)
    {
        bool swapped = false;
        for(int j=0;j<toTest.size()-i-1;j++)
        {
            int leftScore = getLocScore(rows, cols, toTest[j][0]);
            int rightScore = getLocScore(rows, cols, toTest[j+1][0]);
            if(leftScore>rightScore)
            {
                swapped = true;
                vector<int> temp = toTest[j];
                toTest[j] = toTest[j+1];
                toTest[j+1] = temp; 
            }
            else if(leftScore==rightScore && toTest[j][1]>toTest[j+1][1])
            {
                swapped = true;
                vector<int> temp = toTest[j];
                toTest[j] = toTest[j+1];
                toTest[j+1] = temp;                
            }
        }   
        if(!swapped)
        {
            break;
        }
    }
    for(int i=0;i<toTest.size();i++)
    {
        if(checkWorks(rows, cols, toTest[i][0], toTest[i][1]))
        {
            int j = toTest[i][0];
            cout<<"Worked with -> Location = ("<<j/cols+1<<","<<j%cols+1<<") colOrder = "<<toTest[i][1]+1<<endl;
            break;
        }
    }
}

int main()
{
    srand(time(0));
    vector<vector<int>> g;
    int rows,cols;
    cin>>rows>>cols;
    exec(rows,cols);
    return 0;
}