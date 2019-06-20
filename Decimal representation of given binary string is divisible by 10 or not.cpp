/*Approach: First of all we need to know that last digit of
 pow(2, i) = 2, 4, 8, 6 if i % 4 is equal to 1, 2, 3, 0 respectively,
 where i is greater than equal to 1.
 So, in the binary representation we need to know the position of
 digit ‘1’ from the right, so as to know the perfect power of 2 with
 which it is going to be multiplied. This will help us to obtain the last
 digit of the required perfect power’s of 2. We can add these
  digits and then check whether the last digit of the
  sum is 0 or not which implies that the number is divisible
   by 10 or not. Note that if the last digit in the binary
   representation is ‘1’ then it represents an odd number,
   and thus not divisible by 10.*/


// C++ implementation to check whether decimal
// representation of given binary number is
// divisible by 10 or not
#include <bits/stdc++.h>
using namespace std;

// function to check whether decimal representation
// of given binary number is divisible by 10 or not
bool isDivisibleBy10(string bin)
{
	int n = bin.size();

	// if last digit is '1', then
	// number is not divisible by 10
	if (bin[n-1] == '1')
		return false;

	// to accumulate the sum of last digits
	// in perfect powers of 2
	int sum = 0;

	// traverse from the 2nd last up to 1st digit
	// in 'bin'
	for (int i=n-2; i>=0; i--)
	{
		// if digit in '1'
		if (bin[i] == '1')
		{
			// calculate digit's position from
			// the right
			int posFromRight = n - i - 1;

			// according to the digit's position,
			// obtain the last digit of the applicable
			// perfect power of 2
			if (posFromRight % 4 == 1)
				sum = sum + 2;
			else if (posFromRight % 4 == 2)
				sum = sum + 4;
			else if (posFromRight % 4 == 3)
				sum = sum + 8;
			else if (posFromRight % 4 == 0)
				sum = sum + 6;
		}
	}

	// if last digit is 0, then
	// divisible by 10
	if (sum % 10 == 0)
		return true;

	// not divisible by 10
	return false;
}

// Driver program to test above
int main()
{
	string bin = "11000111001110";

	if (isDivisibleBy10(bin))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
