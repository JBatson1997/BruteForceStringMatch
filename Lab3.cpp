/*Johann batson
400000715
Algorithms lab3.2 exercise 1*/
#include <iostream>
#include <string>

using namespace std;

int BruteForceStringMatch(string Text, string Pattern)
{



	int counter = 0;
	for (size_t i = 0; i < Text.length() - Pattern.length() + 1; i++)
	{
		size_t j = 0;
		
		while (j < Pattern.length() && Pattern[j] == Text[i + j])
		{
			j = j + 1;
			counter++;
		}
		
		if (j == Pattern.length())
		{
			cout << "The number of times the comparison operation is executed is:" << counter << endl;
			return i;
		}

	}
	cout << "The number of times the comparison operation is executed is:" << counter << endl;
	return -1;
}

int main()
{
	string T = "qiseightqwaszxcdfret";
	string P = "xcdfr";
	cout << "The pattern is" << BruteForceStringMatch(T, P) << endl;

	 T = "qiseightqwaszxcdfret";
	 P = "qis";
	cout << "The pattern is" << BruteForceStringMatch(T, P) << endl;

	T = "aaaaaaaaaaaaaaaaaaab";
	P = "aaaab";
	cout << "The pattern is" << BruteForceStringMatch(T, P) << endl;

	T = "aaaaaaaaaaaaaaaaaaab";
	P = "aab";
	cout << "The pattern is" << BruteForceStringMatch(T, P) << endl;
	system("pause");
	return 0;

}