#include <iostream>
int N, S;
int arr[20];
int cases = 0;
//1��, 2��, ... N���� �̴� ��� ����� �� Ȯ��
void solve(int sum = 0, int idx = 0)
{
    if (sum == S) ++cases;
    for (int i = idx; i < N; ++i) solve(sum + arr[i], i + 1);
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> S;
    for (int i = 0; i < N; ++i) std::cin >> arr[i];
    if (S == 0) --cases;    //S�� 0�ΰ�� solve�Լ��� ó�� ȣ���� �� sum == 0�̶� cases�� 1�� �������Ƿ� �̸� 1�� ����
    solve();
    std::cout << cases;
}