// CPP for divisibilty of number by 999
#include<bits/stdc++.h>
using namespace std;

// function to check divisibility
bool isDivisible999(string num)
{
	int n = num.length();
	if (n == 0 && num[0] == '0')
	return true;

	// Append required 0s at the beginning.
	if (n % 3 == 1)
	num = "00" + num;
	if (n % 3 == 2)
	num = "0" + num;

	// add digits in group of three in gSum
	int gSum = 0;
	for (int i = 0; i<n; i++)
	{
		// group saves 3-digit group
		int group = 0;
		group += (num[i++] - '0') * 100;
		group += (num[i++] - '0') * 10;
		group += num[i] - '0';
		gSum += group;
	}

	// calculate result till 3 digit sum
	if (gSum > 1000)
	{
		num = to_string(gSum);
		n = num.length();
		gSum = isDivisible999(num);
	}
	return (gSum == 999);
}

// driver program
int main()
{
	string num = "1998";
	int n = num.length();
	if (isDivisible999(num))
		cout << "Divisible";
	else
		cout << "Not divisible";
	return 0;
}

