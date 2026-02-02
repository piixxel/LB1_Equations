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
    string chislo;
    double value;
    cout << text;
    while (true)
    {
        cin >> chislo;
        replace(chislo.begin(), chislo.end(), ',', '.'); //инициализация чисел с запятой (замена запятой на точку)
        value = stod(chislo);
        if (cin.fail())
        {
            cout << "Error!!! Enter again, Kirill :)\n" << text;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        return value;
    }
}

Equations::Equations()
{
    
    cout << "Enter index ax^2 + bx + c = 0" << endl;
    this->a = getNum("Enter index a = ");
    this->b = getNum("Enter index b = ");
    this->c = getNum("Enter index c = ");
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
                cout << "No solutions" << endl;
                return false;
            }
            cout << "Many solutions" << endl;
            return false;
        }
        double x;
        x = -c / b;
        cout << "Solution x = " << x << endl;
        return false;
    }
    return true;
}

void Equations::prov_disk()
{
    if (this->disk < 0)
    {
        cout << "No solutions" << endl;
        return;
    }
    if (this->disk == 0)
    {
        double x = (-b) / (2 * a);
        cout << "Solution  x = " << x << endl;
        return;
    }
    if (this->disk > 0)
    {
        double x1 = (-b - sqrt(disk)) / (2 * a);
        double x2 = (-b + sqrt(disk)) / (2 * a);
        cout << "Solutions  x1 = " << x1 << " и x2 = " << x2 << endl;
        return;
    }
}



int main()
{
    
    Equations a;
    
    if (!a.prov_1())
        return 0;
    a.diskr();
    a.prov_disk();

    return 0;
}