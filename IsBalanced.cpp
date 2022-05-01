// IsBalanced.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

string isBalanced(string);

int main()
{
	cout << isBalanced("{(([])[])[]}") << endl;
	cout << isBalanced("{(([])[])[]]}") << endl;
	cout << isBalanced("{(([])[])[]}[]") << endl;

	return EXIT_SUCCESS;
}

string isBalanced(string s) 
{
	stack<char> stapel;

	for (int i = 0; i < s.length(); i++)
	{
		if(s.length() % 2 == 1)
			return "NO";

		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			stapel.push(s[i]);
		}
		else
		{
			if (stapel.empty())
				return "NO";

			if (
				!((stapel.top() == '(' && s[i] == ')') ||
					(stapel.top() == '{' && s[i] == '}') ||
					(stapel.top() == '[' && s[i] == ']'))
				)
				return "NO";

			stapel.pop();
		}
	}

	if (stapel.empty())
		return "YES";

	return "NO";
}

