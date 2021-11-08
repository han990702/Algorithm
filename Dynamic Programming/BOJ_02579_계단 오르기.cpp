#include <iostream>
#include <algorithm>
int N;
int stairs[300];
int cache[300][2];
int solve(int idx = 0, bool prev_jmp = true)	//prev_jmp = true�̸� idx�� �� �� 2ĭ �����Ѱ�, false�̸� 1ĭ �����Ѱ�
{
	if (idx == N - 1) return stairs[idx];	//������ ĭ
	if (idx == N) return -987654321;	//������ ĭ�� ������� ����� ���� ���Ե��� �����Ƿ� -987654321�� ����(�� ��� �ִ��� ã�� �� �˾Ƽ� �ɷ���)
	if (cache[idx][prev_jmp]) return cache[idx][prev_jmp];
	int ret = -987654321;
	if (prev_jmp) ret = std::max(ret, solve(idx + 1, false));	//1ĭ ������ ������ ���(������ 2ĭ������ ���)
	ret = std::max(ret, solve(idx + 2, true));	//2ĭ ����(2ĭ ������ ������ ������ ������� ������ ����)
	//idx ĭ���� ���������� prev_jmp���� ��(1ĭor2ĭ) ���� ������ �ִ��� ĳ�ÿ� ���� �� ����
	return cache[idx][prev_jmp] = stairs[idx] + ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	for (int i = 0; i < N; ++i) std::cin >> stairs[i];
	std::cout << std::max(solve(), solve(1));    //���������� ��ĭ(idx = 0), ��ĭ ����(idx = 1)�ϴ� ��쿡 ���� ȣ��
}