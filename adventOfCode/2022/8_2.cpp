#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <chrono>
using namespace std::chrono;
 
using namespace std;

typedef long long ll;

int main()
{
    string filename = "8input.txt";
    ifstream fin(filename);

    vector<string> mat;
    int ans=0;
    while(!fin.eof())
    {
        string s;
        fin>>s;
        if(s=="")break;
        mat.push_back(s);
    }
    auto start = high_resolution_clock::now();
    for(int x=0;x<mat[0].size();x++)
    {
        for(int y=0;y<mat.size();y++)
        {
            int val = mat[y][x];
            int c=1;
            int c1=1;
            if(y==3 && x==2)
            {
                int Checkpoint=0;
                Checkpoint++;
            }
            for(int i=1;;i++)
            {
                if(y-i<0)
                {
                    c1--;
                    break;
                }
                else if(mat[y-i][x]<val)c1++;
                else break;
            }
            c*=c1;
            c1=1;
            for(int i=1;;i++)
            {
                if(y+i>=mat.size())
                {
                    c1--;
                    break;
                }
                else if(mat[y+i][x]<val)c1++;
                else break;
            }
            c*=c1;
            c1=1;
            for(int i=1;;i++)
            {
                if(x-i<0)
                {
                    c1--;
                    break;
                }
                else if(mat[y][x-i]<val)c1++;
                else break;
            }
            c*=c1;
            c1=1;
            for(int i=1;;i++)
            {
                if(x+i>=mat[0].size())
                {
                    c1--;
                    break;
                }
                else if(mat[y][x+i]<val)c1++;
                else break;
            }
            c*=c1;
            ans = max(ans, c);
        }
    }
    cout << ans << '\n';
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << duration.count() << " micro seconds"<< endl;
    return 0;
}