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

using namespace std;

int main()
{
    int c = 1;
    while(true) {
        string end("end"), s;
        cin >> s;
        if(s == end)
            return 0;
        vector<stack<char>> cont;

        for(size_t j = 0; j < s.size(); ++j){
            unsigned int i = 0;
            for(; i < cont.size(); ++i){
                if(s[j] <= cont.at(i).top()  ){
                    cont.at(i).push(s[j]);
                    break;
                }
            }
            if(i == cont.size()){
                stack<char> ss;
                ss.push(s[j]);
                cont.push_back(ss);
            }
        }


        cout << "Case " << c << ": " << cont.size() << endl;
        c++;
    }
}
