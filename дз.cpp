#include <iostream>

int* create(int n) { return new int[n]; }
void read(int* a, int n) { for (int i = 0; i < n; i++) std::cin >> a[i]; }
void print(int* a, int n) { for (int i = 0; i < n; i++) std::cout << a[i] << ' '; std::cout << '\n'; }
void del(int* a) { delete[] a; }

void task1(int* a, int n, int x) {
    for (int i = 0; i < n; i++)
        if (a[i] == x) { std::cout << "position: " << i + 1 << '\n'; return; }
    std::cout << "Not found\n";
}

bool task2(int* a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

int task3(int* a, int n) {
    int c = 0;
    for (int i = 1; i < n - 1; i++)
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) c++;
    return c;
}

int main() {
    int n;
    std::cout << "n = "; std::cin >> n;

    int* a = create(n);
    read(a, n);
    print(a, n);
    int x; std::cout << "x = "; std::cin >> x;
    task1(a, n, x);
    del(a);

    a = create(n);
    read(a, n);
    print(a, n);
    std::cout << (task2(a, n) ? "Sorted" : "Not sorted") << '\n';
    del(a);

    a = create(n);
    read(a, n);
    print(a, n);
    std::cout << "Count: " << task3(a, n) << '\n';
    del(a);

    return 0;
}