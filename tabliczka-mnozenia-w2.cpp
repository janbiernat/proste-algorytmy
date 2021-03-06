#include <iostream> /*Biblioteka "iostream" (ang. input/output stream) 
                      oznacza strumień wejścia/wyjścia. 
                      Za pomocą tej biblioteki można m.in. wprowadzać 
                      informacje ze standardowych urządzeń 
                      wejścia (klawiatura) lub wyprowadzać 
                      informacje ze standardowych urządzeń 
                      wyjścia (ekran).*/ 
#include <conio.h>  /*Obsługa klawiatury za pomocą.*/ 
#include <cstdlib>  /*Posiada m.in. instrukcje do zainicjowania generatora liczb pseudolosowych.*/ 
#include <ctime>    /*Biblioteka "ctime " zawiera funkcje związane z obsługą czasu i daty.*/ 
#include <string.h> /*Podłączenie biblioteki umożliwiającej obsługę łańcuchów znaków.*/ 
/*--== Borland C++Builder (Console Application) ==-- 
                                Kurs podstawowy 
 Copyright(c)by Jan T. Biernat*/ 
using namespace std; 
//Blok główny. 
int main() { 
  cout << "--== Tabliczka mnozenia w2 ==--\n"; 
  cout << "Copyright (c)by Jan T. Biernat\n"; 
  cout << "UWAGA: Wpisanie wartosci mniejszej od 0, spowoduje wyjscie z programu!\n\n"; 
  //Deklaracja stałych. 
    const int iIloscKomentarzy = 5; 
    const string tSpc0 = "   "; 
    const string tKomentarzePozytywne[iIloscKomentarzy] = {"Bardzo dobrze", 
                                                           "Wspaniale", 
                                                           "Rewelacyjnie", 
                                                           "Dobrze", 
                                                           "Swietnie"}; 
    const string tKomentarzeNegatywne[iIloscKomentarzy] = {"Bardzo zle", 
                                                           "zle", 
                                                           "Bledna odpowiedz", 
                                                           "Fatalnie", 
                                                           "Beznadziejna odpowiedz"}; 
  //Deklaracja zmiennych. 
    short int A, B, iOdp, iPoziom = 0; 
    int iLicznik = 0, iPozytywne = 0, iNegatywne = 0, iOcena = 0; 
    bool logJest = true; 
  //Wybranie poziomu. 
    cout << "\nZ jakiego przedzialu mam losowac liczby (od 5 do 31): "; 
    cin >> iPoziom; 
    if(iPoziom < 5) iPoziom = 5; 
    else if(iPoziom > 31) iPoziom = 31; 
    cout << "\nBede losowal liczby z zakresu od 0 do " << iPoziom << ".\n"; 
  //Losowanie pytań. 
    do{ 
      iLicznik++; //Licznik = Licznik+1; 
      srand(time(NULL)); //Zainicjowanie generatora liczb pseudolosowych. 
      if(logJest == true) { 
        //Losowanie liczb. 
          A = 0; 
          A = rand()%(iPoziom+1); 
          B = 0; B = rand()%(iPoziom+1); 
      } 
      cout << "\n\n" << iLicznik << ") " << A << " x " << B << " = "; 
      //Sprawdzenie, czy odpowiedź użytkownika jest prawidłowa. 
        iOdp = 0; cin >> iOdp; 
        if(iOdp > -1) { 
          string tKomentarz = "", tPrawidlowyWynik = ""; 
          if(A*B == iOdp) { 
            iPozytywne++; //Zliczaj prawidłowe odpowiedzi. 
            cout << tSpc0 << tKomentarzePozytywne[rand()%(iIloscKomentarzy)] << "."; 
            logJest = true; 
          } else { 
                    iNegatywne++; //Zliczaj błędne odpowiedzi. 
                    cout << tSpc0 << tKomentarzeNegatywne[rand()%(iIloscKomentarzy)] << "!"; 
                    cout << "\n" << tSpc0 << "Prawidlowa odpowiedz to " << (A*B) << "."; 
                    logJest = false; 
                 } 
        } 
    } while(iOdp > -1); 
  //Raport z przeprowadzonego testu. 
    if(iLicznik-1 > 0) { 
      cout << "\n\nIlosc zadanych pytan: " << iLicznik-1; 
      iOcena = 0; iOcena = iPozytywne * 100 / (iLicznik-1); 
      cout << "\n  Odpowiedzi poprawnych : " << iPozytywne << " (" << iOcena << "%)"; 
      cout << "\n  Odpowiedzi negatywnych: " << iNegatywne << " (" << iNegatywne * 100 / (iLicznik-1) << "%)"; 
      //Wyświetl ocenę. 
        string tOcena = ""; 
        if(iOcena > 95) tOcena = "Bardzo dobry (5.0)"; 
        else if(iOcena > 80) tOcena = "Dobry (4.0)"; 
             else if(iOcena > 70) tOcena = "Dostateczny (3.0)"; 
                  else if(iOcena > 50) tOcena = "Mierny (2.0)"; 
                       else if(iOcena <= 50) tOcena = "Jedynka (1.0)"; 
        cout << "\nOtrzymana ocena to: " << tOcena; 
      //Naciśnij dowolny klawisz. 
        cout << "\n\nNacisnij dowolny klawisz..."; getch(); 
    } 
} 
