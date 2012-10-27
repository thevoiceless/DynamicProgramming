#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void printLongestSubsequenceArray(int**& results, string input);
string trace(int**& results, string input, int row, int col);
void calcResultsRow(int**& result, int row, string input);
void calcResultsCol(int**& result, int row, int col, string input);

int main() 
{
	string input;
	string longestSubsequence;
	int** results;

	//A C G T G T C A A A A T C G
	//C T A A A A T C

	cout << "Please enter a string: " << flush;
	cin >> input;

	results = new int* [input.length() + 1];

	for (int i=0; i<=input.length(); i++)
	{
		results[i] = new int [input.length() + 1];
	}

	calcResultsRow(results, input.length(), input);
	//printLongestSubsequenceArray(results, input); //Debug output for the results array
	longestSubsequence = trace(results, input, input.length(), input.length());

	for (int i=0; i<=input.length(); i++)
	{
		delete [] results[i];
	}

	delete [] results;

	cout << "Original String: " << input << endl;
	cout << "Longest Subsequence: " << longestSubsequence << endl;

	system("pause");
	return 0;
}

void printLongestSubsequenceArray(int**& results, string input)
{
	//This is debug output to look at our results array
	cout << "  0 ";
	for (int i=1; i<=input.length(); i++)
	{
		cout << input[input.length() - i] << " ";
	}
	cout << endl;

	for (int i=0; i<=input.length(); i++)
	{
		if (i == 0)
		{
			cout << "0 ";
		}
		else
		{
			cout << input[i-1] << " ";
		}

		for (int j=0; j<=input.length(); j++)
		{
			cout << results[i][j] << " ";
		}
		cout << endl;
	}
}

void calcResultsRow(int**& results, int row, string input)
{
	if (row > 0)
	{
		calcResultsRow(results, row - 1, input);
	}

	calcResultsCol(results, row, input.length(), input);

	return;
}

void calcResultsCol(int**& results, int row, int col, string input)
{
	if (col > 0)
	{
		calcResultsCol(results, row, col-1, input);
	}

	if (row == 0 || col == 0)
	{
		results[row][col] = 0;
	}
	else
	{
		if (input[row-1] == input[input.length()-col])
		{
			results[row][col] = results[row-1][col-1] + 1;
		}
		else
		{
			results[row][col] = max(results[row-1][col], results[row][col-1]);
		}
	}

	return;
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