#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

std::string maxlong("");

string next(string& str, int& off)
{
    string res("");
    while ( off < str.size() and str[off] != '\\' and str[off+1] != 'n') {
        res += str[off];
        off++;
    }
    return res;
}

int get_depth(string& str, int& off)
{
    int depth = 0;
    while ( off < str.size() and str[off] == '\\' and str[off+1] == 't' ) {
        off += 2;
        depth++;
    }
    return depth;
}

void get_longes_path(string& str, int& off, int depth, string path)
{
    // cout << "Recursed " << endl;
    while ( true ) {
        // cout << "get_longes_path called with " << off << " and " << depth << endl;
        if ( off >= str.size() ) {
            break;
        }
        string s = next(str, off);

        off += 2;
        int d = get_depth(str, off);
        // cout << d << " and curr is " << depth << endl;
        cout << "depth " << depth << " - " << path << "-" << s << endl;
        if ( maxlong.size() < string(path+s).size() ) {
            maxlong = (path+s);
        }
        
        if ( d > depth ) {
            get_longes_path(str, off, d, (path+s));
        } else if ( d < depth ) {
            cout << "recurse out " << endl;
            break;
        }
    }
}

int main(void)
{
    string str("");
    cout << "Enter string :";
    cin >> str;
   
    string path("");
    int off = 0;
    get_longes_path(str, off, 0, path);

    cout << maxlong << endl;
    return 0;
}
