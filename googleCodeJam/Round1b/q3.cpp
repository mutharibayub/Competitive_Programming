#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <random>
#include <assert.h>

using namespace std;

int countOnes(int num)
{
    int count=0;
    for(int i=0;i<31;i++)
    {
        count += num&(1<<i)?1:0;
    }
    return count;
}

void printBinary(int num)
{
    for(int i=0;i<8;i++)
    {
        cout<<(num&(1<<(7-i))?'1':'0');
    }
}

void testCase()
{
    int n;
    array<int,256> rands;
    for(int i=0;i<256;i++)
    {
        rands[i]=i;
    }
    do
    {   
        cin>>n;
        if(n==8)
        {
            cout<<"11111111\n";
        }
        else if(n==0)
        {
            return;
        }
        else if(n==-1)
        {
            assert(0);
        }
        else
        {
            unsigned seed = rand();
            shuffle(rands.begin(),rands.end(),default_random_engine(seed));
            int i=0;
            for(;countOnes(rands[i])!=n;i++)
            {}
            printBinary(rands[i]);
            cout<<endl<<flush;
        }

    }while (1);
}

int main()
{
    srand(time(0));
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase();
    }

    return 0;
}