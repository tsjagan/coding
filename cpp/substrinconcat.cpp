#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using Words = vector<string>;

void Swap(Words& words, int i, int j)
{
    string t = words[i];
    words[i]  = words[j];
    words[j] = t;
}

void Permutation(Words& words, int curr, Words &res)
{
    if (curr == words.size()) {
        string r;
        for (auto& w : words) {
            r += w;
        }
        res.push_back(r);
        cout << r << endl;
        return;
    }
    for (int i = curr; i < words.size(); i++) {
        Swap(words, curr, i);
        Permutation(words, curr+1, res);
        Swap(words, curr, i);
    }
}

int main(void)
{
    // convert word2 to word1
    string text = "barfoothebarman";
    Words words = {string("bar"), string("the"), string("foo")};

    Words res;
    Permutation(words, 0, res);

    return 0;
}
