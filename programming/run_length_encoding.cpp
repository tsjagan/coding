#include <stdlib.h>
#include <iostream>

using namespace std;

// rle(aabccccddddef) = a2b1c4d4e1f2
string rle(string& str)
{
    if ( str.size() == 0 ) {
        return string("");
    }
    string res("");
    uint32_t count = 1;
    char c = str[0];
    for ( int i = 1; i < str.size(); i++ ) {
        if ( str[i] == c ) {
            count++;
        } else {
            res += c;
            if ( count != 1 ) {
                res += to_string(count);
            }
            count = 1;
            c = str[i];
        }
    }
    res += c;
    if ( count != 1 ) {
        res += to_string(count);
    }
    return res;
}

int main(void)
{
    string str("");
    cout << "Enter the string : ";
    cin >> str;
    cout << rle(str) << endl;
}
