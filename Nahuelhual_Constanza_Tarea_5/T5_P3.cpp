#include <iostream>
#include <string>
#include <list>
#include "T5_P3.h"
using namespace std;

//Se define el constructor de la clase List()
//Se inicializa el puntero head a nullptr (es decir, ningún nodo) e inicializa la lista en tamaño 0.
List::List() : head(nullptr), size(0) {};

//Función que inserta los valores al final de la lista
void List::Insert(int n, int i) {
    //Condicional que detecta si la posición no pertenece a la lista
    if (i<0 || i>size) {
        cout << "Error en la posición" << endl;
        return;}
    //Se declara un nodo de la lista NodeList al que se le asigna una memoria nueva a un nuevo
    NodeList* node = new NodeList(n);
    if(i==0){
        //Se crea un nuevo nodo que será el primero de la lista (head)
        node->next = head;
        head = node;}
    else {
        //Se declara el puntero now que apunta al nodo que apunta head
        NodeList* now = head;
        //Ciclo for que recorre la lista enlazada
        for(int j = 0; j<i-1; ++j){
            //Actualiza el nodo now con el siguiente nodo en la lista
            now = now->next;}
        //next apuntará al siguiente nodo en now
        node->next = now->next;
        //Se actualiza el puntero next asignándole el nuevo nodo
        now->next = node;
    }
    //Aumenta el tamaño de la lista
    size++;
    cout << "Elemento " << n << " insertado en la posición " << i << endl;
}

//Función que elimina el nodo en la posición i de la lista
void List::Delete(int i) {
    //Condicional que detecta si la posición no corresponde a la lista
    if (i<0 || i>=size) {
        cout << "Posición inválida. Tamaño de la lista: " << size << endl;
        return;}
    //Puntero del que apunta al primer nodo de la lista
    NodeList* del = head;
    //Si la posición es la primera (head) se elimina
    if (i==0) {head = head->next;}
    else {
        //Se define como nulo el nodo anterior al que se debe eliminar
        NodeList* ant = nullptr;
        //Ciclo for que "busca" la posición a eliminar
        for (int j = 0; j<i; ++j) {
            //Se guarda el nodo anterior
            ant = del;
            //Se actualiza al siguiente nodo
            del = del->next;}
        //El siguiente del anterior es el que se debe eliminar
        ant->next = del->next;}
    //Se elimina
    delete del;
    //Disminuye el largo de la lista
    size--;
    //Se "printea" la lista
    Print();
}

//Función que cambia el término en la posición j por el término en k 
void List::Swap(int j, int k) {
    //Condicional que verifica si la posición existe dentro de la lista
    if (j<0 && j>=size || k<0 || k>=size) {
        cout << "Error en la posición" << endl;
        return;}
    //Condicional que ve si las posiciones son iguales
    if (j==k) {
        cout << "Las posiciones son iguales" << endl;
        return;}
    //Se crean los punteros nj y nk que apuntan al primer término de la lista
    NodeList* nj= head;
    NodeList* nk = head;
    //Ciclos for que recorren la lista buscando las posiciones j y k
    for (int m = 0; m<j; ++m) {
        nj = nj->next;}
    for (int m = 0; m<k; ++m) {
        nk = nk->next;}
    //Se define la variable que almacena el nodo
    int x = nj->data;
    //Se intercambian los nodos (nk ahora es nk)
    nj->data = nk->data;
    //(nk es nj)
    nk->data = x;}

//Función asociada a la clase List que "da vuelta" la lista
void List::Reverse() {
    //Condicional que verifica que existe más de un elemento
    if (size <= 1) {return;}
    //Se definen los nodos a utilizar (como se realizó anteriormente)
    //ant es el nodo anterior, se inicializa como nulo
    NodeList* ant = nullptr;
    //now es el nodo que se está utilizando, se inicializa con el primer valor
    NodeList* now = head;
    //next es el siguiente nodo, se inicializa como nulo
    NodeList* next = nullptr;
    //Ciclo while que recorre la lista
    while (now != nullptr) {
        //Se define el nodo next
        next = now->next;
        //next apuntará al anterior
        now->next = ant;
        //El nodo anterior será el actual
        ant = now;
        //el nodo actual será el siguiente
        now = next;}
    //El primero será el último
    head = ant;
}

//Función asociada que imprime la lista
void List::Print() {
    //Se define now que apunta a head
    NodeList* now = head;
    //Ciclo while que recorre la lista nodo a nodo imprimiéndolos
    while (now != nullptr) {
        cout << now->data << " ";
        now = now->next;}
    cout << endl;
}

//Función principal
int main(){
    //Se declaran las variables
    int num, data, i, n;
    //Se inicializa el objeto L de la clase List
    List L;
    //Texto en pantalla
    cout << "BUEN  DÍA :)" << endl;
    cout << "Escribe la cantidad de datos que deseas en la lista :";
    cin >> num;
    cout << "Escribe los enteros que deseas agregar a la lista: ";
    //Ciclo for que crea la lista
    for(int i=0; i<num; ++i){
        cin >> data;
        L.Insert(data, i);}
    cout << "La lista original es: ";
    L.Print();
    //Imprime los datos solicitados utilizando las funciones asociadas a la clase List
    cout << "Escribe que deseas insertar en la lista: " << endl;
    cin >> n;
    cout << "Escribe la posición en la que deseas insertar el valor: " << endl;
    cin >> i;
    cout << endl;
    L.Insert(n, i);
    cout << "Lista actual: ";
    L.Print();
    cout << endl;
    int j, k;
    cout << "Escribe las posiciones que deseas cambiar: ";
    cin >> j >> k;
    L.Swap(j, k);
    cout << "Lista actual: ";
    L.Print();
    cout << "La lista al revés es: ";
    L.Reverse();
    L.Print();

    return 0;
}