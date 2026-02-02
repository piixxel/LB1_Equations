#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>


using namespace std;

class Equations
{
public:
    Equations();
    void diskr();
    bool prov_1();
    void prov_disk();

private:
    double a, b, c, disk;

};
//ввод числа с проверкой 
double getNum(const string text)
{
    
    double value;
    cout << text;
    while (true)
    {
        cin >> value;
        if (cin.fail())
        {
            cout << "Ошибка!!! Озаруешь, КИРИЛЛ :)\n" << text;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        return value;
    }
}

Equations::Equations()
{
    
    cout << "Введите коэффициенты для уравнения ax^2 + bx + c = 0" << endl;
    this->a = getNum("Введите коэффициент a = ");
    this->b = getNum("Введите коэффициент b = ");
    this->c = getNum("Введите коэффициент c = ");
    this->disk = 0;
}

void Equations::diskr()
{
    this->disk = (pow(b, 2)) - (4 * a * c);
}

bool Equations::prov_1()
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "Нет решений" << endl;
                return false;
            }
            cout << "Бесконечность решений" << endl;
            return false;
        }
        double x;
        x = -c / b;
        cout << "Корень уравнения x = " << x << endl;
        return false;
    }
    return true;
}

void Equations::prov_disk()
{
    if (this->disk < 0)
    {
        cout << "Нет решений" << endl;
        return;
    }
    if (this->disk == 0)
    {
        double x = (-b) / (2 * a);
        cout << "Корень уравнения x = " << x << endl;
        return;
    }
    if (this->disk > 0)
    {
        double x1 = (-b - sqrt(disk)) / (2 * a);
        double x2 = (-b + sqrt(disk)) / (2 * a);
        cout << "Корни уравнения  x1 = " << x1 << " и x2 = " << x2 << endl;
        return;
    }
}



int main()
{
    setlocale(LC_ALL, "rus");
    Equations a;
    
    if (!a.prov_1())
        return 0;
    a.diskr();
    a.prov_disk();

    return 0;
}