#include <iostream>
#include <cmath>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Russian");
    const double eps = 1e-10;

    double x1, y1, x2, y2, x3, y3;
    double dx, dy;

    std::cout << "Введите координаты вершин треугольника:\n";
    std::cout << "A (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "B (x2 y2): ";
    std::cin >> x2 >> y2;
    std::cout << "C (x3 y3): ";
    std::cin >> x3 >> y3;
    std::cout << "Введите координаты точки D: ";
    std::cin >> dx >> dy;

    if (!std::cin) {
        std::cout << "Ошибка\n";
        return 1;
    }

    double s2ABC = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

    if (std::fabs(s2ABC) < eps) {
        std::cout << "Три точки не образуют невырожденный треугольник\n";
        return 0;
    }

    double s2DBC = (x2 - dx) * (y3 - dy) - (x3 - dx) * (y2 - dy);
    double s2DCA = (x3 - dx) * (y1 - dy) - (x1 - dx) * (y3 - dy);
    double s2DAB = (x1 - dx) * (y2 - dy) - (x2 - dx) * (y1 - dy);

    double absSABC = std::fabs(s2ABC);
    double absSDBC = std::fabs(s2DBC);
    double absSDCA = std::fabs(s2DCA);
    double absSDAB = std::fabs(s2DAB);

    double sumS = absSDBC + absSDCA + absSDAB;

    if (std::fabs(sumS - absSABC) < eps) {
        if (absSDBC < eps || absSDCA < eps || absSDAB < eps) {
            std::cout << "Точка D лежит на стороне треугольника.\n";
        }
        else {
            std::cout << "Точка D находится внутри треугольника.\n";

            double a = absSDBC / 2.0;
            double b = absSDCA / 2.0;
            double c = absSDAB / 2.0;

            double temp;

            if (a < b) { temp = a; a = b; b = temp; }
            if (b < c) { temp = b; b = c; c = temp; }
            if (a < b) { temp = a; a = b; b = temp; }

            std::cout << "Площади треугольников по убыванию, образованных точкой D и сторонами:\n";
            std::cout << "1) " << a << "\n";
            std::cout << "2) " << b << "\n";
            std::cout << "3) " << c << "\n";
        }
    }
    else {
        std::cout << "Точка D находится вне треугольника.\n";
    }

    return 0;
}