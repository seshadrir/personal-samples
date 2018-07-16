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
        int n,t,m;
        cin >> n >> t >> m;
        queue<pair<int,int> > lq,rq;
        vector<pair<int, int> > order;
        int nn = 0;
        while(m--){
            int ct;
            string b;
            cin >> ct >> b;
            if(b == "left"){
                lq.push(make_pair(ct,nn));
            } else {
                rq.push(make_pair(ct,nn));
            }
            nn++;
        }

        int currentTime = 0; bool onLeftBank = true;
        while (!lq.empty() || !rq.empty()) {
            int lcf = INT_MAX, rcf = INT_MAX;
            if(!lq.empty())
                lcf = lq.front().first;
            if(!rq.empty())
                rcf = rq.front().first;

            if(currentTime < min(lcf, rcf)){
                currentTime = min(lcf, rcf);
                continue;
            }
            if((onLeftBank && (currentTime >= lcf)) ||
                    (!onLeftBank && (currentTime >= rcf))){
                queue<pair<int, int> >& cq = onLeftBank?lq:rq;
                int currentCapacity = n;
                while(currentCapacity-- && !cq.empty() && cq.front().first <= currentTime){
                    pair<int, int> pp = cq.front();
                    pp.first = currentTime+t;
                    order.push_back(make_pair(pp.second, pp.first));
                    cq.pop();
//                    cout << currentTime+t << endl;
                }
                currentTime += t;
                onLeftBank = onLeftBank?false:true;
                continue;

            }
            currentTime += t;
            onLeftBank = onLeftBank?false:true;


        }
        sort(order.begin(), order.end());
        for(int i = 0; i < order.size(); ++i)
            cout << order.at(i).second << endl;
        if(c)
            cout << endl;



    }
    return 0;
}
