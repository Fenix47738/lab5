#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Figure(); // task 1

void EnterConsole(vector<double>& pointsX, vector<double>& pointsY, int& N, double& r); // за допомогою цієї методу користувач вводить у консоль для першого завдання
int AmountPointsInFigure(vector<double> pointsX, vector<double> pointsY, int N, double r); // цей метод виконує перше завдання
void Console_Figure(int amount); // цей метод виводить результат пршого завдання у консоль

bool isPointInSector(double x, double y, double r); // цей метод перевіряє чи точка у секторі?
bool isAngleInSector(double angleDeg, double startDeg, double endDeg); // цей метод перевіряє два сектора

void Formula19(); // таск 2

void EnterConsole_Formula19(double& x, int& n); // за допомогою цієї методу користувач вводить у консоль для другого завдання
void Formula19Calculation(double& sum, double x, int n); // цей метод виконує друге завдання
void Console_Formula19(double sum); // цей метод виводить результат другого завдання у консоль

void Formula32(); // таск 3

void EnterConsole_Formula32(double& e, double& g); // за допомогою цієї методу користувач вводить у консоль для третього завдання
double SumSeries(double e, double g); // цей метод виконує третє завдання
void Console_Formula32(double sum); // цей метод виводить результат третього завдання у консоль

int main()
{
    int menu; // змінна за допомогою якого буде перевірятися вибір користувача у меню

    do // цей цикл використовується як меню
    {
        cin >> menu; // кирустувач обирає завдання

        switch (menu)
        {
            case 1: Figure(); break; // перше
            case 2: Formula19(); break; // друге
            case 3: Formula32(); break; // третьє
            case 0: cout << "Bye :)" << endl; break; // вихіді
            default: cout << "only 1, 2 or 3" << endl; break; // користувач захотів обрати неіснуюче завдання
        }
    } while (menu != 0); // нуль це вихід
    

    // програма завершається
    system("pause");
    return 0;
}

void Figure()
{
    int N; // змінна яка виконує роль розміру для масивів а точніше кількість точок

    double r; // змінна радіус

    vector<double> pointsX; // ось х точки
    vector<double> pointsY; // ось у точки

    EnterConsole(pointsX, pointsY, N, r); // ці методи вже описані вишче
    int amountPointsInFigure = AmountPointsInFigure(pointsX, pointsY, N, r);
    Console_Figure(amountPointsInFigure);
}

void EnterConsole(vector<double>& pointsX, vector<double>& pointsY, int& N, double& r)
{
    cout << "Enter n count points: "; // просимо користувача ввести розмір для масивів
    cin >> N; // користува обирає розмір

    pointsX.resize(N); // мінюємо розмір масивів згідно з вибором користувача а точніше кількість точок
    pointsY.resize(N);

    cout << "Enter radius: "; // просимо користувача ввести радіус
    cin >> r; // користувач вводить радіус

    cout << "Enter x and y points"; // просимо користувача ввести осі

    for (int i = 0; i < N; i++) // цикл для зручності а також працю згідно з кількістью точок
    {
        cout << "begin x than y" << endl; // просимо користувача ввести спочатку х а вже потім у
        cin >> pointsX.at(i) >> pointsY.at(i); // корситувач вводить осі
    }
}

int AmountPointsInFigure(vector<double> pointsX, vector<double> pointsY, int N, double r)
{
    int amount = 0; // змінна в які буде зберігатися кількість точок які входять у сектора

    for (int i = 0; i < N; i++) // цикл згідно з кількістью точок
    {
        amount += isPointInSector(pointsX.at(i), pointsY.at(i), r) ? 1 : 0; // програма перевіряє чи точка у секторі?
    }

    return amount; // повертаємо цю кількість
}

void Console_Figure(int amount)
{
    cout << "Amount points in figure: " << amount << endl; // виводимо кількість точок у фігурах або секторах
}

// Основная функция проверки
bool isPointInSector(double x, double y, double r)
{
    double distance = sqrt(x * x + y * y); // склідуємо
    if (distance > r) return false; // не потрапили у радіус значить точно вне будь якої фігури або сектораі

    double angleRad = atan2(y, x);
    double angleDeg = angleRad * 180.0 / M_PI;
    if (angleDeg < 0) angleDeg += 360.0;

    // перевірка двух секторів
    return isAngleInSector(angleDeg, 45.0, 90.0) || isAngleInSector(angleDeg, 90.0, 135.0);
}

bool isAngleInSector(double angleDeg, double startDeg, double endDeg)
{
    return angleDeg >= startDeg && angleDeg <= endDeg; // повертає чи воно у секторах?
}

void Formula19()
{
    double sum = 0.0; // змінна сума

    double x; // змінна х
    int n; // змінна n

    EnterConsole_Formula19(x, n); // ці методи описані вище
    Formula19Calculation(sum, x, n);
    Console_Formula19(sum);
}

void EnterConsole_Formula19(double& x, int& n)
{
    cout << "Enter x and n" << endl; // просимо користувача ввести x а потім n
    cin >> x >> n; // користувач вводить
}

void Formula19Calculation(double& sum, double x, int n)
{
    for (int k = 0; k <= n; k++) // цикл згідно формули
    {
        double element = pow(-1, k) * pow(-M_PI/2+x, 1+2*k)/tgamma(1+2*k+1); // змінна зберігає елемент

        sum += element; // додаємо елемент до загальної суми
        
        if (k % 4 == 0) // кожну четвертий елемент треба вивести у консоль
            cout << "Element k-" << k+1 << " : " << element << endl;
    }
}

void Console_Formula19(double sum)
{
    cout << "your sum: " << sum << endl; // виводимо суму
}

void Formula32()
{
    double e, g; // змінні мала та велика величена

    EnterConsole_Formula32(e, g); // ці методи описані вишче
    double sum = SumSeries(e, g);
    Console_Formula32(sum);
}

void EnterConsole_Formula32(double& e, double& g)
{
    cout << "Enter e: "; // просимо користувача ввести е
    cin >> e; // користувач вводить

    cout << "Enter g: "; // просимо користувача ввести g
    cin >> g; // користувач вводить
}

double SumSeries(double e, double g)
{
    double sum = 0.0; // загальна сума

    for (int n = 1; n <= INFINITY; ++n) //нескінченність тому що формула така
    {
        double term = pow(5, n) / sqrt(n * pow(2, n - 1));

        if (fabs(term) < e) // Перевірка на збіжність (умова |un| < e)
        {
            cout << "|un| < e, end for n: " << n << endl;
            break;
        }

        if (fabs(term) > g) // Перевірка на розбіжність (умова |un| > g)
        {
            cout << "|un| > g, end for n: " << n << endl;
            break;
        }

        sum += term; // додаємо терм до общої суми
    }

    return sum; // повертаємо общу суму
}

void Console_Formula32(double sum)
{
    cout << "sum: " << sum << endl; // виводимо суму
}