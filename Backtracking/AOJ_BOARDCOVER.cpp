#include <iostream>
int board_cover(char** board, int h, int w)
{
    int i = 0, j = 0;
    bool find = false;
    for (; i < h; ++i)  //�� ĭ�� ���� �����ִ� ĭ, ���� ���� ���ʿ� �ִ� ĭ ã��
    {
        for (j = 0; j < w; ++j)
        {
            if (board[i][j] == '.')
            {
                find = true;
                break;
            }
        }
        if (find) break;
    }
    if (!find) return 1;   //���� ĭ�� ������ ����� �� 1 �߰�
    int ret = 0;
    //i, jĭ�� �����Ͽ� L�ڸ�� ������� ���� ��� 4����
    //(����ĭ�� ��ĭ, ����ĭ�� �̹� �����ְų� ���� �� ���� ĭ�̹Ƿ� ���� 4���� ��)
    board[i][j] = '#';
    if (i + 1 < h)
    {
        if (board[i + 1][j] == '.')
        {
            board[i + 1][j] = '#';
            if (j - 1 >= 0 && board[i + 1][j - 1] == '.')
            {
                board[i + 1][j - 1] = '#';
                ret += board_cover(board, h, w);    //1
                board[i + 1][j - 1] = '.';
            }
            if (j + 1 < w)
            {
                if (board[i + 1][j + 1] == '.')
                {
                    board[i + 1][j + 1] = '#';
                    ret += board_cover(board, h, w);    //2
                    board[i + 1][j + 1] = '.';
                }
                if (board[i][j + 1] == '.')
                {
                    board[i][j + 1] = '#';
                    ret += board_cover(board, h, w);    //3
                    board[i][j + 1] = '.';
                }
            }
            board[i + 1][j] = '.';
        }
        if (j + 1 < w && board[i][j + 1] == '.' && board[i + 1][j + 1] == '.')
        {
            board[i][j + 1] = '#';
            board[i + 1][j + 1] = '#';
            ret += board_cover(board, h, w);    //4
            board[i][j + 1] = '.';
            board[i + 1][j + 1] = '.';
        }
    }
    board[i][j] = '.';
    return ret;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    while (N--)
    {
        int H, W;
        std::cin >> H >> W;
        char** board = new char*[H];
        int count = 0;
        for (int i = 0; i < H; ++i)
        {
            board[i] = new char[W];
            for (int j = 0; j < W; ++j)
            {
                std::cin >> board[i][j];
                if (board[i][j] == '.') ++count;
            }
        }
        if (count % 3 == 0) std::cout << board_cover(board, H, W) << '\n';
        else std::cout << 0 << '\n';    //�� ĭ�� ������ 3�� ����� �ƴϸ� ����� ���� 0��
    }
}