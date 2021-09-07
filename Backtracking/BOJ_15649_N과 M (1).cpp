#include <iostream>
#include <vector>
void permutation(std::vector<int>& p, bool* inp, int n, int m)
{
    if (p.size() == m)  //������ �ϼ��Ǹ� ���
    {
        for (int i = 0; i < m; ++i) std::cout << p[i] << ' ';
        std::cout << '\n';
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (!inp[i])    //i�� ������ ���°�츸 ���� �߰�
            {
                inp[i] = true;
                p.push_back(i);
                permutation(p, inp, n, m);
                p.pop_back();
                inp[i] = false;
            }
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
    bool* is_in_permutation = new bool[N + 1]; //�� ���� �ε����� �Ͽ� ������ ����ִ��� Ȯ���ϴ� �迭
    for (int i = 1; i <= N; ++i) is_in_permutation[i] = false;
    permutation(p, is_in_permutation, N, M);
}