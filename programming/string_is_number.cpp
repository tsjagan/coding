#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_number(string& str)
{
    int s = static_cast<int>('0');
    int e = static_cast<int>('9');
    for ( int i = 0; i < str.size(); i++ ) {
        if ( str[i] < s || str[i] > e ) {
            cout << str[i] << " not a digit" << endl;
            return false;
        }
    }
    cout << str << " is a number " << endl;
    return true;
}

int main(void)
{
    string str;
    cout << "Enter string to be checked : ";
    cin >> str;

    is_number(str);
    return 0;
}