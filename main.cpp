#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <windows.h>
#include "Funciones.h"
#define TAM 10
#define PRECISION 6
#define INTERVALOS 10
#define MAX_ITERACIONES 100
using namespace std;


int main()
{
    carga();
    marco();

    int opcion;

    do
    {
        system("cls");

        gotoxy (19, 2); printf("%c %c %c    %c %c %c     %c %c %c    %c       %c   %c %c %c %c     %c %c %c    %c %c %c %c %c    %c %c %c  ", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
        gotoxy (19, 3); printf("%c    %c   %c    %c   %c     %c    %c     %c    %c          %c     %c       %c       %c     %c   ", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
        gotoxy (19, 4); printf("%c    %c   %c    %c   %c     %c     %c   %c     %c          %c             %c       %c     %c     ", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
        gotoxy (19, 5); printf("%c    %c   %c    %c   %c     %c       %c       %c %c %c %c    %c             %c       %c     %c     ", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
        gotoxy (19, 6); printf("%c %c %c    %c %c %c    %c     %c       %c       %c          %c             %c       %c     %c    ", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
        gotoxy (19, 7); printf("%c        %c %c      %c     %c       %c       %c          %c             %c       %c     %c        ", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
        gotoxy (19, 8); printf("%c        %c  %c     %c     %c       %c       %c          %c     %c       %c       %c     %c     ", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
        gotoxy (19, 9); printf("%c        %c   %c     %c %c %c        %c       %c %c %c %c     %c %c %c        %c        %c %c %c", 220, 220, 220, 220, 220);

        for (int a = 4; a <= 114; a++)
        {
            gotoxy (a, 11); printf("%c", 223);
        }

        for (int a = 4; a <= 114; a++)
        {
            gotoxy (a, 1); printf("%c", 223);
        }

        for (int a = 1; a <= 10; a++)
        {
            gotoxy (114, a); printf("%c", 219);
        }

        for (int a = 1; a <= 10; a++)
        {
            gotoxy (4, a); printf("%c", 219);
        }


        gotoxy (43, 13); cout << "         MENU DE OPCIONES";
        gotoxy (43, 15); cout << "1. Metodo de Biseccion del Intervalo";
        gotoxy (43, 16); cout << "2. Metodo de Newton Raphson";
        gotoxy (43, 17); cout << "3. Metodo de la Secante";
        gotoxy (43, 18); cout << "4. Metodo de Birge Vieta";
        gotoxy (43, 19); cout << "5. Metodo de Lin Bairstow";
        gotoxy (43, 20); cout << "0. Para salir";
        gotoxy (43, 22);
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            system("cls");
            printf("\nRecuerda definir tu Funcion antes de utilizar el Programa\n\n");
            system("PAUSE");
            system("cls");

            cout << setprecision(PRECISION);

            double a, b, tolerancia, errorA;
            int cont = 1, aux = 33;

            cout << "\t\tMETODO DE BISECCION DEL INTERVALO" << endl;
            cout << "\nIngrese el intervalo inicial [a, b]" << endl;
            cout << "\na = ";
            cin >> a;

            cout << "b = ";
            cin >> b;

            imprimePuntos(a, b);

            cout << "\nEscoje el intervalo adecuado" << endl;
            cout << "\na = ";
            cin >> a;

            cout << "b = ";
            cin >> b;

            float xr;

            cout << "\nf(" << a << ") = " << f(a) << endl;
            cout << "f(" << b << ") = " << f(b) << endl;


            if (f(a) * f(b) > 0)
            {
                system("cls");
                cout << "\nNo se puede aplicar el Metodo de Biseccion del Intervalo\n";
                cout << "Porque f(" << a << ") y f(" << b << ") tienen el mismo signo" << endl;
            }
            else
            {
                cout << "\nDame 't' para el Error Estimado = ";
                cin >> tolerancia;

                tolerancia = (0.5 * pow(10, 2-tolerancia));

                cout << "\nITERACION\ta             b              f(a)            f(b)         a+b/2         f(a+b/2)           Ea\n" << endl;

                do
                {
                    xr = (a + b) / 2.0;
                    errorA = fabs((xr - a)/xr) * 100;

                    gotoxy(0, aux);
                    printf("%i", cont);
                    gotoxy(12, aux);
                    printf("%.6f", a);
                    gotoxy(27, aux);
                    printf("%.6f", b);
                    gotoxy(42, aux);
                    printf("%.6f", f(a));
                    gotoxy(58, aux);
                    printf("%.6f", f(b));
                    gotoxy(73, aux);
                    printf("%.6f", xr);
                    gotoxy(88, aux);
                    printf("%.6f", f(xr));
                    gotoxy(104, aux);
                    printf("%.6f", errorA);

                    if (errorA <= tolerancia)
                    {
                        cout << "\n\nPara un Error Estimado de: " << tolerancia << "\nLa aproximacion de la Raiz es: " << xr << "\n\n";

                        break;
                    }
                    else
                    {
                        if (f(xr) * f(a) > 0)
                        {
                            a = xr;
                        }
                        else if (f(xr) * f(b) > 0)
                        {
                            b = xr;
                        }
                    }

                    cont++;
                    aux++;
                }
                while (1);
            }

            system("PAUSE");
        }

        break;
        case 2:
        {
            system("cls");
            printf("\nRecuerda definir tu Funcion antes de utilizar el Programa\n\n");
            system("PAUSE");
            system("cls");

            double a;
            double b;
            double tolerancia;
            double x0;
            double x1;
            double errorA;
            int iteracion = 1;
            bool converge = true;

            int aux = 29;

            cout << setprecision(PRECISION);
            printf("\t\tMETODO DE NEWTON RAPHSON\n");
            cout << "\nIngrese el intervalo inicial [a, b]:" << endl;

            cout << "\na = ";
            cin >> a;

            cout << "b = ";
            cin >> b;

            imprimePuntos(a, b);

            cout << "\nEscoja el punto inicial adecuado:   Xn = ";
            cin >> x0;

            cout << "\nDame 't' para el Error Estimado\n";
            cin >> tolerancia;

            tolerancia = (0.5 * pow(10, 2-tolerancia));

            cout << "\n\nITERACION\tXn            f(Xn)          f'(Xn)          Xn+1             Ea\n" << endl;

            do
            {

                if (iteracion > MAX_ITERACIONES)
                {
                    converge = false;
                    break;
                }
                else
                {
                    x1 = x0 - f(x0) / f_derivada(x0);
                    errorA = fabs((x1 - x0)/x1) * 100;


                    gotoxy(0, aux);
                    printf("%i", iteracion);
                    gotoxy(13, aux);
                    printf("%.6f", x0);
                    gotoxy(28, aux);
                    printf("%.6f", f(x0));
                    gotoxy(43, aux);
                    printf("%.6f", f_derivada(x0));
                    gotoxy(59, aux);
                    printf("%.6f", x1);
                    gotoxy(75, aux);
                    printf("%.6f", errorA);


                    if (errorA <= tolerancia)
                    {
                        converge = true;
                        break;
                    }
                    else
                    {
                        x0 = x1;
                        iteracion++;
                        aux++;
                    }
                }

            }
            while (1);

            if (converge)
            {
                printf("\n\n\nPara un Error Estimado de: %.6f\nLa aproximacion de la Raiz es: %.6f\n\n", tolerancia, x1);
            }
            else
            {
                cout << "\n\n\nSe sobrepasó la máxima cantidad de iteraciones permitidas" << endl;
            }

            system("PAUSE");
        }

        break;
        case 3:
        {
            system("cls");
            printf("\nRecuerda definir tu Funcion antes de utilizar el Programa\n\n");
            system("PAUSE");
            system("cls");

            double a, b, c, t, errorA;
            int count = 1, n, aux = 17;

            printf("\t\tMETODO DE LA SECANTE\n");

            printf("\nIntroduce el valor de Xn-1:\n");
            scanf("%lf", &a);

            printf("\nIntroduce el valor de Xn:\n");
            scanf("%lf", &b);

            printf("\nIntroduce 't' para el Error Estimado:\n");
            scanf("%lf", &t);

            printf("\nIntroduce el numero maximo de iteraciones:\n");
            scanf("%i", &n);

            t = (0.5 * pow(10, 2-t));

            printf("\n\n");

            printf("ITERACION      Xn-1            Xn           f(Xn-1)          f(Xn)           Xn+1             Ea\n");

            do
            {
                if (f(a) == f(b))
                {
                    system("cls");
                    printf("\nLa solucion no puede ser encontrada debido a que los valores de Xn-1 y Xn son iguales\n");
                    return 0;
                }

                c = (a*f(b)-b*f(a))/(f(b)-f(a));
                errorA = fabs((c - b)/(c)) * 100;

                gotoxy(0, aux);
                printf("%i", count);
                gotoxy(13, aux);
                printf("%.6f", a);
                gotoxy(28, aux);
                printf("%.6f", b);
                gotoxy(43, aux);
                printf("%.6f", f(a));
                gotoxy(59, aux);
                printf("%.6f", f(b));
                gotoxy(75, aux);
                printf("%.6f", c);
                gotoxy(91, aux);
                printf("%.6f", errorA);

                a = b;
                b = c;

                count++;
                aux++;

                if (count == n+1)
                {
                    break;
                }
            }
            while (errorA > t);

            printf("\n\n\nPara un Error Estimado de: %.6f\nLa aproximacion de la Raiz es: %.6f\n\n", t, c);

            system("PAUSE");
        }

        break;
        case 4:
        {
            system("cls");

            int m, flag = 0, aux = 0;
            float r, x, x1, fx, fdx, t1, errorA;

            printf("\t\tMETODO DE BIRGE-VIETA\n");
            printf("\nIntroduce el grado mas grande de la Ecuacion: ");
            scanf("%d", &m);

            for (int i = 0; i <= m; i++)
            {
                printf("\nCoeficiente x[%d] = ", m-i);
                scanf("%f", &p[i]);
                ply[i] = p[i];
            }

            printf("\nIntroduce el valor de Xn: ");
            scanf("%f", &r);
            x = r;

            printf("\nDame t para el Error Estimado\n");
            cin >> t1;

            t1 = (0.5 * pow(10, 2-t1));
            errorA = fabs((x - r)/(x)) * 100;


            do
            {
                aux += 1;

                printf("\n---------------------------------------------------------------------\n");
                printf("\nITERACION %i \t\t\t\t\t Xn+1 = %f\n", aux, x);

                fx = sintetica(m, x);

                for (int i = 0; i <= m; i++)
                    p[i] = q[i];

                fdx = sintetica(m-1, x);
                x1 = x - (fx/fdx);

                errorA = fabs((x1 - x)/(x1)) * 100;
                printf("\n\nError Absoluto: %f\n", errorA);

                if (errorA <= t1)
                    flag = 1;

                x = x1;

                for (int i = 0; i <= TAM-1; i++)
                    p[i] = ply[i];


            }
            while(flag != 1);

            printf("\n---------------------------------------------------------------------\n");
            printf("\nPara un Error Estimado de: %.6f\nLa aproximacion de la Raiz es: %.6f\n\n", t1, x1);

            system("PAUSE");
        }

        break;
        case 5:
        {
            system("cls");
            printf("\t\tMETODO DE LIN BAIRSTOW\n\n");

            int n, m, w, np, contadorConver, k, z, nx, mx;
            float r, s, e, dr, ds, error, newsize, r0, s0;
            cout << "Introduce el grado del Polinomo: " << endl;
            cin >> n;

            n++;
            w = contadorConver = z = 0; //w es el contador de veces que se repite el proceso (no solo la division, todo el proceso)
            m = n-1;

            float C[n], Mr[n], Ms[n], Mat1[n], Mat2[m], raizReal[n], raizImaginaria[n];
            float raiz;

            for (int i = 0; i < n; i++)
            {
                Mr[i] = Ms[i] = Mat1[i] = raizReal[i] = raizImaginaria[i] = 0;
            }

            cout << "\nIntroduzca los coeficientes del Polinomio (El primer coeficiente debe ser 1)" << endl;

            for (int i = 0; i < n; i++)
            {
                cout << "\nIntroduzca el coeficiente de x^" << -i+(n-1) << " :" << endl;
                cin >> C[i];
            }

            if (C[0] != 1)
            {
                system("cls");
                cout << "El coeficiente de x^" << n-1 << " debe ser = 1 " << endl;
                return 0;
            }
            else
            {
                cout << endl << "Introduce el Valor Inicial de r: " << endl;
                cin >> r0;
                cout << endl << "Introduce el Valor Inicial de s: " << endl;
                cin >> s0;
                cout << endl << "Introduzca el valor del Error de Convergencia: " << endl;
                cin >> error;
                cout << endl << "Introduzca numero maximo de iteraciones: " << endl;
                cin >> k;
                dr = ds = 1;

                for (int j = 0; j < 2*(n-1); j = j+2)		// Se necesita sumarle 2 al contador dado que en cada paso se guardan 2 valores en las raices (j y j+1)
                {
                    dr = ds = 1;
                    np = (n-1) - 2*w; // np es el grado del polinomio a dividir
                    nx = n-1 - 2*w;
                    mx = nx-1;
                    if (np <= 2)
                    {
                        if (np == 2)
                        {
                            raiz = (C[1] * C[1])-(4 * C[2]);
                            if (raiz < 0)
                            {
                                raiz = abs(raiz);
                                raizReal[j] = (-C[1])/2;
                                raizReal[j+1] = (-C[1])/2;
                                raizImaginaria[j] = sqrt(raiz)/2;
                                raizImaginaria[j+1] = -sqrt(raiz)/2;
                            }
                            else
                            {
                                raizReal[j] = ((-C[1])+(sqrt(raiz)))/2;
                                raizReal[j+1] = ((-C[1])-(sqrt(raiz)))/2;
                                raizImaginaria[j] = 0;
                                raizImaginaria[j+1] = 0;
                            }
                        }
                        else
                        {
                            raizReal[j] = -C[1];
                        }
                        break;
                    }
                    else
                    {
                        contadorConver = 0;
                        r = r0;
                        s = s0;
                        for (int i = 0; i<= np; i++)
                        {
                            Mr[i] = Ms[i] = Mat1[i] = Mat2[i] = 0;
                        }

                        do
                        {
                            for (int i = 0; i <= np ; i++) // PRIMERA DIVISION SINTETICA
                            {
                                Mat1[i] = C[i] + Mr[i] + Ms[i];
                                Mr[i+1] = (-r)*(Mat1[i]);
                                Ms[i+2] = (-s)*(Mat1[i]);
                            }
                            for (int i = 0; i<= np; i++)
                            {
                                Mr[i] = Ms[i] = 0;
                            }
                            for (int i = 0; i < np; i++) // SEGUNDA DIVISION SINTETICA
                            {
                                Mat2[i] = -Mat1[i] + Mr[i] + Ms[i];
                                Mr[i+1] = (-r)*(Mat2[i]);
                                Ms[i+2] = (-s)*(Mat2[i]);
                            }
                            dr = (((Mat2[mx-1])*(-Mat1[nx-1]))-((-Mat1[nx])*(Mat2[mx-2])))/(((Mat2[mx-1])*(Mat2[mx-1]))-((Mat2[mx]+Mat1[nx-1])*(Mat2[mx-2])));	//cramer
                            ds = (((-Mat1[nx])*(Mat2[mx-1]))-((Mat2[mx]+Mat1[nx-1])*(-Mat1[nx-1])))/(((Mat2[mx-1])*(Mat2[mx-1]))-((Mat2[mx]+Mat1[nx-1])*(Mat2[mx-2])));	//cramer
                            r = r+dr;
                            s = s+ds;
                            contadorConver++;
                            if (contadorConver > k)
                            {
                                system("cls");
                                cout << "Fallo en la convergencia" << endl;
                                break;
                            }
                            z++;
                        }
                        while ((abs(dr/r))*100 > error && (abs(ds/s))*100 > error);

                        raiz = (r*r)-(4*s);
                        if (raiz < 0)
                        {
                            raiz = abs(raiz);
                            raizReal[j] = -r/2;
                            raizReal[j+1] = -r/2;
                            raizImaginaria[j] = sqrt(raiz)/2;
                            raizImaginaria[j+1] = -sqrt(raiz)/2;
                        }
                        else
                        {
                            raizReal[j] = ((-r)+(sqrt(raiz)))/2;
                            raizReal[j+1] = ((-r)-(sqrt(raiz)))/2;
                            raizImaginaria[j] = 0;
                            raizImaginaria[j+1] = 0;
                        }
                        w++;
                        newsize = (n-1)-(2*w);
                        for (int i = 0; i <= newsize; i++)
                        {
                            C[i] = Mat1[i];
                        }
                    }
                }
                cout << "\n\nLas Raices aproximadas son:" << endl << endl;
                for (int i = 0 ; i < n-1; i++)
                {
                    if (raizImaginaria[i] == 0)
                    {
                        cout << "X" << i + 1 << " = " << raizReal[i] << endl;
                    }
                    else
                    {
                        cout << "X" << i + 1 << " = " << raizReal[i];
                        if (raizImaginaria[i] < 0)
                        {
                            cout << " " << raizImaginaria[i] << "i" << endl;
                        }
                        else
                        {
                            cout << " + " << raizImaginaria[i] << "i" << endl;
                        }
                    }
                }
            }

            printf("\n");
            system("PAUSE");
            break;
        }
        case 0:
            system("cls");
            break;
        }

    }
    while(opcion != 0);

    system("PAUSE");
    return 0;
}
