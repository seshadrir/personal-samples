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
<<<<<<< HEAD
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
=======

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
>>>>>>> 21e18cc8df35e135a32afc2e7ac649a4f40995cf
        }


        cout << "Case " << c << ": " << cont.size() << endl;
        c++;
    }
}
