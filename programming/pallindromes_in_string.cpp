#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;
using Cache = std::map<std::pair<int, int>, int>;
int _longest_pallindrome(string& str, int start, int end, int32_t& max);
/*
example: b d a b c c b a c a b d a d a c
*/

int32_t longest_pallindrome(string& str)
{
    static int32_t max = 0;
    _longest_pallindrome(str, 0, str.size()-1, max);
    return max;
}

int _longest_pallindrome(string& str, int start, int end, int32_t& max)
{
    static Cache cache;
    if ( start == end ) {
        return 1;
    }
    auto entry = std::make_pair(start, end);
    if ( cache.find(entry) != cache.end() ) {
        return cache[entry];
    }
    for ( int i = start; i <= end; i++ ) {
        for ( int j = i+1; j <= end; j++ ) {
            if ( str[i] == str[j] ) {
                auto subentry = std::make_pair(i, j);
                cache[subentry] = 0;
                int ret = _longest_pallindrome(str, i+1, j-1, max);
                int substr_len = j - i - 1;
                if ( ret == substr_len ) {
                    cache[subentry] = ret + 2;
                    if ( max < (ret+2) ) {
                        cout << "Pallindrome from " << i << " to " << j << endl;
                        max = ret + 2;
                    }
                }
            }
        }
    }
    return cache[entry];
}

int main(void)
{
    string str;
    cout << "Entr string : ";
    cin >> str; 
    cout << "Longest pallindrome = " << longest_pallindrome(str) << endl;
    return 0;
}
