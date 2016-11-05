#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <cstring>

using namespace std;


/*
 * Floating point numbers are represented using a format that has three parts
 * sign bit, exponent (signifies the range)  and a mantissa (signifies precision_
 * Single precision - generally 23-bit mantissa (8 exponent bits and 1 sign bit)
 * Double precision - generally 52-bit mantissa (11 exponent bits and 1 sign bit)
 * The more number of bits in mantissa, higher precision can be achieved
 *
 * So, if the fractional portion needs more bits that can be stored in the mantissa
 * then we lose precision
 * Also, some numbers cannot be converted exactly to binary floating point.
 * For eg: 0.2 or 0.1 because the conversion is recurring
 */
void print_bits(float a)
{
    uint32_t shifter = 1;
    uint32_t raw = 0;
    memcpy(&raw, &a, sizeof(float));

    cout << "Mantissa is : " << endl;
    for ( uint16_t i = 0; i < 23; i++ ) {
        uint16_t bit = (raw & shifter) == 0 ? 0 : 1;
        cout << bit << " ";
        shifter <<= 1;
    }
    cout << endl;
    cout << "Exponent is : ";
    for ( uint16_t i = 0; i < 8; i++ ) {
        uint16_t bit = (raw & shifter) == 0 ? 0 : 1;
        cout << bit << " ";
        shifter <<= 1;
    }
    cout << endl;
    cout << "sign bit is : ";
    uint16_t bit = (raw & shifter) == 0 ? 0 : 1;
    cout << bit << " " << endl;
    shifter <<= 1;
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
    float a = 1.02;
    print_bits(a);

    a = 0.0002;
    print_bits(a);
    return 0;
}
