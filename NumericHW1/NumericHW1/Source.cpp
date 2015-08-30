#include <iostream>

using namespace std;

int i = 0;
int dcount = 0;
char ans[1000];
char input[100];
float dcheck[10];
void cbten2two(int n)
{
	if (n >= 2)
	{
		cbten2two(n / 2);
		ans[i] = (n % 2) + '0';
		i++;
	}
	else
	{
		ans[i] = (n % 2) + '0';
		i++;
	}
}
void cbdten2two(float n)
{
	n = roundf(n * 100000) / 100000.0;
	bool sc = false;
	for (int j = 0; j <= dcount; j++)
	{
		if (n == dcheck[j])
			sc = true;
	}
	if (sc == false)
	{
		if (n * 2 < 1)
		{
			dcheck[dcount] = n;
			dcount++;
			ans[i] = '0';
			i++;
			cbdten2two(n * 2);
		}
		else
		{
			dcheck[dcount] = n;
			dcount++;
			ans[i] = '1';
			i++;
			cbdten2two((n * 2) - 1);
		}
	}

}
int main()
{
	cin >> input;
	cbten2two(atoi(input));
	if (((atof(input)) - atoi(input)) != 0)
	{
		ans[i] = '.';
		i++;
		cbdten2two((atof(input)) - atoi(input));
	}
	cout << ans << endl;
	system("pause");
	return 0;
}
