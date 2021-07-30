#include <iostream>
#include <iomanip>
/*
10000��° �Ǻ���ġ ���� ��� C++���� ���� ū ���� ������ �� �ִ� Ÿ���� unsigned long long���ε� �ξ��� �����ϴ�.
ū ���� ��Ÿ���� ���� unsigned long long A[n] �迭�� �����,
A[0] ���� ���� ��Ÿ���� �����Ͽ� A[i]�� 10^18�� �Ǹ� A[i + 1]�� ĳ����Ű�� ������� �����Ͽ���.
���� ū �� A�� : (A[0] * 1) + (A[1] * 10^18) + (A[2] * (10^18)^2) + ... �̴�.
*/

//unsigned long long�� �� 1800�� �����ε�
//�� ���� ������ �� 1800���� ������ �ȵȴ�.
//1800�� / 2 = 900�������� 10^x �÷� �ؾ� �ϱ� ������ 100���� �ִ�.
#define d 1'000'000'000'000'000'000	//100��, 10^18
#define n 120	//�迭�� ũ��. 100��^120(10^2160)���� ����. 
//10000��° �Ǻ���ġ ���� 2090�ڸ��� �̹Ƿ� 10^2090������ ǥ���� �� �־�� �Ѵ�.

int main()	//4ms
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	unsigned long long n1[n] = { 0 };	//�ʱⰪ F(0) = 0
	unsigned long long n2[n] = { 1, 0 };	//�ʱⰪ F(1) = 1
	unsigned long long tmp[n] = { 0 };

	for (int i = 2; i <= N; ++i)	//F(N)�� ���ϱ�
	{
		for (int j = 0; j < n; ++j)	//�ε��� j�� (100^18)^j �� �ǹ� 
		{
			tmp[j] += n1[j] + n2[j];	//n1 = F(i - 2), n2 = F(i - 1)
			if (tmp[j] >= d)	//10^18���� ũ�ų� ������ ĳ�� �߻�
			{
				++tmp[j + 1];
				tmp[j] -= d;
			}

			n1[j] = n2[j];	
			n2[j] = tmp[j];
			tmp[j] = 0;
		}
 	}

	if (N)
	{
		int i = 0;
		for (; i < n && n2[i] != 0; ++i);
		std::cout << n2[--i];
		--i;
		for (; i >= 0; --i)
		{
			std::cout << std::setw(18) << std::setfill('0') << n2[i];
		}
	}
	else std::cout << 0;
}