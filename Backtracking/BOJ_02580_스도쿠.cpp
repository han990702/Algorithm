#include <iostream>
bool sudoku(int board[][9], int r = 0)
{
    bool nine[10];  //board[i][j]�� �� �� �ִ� ����(�ε���)�� false�� ������ �迭

    for (int i = r; i < 9; ++i) for (int j = 0; j < 9; ++j)
    {//r���� �����ϸ� �̹� ä���� ���� �ǳ� �� �� �ִ�.
        if (board[i][j] == 0)
        {
            for (int k = 1; k <= 9; ++k) nine[k] = false; //�ʱ�ȭ
            for (int k = 0; k < 9; ++k) nine[board[i][k]] = true;   //���ι��� ���� Ȯ��
            for (int k = 0; k < 9; ++k) nine[board[k][j]] = true;   //���ι��� ���� Ȯ��
            for (int q = i / 3 * 3; q < i / 3 * 3 + 3; ++q) //3*3 �ȿ� �ִ� ���� Ȯ��
            {
                for (int w = j / 3 * 3; w < j / 3 * 3 + 3; ++w)
                {
                    nine[board[q][w]] = true;
                }
            }

            nine[0] = true;
            for (int k = 1; k <= 9; ++k) if (nine[k] == false)  //���� ���ڸ� board[i][j]�� ���� �� ����
            {
                nine[0] = false;
                board[i][j] = k;

                if (sudoku(board, i))   //�����ΰ�� ���� ���� ������ ���ڷ� ����
                {
                    nine[0] = true;
                    board[i][j] = 0;
                }
                else break; //�����ΰ�� ��������
            }
            if (nine[0]) return true;    //nine[1~9]�� ��� true�̸�(=board[i][j]�� �� ���ڰ� �ϳ��� ������)
            //�����̹Ƿ� ������Ȳ���� ���ư�

        }
    }
    return false;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int board[9][9];
    for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) std::cin >> board[i][j];

    sudoku(board);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j) std::cout << board[i][j] << ' ';
        std::cout << '\n';
    }
}