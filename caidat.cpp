#include "kb.h"

vector<string> a;
int n = 15, x = 1, y = 1;
int mx, my;
int level = 1;

void taoMeCung()
{
    srand(time(0));

    a.assign(n, string(n, '#'));

    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < n - 1; j++)
            a[i][j] = (rand() % 4 ? ' ' : '#');

    a[1][1] = 'P';
    x = 1;
    y = 1;
    mx = n - 2;
    my = 1;
    a[n - 2][n - 2] = 'X';
    a[mx][my] = 'M';
}

void hienThi()
{
    system("cls");

    for (auto s : a)
        cout << s << endl;
}

void choi()
{
    int diem = 0;
    int buoc = 0;
    char c;


    while (true)
    {
        hienThi();

        if (x == n - 2 && y == n - 2)
        {
            diem = 1000 - buoc * 5;

            if (diem < 0)
                diem = 0;

            cout << "\nBan thang\n";
            cout << "So buoc: " << buoc << endl;
            cout << "Diem: " << diem << endl;
            break;
        }
        if (x == mx && y == my)
        {
            cout << "\nBan da bi ma bat!\n";
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
            buoc++;

            if (a[x][y] != 'X')
                a[x][y] = 'P';
        }
        if (level == 1)
        {
            if (rand() % 2)
                diChuyenMa();
        }
        else if (level == 2)
        {
            diChuyenMa();
        }
        else
        {
            diChuyenMa();
            diChuyenMa();
        }
    }
}
void diChuyenMa()
{
    a[mx][my] = ' ';

    if (mx < x && a[mx + 1][my] != '#')
        mx++;
    else if (mx > x && a[mx - 1][my] != '#')
        mx--;
    else if (my < y && a[mx][my + 1] != '#')
        my++;
    else if (my > y && a[mx][my - 1] != '#')
        my--;

    a[mx][my] = 'M';
}
