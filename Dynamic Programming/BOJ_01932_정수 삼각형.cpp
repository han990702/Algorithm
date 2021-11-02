#include <iostream>
#include <algorithm>
int N;
int triangle[500][500];
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	for (int i = 0; i < N; ++i) for (int j = 0; j <= i; ++j) std::cin >> triangle[i][j];
	/*
		� ��η� t[i][j]�� �����Դ����� ���� ����
		t[i][j]���� �������� �ִ� ��δ� �׻� �����Ƿ�
		�Ʒ����� ���ʴ�� t[i][j]������ �ִ밪�� ���ϸ�
		���ȣ���� ���� �ʰ� ������ Ǯ �� �ִ�.
	*/
	for (int i = N - 2; i >= 0; --i) 
		for (int j = 0; j <= i; ++j) triangle[i][j] += std::max(triangle[i + 1][j], triangle[i + 1][j + 1]);
	std::cout << triangle[0][0];
}