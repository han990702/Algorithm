#include <iostream>
long long cache[100];
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	//1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37
	//������ �׸��� �� ���� �߰��Ǵ� �ﰢ���� ���� ������ �߰��� �ﰢ���� �� P(N-1) + 5ȸ ���� �߰��� �ﰢ���� �� P(N - 5)�̹Ƿ�
	//P(N) = P(N - 1) + P(N - 5)���� �� �� �ִ�.
	
	cache[0] = cache[1] = cache[2] = 1;
	cache[3] = cache[4] = 2;
	for (int i = 5; i < 100; ++i) cache[i] = cache[i - 1] + cache[i - 5];

	int T;
	std::cin >> T;
	while (T--)
	{
		int N;
		std::cin >> N;
		std::cout << cache[N - 1] << '\n';
	}
}