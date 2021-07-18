#include <iostream>
#include <cmath>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	bool eratosthenes[7368787 + 1] = { 0 };	//eratosthenes[i] == 0 �̸� �Ҽ�
	//�����佺�׳׽��� ü �̿�
	for (int j = 4; j <= 7368787; j += 2) eratosthenes[j] = 1;    //2�� ����� �̸� �ռ����� ó��
	for (int i = 3; i <= sqrt(7368787); ++i)
	{
		if (!eratosthenes[i])	//�Ҽ��� ��� �� ����� ��� �ռ����� ó��
		{										//i + i�� ����: Ȧ���� j�� Ȧ���� i�� ���ϸ� ¦���� ��
			for (int j = i * i; j <= 7368787; j += i + i) eratosthenes[j] = 1;	//2�������� ¦���� �̹� �ռ����� ó���� �Ǿ������Ƿ�
		}																		//¦���ΰ�츦 �ǳ� �پ �ݺ� Ƚ���� 1/2�� ��
	}

	int count = 1;
	for (int i = 2; i <= 7368787; ++i)
	{
		if (!eratosthenes[i])
		{
			if (N == count)
			{
				std::cout << i;
				break;
			}
			++count;
		}
	}
}