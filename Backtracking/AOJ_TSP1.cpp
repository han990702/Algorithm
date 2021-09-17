#include <iostream>
#include <iomanip>
double TSP(double** DM, int N, int city = 0, double distance = 0)
{
    double min = 1415 * 10;
    DM[city][city] = 1416;    //�湮������ ǥ��
    bool finish = true;
    for (int i = 0; i < N; ++i) if (DM[i][i] == 0)  //���� i�� �湮�� ���� ������
    {
        finish = false; //��� �湮�Ѱ��� �ƴϹǷ� false
        double ret = TSP(DM, N, i, distance + DM[city][i]); //���� i�湮, �Ÿ� �߰�
        if (min > ret) min = ret;
    }
    DM[city][city] = 0;
    if (finish) return distance;    //��� ���ÿ� �湮������ �Ÿ� return
    return min;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int C;
    std::cin >> C;

    while (C--)
    {
        int N;
        std::cin >> N;

        double** distance_matrix = new double* [N];
        for (int i = 0; i < N; ++i)
        {
            distance_matrix[i] = new double[N];
            for (int j = 0; j < N; ++j) std::cin >> distance_matrix[i][j];
        }

        double min = 1415 * 10;
        for (int i = 0; i < N; ++i) //ó�� ����� ���÷� ���ƿ��� �ʱ� ������ �� ���ÿ��� ����ϴ°�츦 ��� ����ؾ� ��
        {
            double ret = TSP(distance_matrix, N, i);
            if (min > ret) min = ret;
        }
        std::cout << std::fixed << std::setprecision(10) << min << '\n';
    }
}