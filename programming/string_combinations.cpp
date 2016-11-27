#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

// abc
// Length 1: a, b, c
// Length 2: ab, ac
//           ba, bc
//           ca, cb
// Length 2: abc, acb
//           bac, bca
//           cab, cba
//

void swap(string& str, int l, int r)
{
    char t = str[r];
    str[r] = str[l];
    str[l] = t;
}

void combinations(string& s, int len, string& res, std::size_t start = 0)
{
    if ( res.size() == len ) {
        cout << "Selection = " << res << endl;
        return;
    }
    for ( int i = start; i < s.size(); i++ ) {
        res.push_back(s[i]);
        combinations(s, len, res, i+1);
        res.pop_back();
    }
}

int main(void)
{
    string str("");
    cout << "Enter the string :";
    cin >> str;

    for ( int i = 1; i <= str.size(); i++ ) {
        // select i items from a string of length str.size()
        string res("");
        combinations(str, i, res);
    }
    return 0;
}