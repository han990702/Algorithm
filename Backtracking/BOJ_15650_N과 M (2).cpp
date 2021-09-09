#include <iostream>
#include <vector>
void permutation(std::vector<int>& p, int n, int m)
{
    if (p.size() == m)  //������ �ϼ��Ǹ� ���
    {
        for (int i = 0; i < m; ++i) std::cout << p[i] << ' ';
        std::cout << '\n';
    }
    else
    {
        for (int i = (p.empty() ? 1 : p.back() + 1); i <= n; ++i)   //p�� ������ ������ 1 ū ���� ���� �� �����Ƿ�
        {
            p.push_back(i);
            permutation(p, n, m);
            p.pop_back();
        }
    }
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> p; //������ �Ѱ��� ����� ������ ������ ����
    permutation(p, N, M);
}