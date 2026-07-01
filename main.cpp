#include "kb.h"

int main()
{
    int lc;

    do
    {
        system("cls");

        cout << "===== GAME ME CUNG =====\n";
        cout << "1. Tao me cung va choi\n";
        cout << "2. Thoat\n";
        cout << "Lua chon: ";
        int level;

        cout << "Chon do kho:\n";
        cout << "1. De\n";
        cout << "2. Trung binh\n";
        cout << "3. Kho\n";
        cin >> level;

        switch (level)
        {
        case 1: n = 11; break;
        case 2: n = 15; break;
        case 3: n = 21; break;
        }
        cin >> lc;

        switch (lc)
        {
        case 1:
            taoMeCung();
            choi();
            system("pause");
            break;

        case 2:
            cout << "Tam biet\n";
            break;

        default:
            cout << "Lua chon khong hop le\n";
            system("pause");
        }

    } while (lc != 2);

    return 0;
}
