#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool _RegexMatch(string& w1, string& w2)
{
}

bool RegexMatch(string& w1, string& w2)
{
    return _RegexMatch(w1, w2);
}

bool _RegexMatchNoKleene(string& w1, string& w2, int i)
{
    if (i > w1.size()) {
        return true;
    }
    if (w1[i] == w2[i] or w2[i] == '.') {
        return true && _RegexMatchNoKleene(w1, w2, i+1);
    }
    return false;
}

bool RegexMatchNoKleene(string& word1, string& word2)
{
    if (w1.size() != w2.size()) {
        return false;
    }
    return _RegexMatchNoKleene(word1, word2, 0);
}

int main(void)
{
    // convert word2 to word1
    string word1 = "aab";
    string word2 = "a.b";

    bool res = RegexMatchNoKleene(word1, word2);
    cout << "Result = " << res << endl;
    return 0;
}
