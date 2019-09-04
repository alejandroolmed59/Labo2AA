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

int promedio(){
      int acum=0;
      int contador=0;
      Nodo *aux = inicio;
      while(aux){
        acum+=aux->dato;
        aux=aux->sig;
        contador++;
      }
      return acum/contador;
    }
    int Longitud(){
      Nodo *aux= inicio;
      int cont=0;
      while(aux){
        aux= aux->sig;
        cont++;
      }
      return cont;
    }

    int getPos(int pos){
      Nodo *aux= inicio;
      int cont=0;
      while(aux){
        if(cont ==pos){
          return aux->dato;
        }
        aux = aux->sig;
        cont++;
      }
      return 0;
    }


    Cola(){
      inicio= NULL;
    }
  
};

Cola anniadirMultiplos(Cola cola1, int prom){
  Cola newCola;
  int lenght = cola1.Longitud();
  for(int i=0; i<lenght; i++){
      int dato= cola1.getPos(i);
      if(dato%prom == 0){
          newCola.push(dato);
      }
  }
  return newCola;
}


int main() {
  Cola cola1;
  cola1.push(1);
  cola1.push(2);
  cola1.push(3);
  cola1.push(5);
  cola1.push(6);
  cola1.invertir();
  cola1.mostrarCola();

int promedioCola1= cola1.promedio();
  Cola cola2;
  cola2 = anniadirMultiplos(cola1, promedioCola1);
  cola2.mostrarCola();
}
