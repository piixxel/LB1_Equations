#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

//валидация
double getValue(string text)
{
    string value;
    int length;
    bool boo;
    
    while (true)
    {
        cout << text;
        cin >> value;
        boo = true;
        length = value.size();

        for (int i = 0; i < length; i++) //проверка на запятую
        {
            if (value[i] == ',')
                value[i] = '.';

            if (!((value[i] >= '0' && value[i] <= '9') || value[i] == '.' || value[i] == '-'))
            {
                boo = false;
                cout << "Error! Try again" << endl;
                break;
            }
        }

        if (boo)
        {
            break;
        }
           
    }
    return stod(value);
}


// проверка аргументов
bool provDisk(double a, double b, double c) 
{
    if (a == 0)
    {
        if (b == 0)
        {
            (c == 0) ? cout << "No solutions" << endl : cout << "So many solutions" << endl;
            return false;
        }
        double x = -c / b;
        cout << "Solution x = " << x << endl;
        return false;
    }
    return true;
}

//подсчет корней
void itog(double a, double b, double c)
{
    double disk = (pow(b, 2)) - (4 * a * c);

    if (disk < 0)
    {
        cout << "No solutions" << endl;
        return;
    }
    if (disk == 0)
    {
        double x = (-b) / (2 * a);
        cout << "Solution x = " << x << endl;
        return;
    }
    if (disk > 0)
    {
        double x1 = (-b - sqrt(disk)) / (2 * a);
        double x2 = (-b + sqrt(disk)) / (2 * a);
        cout << "Solutions  x1 = " << x1 << " и x2 = " << x2 << endl;
        return;
    }
}



int main()
{
   
    double a = getValue("Enter value a = ");
    double b = getValue("Enter value b = ");
    double c = getValue("Enter value c = ");
    if (!provDisk(a, b, c))
    {
        return 0;
    }
       
    itog(a,b,c);

    return 0;
}