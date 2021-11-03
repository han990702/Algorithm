#include <iostream>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t[100][100];
	int cases[100][100];

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
		�Ʒ����� ���ʴ�� �ö󰡸鼭 t[i][j]������ �ִ밪�� ���ϸ�
		���ȣ���� ���� �ʰ� �ִ밪�� ���� �� �ִ�.

		cases�� ����� ���� ������ �迭�̴�.
		cases[i][j] �� �ش� ĭ���� �ִ��η� ������ �� �ִ� ����� ���̴�.
		�� �Ʒ�ĭ�� ��� �ڽ� �� ��ü�� �ִ����̹Ƿ� ����� ���� 1�̴�.
		��ĭ������ ����� ���� �Ʒ�, �Ʒ������ʿ��� �� �� �ִ����� �ʿ����� ����� ���� ����.
		��, �Ʒ�ĭ, �Ʒ�������ĭ�� �Ѵ� �ִ��ζ�� �Ʒ�, �Ʒ������ʿ����� ����� �� �� ���̴�.
		*/
		for (int i = 0; i < n; ++i) cases[n - 1][i] = 1;
		for (int i = n - 2; i >= 0; --i) for (int j = 0; j <= i; ++j)
		{
			if (t[i + 1][j] > t[i + 1][j + 1])
			{
				t[i][j] += t[i + 1][j];
				cases[i][j] = cases[i + 1][j];
			}
			else if (t[i + 1][j] < t[i + 1][j + 1])
			{
				t[i][j] += t[i + 1][j + 1];
				cases[i][j] = cases[i + 1][j + 1];
			}
			else
			{
				t[i][j] += t[i + 1][j];
				cases[i][j] = cases[i + 1][j] + cases[i + 1][j + 1];
			}			
		}

		std::cout << cases[0][0] << '\n';
	}
}