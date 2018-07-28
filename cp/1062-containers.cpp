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
    int c = 1;
    while(true) {
        string end("end"), s;
        cin >> s;
        if(s == end)
            return 0;
        vector<stack<char>> cont;
        vector<int> count(26, 0), stackLoc(26, -1), inStack(26, 0);

        for(unsigned int i = 0; i < s.size(); ++i)
            count[s[i] - 'A']++;

        for(int i = 0; i < s.size(); ++i){

            const unsigned char c = s[i];
            unsigned int index = c - 'A';
            if(stackLoc[index] != -1){
                cont[stackLoc[index]].push(c);
                inStack[index]++;
            } else {
                for(unsigned int  j = 0; j < cont.size(); ++j){
                    const char ts = cont.at(j).top();
                    unsigned int tsi = ts-'A';
                    if(inStack[tsi] == count[tsi] && inStack[index] == 0 && c < ts ){
                        cont[j].push(c);
                        stackLoc[index] = j;
                        inStack[index]++;
                        break;
                    }
                }
                if(stackLoc[index] == -1){
                    stack<char> sss;
                    sss.push(c);
                    inStack[index]++;
                    stackLoc[index] = cont.size();
                    cont.push_back(sss);

                }
            }
        }


        cout << "Case " << c << ": " << cont.size() << endl;
        c++;
    }
}
