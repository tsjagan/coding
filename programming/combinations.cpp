#include <iostream>
#include <string>
#include <vector>

using namespace std;


// abcd
// Length = 1
// a
// b
// c
// d
// Length = 2
// ab
// ac
// ad
// bc
// bc
// cd
void _combinations(string& str, string& res, int off, int length)
{
    if ( res.size() == length ) {
        cout << "Combination = " << res << endl;
        return;
    }
    for ( int i = off; i < str.size(); i++ ) {
        res.push_back(str[off]);
        _combinations(str, res, off+1, length);
        res.pop_back();
        off++;
    }
}

void combinations(string& str)
{
    for ( int i = 1; i <= str.size(); i++ ) {
        string res("");
        _combinations(str, res, 0, i);
    }
}


int main(void)
{
    string str("");
    cout << "Enter the string : ";
    cin >> str;
    combinations(str);
    return 0;
}
