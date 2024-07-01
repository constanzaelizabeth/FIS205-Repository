#include <iostream>
#include <iomanip>

using namespace std;

//Se inicializa la clase TrigonometicFunctions
class TrigonometricFunctions{
    
    private:
        //Se definen las variables
        float degree;
        double coseno, seno, tangente, secante, cosecante, cotangente;
        //static const float tol = 0.01;
        static const int max = 500;
        //static double p(double num, double exp);

    public:
        //Función asociada a la clase TrigonometicFunctions que calcula el factorial de n
        double fun(int n){
            if(n==0){return 1;}
            else{return n*fun(n-1);}}

        //Función que calcula el coseno con Series de Taylor
        double Cos(float degree){
            //Inicializa los valores del coseno t 
            double coseno = 0.0;
            double t;
            int i = 0;
            do {
            t = pow(-1, i) * pow(degree, 2 * i) / fun(2 * i);
            coseno = t + 1;
            i = i + 1;}
            while (abs(t) >= 0.01 && i < max);
            return coseno;}

        //Función que calcula el seno con Series de Taylor
        double Sin(float degree){
            double seno = 0.0;
            double t;
            int i = 0;
            do{t = pow(-1,i)*pow(degree, 2*i+1) / fun(2*i+1);
                seno = t+1;
                i = i+1;}
            while(abs(t) >= 0.01 && i<max);
            //seno = degree + (1/3)*degree*degree*degree;
            return seno;}

        //Función que calcula la tangente en base al seno y conseno
        double Tan(float degree){
            tangente = Sin(degree)/Cos(degree);
            return tangente;}

        //Función que calcula la cotangente en base al seno y conseno
        double Cotg(float degree){
            tangente = Cos(degree)/Sin(degree);
            return tangente;}

        //Función que calcula la secante en base al seno y conseno
        double Sec(float degree){
            secante = 1/Cos(degree);
            return secante;}

        //Función que calcula la tangente en base al seno y conseno
        double Cosec(float degree){
            cosecante = 1/Sin(degree);
            return cosecante;}};

//Función principal
int main() {
    //Se define la variable que guardará el grado del polinomio
    float static degree;
    cout << "BUEN  DÍA :)" << endl;
    cout << "Ingresa un valor flotante para calcular las funciones trigonométricas de éste: ";
    cin >> degree;
    //Se inicializa un objeto TFun de la clase TrigonometricFuncions
    TrigonometricFunctions TFun;
    cout << "El seno de " << degree << " es " << setprecision(2) << TFun.Sin(degree) << endl;
    cout << "El coseno de " << degree << " es " << setprecision(2) << TFun.Cos(degree) << endl;
    cout << "La tangente de " << degree << " es " << setprecision(2) << TFun.Tan(degree) << endl;
    cout << "La cotangente de " << degree << " es " << setprecision(2) << TFun.Cotg(degree) << endl;
    cout << "La secante de " << degree << " es " << setprecision(2) << TFun.Sec(degree) << endl;
    cout << "La cosecante de " << degree << " es " << setprecision(2) << TFun.Cosec(degree) << endl;
    return 0;
}