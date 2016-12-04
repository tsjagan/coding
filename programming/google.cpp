convert(“VI”)  -> 6
convert(“VIIII”) > -1
convert(“IX”) -> 9

< 5000
/*
 * IV = 4
 * IX = 9
 * VIII = 8
 * XLIX = 49 (10 + (50 - 20) + 1 + (10 - 2) = 49)
 */
std::map<char, int> mapping = {
‘I’, 1,
‘V’, 5,
‘X’, 10,
‘L’, 50,
‘C’, 100,
‘D’, 500,
‘M’, 1000
};

// consecutive same digits
IIII -> IV  (3 consecutive is valid)
XXI
VV -> X     
VVV -> XV

120 -> CXX
XXC

int convert(const string& r)
{
	int res = 0;
	for ( int i = 0; i < r.size(); i++ ) {
		if ( mapping.find(r[i]) == mapping.end() ) {
			return -1;
		}
		int digit = mapping[r[i]];
		res += digit;
		if ( digit == 1 and ((res+1) % 10)) == 0 ) {
			return -1;
		}
		switch ( digit ) {
			case 5:
			case 10:
				if ( i != 0 and mapping[str[i-1] == 1 ) {
					res -= 2;
				}
				break;
			case 50:
			case 100:
				if ( i != 0 and mapping[str[i-1] == 10 ) {
					res -= 20;
				}
				break;
			case 500:
			case 1000:
				if ( i != 0 and mapping[str[i-1] == 100 ) {
					res -= 200;
				}
				break;
			default
				break;
		}
	}
	return res;
}

struct node {
  int value;
  node* left;
  node* right;
};


/*
Example:
				5
	(max=5)3 			7 (min = 5)
(max=3)2		(min=3, max=5)4     6			9
*/
bool isBst(node* root) {
// start here
	int max = 0xFFFFF;
	int min = (1 << 31);
	return _isBST(root, min, max)
}




bool _isBST(node* node, min, max)
{
	if ( node == nullptr ) {
		return true;
	}
	int curr = node->value;
	if ( curr < min || curr > max ) {
		return false;
} 


bool ret = _isBST(node->left, min, curr);
if ( ret == false ) {
	return false;
}
ret = _isBST(node->left, curr, max);
if ( ret == false ) {
	return false;
}
	return true;
}






