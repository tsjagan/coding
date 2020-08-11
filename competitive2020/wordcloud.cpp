#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int getWidth(string& word, double p) {
    return ceil((9.0 * word.size() * p) / 16.0);
}

int getHeight(tuple<string, int>& e, int m) {
    double nu = 40.0 * (get<1>(e) - 4.0);
    double de = (m - 4.0);
    return ceil(8 + (nu / de));
}

int buildCloud(vector<string>& wds, vector<int> counts, int width) {
    int maxOccurences = *max_element(counts.begin(), counts.end());

    int cloudSize = 0;
    vector<tuple<string, int>> words;
    for (int i = 0; i < wds.size(); i++) {
        words.push_back(make_tuple(wds[i], counts[i]));
    }

    sort(words.begin(), words.end(), [](const auto& one, const auto& two) {
        return  get<0>(one) < get<0>(two);
    });

    int serial = 1;
    int cur = 0;
    int currMax = 0;
    for (auto& entry : words) {
        if (get<1>(entry) < 5) {
            continue;
        }

        auto p = getHeight(entry, maxOccurences);
        auto w = getWidth(get<0>(entry), p);

        if (cur + w > width) {
            cloudSize += currMax;
            cout << "Adding " << currMax << endl;
            serial++;
            currMax = 0;
            cur = 0;
        }
        currMax = max(currMax, p);
        cur += w + 10;
    }
    cloudSize += currMax;

    return cloudSize;
}


int main(void) {
    vector<string> words = {"apple", "banana", "grape", "kiwi", "orange", "strawberry"};
    vector<int> counts = {10, 5, 20, 18, 12, 10};

    auto res = buildCloud(words, counts, 610);
    cout << "CLOUD " << res << endl;
    return 0;
}