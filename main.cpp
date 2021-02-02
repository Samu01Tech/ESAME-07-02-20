#include <iostream>
#include <cstdlib>
#include <cstring>
#define DIM 2
using namespace std;

typedef enum TCarta { CREDITO, DEBITO, PREPAGATA } TCarta;
typedef struct TcartaCliente{
  char coloreR, coloreG, coloreB; 
  float saldo;
  TCarta tipoCarta;
  TcartaCliente(){ 
    saldo = 0.0;
    tipoCarta = CREDITO;
    strcpy(&coloreR, "0");
    strcpy(&coloreG, "0");
    strcpy(&coloreB, "0");
  }
  void stampa() {
    cout << "======================" << endl;
    cout << "Saldo: " << saldo << endl;
    switch(tipoCarta){
      case 0: {
        cout << "Tipo carta: CREDITO" << endl;
        break;
      }
      case 1: {
        cout << "Tipo carta: DEBITO" << endl;
        break;
      }
      case 2: {
        cout << "Tipo carta: PREPAGATA" << endl;
        break;
      }
    }
    cout << "Colore: " << coloreR << coloreG << coloreB << endl;
    cout << "======================" << endl;
  }
} TcartaCliente;
typedef struct TcodaFIFO {
  int n, dim, head, tail;
  TcartaCliente *s;

  TcodaFIFO(){
    dim = DIM;
    n = 0;
    head = 0;
    tail = 0;
    s = new TcartaCliente[DIM];
  }
  TcodaFIFO(int x){
    dim = x;
    n = 0;
    head = 0;
    tail = 0;
    s = new TcartaCliente[x];   
  }
  ~TcodaFIFO(){
    delete [] s;
  }
  void stampa() const{
    if(n == 0){
      cout << "Nesuna carta" << endl;
      return;
    }
    int i = head;
    do{
      s[i].stampa();
      i = ++i  % dim;
    } while(i != tail);
  }
  bool codaIsEmpty(TcodaFIFO* p){
    return n == 0;
  }
  bool codaIsFull(TcodaFIFO* p){
    return n == dim;
  }
} TcodaFIFO;

TcartaCliente* initCarte(TcartaCliente* ca);
bool checkValoreColore(char colore);

int main() {
  TcodaFIFO* carteBanca = new TcodaFIFO(10);
  TcartaCliente* carta;
  /*
  for(int i=0; i<5; i++) { initCarte(&carta); addCarte(carteBanca, carta); }
  stampaCarteBanca(carteBanca);
  printf(“saldoTot=%f\n”, esportaCarte(carteBanca, DEBITO));
  */
  carta = initCarte(carta);
}

TcartaCliente* initCarte(TcartaCliente* ca){
  char inputColore;
  cout << "Creazione carta" << endl;
  cout << "---------------" << endl;
  do{
    cout << "Inserire un carattere: ";
    cin >> inputColore;
  }while(checkValoreColore(inputColore) == 1);
  cout << "colore corretto"<< endl;
}

bool checkValoreColore(char colore){
  if(colore < '0' || colore > '9'){
    if(colore < 'A' || colore > 'F'){
      return 1;
    }
    return 0;
  } else {
    return 0;
  }
}

