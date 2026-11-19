#include <iostream>
#include <cstring>

using namespace std;

struct Studente {
    char nome[30];
    char cognome[30];
    int matricola;
    float media;
};

Studente * genera_studente (char nome[], char cognome[], int matricola, float media_ponderata ){
    Studente * stud = new Studente;
    strcpy(stud->nome, nome);
    strcpy(stud->cognome, cognome);
    stud->matricola = matricola;
    stud->media = media_ponderata;
    return stud;
}

void stampa_studente (Studente * studente ){
    cout << "Studente: " << studente->cognome << " " << studente->nome << ", nMat: " << studente->matricola << ", media: " << (*studente).media << endl;
}

int main(){
    char nome[30];
    char cognome[30];
    int matricola;
    float media;

    cout << "Inserisci valore per lo studente" << endl;
    cout << "Nome: ";
    cin >> nome;
    cout << "Cognome: ";
    cin >> cognome;
    cout << "matricola: ";
    cin >> matricola;
    cout << "media: ";
    cin >> media;
    Studente * s = genera_studente(nome, cognome, matricola, media);
    stampa_studente(s);
    delete s;

    return 0;
}