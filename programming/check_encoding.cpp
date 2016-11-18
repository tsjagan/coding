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


using byte = unsigned char;


int getLengthOfEncoding(byte fb)
{
// count number of leading 1’s
	int count = 0;
	byte shifter = (1<<7);
	while ( (fb & shifter) == 1 ) {
		shifter >> 1;
		count++;
	}
	return count;
}


byte getByte(byte* seq, int len, int index)
{
	Assert( seq != nullptr );
	Assert ( index <= len );
	return *(seq + index);
}


bool checkValid(byte b)
{
	byte t = (1 << 7 );
	if ( (b & t) == 0 ) { //check for msb, has to be 1
		return false;
	}
	t =>> 1;
if ( (b & t) == 1 ) { //check for msb-1, has to be 0
return false;
}
return true;
}


bool IsUtf8Decodable(byte* seq, int len) {
	if ( seq == nullptr ) {
		return false;
	}
	int index = 0;
	while ( index < len ) {
	byte fb = getByte(seq, index);
	if ( (fb & (1<<7) == 0 ) ) {
	index++;
	} else {
	int length = getLengthOfEncoding(fb);
	if ( length == 1 ) {
		return false;
	}
		for ( int i = 1; i <= length; i++ ) {
			byte b = getByte(seq, len, index + i);
			bool ret = checkValid(b);
			if ( ret == false ) {
				return false;
			}
		}
		index += (length+1);
	}
	}
	return true;
}


                 0             1             2
byte seq[] = 01111111 11000010 11111111 00000000 11101101 10000111 10110101 01011101


11111111 ….
