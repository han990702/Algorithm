#include <iostream>
#include <algorithm>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int t[100][100];

	int C;
	std::cin >> C;
	while (C--)
	{
		int n;
		std::cin >> n;
		for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) std::cin >> t[i][j];
		/*
		� ��η� t[i][j]�� �����Դ����� ���� ����
		t[i][j]���� �������� �ִ� ��δ� �׻� �����Ƿ�
		�Ʒ����� ���ʴ�� t[i][j]������ �ִ밪�� ���ϸ�
		���ȣ���� ���� �ʰ� ������ Ǯ �� �ִ�.
		*/
		for (int i = n - 2; i >= 0; --i) for (int j = 0; j <= i; ++j)
		{
			t[i][j] += std::max(t[i + 1][j], t[i + 1][j + 1]);
		}

		std::cout << t[0][0] << '\n';
	}
}