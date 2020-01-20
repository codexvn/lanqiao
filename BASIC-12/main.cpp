#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	while (N--)
	{

		string get, tmp;
		cin >> tmp;
		for (string::iterator i = tmp.begin(); i != tmp.end(); i++)
			switch (*i)
			{
			case '0':
				get.append("0000");
				break;
			case '1':
				get.append("0001");
				break;
			case '2':
				get.append("0010");
				break;
			case '3':
				get.append("0011");
				break;
			case '4':
				get.append("0100");
				break;
			case '5':
				get.append("0101");
				break;
			case '6':
				get.append("0110");
				break;
			case '7':
				get.append("0111");
				break;
			case '8':
				get.append("1000");
				break;
			case '9':
				get.append("1001");
				break;
			case 'A':
				get.append("1010");
				break;
			case 'B':
				get.append("1011");
				break;
			case 'C':
				get.append("1100");
				break;
			case 'D':
				get.append("1101");
				break;
			case 'E':
				get.append("1110");
				break;
			case 'F':
				get.append("1111");
				break;
			}
		if (get.length() % 3 == 2)
			get = "0" + get;
		else if (get.length() % 3 == 1)
			get = "00" + get;
		int sum = 0;
		if ((sum = get[0] * 4 + get[1] * 2 + get[2] * 1 - '0' * 7) != 0)
			cout << sum;
		for (int i = 3; i < get.length(); i += 3)
		{
			sum = sum = get[i] * 4 + get[i + 1] * 2 + get[i + 2] * 1 - '0' * 7;
			cout << sum;
		}
		cout << endl;
	}
	return 0;
}
