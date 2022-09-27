#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int consecZero = 1;
    int myN = 0;
    for(int i=0;i<=flowerbed.size();i++)
    {
        if(i==flowerbed.size())consecZero++;
        if(i==flowerbed.size() || flowerbed[i]==1)
        {
            myN += (consecZero-1)/2;
            consecZero=0;
        }
        else
        {
            consecZero++;
        }
    }  
    return myN>=n;
}

int main()
{
    
    return 0;
}