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

void permutations(string& s, int len, std::size_t start = 0)
{
    if ( start == len ) {
        std::cout << string(s, 0, len) << std::endl;
        return;
    }
    for ( std::size_t i = start; i < s.length(); i++ ) {
        std::swap(s[start], s[i]);
        permutations(s, len, start + 1);
        std::swap(s[start], s[i]);
    }
}

int main(void)
{
    string str("");
    cout << "Enter the string :";
    cin >> str;

    for ( int i = 1; i <= str.size(); i++ ) {
        permutations(str, i);
    }
    return 0;
}