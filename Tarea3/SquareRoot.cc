#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Función que aproxima la raíz cuadrada con el método de Newton-Raphson
float SquareRoot(float Num, float Aprox, float Tol){
    //Crea una variable flotante que almacena el cuadrado de la aproximación realizada
    float Ap = Aprox*Aprox;
    //Compara el error entre la aproximación y el valor con la tolerancia
    if(abs(Ap - Num) < Tol){return Aprox;}
    else{
        //Mejora la aproximación
        float NewAprox = (Aprox + Num/Aprox)/2;
        //Vuelve a llamar a la función
        return SquareRoot(Num, NewAprox, Tol);}}

//Función principal, inicializa los datos y utiliza SquareRoot() para aproximar la raíz
int main(){
    float N = 2.0;
    float A = 1.0;
    float T = 10e-6;
    //Almacena el resultado tras aplicar la función SquareRoot() en una variable flotante
    float Result = SquareRoot(N, A, T);
    cout << fixed << setprecision(6) << Result << endl; //modifica la precisión mostrada en la terminal
    return 0;}