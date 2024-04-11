#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

//Función que recibe la palabra y el archivo.dat a crear
//Esta define si la pabra es palíndrome o no
void Palindrome(string String, ofstream &archive){
    //Almacena la palabra en otra variable
    string StringR = String;
    string Si = " es un palindrome";
    string No = " no es un palindrome";
    //Da vuelta la palabra en la nueva variable
    reverse(StringR.begin(), StringR.end());
    //Compara ambas palabras
    if(StringR == String){
        //Guarda el resultado en un archivo
        archive << String << Si << endl;
        //Imprime el resultado en la terminal
        cout << String << Si << endl;}
    else{
        //Guarda el resultado en un archivo
        archive << String << No << endl;
        //Imprime el resultado en la terminal
        cout << String << No << endl;}
        return;}

int main(){
    //Crea el archivo.dat para almacenar los resultados
    ofstream archive("Palindrome¿.dat", ios::out|ios::binary);
    if(!archive){
        //Informa si ocurre un error al crear el archivo
        cout << "Error al abrir el archivo" << endl;
        return 1;}
    bool i = true;
    //Da la instrucción para salir
    cout << "Escribe exit si deseas terminar." << endl;
    while(i){
        string String;
        //Instrucción
        cout << "Escribe una palabra: ";
        //Almacena la palabra en una variable
        cin >> String;
        //Utiliza la función Palindrome() con entradas la palabra y el archivo a redactar
        Palindrome(String, archive);
        //Salida del input
        if(String == "exit"){
            i = false;}    
        }
    //Cierra el archivo
    archive.close();
    cout << "Archivo Palindorme¿.dat ha sido creado" << endl;
    return 0;}

