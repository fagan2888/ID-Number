#include <iostream>
#include <string>
using namespace std;

string id;
int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char validate[11] = {'1','0','X','9','8','7','6','5','4','3','2'};

bool process(string id)
{
	if(id.length() != 18)
	{
		return false;
	}
	for(int i = 0;i < id.length() - 1;i ++)
	{
		if(id[i] < '0' || id[i] > '9')
		{
			return false;
		}
	}
	if(id[17] < '0' || id[17] > '9')
	{
		if(id[17] != 'x' && id[17] != 'X')
		{
			return false;
		}
	}
	return true;
}


/*
 11010819950730631X
 110108 -- Haidian, Beijing
 19950730 -- Birthdate
 631 -- Sequence Code (male: odd, female: even)
 X -- Validate Code
 */

char getValidateCode(string id)
{
	int sum = 0;
	for(int i = 0;i < 17;i ++)
	{
		sum += (id[i] - '0') * weight[i];
	}
	return validate[sum % 11];
}

int main(int argc, const char * argv[]) {
	while(true)
	{
		cout << ">> Input ID: ";
		cin >> id;
		if(!process(id))
		{
			cout << ">> Invalid input" << endl;
			break;
		}
		char code = getValidateCode(id);
		if(id[17] == code || (id[17] == 'x' && code == 'X'))
		{
			cout << ">> Valid ID " << id << endl;
		}
		else
		{
			cout << ">> Invalid ID " << id << endl;
			cout << ">> The last digit should be " << code << endl;
		}
	}
	return 0;
}