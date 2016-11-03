#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <cstring>

using namespace std;

void print_bits(double a)
{
    uint64_t shifter = 1;
    uint64_t raw = 0;
    memcpy(&raw, &a, sizeof(double));
    cout << " Binary representation of " << a << " is : " << endl;
    for ( uint16_t i = 0; i < 64; i++ ) {
        uint16_t bit = (raw & shifter) == 0 ? 0 : 1;
        cout << bit << " ";
        shifter <<= 1;
    }
    cout << endl;
}

void endianness()
{
    uint32_t a = 1; //0001
    char *c = reinterpret_cast<char*>(&a);
    if ( *c == 1 ) {
        cout << "Little endian machine, LSB first " << endl;
    } else {
        cout << "Big endian machine, MSB first " << endl;
    }
}

int main(void)
{
    endianness();
    double a = 0.2;
    print_bits(a);
    a = 1 / 5.0;
    print_bits(a);
    return 0;
}
