#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int bit, length, count = 0; // 10n6ֻ��Ҫ��int 
	cin >> bit >> length;
	int** dp_data = new int* [length];
	for (int i = 0; i <= length; i++)
		dp_data[i] = new int[bit + 1];
	if (length == 1)
		cout << bit - 1;
	else {
		for (int i = 0; i < bit; i++)
			dp_data[1][i] = 1; //�������
		for (int i = 2; i < length; i++)//i���ڱ�ʾ�ڵ�����iλ 
			for (int j = 0; j <= bit; j++) // j���ڴ�0ö�ٵ�bit-1��ͳ�Ƶ�λ��Ϊi+1λʱ��2λ���Ϊj�Ļ��ж�������� 
				for (int num = 0; num < bit; num++) //k���� 
					if (num != j - 1 and num != j + 1) //Ѱ�ҵ�3λ���ܵ���
					{
						dp_data[i][j] += dp_data[i - 1][num];
						dp_data[i][j] %= 1000000007;//��ֹ���; 
					}
		//�����1λ��
		for (int i = 1; i < bit; i++) //��Ϊ��1λ����Ϊ0�����Դ�1��ʼ
			for (int num = 0; num < bit; num++)
				if (num != i - 1 and num != i + 1) {//Ѱ�ҵ�2λ���ܵ���
					count += dp_data[length - 1][num];
					count %= 1000000007;//��ֹ���; 
				}
		cout << count;
	}
	return 0;
}
