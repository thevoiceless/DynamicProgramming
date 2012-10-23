#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string reverseString(string input);
string trace(int**& results, string input, int row, int col);

int main() 
{
	string input;
	string reverseInput;
	string longestSubsequence;
	int stringLen = 0;
	int** results;

	//A C G T G T C A A A A T C G
	//C T A A A A T C

	cout << "Please enter a string: " << flush;
	cin >> input;

	stringLen = input.length();
	
	reverseInput = reverseString(input);

	results = new int* [stringLen + 1];

	for (int i=0; i<=stringLen; i++)
	{
		results[i] = new int [stringLen + 1];
	}

	for (int i=0; i<=stringLen; i++)
	{
		results[i][0] = 0;
		results[0][i] = 0;
	}

	for (int i=1; i<=stringLen; i++)
	{
		for (int j=1; j<=stringLen; j++)
		{
			if (input[i-1] == reverseInput[j-1])
			{
				results[i][j] = results[i-1][j-1] + 1;
			}
			else
			{
				results[i][j] = max(results[i][j-1], results[i-1][j]);
			}
		}
	}

	longestSubsequence = trace(results, input, stringLen, stringLen);

	for (int i=0; i<=stringLen; i++)
	{
		delete [] results[i];
	}

	delete [] results;

	cout << "Original String: " << input << endl;
	cout << "Longest Subsequence: " << longestSubsequence << endl;

	system("pause");
	return 0;
}

string reverseString(string input)
{
	string temp;

	for (int i=0; i<input.length(); i++)
	{
		temp += input[input.length() - 1 - i];
	}

	return temp;
}

string trace(int**& results, string input, int row, int col)
{
	string temp = "";

	if ((row == 0) || (col == 0))
	{
		return temp;
	}

	if (results[row][col] == results[row-1][col])
	{
		temp = trace(results, input, row-1, col);
	}
	else if (results[row][col] == results[row][col-1])
	{
		temp = trace(results, input, row, col-1);
	}
	else
	{
		temp = trace(results, input, row-1, col-1) + input[row-1];
	}

	return temp;
}