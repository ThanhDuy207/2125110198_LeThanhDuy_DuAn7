#include "kb.h"

vector<string> a;
int n = 15, x = 1, y = 1;

void taoMeCung()
{
    srand(time(0));

    a.assign(n, string(n, '#'));

    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < n - 1; j++)
            a[i][j] = (rand() % 4 ? ' ' : '#');

    a[1][1] = 'P';
    a[n - 2][n - 2] = 'X';
}

void hienThi()
{
    system("cls");

    for (auto s : a)
        cout << s << endl;
}

void choi()
{
    char c;

    while (true)
    {
        hienThi();

        if (x == n - 2 && y == n - 2)
        {
            cout << "\nBan thang\n";
            break;
        }

        c = _getch();

        int nx = x, ny = y;

        if (c == 'w') nx--;
        if (c == 's') nx++;
        if (c == 'a') ny--;
        if (c == 'd') ny++;

        if (a[nx][ny] != '#')
        {
            a[x][y] = ' ';
            x = nx;
            y = ny;

            if (a[x][y] != 'X')
                a[x][y] = 'P';
        }
    }
}
