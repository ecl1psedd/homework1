#include <iostream>

int main() {
    int n;
    int a[1000];

    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            std::cout << a[i] << " ";
        }
    }
    std::cout << std::endl;

    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if ((a[i] > 0) == (a[i - 1] > 0)) {
            flag = false;
            break;
        }
    }
    std::cout << (flag ? "YES" : "NO") << std::endl;

    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int current = 1, best = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) current++;
        else current = 1;
        if (current > best) best = current;
    }
    std::cout << best << std::endl;

    return 0;
}