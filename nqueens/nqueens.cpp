#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;




class FOUR_QUEENS
{
public:

	void printVector(const vector<int>& vecSolutions)
	{
		for (size_t i = 0; i < vecSolutions.size(); i++)
		{
			cout << vecSolutions[i] << " ";
		}
		cout << endl;
	}

	bool isValid(const vector<int>& vecSolutions)
	{
		
		attemps++;

		int value = vecSolutions.back();

		for (size_t i = 0; i < vecSolutions.size() - 1; ++i)
		{
			if (vecSolutions[i] == value)
			{
				return false;
			}
		}

	
		int offset = 1;
		for (int i = vecSolutions.size() - 2; i >= 0; --i)
		{
			if (value == vecSolutions[i] + offset)
			{
				return false;
			}
			
			if (value == vecSolutions[i] - offset)
			{
				return false;
			}
			++offset;
		}

		return true;
	}

	void nQueens(vector<int>& vecSolutions, int leftToPlace, int totalToPlace)
	{
		if (!leftToPlace)
		{
			solutions++;
			printVector(vecSolutions);
			return;
		}

		vecSolutions.push_back(0);
		for (int i = 0; i < totalToPlace; ++i)
		{
			vecSolutions.back() = i;
			if (isValid(vecSolutions))
			{
				nQueens(vecSolutions, leftToPlace - 1, totalToPlace);
			}
		}
		vecSolutions.pop_back();
	}

	int getAttempts()
	{
		return attemps;
	}

	int getSolutions()
	{
		return solutions;
	}

private:
	int attemps = 0;
	int solutions = 0;
};


int main()
{
	const int BOARD_SIZE = 4;
	FOUR_QUEENS queen;
	cout << BOARD_SIZE<<"x"<< BOARD_SIZE<<" board\n";
	vector<int> v;
	queen.nQueens(v, BOARD_SIZE,BOARD_SIZE);

	cout << "Checks: " << queen.getAttempts() << endl;
	cout << "Solutions: " << queen.getSolutions() << endl;
}
