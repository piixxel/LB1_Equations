#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool validate(string value)
{
    int length;
    length = value.size();

    for (int i = 0; i < length; i++) //проверка на запятую
    {
        if (value[i] == ',')
            value[i] = '.';

        if (!((value[i] >= '0' && value[i] <= '9') || value[i] == '.' || value[i] == '-'))
        {
            cout << "Error! Try again" << endl;
            return false;
        }
    }
    return true;
}

double getValue(string text)
{
    string value;
            
    while (true)
    {
        cout << text;
        cin >> value;
               
        if (!validate(value))
        {
            continue;
        }
        return stod(value);
    }
    
}


// проверка аргументов
bool validateDisk(double a, double b, double c) 
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
void result(double a, double b, double c)
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

    if (!validateDisk(a, b, c))
    {
        return 0;
    }
       
    result(a,b,c);

    return 0;
}