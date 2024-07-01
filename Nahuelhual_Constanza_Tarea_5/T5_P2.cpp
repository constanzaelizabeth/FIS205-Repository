#include <iostream>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    double matrix[2][2];
public:
    Matrix() {
        for (int i = 0; i < 2; ++i) {
            for (int j=0; j<2; ++j) {
                matrix[i][j] = 0.0;}}}

    //Se define el constructor que crea la matriz
    Matrix(double a, double b, double c, double d) {
        //Se asigna un valor a cada una de las componentes
        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;}

    //Función que calcula el determinante de la matrix
    double Determinant() {
        return matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];}

    //Constructor que calcula la inversa
    Matrix Inverse() {
        //Se calcula el determinante
        double det = Determinant();
        //Condición para que la inversa exista
        if (det == 0) {cout << "La matriz no tiene inversa."<< endl;}
        //Se define el inverso del determinante
        double InvDet = 1.0 / det;
        //Se asignan los valores a la matriz inversa
        Matrix inv(matrix[1][1] * InvDet, -matrix[0][1]*InvDet, -matrix[1][0]*InvDet, matrix[0][0]*InvDet);
        //Devuelve el resultado
        return inv;}

    //Constructor que calcula la suma de las matrices
    Matrix Addition(const Matrix& A) {
        //Se define la matriz que guardará el resultado de la suma
        Matrix add;
        //Ciclo for que recorre las filas de la matriz
        for (int i = 0; i < 2; ++i) {
            //Ciclo for que recorre las columnas
            for (int j = 0; j < 2; ++j) {
                //Suma las matrices por componentes
                add.matrix[i][j] = matrix[i][j] + A.matrix[i][j];}}
        //Devuelve el resultado
        return add;}

    //Constructor que calcula la resta de las matrices
    Matrix Subtract(const Matrix& A) {
        //Se define la matriz que guardará el resultado de la resta
        Matrix sus;
        //Ciclo for que recorre las filas de la matriz
        for (int i = 0; i < 2; ++i) {
            //Ciclo for que recorre las columnas
            for (int j = 0; j < 2; ++j) {
                //Resta las matrices por componentes
                sus.matrix[i][j] = matrix[i][j] - A.matrix[i][j];}}
        //Devuelve el resultado
        return sus;}

    //Constructor que calcula la multiplicación de las matrices
    Matrix Multiply(const Matrix& A) {
        //Se define la matriz que guardará el resultado de la resta
        Matrix mult;
        //Ciclo for que recorre las filas de la matriz
        for (int i = 0; i < 2; ++i) {
            //Ciclo for que recorre las columnas
            for (int j = 0; j < 2; ++j) {
                //Multiplica las matrices y guarda el resultado en mult
                mult.matrix[i][j] = matrix[i][0]*A.matrix[0][j] + matrix[i][1]*A.matrix[1][j];}}
        //Devuelve el resultado
        return mult;}

    //Función que imprime la matriz
    void Print() {
        //Ciclo for que recorre las filas de la matriz
        for (int i = 0; i<2; ++i) {
            //Ciclo for que recorre las columnas
            for (int j=0; j<2; ++j) {
                //Imprime la matriz por componente dejando un espacio entre columnas
                cout << matrix[i][j] << " ";}
            //Salto de línea entre filas
            cout << endl;}}};

//Función principal
int main() {
    //Se definen las componentes de las matrices
    double a, b, c, d, e, f, g, h;
    //Entradas
    cout << "BUEN  DÍA :)" << endl;
    cout << "Escribe las entradas de la matriz 1 en orden por fila: ";
    cin >> a >> b >> c >> d;
    cout << endl;
    cout << "Escribe las entradas de la matriz 2 en orden por fila: ";
    cin >> e >> f >> g >> h;
    cout << endl;
    //Se crean las matrices
    Matrix M1(a, b, c, d);
    Matrix M2(e, f, g, h);
    //Se imprimen las matrices
    cout << "Las matrices son: " << endl;
    M1.Print();
    M2.Print();
    //Se imprimen los resultados llamando a los constructores y las funciones creadas dentro de la clase
    cout << "Las matrices inversas son: " << endl;
    Matrix invM1 = M1.Inverse();
        invM1.Print();
    Matrix invM2 = M2.Inverse();
        invM2.Print();
    cout << "La suma de las matrices es: " << endl;
    Matrix sum = M1.Addition(M2);
    sum.Print();
    cout << "La resta de las matrices es: " << endl;
    Matrix diff = M1.Subtract(M2);
    diff.Print();
    cout << "La multiplicación de las matrices es: " << endl;
    Matrix mult = M1.Multiply(M2);
    mult.Print();

    return 0;
}