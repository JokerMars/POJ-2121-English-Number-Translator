#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<algorithm>

using namespace std;

string str2num[] = 
{ "zero", "one", "two", "three",
"four", "five", "six", "seven",
"eight","nine", "ten", "eleven", "twelve",
"thirteen", "fourteen", "fifteen", "sixteen", 
"seventeen", "eighteen", "nineteen", "twenty",
"thirty", "forty", "fifty", "sixty", "seventy", 
"eighty", "ninety","hundred", "thousand", "million" };

int num2str[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000 };

int main()
{
	map<string, int>mapTable;
	for (int i = 0;i < 31;i++)
	{
		mapTable.insert(make_pair(str2num[i], num2str[i]));
	}

	string str, line;
	while (getline(cin, line))
	{
		if (line.length() == 0)
			break;

		istringstream input(line);
		bool isNeg = false;
		long long ans = 0;
		long long pre = 0;

		while (input >> str)
		{
			if (str == "negative")
			{
				isNeg = true;
			}
			else if (str == "hundred")
			{
				pre *= 100;
			}
			else if (str == "thousand")
			{
				pre *= 1000;
				ans += pre;
				pre = 0;
			}
			else if (str == "million")
			{
				pre *= 1000000;
				ans += pre;
				pre = 0;
			}
			else
			{
				pre += mapTable[str];
			}

		}

		ans += pre;
		if (isNeg)
		{
			ans *= -1;
		}

		cout << ans << endl;

	}

	return 0;
}