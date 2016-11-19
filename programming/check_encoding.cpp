#include <stdlib.h>
#include <iostream>

using namespace std;

/*
Determine whether a byte sequence is UTF-8 decodable


UTF-8 is a variable-length encoding of characters. Characters may be encoded by 1-byte to 8-byte runes. If the most significant bit of the first byte in the rune is 0, the rune is 1 byte long. Otherwise, its length is the number of leading 1's in the first byte. If a rune is more than one byte long, all subsequent bytes in this rune start with 10. Here's a chart:


0XXXXXXX = this is the entire rune.
10XXXXXX = this is a continuation of the rune from the previous byte.
110XXXXX = this is the start of a 2-byte rune.
1110XXXX = this is the start of a 3-byte rune.
11110XXX = this is the start of a 4-byte rune.
111110XX = this is the start of a 5-byte rune.
1111110X = this is the start of a 6-byte rune.


Example:
1 byte encoding - 0-------
3 byte encoding - 11000000 10XXXXXX 10XXXXXX
4 byte encoding - 11110000 10XXXXXX 10XXXXXX 10XXXXXX

// example: byte seq[] = 01111111 11000010 11111111 00000000 11101101 10000111 10110101 01011101
*/

using byte = unsigned char;

int getLengthOfEncoding(byte fb)
{
	int count = 0;
	byte shifter = (1<<7);
	bool zero = false;
	for ( int i = 0; i < 8; i++ ) {
		if ( fb & shifter ) {
			count++;
		} else {
			zero = true;
			break;
		}
		shifter = shifter >> 1;
	}
	if ( zero == false ) {
		return -1;
	}
	if ( count <= 1 ) {
		return -1;
	}
	return count;
}

byte getByte(byte* seq, int len, int index)
{
	//cout << "Getting byte at index " << index << endl;
	return *(seq + index);
}

bool checkValid(byte b)
{
	byte t = (1 << 7);
	//cout << "(b & (1<<7)) = " << (int)(b&t) << endl; 
	if ( (b & t) == 0 ) { //check for msb, has to be 1
		return false;
	}
	t = (1 << 6);
	//cout << "(b & (1<<6)) = " << (int)(b&t) << endl; 
	if ( (b & t) == 64 ) { //check for msb-1, has to be 0
		return false;
	}
	return true;
}

bool IsUtf8Decodable(byte* seq, int len)
{
	if ( seq == nullptr ) {
		return false;
	}
	int index = 0;
	while ( index < len ) {
		//cout << "Processing index " << index << endl;
		byte fb = getByte(seq, len, index);
		if ( (fb & (1<<7)) == 0 ) {
			index++;
		} else {
			int length = getLengthOfEncoding(fb);
			if ( length == -1 ) {
				cout << "Invalid length in large char at index " << index << endl; 
				return false;
			}
			cout << "Character of length " << length << " at index " << index << endl;
			for ( int i = 1; i <= length; i++ ) {
				byte b = getByte(seq, len, index + i);
				bool ret = checkValid(b);
				if ( ret == false ) {
					cout << "Invalid subsequent byte at index " << index+i << endl; 
					return false;
				}
			}
			index += (length+1);
		}
	}
	return true;
}


int main(void)
{
	// example: byte seq[] = 01111111 11000010 11111111 00000000 11101101 10000111 10110101 01011101
	// byte seq[8] = {0x7F,0xC2,0xFF,0x00,0xED,0x87,0xB5,0x5D};
	byte seq[8] = {0b01111111,0b11000010,0b10111111,0b10000000,0b11101111,0b10000111,0b10110101,0b10011101};
	cout << IsUtf8Decodable(seq, 8) << endl;
	return 0;
}