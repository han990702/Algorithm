#include <iostream>
#include <exception>
int N;
int cache[1000001];
int solve(int i = 0)
{
	if (i == N) return 1;
	if (i > N) return 0;
	if (cache[i]) return cache[i];
	return cache[i] = (solve(i + 1) + solve(i + 2)) % 15746;
}
//i�� �ʹ� Ŀ���� ���� �����÷ο찡 �߻��Ѵ�.
//VS���� ������Ʈ-�Ӽ�-��Ŀ-�ý���-���ÿ���ũ�� ���� ���ÿ���ũ�⸦ �����ϰ� �÷��ָ� �ȴ�.
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;

	std::cout << solve();
}