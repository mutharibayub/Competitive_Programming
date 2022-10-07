#include <iostream>
using namespace std;

string capitalizeTitle(string title) {
    int wordStart = 0;
    for(int i=0;title[i];i++)
    {
        if(title[i]==' ')
        {
            wordStart=i+1;
            continue;
        }
        if(title[i+1]==' '||title[i+1]==0)
        {
            for(int j=wordStart;j<=i;j++)
            {
                title[j]=title[j]|32;
            }
            if(i-wordStart+1>2)
            {
                title[wordStart]=title[wordStart]&(~32);
            }
        }
    }   
    return title; 
}

int main()
{
    cout<<capitalizeTitle("capiTalIze tHe titLe");
}