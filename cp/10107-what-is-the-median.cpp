#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
    int v;
    vector<int> a;
    while (scanf("%d", &v) == 1){
        a.push_back(v);
        if(a.size() == 1){
            cout << a[0] << endl;
        } else if(a.size() == 2){
            cout << (a[0]+a[1])/2 << endl;
        } else {
            if(a.size()%2 == 1){
                nth_element(a.begin(), a.begin()+a.size()/2, a.end());
                std::cout << a[a.size()/2] << endl;
            } else {
                nth_element(a.begin(), a.begin()+a.size()/2, a.end());
                int s = a[a.size()/2];
                nth_element(a.begin(), a.begin()+a.size()/2-1, a.end());
                int f = a[a.size()/2-1];
                std::cout << (f+s)/2 << endl;
            }
        }
    }
    return 0;
}
