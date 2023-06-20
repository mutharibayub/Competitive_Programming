#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <random>

using namespace std;

typedef long long ll;

const int sampleSize = 350;

void findAns(int cur, int mn, int mx) {
    int sqrt = (1000-sampleSize)/2;

    int num = 0;
    map<int, int> locs;

    locs[cur] = 0;
    for(int i=1;i<sqrt;i++) {
        cout << "+ 1" << endl;
        cin>>num;
        if(locs.find(num) != locs.end()) {
            cout << "! " << i << endl;
            return;
        }
        locs[num] = i; 
    }
    cout << "+ " << mn-sqrt << endl;
    cin>>num;
    if(locs.find(num)!=locs.end()) {
        cout << "! " << mn - locs[num] - 1 << endl;
        return; 
    }
    for(int i=1;i<=sqrt;i++) {
        cout << "+ " << sqrt << endl;
        cin>>num;
        if(locs.find(num) != locs.end()) {
            cout << "! " << mn + (i*sqrt) - locs[num] - 1 << endl;
            return;
        }
    }
    assert(false);
}

int main() {

    random_device rd;  // a seed source for the random number engine
    mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(1, int(1e6)-1);

    int mx = 0;
    int num = 0;

    set<int> samples;
    while(samples.size() < sampleSize) {
        samples.insert(distrib(gen));
    }

    cin>>num;
    mx = max(mx, num);
    int last = 0;
    for(auto sample: samples) {
        cout << "+ " << sample-last << endl;
        cin>>num;
        mx = max(mx, num);
        last = sample;
    }
    
    findAns(num, mx, 1e6);

    return 0;
}