#include <string>
#include <iostream>
//#ifndef T5_P3_h
#define T5_P3_h
using namespace std;

//Se define la clase NodeList que representa un nodo
class NodeList{
    friend class Folder;
    public:
        //Valor del nodo
        int data;
        //Puntero next apunta al siguiente nodo
        NodeList* next;
        NodeList(int n) : data(n), next(nullptr){};};

class List{
    private:
        NodeList* head;
        int size;

    public:
        List();
        void Insert(int n, int i);
        void Delete(int i);
        void Swap(int j, int k);
        void Reverse();
        void Print();};

//#endif;
