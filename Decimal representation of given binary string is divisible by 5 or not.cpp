/*Approach: The following steps are:

Convert the binary number to base 4.
Numbers in base 4 contains only 0, 1, 2, 3 as their digits.
5 in base 4 is equivalent to 11.
Now apply the rule of divisibility by 11 where you add all the digits at odd places and add all the digits at even places and then subtract one from the other. If the result is divisible by 11(which remember is 5), then the binary number is divisible by 5.
How to covert binary number to base 4 representation?

Check whether the length of binary string is even or odd.
If odd, the add ‘0’ in the beginning of the string.
Now, traverse the string from left to right.
One by extract substrings of size 2 and add their equivalent
 decimal to the resultant string.*/


 // C++ implementation to check whether decimal representation
// of given binary number is divisible by 5 or not
#include <bits/stdc++.h>

using namespace std;

// function to return equivalent base 4 number
// of the given binary number
int equivalentBase4(string bin)
{
	if (bin.compare("00") == 0)
		return 0;
	if (bin.compare("01") == 0)
		return 1;
	if (bin.compare("10") == 0)
		return 2;
	return 3;
}

// function to check whether the given binary
// number is divisible by 5 or not
string isDivisibleBy5(string bin)
{
	int l = bin.size();

	if (l % 2 != 0)
	// add '0' in the beginning to make
	// length an even number
		bin = '0' + bin;

	// to store sum of digits at odd and
	// even places respectively
	int odd_sum, even_sum = 0;

	// variable check for odd place and
	// even place digit
	int isOddDigit = 1;
	for (int i = 0; i<bin.size(); i+= 2)
	{
		// if digit of base 4 is at odd place, then
		// add it to odd_sum
		if (isOddDigit)
			odd_sum += equivalentBase4(bin.substr(i, 2));
		// else digit of base 4 is at even place,
		// add it to even_sum
		else
			even_sum += equivalentBase4(bin.substr(i, 2));

		isOddDigit ^= 1;
	}

	// if this diff is divisible by 11(which is 5 in decimal)
	// then, the binary number is divisible by 5
	if (abs(odd_sum - even_sum) % 5 == 0)
		return "Yes";

	// else not divisible by 5
	return "No";

}

// Driver program to test above
int main()
{
	string bin = "10000101001";
	cout << isDivisibleBy5(bin);
	return 0;
}


