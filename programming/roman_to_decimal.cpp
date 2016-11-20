#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

static std::map<char, int> mapping = 
{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int roman_to_decimal(string& str)
{
    int res = 0;
    for ( int i = 0; i < str.size(); i++ ) {
        if ( mapping.find(str[i]) == mapping.end() ) {
            throw runtime_error("Invalid character");
        }
        int rdigit = mapping[str[i]];
        res += rdigit;
        switch ( rdigit ) {
            case 5:
            case 10:
                if ( i != 0 and mapping[str[i-1]] == 1 ) {
                    res -= 2;
                }
                break;
            case 50:
            case 100:
                if ( i != 0 and mapping[str[i-1]] == 10 ) {
                    res -= 20;
                }
                break;
            case 500:
            case 1000:
                if ( i != 0 and mapping[str[i-1]] == 100 ) {
                    res -= 200;
                }
                break;
        }
    }
    return res;
}

int main(void)
{
    string str;
    cout << "Enter roman numeral string : ";
    cin >> str;

    cout << "Roman to decimal = " << roman_to_decimal(str) << endl;
}