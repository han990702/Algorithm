#include <iostream>
#include <string>
//ũ�� N�� ������ ũ�� N/3�� ������ 3*3 ��ķ� �̷���� �ִٰ� �� �� �ִ�.
//3*3�迭 ���� ����� 1,1�� �����̴�.
//���� ����� 1,1�� �����ϰ� ������ �κп� ���� ũ�� N/3�� ������ ä��� �ȴ�.
void asterisk(int n, int y, int x, std::string* s)
{
	if (n > 1)
	{
		n /= 3;
		asterisk(n, y + n * 0, x + n * 0, s);
		asterisk(n, y + n * 0, x + n * 1, s);
		asterisk(n, y + n * 0, x + n * 2, s);

		asterisk(n, y + n * 1, x + n * 0, s);
		//1, 1�� ����
		asterisk(n, y + n * 1, x + n * 2, s);

		asterisk(n, y + n * 2, x + n * 0, s);
		asterisk(n, y + n * 2, x + n * 1, s);
		asterisk(n, y + n * 2, x + n * 2, s);
	}
	else
	{
		s[y][x] = '*';
	}

}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::string* s = new std::string[N];

	for (int i = 0; i < N; ++i) s[i] = std::string(N, ' ');

	asterisk(N, 0, 0, s);

	for (int i = 0; i < N; ++i) std::cout << s[i] << '\n';
}