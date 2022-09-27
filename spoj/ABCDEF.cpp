#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_set<int> set;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        set.insert(arr[i]);
    }
    int64_t count = 0;
    for(int a=0;a<n;a++)
    {
        for(int b=0;b<n;b++)
        {
            for(int c=0;c<n;c++)
            {
                for(int d=0;d<n;d++)
                {
                    if(arr[d] && (arr[a]*arr[b]+arr[c])%arr[d]==0)
                    for(int e=0;e<n;e++)
                    {
                        if(set.find((arr[a]*arr[b]+arr[c])/arr[d]-arr[e])!=set.end())
                        {
                            count++;
                        }
                    }   
                }   
            }   
        }
        cout << count << endl;
    }
    cout << count << endl;

    return 0;
}