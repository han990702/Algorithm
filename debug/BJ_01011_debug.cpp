#include <iostream>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--)
	{
		int x, y;
		std::cin >> x >> y;
		x = y - x;
		//x�� 2^31�� ����� �� ���� �߻�.
		//int i = 1, s = 0;
		long long i = 1, s = 0;
		while (s < x) s += i++ * 2;    //s �� int�϶� 2^31 - 1���� Ŀ���� �����÷ο� ���� ���ѷ���.
		//long long ���� �ذ�.
		if (s - --i < x) std::cout << i * 2 << '\n';
		else std::cout << i * 2 - 1 << '\n';
	}
}