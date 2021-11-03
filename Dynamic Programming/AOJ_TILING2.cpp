#include <iostream>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	/*
	2*n ������ 2*1 Ÿ�Ϸ� ä��� ����������
	Ÿ���� ���ٿ� ���η� ��ġ�ϸ� �Ʒ��ٵ� �ݵ�� ���η� ��ġ�ؾ� �ϱ� ������ ���Ʒ��� ��Ī�̴�.
	���� nĭ�� 1ĭȤ�� 2ĭ¥�� Ÿ�Ϸ� ä��� ������ ����.

	���ݱ��� ä�� ĭ�� i�� �� �� ���� N - i ĭ���� ������ ������ ��� ����� ���� ���ϴ� ����Լ��� �����ߴ�.
	i���� ĭ�� ä���� �� ���� ĭ�� ä��� �������� �Ѱ�¥��, �ΰ�¥�� �ΰ��� �̹Ƿ�
	solve(i) = solve(i + 1) + solve(i + 2) �̰�
	i == N�̸� ��� ĭ�� ä�������Ƿ� �� ���� ����� ���� �ϼ��Ǿ� 1�� �����ϰ� �Ͽ���.
	int solve(int i = 0)
	{
		if (i == N) return 1;
		if (i > N) return 0;
		if (cache[i]) return cache[i];
		return cache[i] = (solve(i + 1) + solve(i + 2)) % 1000000007;
	}
	��� ȣ���� �帧���� ó������ ���ϵǴ� �������� �������� ����
	�Ǻ���ġ ������ ���ٴ°� �� �� �ִ�.
	solve(N - 1) == solve(N) == 1 �̹Ƿ� solve(N - 2) = solve(N - 1) + solve(N) == 2 �̹Ƿ� �Ǻ���ġ ������ ���� �� �� �ִ�.
	*/

	int cache[101];
	cache[0] = cache[1] = 1;
	for (int i = 2; i <= 100; ++i) cache[i] = (cache[i - 2] + cache[i - 1]) % 1000000007;

	int C;
	std::cin >> C;
	while (C--)
	{
		int N;
		std::cin >> N;
		std::cout << cache[N] << '\n';
	}
}