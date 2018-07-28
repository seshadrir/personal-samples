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

bool isEmpty(const vector<queue<int> >& queues, const stack<int>& s){
    if(!s.empty()) {
        return false;
    }
    for(unsigned int i = 0; i < queues.size(); ++i) {
        if(!queues[i].empty()) {
            return false;
        }
    }
    return true;
}

int main()
{
    int SET;
    cin >> SET;
    while(SET--){
        unsigned int N, S, Q;
        cin >> N >> S >> Q;
        vector<queue<int> > stations(N);
        for(unsigned int i = 0; i < N; ++i){
            int cl;
            cin >> cl;
            while(cl--){
                int ss;
                cin >> ss;
                stations[i].push(ss);
            }
        }

        stack<int> s;
        const unsigned int load = 1, unload = 1, move = 2;
        unsigned int cl = 0, t = 0;
        while(!isEmpty(stations, s)){
            cl = cl % N;
            /// unloading the stack
            while(!s.empty()) {
                int top = s.top();
                if((top-1) == cl){
                    s.pop();
                    t = t + unload;
                    continue;
                }
                if(stations[cl].size() < Q){
                    s.pop();
                    t = t + unload;
                    stations[cl].push(top);
                    continue;
                } else {
                  break;
                }
            }


            /// loading the stack
            while(!stations[cl].empty()){
                int ss = stations[cl].front();
                if(s.size() < S){
                    s.push(ss);
                    stations[cl].pop();
                    t = t + load;
                } else {
                    break;
                }
            }
            t = t + move;








            cl++;
        }
        cout << t-move << endl;



    }
    return 0;
}
