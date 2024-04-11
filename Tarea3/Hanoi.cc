#include <iostream>
#include <cmath>

using namespace std;

//Función que imprime las instrucciones para resolver la Torre de Hanoi
void Move(int Num, string A, string C, string B){
    if(Num == 1){
        cout << "Mover anillo " << Num << " desde " << A << " hasta " << C << endl;}
    else{
        //LLama a la función con entradas: A como la torre inicial, B como la torre de llegada y C como la auxiliar
        Move(Num - 1, A, B, C);
        cout << "Mover anillo " << Num << " desde " << A << " hasta " << C << endl;
        //LLama a la función con entradas: B como la torre inicial, C como la torre de llegada y A como la auxiliar
        Move(Num - 1, B, C, A);}}
        
//Función principal
int main(){
    //Se definen las variables
    int Num;
    string A = "A";
    string B = "B";
    string C = "C";
    //Instrucciones en la terminal
    cout << "Indica el número de anillos: ";
    cin >> Num;
    cout << "Pasos a seguir para resolver la Torre de Hanoi con " << Num << " anillos" << endl;
    //Llama a la función que imprime las instrucciones con entradas el número de anillos;
    //A como la torre de inicio de los anillos, C la torre de llegada y B la auxiliar
    Move(Num, A, C, B);
    return 0;}
    