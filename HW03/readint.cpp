#include "readint.h"
#include <stdexcept>
using namespace std;

int read_int(const string &prompt, int low, int high)
{
	cin.exceptions(ios_base::failbit);
	int num = 0;
	if (high <= low + 1)
	{
		throw invalid_argument("Low is too big");
	}
	while (true)
	{
		try
		{
			cout << prompt;
			cin >> num;
			try
			{
				if (num < high && num > low)
					return num;
			}
			catch (range_error&)
			{
				cin.clear();
				cin.ignore();
			}
		}
		catch (ios_base::failure& ex)
		{
			cout << "Bad Numeric String -- try again" << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}
}