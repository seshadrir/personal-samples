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
#include <stack>

using namespace std;

int main()
{
    while(true) {
        int N;
        cin >> N;
        if(N == 0)
            return 0;
        while(true){
            vector<int> req;
            int v;
            for(int i = 0; i < N; ++i){
                cin >> v;
                if(v == 0)
                    break;
                req.push_back(v);
            }
            if(req.size() != N){
                cout << endl;
                break;
            }
            stack<int> s;
            int k = 0;
            for(int i = 1; i <= N; ++i){
                //            orig.push_back(i);
                s.push(i);
                while(!s.empty() && s.top() == req[k]){
                    s.pop();
                    k++;
                }
            }
            if(s.empty() && k == N)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }

    }
    return 0;
}
