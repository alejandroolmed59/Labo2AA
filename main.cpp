#include <iostream>
using namespace std;

struct Nodo{
  int dato;
  Nodo *sig; 
};

class Cola{
  private:
  Nodo *inicio;
  Nodo *fin;

  public:
    Nodo* crearNodo(int valor){
      Nodo *n = new Nodo;
      n->dato = valor;
      n->sig=nullptr;
      return n;
    }

    void pop(){
    Nodo *temp= inicio;
    inicio = inicio->sig;
    free(temp);
  }


    void mostrarCola(){
      Nodo *temp = inicio;
      if(!inicio)
      cout<<"La list no posee elementos"<<endl;
      else 
      while(temp){
        cout<<temp->dato<<" ";
        temp = temp -> sig;
      }
      cout<<endl;
    }

    void push(int valor){
      Nodo *n = crearNodo(valor),*temp;
      if(!inicio){
        inicio = n;
        fin=n;
      }
      else {
        fin->sig=n;  
        fin=n;
      }
    }
    void invertir(){
      if(!inicio) return; 
      Nodo n = *inicio;
      pop();
      invertir();
      push(n.dato);  
    }


    Cola(){
      inicio= NULL;
    }
  
};



int main() {
  Cola cola1;
  cola1.push(1);
  cola1.push(2);
  cola1.push(3);
  cola1.push(5);
  cola1.push(6);
  cola1.invertir();
  cola1.mostrarCola();
}
