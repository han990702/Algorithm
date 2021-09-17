#include <iostream>
int TSP(int** DM, int N, int city = 0, int distance = 0)
{
    int min = 1'000'000 * 10;
    DM[city][city] = 987654321;    //�湮������ ǥ��
    bool finish = true;
    for (int i = 0; i < N; ++i) if (DM[i][i] == 0)  //���� i�� �湮������ ������
    {
        finish = false; //��� �湮�Ѱ��� �ƴϹǷ� false
        if (DM[city][i] != 0)   //city���� i�� ���� ��ΰ� ������
        {
            int ret = TSP(DM, N, i, distance + DM[city][i]);    //���� i�湮, ���(�Ÿ�) �߰�
            if (min > ret) min = ret;
        }
    }
    DM[city][city] = 0;
    //��� ���ø� �湮�߰�, city -> 0 (ó�� ����� ����)���� ���� ���� ������ ���� �Ÿ��� return
    if (finish && DM[city][0] != 0) return distance + DM[city][0];
    return min;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int** distance_matrix = new int* [N];
    for (int i = 0; i < N; ++i)
    {
        distance_matrix[i] = new int[N];
        for (int j = 0; j < N; ++j) std::cin >> distance_matrix[i][j];
    }

    std::cout << TSP(distance_matrix, N);  
}