#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	short N, M;
	std::cin >> N >> M;

	char** board = new char* [N];	//2���� �迭 �����Ҵ�
	for (int i = 0; i < N; ++i) board[i] = new char[M];

	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) std::cin >> board[i][j];

	short min = 32;	//ĥ�ؾ� �� �ּ� ĭ�� �ִ밪(�ʱⰪ)
	for (int i = 0; i < N - 7; ++i) for (int j = 0; j < M - 7; ++j)	//N*M���� ���� 8*8ũ�� ������ �� �ִ� ��� ����� ��
	{//i, j�� �� 8*8�� �� ���� ��ĭ�� �ε����� ��
		short Wpaint = 0;	//�� ���� ��ĭ�� ������� �� ��� ĥ�ؾ� �� ĭ��
		short Bpaint = 0;	//�� ���� ��ĭ�� ���������� �� ��� ĥ�ؾ� �� ĭ��
		for (int q = i; q < i + 8; ++q) for (int w = j; w < j + 8; ++w)	//8*8�� �� ĭ�� ������ Ȯ���ϴ� ����
		{
			if ((q + w) % 2 == 0)	//���� ¦���� ĭ(ex 0,0 1,1 2,4 ...)
			{
				if (board[q][w] == 'B') ++Wpaint;	//0,0�� ������� �� ��� ¦��ĭ�� �������̸� ��� ĥ�ؾ� ��
				else ++Bpaint;	//0,0�� ���������� �� ��� ¦��ĭ�� ����̸� ������ ĥ�ؾ� ��
			}
			else	//���� Ȧ���� ĭ(ex 0,1 1,0 3,4...)
			{
				if (board[q][w] == 'W') ++Wpaint;	//Ȧ��ĭ�� ����̸� ������ ĥ�ؾ� ��
				else ++Bpaint;	//Ȧ��ĭ�� �������̸� ��� ĥ�ؾ� ��
			}
		}
		if (Wpaint < min) min = Wpaint;
		if (Bpaint < min) min = Bpaint;
	}
	std::cout << min;
}