#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

using Hash = std::map<char, char>;

bool isIsomorphic(string s, string t) {
    if ( s.size() != t.size() ) {
        return false;
    }
    Hash mapfrom, mapto;
    for ( auto& c : s ) {
        mapfrom[c] = (char)(0);
    }
    for ( auto& c : t ) {
        mapto[c] = (char)(0);
    }
    for ( int i = 0; i < s.size(); i++ ) {
        if ( mapfrom[s[i]] == 0 ) {
            if ( mapto[t[i]] != 0 and mapto[t[i]] != s[i]) {
                cout << "To Mismatch at index " << i << endl;
                return false;
            }
            mapfrom[s[i]] = t[i];
            mapto[t[i]] = s[i];
            cout << "Mapfrom of " << s[i] << " = " << mapfrom[s[i]] << endl;
            cout << "Mapto of " << t[i] << " = " << mapto[t[i]] << endl;
            s[i] = t[i];
        } else if ( mapfrom[s[i]] != t[i] ) {
            cout << "From Mismatch at index " << i << endl;
            return false;
        } else {
            s[i] = t[i];
        }
    }
    return (s == t);
}

int main(void)
{
    string s("");
    string t("");

    cout << "Enter string 1 : ";
    cin >> s;
    cout << "Enter string 2 : ";
    cin >> t;

    cout << isIsomorphic(s, t) << endl;
    return 0;
}
