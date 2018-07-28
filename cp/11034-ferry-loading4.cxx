#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <queue>
#include <bitset>
#include <set>
#include <stack>
#include <map>
#include <string>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int c;
    cin >> c;
    while(c--){
        int l,m;
        cin >> l >> m;
        queue<int> lq,rq;
        while(m--){
            int cl;
            string b;
            cin >> cl >> b;
            if(b == "left"){
                lq.push(cl);
            } else {
                rq.push(cl);
            }
        }

        bool onLeftBank = true;
        int n = 0;
        while (!lq.empty() || !rq.empty()) {
          queue< int >& cq = onLeftBank?lq:rq;
          int currentCapacity = 100*l;
          while((currentCapacity > 0) && !cq.empty() && (currentCapacity - cq.front() >= 0)){
            currentCapacity = currentCapacity-cq.front();
            cq.pop();
          }
          n++;
          onLeftBank = onLeftBank?false:true;

        }
        cout << n << endl;


    }
    return 0;
}
