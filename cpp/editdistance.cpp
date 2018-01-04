#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int _Distance(string& res,
              int i1, int i2, int dis,
              string& word1, string& word2)
{
    if (i1 >= word1.size() and i2 < word2.size()) {
        res += (string(" ; delete ") + string(word2, i2, word2.size()));
        return dis + (word2.size() - i2);
    }
    if (i2 >= word2.size() and i1 < word1.size()) {
        res += (string(" ; insert ") + string(word1, i1, word1.size()));
        return dis + (word1.size() - i1);
    }
    if (i1 >= word1.size() or i2 >= word2.size()) {
        return dis;
    }

    int sub = 0;
    if (word1[i1] != word2[i2]) {
        sub = 1;
    }
    
    string subres, insres, delres;
    sub = _Distance(subres, i1+1, i2+1, dis+sub, word1, word2);
    int insert = _Distance(insres, i1+1, i2, dis+1, word1, word2);
    int del = _Distance(delres, i1, i2+1, dis+1, word1, word2);

    dis = min(min(sub, insert), del);
    string tres;
    if (dis == sub) {
        if (word1[i1] != word2[i2]) {
        tres = (string("; substitute ") + word2[i2] + string(" -> ") + word1[i1]); 
        res += tres;
        }
        res += subres;
    } else if (dis == insert) {
        res = (string("; insert ") + word1[i1]) + insres;
    } else if (dis == del) {
        res = (string("; delete ") + word2[i2]) + delres;
    }
    
    return dis;
}

int NaiveDistance(string& word1, string word2)
{
    string res("");
    int d = _Distance(res, 0, 0, 0, word1, word2);
    cout << res << endl;
    return d;
}

int DPDistance(string& word1, string word2)
{
    // rows for word1 letters
    // columns for word2 letters
    int dis[word1.size()+1][word2.size()+1];

    // cost of converting null to all prefixes of word1
    for (int i = 0; i <= word1.size(); i++) {
        dis[i][0] = i;
    }

    // cost of converting null to all prefixes of word2
    for (int i = 0; i <= word2.size(); i++) {
        dis[0][i] = i;
    }

    // find cost of converting wor2 -> word1
    // dis[i][j] = cost of converting word1[0...i-1] to word2[0...j-1]
    for (int i = 1; i <= word1.size(); i++) {
        for (int j = 1; j <= word2.size(); j++) {
            int ins = 1 + dis[i][j-1];
            int del = 1 + dis[i-1][j];
            int subs = 1 + dis[i-1][j-1];
            if (word1[i-1] == word2[j-1]) {
                subs -= 1;
            }
            dis[i][j] = min(subs, min(ins, del));
        }
    }

    for (int i = 0; i <= word1.size(); i++) {
        for (int j = 0; j <= word2.size(); j++) {
            cout << " " << dis[i][j];
        }
        cout << endl;
    }
    return dis[word1.size()][word2.size()];
}

int main(void)
{
    // convert word2 to word1
    string word1 = "abcdac";
    string word2 = "bbcdafcjjj";

    int d = DPDistance(word1, word2);
    cout << "Distance = " << d << endl;
    return 0;
}
