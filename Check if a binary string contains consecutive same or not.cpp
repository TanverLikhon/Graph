/*Efficient Approach : In the binary string, check for last k bits.
 If the all the last k bits are 0, then the binary number is evenly
  divisible by 2k else it is not evenly divisible. Time complexity
  using this approach is O(k)*/
  // C++ implementation to check whether
// given binary number is evenly
// divisible by 2^k or not
#include <bits/stdc++.h>
using namespace std;
// function to check whether
// given binary number is
// evenly divisible by 2^k or not
bool isDivisible(char str[], int k)
{
	int n = strlen(str);
	int c = 0;

	// count of number of 0 from last
	for (int i = 0; i < k; i++)
		if (str[n - i - 1] == '0')
			c++;

	// if count = k, number is evenly
	// divisible, so returns true else
	// false
	return (c == k);
}

int main()
{
	// first example
	char str1[] = "10101100";
	int k = 2;
	if (isDivisible(str1, k))
		cout << "Yes" << endl;
	else
		cout << "No"<< "\n";

	// Second example
	char str2[] = "111010100";
	k = 2;
	if (isDivisible(str2, k))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
