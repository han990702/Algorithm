#include <iostream>
#define p 1'000'000'007
int ApowBmodC(int a, int b, int c)	//���������� �̿��� �ŵ�����(mod c)
{
	if (b == 1) return a;
	if (b % 2) return (long long)a * ApowBmodC(a, b - 1, c) % c;
	long long tmp = ApowBmodC(a, b / 2, c);
	return tmp * tmp % c;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	long long N, K;
	std::cin >> N >> K;
	if (K <= N / 2) K = N - K;
	//N!/(K!*(N-K)!) % p �� �丣���� �������� �̿��Ͽ�
	//((N! % p) * ((K!*(N-K)!)^(p-2)) % p)) % p�� ������ �� �ִ�.
	//(((N!/K!) % p) * (N-K)!^(p-2) % p) % p �ε� ǥ���� �� �ִ�. (N!/K!�� �ٷ� ��� �����ϹǷ�)
	long long t1 = 1, t2 = 1;
	for (int i = K + 1, j = 1; i <= N; ++i, ++j)
	{
		t1 = (t1 * i) % p;	//N*(N-1)*(N-2)*...*(K+1) % p	== (N! / K!) % p
		t2 = (t2 * j) % p;	//(N-K)! % p
	}
	t2 = ApowBmodC(t2, p - 2, p);	//(N-K)!^(p-2) % p
	std::cout << t1 * t2 % p;
}