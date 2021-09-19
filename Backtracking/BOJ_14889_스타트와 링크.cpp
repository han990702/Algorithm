#include <iostream>
#include <algorithm>
int chooseup(int** stats, int N, int idx = 1, int cnt = 1)
{//stats[i][i] = 1�̸� i�� ��ŸƮ��, 0�̸� ��ũ���ΰ����� Ȱ��(������ bool �迭 �ʿ� ����)
    if (cnt == N / 2)   //���� ���� �Ǹ�
    {
        int start = 0, link = 0;
        for (int i = 0; i < N; ++i)
        {
            if (stats[i][i]) for (int j = i + 1; j < N; ++j)    //i�� ��ŸƮ���϶�
            {
                if (stats[j][j]) start += stats[i][j] + stats[j][i];    //j�� ��ŸƮ���̸� �ɷ�ġ�� ����
            }
            else for (int j = i + 1; j < N; ++j)    //i�� ��ũ���϶�
            {
                if (!stats[j][j]) link += stats[i][j] + stats[j][i];    //j�� ��ũ���̸� �ɷ�ġ�� ����
            }
        }
        return (start > link ? start - link : link - start);    //���� ���� ���밪 ����
    }
    int min = 987654321;
    for (int i = idx; i < N; ++i)
    {
        stats[i][i] = 1;
        min = std::min(min, chooseup(stats, N, i + 1, cnt + 1));
        stats[i][i] = 0;
    }
    return min;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int** stats = new int* [N];
    for (int i = 0; i < N; ++i)
    {
        stats[i] = new int[N];
        for (int j = 0; j < N; ++j) std::cin >> stats[i][j];
    }

    stats[0][0] = 1;    //��ŸƮ ���� 0�� �ݵ�� ���Խ�Ŵ(�ߺ��� ���ϱ� ����)
    //�� 6���� �� �������
    //��ŸƮ�� 0, 1, 2 ��ũ�� 3, 4, 5 �� ����
    //��ũ�� 0, 1, 2 ��ŸƮ�� 3, 4, 5 �� ���� ���� ����̹Ƿ�
    //��ŸƮ ���� �Ѹ��� �׻� �̾Ƶθ� �ߺ��� �߻����� ����
    std::cout << chooseup(stats, N);
}