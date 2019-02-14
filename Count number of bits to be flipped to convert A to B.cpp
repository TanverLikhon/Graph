// Count number of bits to be flipped
// to convert A into B
/*Input : a = 10, b = 20
Output : 4
Binary representation of a is 00001010
Binary representation of b is 00010100
We need to flip highlighted four bits in a
to make it b.

Input : a = 7, b = 10
Output : 3
Binary representation of a is 00000111
Binary representation of b is 00001010
We need to flip highlighted three bits in a
to make it b.*/

#include <iostream>
using namespace std;
int countSetBits(int n)
{
	int count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}
	return count;
}
// Function that return count of
// flipped number
int FlippedCount(int a, int b)
{
	// Return count of set bits in
	// a XOR b
	return countSetBits(a^b);
}

// Driver code
int main()
{
	int a = 10;
	int b = 20;
	cout << FlippedCount(a, b)<<endl;
	return 0;
}

