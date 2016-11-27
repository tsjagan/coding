#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

// str = abcdcdkalcdfg
// pattern = cd
// rep - vbn

bool substring(string& str, string& pattern, int& off)
{
    int o = off, s = 0;
    while ( str[o] == pattern[s] ) {
        o++;
        s++;
        if ( o >= str.size() or s >= pattern.size() ) {
            break;
        }
    }
    if ( s == pattern.size() ) {
        off += s - 1;
        return true;
    }
    return false;
}

string substiture(string& str, string& pattern, string& rep)
{
    string res("");
    for ( int i = 0; i < str.size(); i++ ) {
        if ( substring(str, pattern, i) == true ) {
            res += rep;
        } else {
            res += str[i];
        }
    }
    return res;
}

int main(void)
{
    string str("");
    cout << "Enter the string :";
    cin >> str;

    string pattern("");
    cout << "Enter the pattern :";
    cin >> pattern;

    string rep("");
    cout << "Enter the replace :";
    cin >> rep;

    string res = substiture(str, pattern, rep);
    cout << "Result = " << res << endl;
    return 0;
}