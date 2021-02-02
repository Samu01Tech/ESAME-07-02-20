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
int random(int max, int min);

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
  char inputColoreR, inputColoreG, inputColoreB;
  float saldo;
  TCarta tipoCarta;
  cout << "Creazione carta" << endl;
  cout << "---------------" << endl;
  //coloreR//
  do{
    cout << "Inserire un carattere: ";
    cin >> inputColoreR;
  }while(checkValoreColore(inputColoreR) == 1);
  cout << "caratttere colore R corretto"<< endl;
  //coloreG//
  do{
    switch(random(2, 1)){
      case 1: {
        inputColoreG = random('F', 'A');
        break;
      }
      case 2: {
        inputColoreG = random('9', '0');
        break;
      }
    }
  }while(checkValoreColore(inputColoreG) == 1);
  cout << "caratttere colore G corretto"<< endl;
  //coloreB//
  do{
    switch(random(2, 1)){
      case 1: {
        inputColoreG = random('F', 'A');
        break;
      }
      case 2: {
        inputColoreG = random('9', '0');
        break;
      }
    }
  }while(checkValoreColore(inputColoreG) == 1);
  cout << "caratttere colore B corretto"<< endl;
  //saldo//
  do{
    cout << "Inserire il saldo: ";
    cin >> saldo;
  }while(saldo < 100.00 || saldo > 2000.00);
  cout << "saldo corretto"<< endl;
  //tipo carta//
  switch(random(2, 0)){
    case 0: {
      tipoCarta = CREDITO;
      break;
    }
    case 1: {
      tipoCarta = DEBITO;
      break;
    }
    case 2: {
      tipoCarta = PREPAGATA;
      break;
    }
  }
  cout << "saldo corretto"<< endl;
  ca->coloreR = inputColoreR;
  ca->coloreG = inputColoreG;
  ca->coloreB = inputColoreB;
  ca->saldo = saldo;
  ca->tipoCarta = tipoCarta;
  return ca;
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

int random(int max, int min){
  return rand() % (max - min + 1) + min;
}

