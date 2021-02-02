# ESAME-07-02-20

## [A - punti 5] 
Inserire i seguenti tipi in un file dati.h e implementare i metodi di stampa ed i costruttori:
```cpp
#define DIM 2
typedef enum TCarta { CREDITO, DEBITO, PREPAGATA } TCarta;
typedef struct TcartaCliente{
 char coloreR, coloreG, coloreB; float saldo;
 TCarta tipoCarta;
 TcartaCliente () { /*da implementare*/ }
 void stampa() { /*da implementare*/ }
} TcartaCliente;
typedef struct TcodaFIFO {
 int n, dim, head, tail;
 TcartaCliente *s;
 TcodaFIFO () { /*da implementare*/ }
 TcodaFIFO (int x){ /*da implementare*/ }
 void stampa() { /*da implementare*/ }
} TcodaFIFO;
```
## [B - punti 1]
Modificare il file main.cpp includendo il file dati.h ed inserendo il seguente codice nel main:
```cpp
TcodaFIFO* carteBanca = new TcodaFIFO(10);
TcartaCliente carta;
for(int i=0; i<5; i++) { initCarte(&carta); addCarte(carteBanca, carta); }
stampaCarteBanca (carteBanca);
printf(“saldoTot=%f\n”, esportaCarte (carteBanca, DEBITO));
```
## [C - punti 4] 
Implementare una funzione initCarte che riceve in input l’indirizzo di una
variabile di tipo TcartaCliente ca e la inizializza con:
- campo coloreR letta da tastiera valori validi: 0..9 e A..F;
- campi coloreG e coloreB valori casuali tra: 0..9 e A..F;
- campo saldo valore letto da tastiera tra 100,00 e 2000,00;
- campo tipoCarta valore casuale tra CREDITO, DEBITO, PREPAGATA.
## [D - punti 4]
Implementare una funzione addCarte che riceve come input una variabile di
tipo TcodaFIFO *carteBanca, ed una variabile ca di tipo TcartaCliente. La funzione
inserisce nella coda FIFO l’elemento ca. (Inserimento in testa – head)
## [E - punti 2]
Implementare una funzione stampaCarteBanca che riceve come input una
variabile di tipo TcodaFIFO * carteBanca stampa il contenuto della lista utilizzando
opportunamente il metodo stampa di TcodaFIFO nella forma (per l’enum stampare etichetta
in modo opportuno):
```
tipoCarta saldoEuro=saldo colore(coloreR, coloreG, coloreB)
```
## [F - punti 4]
Implementare una funzione esportaCarte che riceve come input una variabile di tipo TcodaFIFO *carteBanca e TCarta tc. 
La funzione elimina tutti gli elementi dalla coda FIFO (cancellazione da coda – tail) ed inserisce in un file “carte.txt” i soli elementi che hanno tipoCarta pari a tc e nella forma:
```
tipoCarta saldoEuro=saldo colore(coloreR, coloreG, coloreB)
```
la funzione inoltre restituisce la somma dei saldi di queste carte.
È possibile creare strutture, funzioni, metodi aggiuntivi per realizzare gli esercizi proposti.
