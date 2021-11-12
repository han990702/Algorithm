#include <iostream>
#define m 1000000007
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int cache[101];
	cache[0] = cache[1] = 1;
	for (int i = 2; i <= 100; ++i) cache[i] = (cache[i - 2] + cache[i - 1]) % m;
	//Ÿ���� ä��� ��� ����� �� - ��Ī�� ����� �� �� ���ָ� �ȴ�.
	//Ÿ���� ä��� ��� ����� ���� TILING2 ������ �����Ƿ� �Ǻ���ġ ������ ���Ѵ�.
	//��Ī�� ����� ����
	//N�� Ȧ���� ���
	//��� ĭ�� ���η� Ÿ���� ��ġ �ϰ� N/2 ĭ�� Ÿ���� ��ġ�ϴ� ����� ���� ����.(���ʿ� ��ġ�Ѱ� �����ʿ� �ݴ�� ��ġ�ϸ� ��Ī�̹Ƿ�)

	//N�� ¦���� ���
	//������ ������ N/2ĭ�� Ÿ���� ��ġ�ϴ� ����� �� + ��� ��ĭ�� ���η� Ÿ���� ��ġ�ϰ� N/2 - 1 ĭ�� Ÿ���� ��ġ�ϴ� ����� �� �̴�.
	int C;
	std::cin >> C;
	while (C--)
	{
		int N;
		std::cin >> N;
		std::cout << (N % 2 ? (m + cache[N] - cache[N / 2]) % m : (2 * m + (long long)cache[N] - cache[N / 2] - cache[N / 2 - 1]) % m) << '\n';
	}
}