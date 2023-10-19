#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void calculateS(const double x, const double log_result, int& n, double &s);
void calculateA(const double x, const int n, double &a);

int main()
{
    double xp, xk, x, dx, log_result = 0, s = 0;

    int n = 1;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "log(1-x) = "; cin >> log_result;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << " |"
        << setw(10) << "log(1-x)" << " |"
        << setw(7) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        calculateS(x, log_result, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << log_result << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(5) << n << " |"
            << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;
    return 0;
}

void calculateS(const double x, const double log_result, int &n, double &s)
{
    n = 1;
    double a = 1;
    s = a;
    do {
        n++;
        calculateA(x, n, a);
        s += a;
    } while (abs(a) >= log_result);
}

void calculateA(const double x, const int n, double &a)
{
    double R = x / n;
    a *= R;
}
