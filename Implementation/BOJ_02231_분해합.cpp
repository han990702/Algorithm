#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int tmp = N;
	int i = 0;	//N�� �� �ڸ������� ����
	for (; tmp != 0; ++i) tmp /= 10;

	//� ������ M���κ��� �����Ǵ� �������� �ִ���
	//M + M�� �ڸ��� * 9 �̴�.

	int j = N - i * 9;	//�����ڰ� N - N�� �ڸ��� * 9 �̸����� ���� �� �����Ƿ� N - i * 9 ���� ����
	if (j < 0) j = 0;
	for (; j < N; ++j)
	{
		tmp = j;
		int sum = j;
		while (tmp)	//�� �ڸ����� ���� ���ϴ� �ݺ���
		{
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == N)	//j�� �������̸� ����ϰ� ����
		{
			std::cout << j;
			return 0;
		}
	}
	std::cout << 0;
	return 0;
}