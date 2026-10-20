#include <iostream>

int main()
{
    const int MAX = 100;
    int rows, cols;

    int a[MAX][MAX];
    std::cin >> rows >> cols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            std::cin >> a[i][j];
    for (int j = 0; j < cols; ++j)
    {
        int mn = a[0][j];
        for (int i = 1; i < rows; ++i)
            if (a[i][j] < mn) mn = a[i][j];
        std::cout << mn << ' ';
    }
    std::cout << '\n';



    int b[MAX][MAX];
    std::cin >> rows >> cols;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            std::cin >> b[j][i];
    for (int j = 0; j < cols; ++j)
        for (int i = 0; i < rows; ++i)
            std::cout << b[j][i] << ' ';
    std::cout << '\n';



    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> a[i][j];
    bool sym = true;
    for (int i = 0; i < n && sym; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i][j] != a[j][i])
            {
                sym = false;
                break;
            }
    std::cout << (sym ? "yes" : "no") << '\n';

    return 0;
}