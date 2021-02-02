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
    switch(tipoCarta){
      case 0: {
        cout << "CREDITO ";
        break;
      }
      case 1: {
        cout << "DEBITO ";
        break;
      }
      case 2: {
        cout << "PREPAGATA ";
        break;
      }
    }
    cout << "saldoEuro=" << saldo;
    cout << " colore(" << coloreR << coloreG << coloreB << ")" << endl;
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

void initCarte(TcartaCliente *ca);
void addCarte(TcodaFIFO *carteBanca, TcartaCliente ca);
void stampaCarteBanca(TcodaFIFO *carteBanca);
float esportaCarte(TcodaFIFO *carteBanca, TCarta tc);
bool checkValoreColore(char colore);
int random(int max, int min);

int main() {
  TcodaFIFO* carteBanca = new TcodaFIFO(10);
  TcartaCliente carta;
  
  for(int i=0; i<5; i++) { initCarte(&carta); addCarte(carteBanca, carta); }
  stampaCarteBanca(carteBanca);
  printf("saldoTot=%f\n", esportaCarte(carteBanca, DEBITO));
  stampaCarteBanca(carteBanca);
  
}

void initCarte(TcartaCliente *ca){
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
        inputColoreB = random('F', 'A');
        break;
      }
      case 2: {
        inputColoreB = random('9', '0');
        break;
      }
    }
  }while(checkValoreColore(inputColoreB) == 1);
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
  cout << "tipo carta corretto"<< endl;
  ca->coloreR = inputColoreR;
  ca->coloreG = inputColoreG;
  ca->coloreB = inputColoreB;
  ca->saldo = saldo;
  ca->tipoCarta = tipoCarta;
  cout << "Carta creata" << endl;
  cout << endl;
}

void addCarte(TcodaFIFO *carteBanca, TcartaCliente ca){
  carteBanca->n++;
  carteBanca->s[carteBanca->tail] = ca;
  carteBanca->tail++;
  carteBanca->tail = carteBanca->tail % carteBanca->dim;
}

void stampaCarteBanca(TcodaFIFO *carteBanca){
  carteBanca->stampa();
}

float esportaCarte(TcodaFIFO *carteBanca, TCarta tc){
  int sommaCarte;
  char* tipoCartaStringa;
  TcartaCliente carta;
  FILE* file;
  file = fopen("carte.txt", "w");
  if(file == NULL){
    cout << "Errore apertura file" << endl;
  }
  do{
    carta = carteBanca->s[carteBanca->head];
    carteBanca->n--;
    carteBanca->head++;
    carteBanca->head = carteBanca->head % carteBanca->dim;
    if(carta.tipoCarta == tc){
      switch(carta.tipoCarta){
        case CREDITO: {
          strcpy(tipoCartaStringa, "CREDITO");
          break;
        }
        case DEBITO: {
          strcpy(tipoCartaStringa, "DEBITO");
          break;
        }
        case PREPAGATA: {
          strcpy(tipoCartaStringa, "PREPAGATA");
          break;
        }
      }
      fprintf(file, "%s saldoEuro=%f colore(%c, %c, %c) \n", tipoCartaStringa, carta.saldo, carta.coloreR, carta.coloreG, carta.coloreB);
      sommaCarte = sommaCarte + carta.saldo;
    }
  } while(carteBanca->head != carteBanca->tail);
  fclose(file);
  return sommaCarte;
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

