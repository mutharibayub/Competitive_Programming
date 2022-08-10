#include <iostream>

using namespace std;

int main()
{
    int cols;
    string inStr;
    string outStr;
    cin>>cols;
    while(cols!=0)
    {
        cin>>inStr;
        outStr.resize(inStr.size(),'-');
        int rows = inStr.size()/cols;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                outStr[j*rows+i] = inStr[i*cols+(i%2==0?j:cols-j-1)];
            }
        }
        cout<<outStr<<'\n';
        cin>>cols;
    }
}