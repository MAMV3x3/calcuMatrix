/**
 * @file MatrixC.cpp
 * @author Miguel Mireles, Ricardo Israel, Julio Valencia
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int x,int y){   
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),dwPos);  
} 

void SumOp(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    int m, n;;
    cout << "Introduzca el numero de filas: ";
    cin >> m;
    cout << "Introduzca el numero de columnas: ";
    cin >> n;
    float A[m][n], B[m][n], C[m][n];
    cout << "\n[!] Digite los datos de la matriz A: " << endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            gotoxy(j*5+1, i + 8);
            cin >> A[i][j];
        }
    }
    cout << "\n[!] Digite los datos de la matriz B: " << endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            gotoxy(j*5+1, i + 11 + m);
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    cout << "\n[!] El resultado de la operacion es: " << endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            gotoxy(j*5+1, i + 2*m + 14);
            cout << C[i][j];
        }
    }
    cout << "\n\n[!] Pulse ENTER para volver al menu" << endl;
    system("pause>nul");
}

void ResOp(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    int m, n;;
    cout << "Introduzca el numero de filas: ";
    cin >> m;
    cout << "Introduzca el numero de columnas: ";
    cin >> n;
    float A[m][n], B[m][n], C[m][n];
    cout << "\n[!] Digite los datos de la matriz A: " << endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            gotoxy(j*5+1, i + 8);
            cin >> A[i][j];
        }
    }
    cout << "\n[!] Digite los datos de la matriz B: " << endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            gotoxy(j*5+1, i + 11 + m);
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    cout << "\n[!] El resultado de la operacion es: "<< endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            gotoxy(j*5+1, i + 2*m + 14);
            cout << C[i][j];
        }
    }
    cout << "\n\n[!] Pulse ENTER para volver al menu" << endl;
    system("pause>nul");
}

void MultOp(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    int m, n, o, p;
    cout << "Introduzca el numero de filas de la matriz A: ";
    cin >> m;
    cout << "Introduzca el numero de columnas de la matriz A: ";
    cin >> n;
    cout << "Introduzca el numero de filas de la matriz B: ";
    cin >> o;
    cout << "Introduzca el numero de columnas de la matriz B: ";
    cin >> p;
    float A[m][n], B[o][p], C[m][n];
    if(n == o){
        cout << "\n[!] Digite los datos de la matriz A: " << endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            gotoxy(j*5+1, i + 10);
            cin >> A[i][j];
        }
    }
    cout << "\n[!] Digite los datos de la matriz B: " << endl;
    for (int i = 0; i < o; i++){
        for(int j = 0; j < p; j++){
            gotoxy(j*5+1, i + 12 + o);
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){ 
            C[i][j] = 0;
            for (int k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
       }
    }
    cout << "\n[!] El resultado de la operacion es: "<< endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            gotoxy(j*5+1, i + 2*m + 17);
            cout << C[i][j];
        }
    }
    cout << "\n\n[!] Pulse ENTER para volver al menu" << endl;
    system("pause>nul");
    }
    else{
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n[!] La operación no se puede realizar: "<< endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "\n\n[!] Pulse ENTER para volver al menu" << endl;
        system("pause>nul");
    }
}

void InverOp(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
    int m;
    cout << "Introduzca las filas y columnas de la matriz: ";
    cin >> m;
    double A[m][m], I[m][m], aux = 0, pivote = 0;
    cout << "\n[!] Digite los datos de la matriz a invertir: " << endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            gotoxy(j*5+1, i + 7);
            cin >> A[i][j];
            I[i][j] = 0;
            if(i == j){
                I[i][j] = 1;
            }
        }
    }
    //Aplicacion de inversa de matriz, reduccion por renglones:
    for (int i = 0; i < m; i++){
        pivote = A[i][i];
        //Convertir el pivote a 1 y aplicar operacion en toda la fila
        for(int k = 0; k < m; k++){
            A[i][k] = A[i][k]/pivote;
            I[i][k] = I[i][k]/pivote;
        }
        for(int j = 0; j < m; j++){
            if(i != j){
                aux = A[j][i];
                for(int k = 0; k < m; k++){
                    A[j][k]=A[j][k] - aux*A[i][k];
                    I[j][k]=I[j][k] - aux*I[i][k];
                }
            }
        }
    }
    cout << "\n[!] La matriz invertida es: "<< endl;
    for (int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            gotoxy(j*10+1, i + 2*m + 7);
            cout << I[i][j];
        }
    }
    cout << "\n\n[!] Pulse ENTER para volver al menu" << endl;
    system("pause>nul");
}

int main(void){
    system( "color 0F" );
    bool cycle = true;
    bool noVal = false;
    int op;

    do{
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 7);
        system("cls");

        cout << "           CALCULADORA DE MATRICES" << endl;
        cout << "       -------------------------------" << endl;
        cout << "\n[!] Seleccione una opcion del menu: \n" << endl;
        cout << " 1. Suma de matrices ( m x n )" << endl;
        cout << " 2. Resta de matrices ( m x n )" << endl;
        cout << " 3. Multiplicacion de matrices ( m x n )" << endl;
        cout << " 4. Matriz inversa ( m x m )" << endl;
        cout << " 5. Sistemas de ecuaciones ( Gauss - Jordan )" << endl;
        cout << " 6. Factorizacion LU" << endl;
        cout << " 0. Salir" << endl;
        cout << "\n >> ";
        cin >> op;

        switch (op){
        case 1:
            system("cls");
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\n[!] Suma de matrices \n" << endl;
            SumOp();
            break;
        case 2:
            system("cls");
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\n[!] Resta de matrices \n" << endl;
            ResOp();
            break;
        case 3:
            system("cls");
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\n[!] Multiplicacion de matrices \n" << endl;
            MultOp();
            break;
        case 4:
            system("cls");
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\n[!] Invertir Matriz \n" << endl;
            InverOp();
            break;
        case 5:
            //Sistema
            //En progreso
            break;
        case 6:
            //LU
            //En progreso
            break;
        case 0:
            cout << "\n[!] Finalizando programa\n" << endl;
            cycle = false;
            break;
        default:
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\n[!] Opcion ingresada no valida\n" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "[!] Pulse ENTER para volver al menu" << endl;
            system("pause>nul");
            break;
        }

    } while(cycle);
}