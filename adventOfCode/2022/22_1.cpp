#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <array>

using namespace std;

#define DEBUG(X) cout << #X": " << X << endl;

int main()
{
    string filename = "22input.txt";
    ifstream fin(filename);

    vector<string> grid;
    string path;
    int r=0,c=0;

    while(!fin.eof())
    {
        string tmp;
        getline(fin, tmp);
        if(tmp=="")
        {
            fin>>path;
            break;
        }
        grid.push_back(tmp);
        c=max(c, (int)tmp.size());
    }
    fin.close();

    r=grid.size();
    vector<int> RS(r,-1),RE(r,-1),CS(c,-1),CE(c,-1);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(j>=grid[i].size())break;
            if(grid[i][j]=='.'||grid[i][j]=='#')
            {
                if(RS[i]==-1)RS[i]=j;
                RE[i]=j;
                if(CS[j]==-1)CS[j]=i;
                CE[j]=i;
            }
        }
    }

    int cr=0,cc=RS[0];
    int dir=0;

    vector<array<int,2>> move = {{0,1},{1,0},{0,-1},{-1,0}};
    for(int i=0;path[i];i++)
    {
        if(path[i]>='0'&&path[i]<='9') // steps
        {
            string tmp="";
            while(path[i]>='0'&&path[i]<='9')
            {
                tmp.push_back(path[i]);
                i++;
            }
            int steps=stoi(tmp);
            for(int j=0;j<steps;j++)
            {
                auto mv = move[dir];
                int tcr=cr,tcc=cc;
                if(mv[0])
                {
                    cr+=mv[0];
                    if(cr<CS[cc])cr=CE[cc];
                    else if(cr>CE[cc])cr=CS[cc];
                }
                else
                {
                    cc+=mv[1];
                    if(cc<RS[cr])cc=RE[cr];
                    else if(cc>RE[cr])cc=RS[cr];
                }
                if(grid[cr][cc]=='#')
                {
                    cr=tcr;
                    cc=tcc;
                    break;
                }
            }
            i--;
        }
        else //dir
        { 
            int dirChange = path[i]=='R'?1:3;
            dir = (dir+dirChange)%4;
        }
    }

    cout << 1000ll*(cr+1)+4ll*(cc+1)+dir << '\n';

    return 0;
}