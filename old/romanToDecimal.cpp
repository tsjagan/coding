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

int main(void)
{
    string roman = "MMMMCMXCIX";
    int total = 0, running = 0;
    int prev = mapping[roman[0]];;
    for (auto& c : roman) {
        if (mapping.find(c) == mapping.end()) {
            cout << "Invalid character : " << c << endl;
            break;
        }
        if (mapping[c] < prev) {
            total += running;
            running = mapping[c];
            cout << "Fall at " << c << " and " << total << endl;
        } else if (mapping[c] > prev) {
            total += (mapping[c] - running);
            running = 0;
            cout << "Pickup at " << c << " and " << total << endl;
        } else {
            running += mapping[c];
        }
        prev = mapping[c];
    }
    cout << "Number = " << total << endl;
	return 0;
}
