#include <iostream>
#define TAM 10
#define PRECISION 6
#define INTERVALOS 10
using namespace std;

float p[TAM], ply[TAM], q[TAM];


//FUNCIONES A DEFINIR
double f(double x)
{
    return (x*x*x) + (2*x*x) + (10*x) - 20;
}

double f_derivada(double x)
{
    return (3*x*x) + (4*x) + 10;
}


float sintetica(int m, float r)
{
    q[0] = p[0];
    for (int i = 1; i <= m; i++)
        q[i] = (q[i-1] * r) + p[i];

    printf("\n");
    for (int i = 0; i < m; i++)
        printf("\t%f", q[i]);

    printf("\t%f", q[m]);

    return (q[m]);
}

void gotoxy (int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void imprimePuntos(double a, double b)
{
    int puntos = INTERVALOS + 1;
    double ancho = (b - a) / INTERVALOS;

    cout << "\n";
    cout << "\tx\t\tf(x)\n" << endl;

    for (int i = 0; i < puntos; i++)
    {
        cout << "\t" << a << "\t\t" << f(a) << endl;
        a = a + ancho;
    }
}

void carga()
{
    int c, m = 27;
    system("cls");
    system("color F0");

    for (int a = 21; a <= 96; a++)
    {
        gotoxy (a, 7);
        printf("%c", 223);
    }

    for (int a = 21; a <= 96; a++)
    {
        gotoxy (a, 20);
        printf("%c", 223);
    }

    for (int a = 7; a <= 19; a++)
    {
        gotoxy (21, a);
        printf("%c", 219);
    }

    for (int a = 7; a <= 19; a++)
    {
        gotoxy (96, a);
        printf("%c", 219);
    }

    gotoxy (55, 10);
    printf("CARGANDO...");
    Sleep(200);
    for(c = 40; c <= 100; c++)
    {
        m++;
        gotoxy (m, 14);
        printf("%c", 219);
        Sleep(20);
    }
    printf("\a");
    system("cls");
}

void marco()
{
    for (int a = 3; a <= 116; a++)
    {
        gotoxy (a, 1);
        printf("%c", 223);
    }

    for (int a = 3; a <= 116; a++)
    {
        gotoxy (a, 11);
        printf("%c", 223);
    }

    for (int a = 1; a <= 10; a++)
    {
        gotoxy (3, a);
        printf("%c", 219);
    }

    for (int a = 1; a <= 10; a++)
    {
        gotoxy (116, a);
        printf("%c", 219);
    }
}
