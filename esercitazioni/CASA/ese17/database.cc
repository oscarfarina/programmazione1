#include <iostream>
#include <fstream>
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

Studente **creaDatabase (fstream &file, int length){
    Studente **database = new Studente*[length];
    char nome[30];
    char cognome[30];
    int matricola;
    float media;

    for(int i = 0; i < length; i++){
        file >> nome >> cognome >> matricola >> media;
        database[i] = genera_studente(nome, cognome, matricola, media);
    }
    return database;
}

int cerca_matricola(Studente ** database, int matricola, int len){
    int indice;
    for(int i = 0; i < len; i++){
        if(database[i]->matricola == matricola){
            indice = i;
            break;
        }
    }
    return indice;
}

int cerca_nome_e_cognome(Studente ** database, char * nome, char * cognome, int len){
    int indice;
    for(int i = 0; i < len; i++){
        if(strcmp(database[i]->nome, nome) == 0){
            if(strcmp(database[i]->cognome, cognome) == 0){
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int studente_top_media(Studente ** database, int len){
    float media = database[0]->media;
    int indice = 0;
    for(int i = 1; i < len; i++){
        if(database[i]->media > media){
            media = database[i]->media;
            indice = i;
        }
    }
    return indice;
}

int main(){
    char nomeFile[30];
    fstream file;
    int length;
    cout << "Inserisci file: ";
    cin >> nomeFile;
    file.open(nomeFile, ios::in);
    if(file.fail()){
        cout << "errore nell'apertura o file inestistente";
        file.close();
        exit(1);
    }
    cout << "inserisci lunghezza file: ";
    cin >> length;

    Studente **database = creaDatabase(file, length);

    for(int i = 0; i < length; i++){
        stampa_studente(database[i]);
    }

    char nome [10] = "mirko";
    char cognome [10] = "cuna";

    cout << "ricerca studente mat 2345 - "; stampa_studente(database[cerca_matricola(database, 2345, length)]);
    cout << "ricerca studente nome: mirko cuna - "; stampa_studente(database[cerca_nome_e_cognome(database, nome, cognome, length)]);
    cout << "ricerca studente media max - "; stampa_studente(database[studente_top_media(database, length)]);

    file.close();
    for(int i = 0; i < length; i++){
        delete database[i];
    }
    delete [] database;
    return 0;
}