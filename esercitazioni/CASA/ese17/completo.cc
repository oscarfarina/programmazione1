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

Studente * genera_studente (char nome[], char cognome[], int matricola, float media_ponderata){
    Studente * stud = new Studente;
    strcpy(stud->nome, nome);
    strcpy(stud->cognome, cognome);
    stud->matricola = matricola;
    stud->media = media_ponderata;
    return stud;
}

void stampa_studente (Studente * studente){
    if(studente != NULL){
        cout << "Studente: " << studente->cognome << " " << studente->nome << ", nMat: " << studente->matricola << ", media: " << (*studente).media << endl;
    }
}

Studente **creaDatabase (fstream &file, int length, int dMax){
    Studente **database = new Studente*[dMax];
    char nome[30];
    char cognome[30];
    int matricola;
    float media;

    for(int i = 0; i < dMax; i++){
        database[i] = NULL;
    }


    for(int i = 0; i < length; i++){
        file >> nome >> cognome >> matricola >> media;
        database[i] = genera_studente(nome, cognome, matricola, media);
    }
    return database;
}

void aggiungiUtente(Studente ** database, Studente * studente, int dMax){
    bool trovato = false;
    for(int i = 0; i < dMax; i++){
        if(database[i] == NULL){
            database[i] = studente;
            trovato = true;
            break;
        }
    }
    if(!trovato){
        cout << "errore. Dimensione massima raggiunta. impossibile inserire utente nel database!!!";
        exit(1);
    }
}

void modificaUtente(Studente ** database, const char nome[], const char cognome[], int matricola, float media_ponderata, int dMax, int index){
    if(index >= 0 && index < dMax && database[index] != NULL){
        if(strlen(nome) > 0){
            strcpy(database[index]->nome, nome);
        }
        if(strlen(cognome) > 0){
            strcpy(database[index]->cognome, cognome);
        }
        if(matricola != 0){
            database[index]->matricola = matricola;
        }
        if(media_ponderata != 0){
            database[index]->media = media_ponderata;
        }
    }
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

void salva(Studente **database, int dMax, fstream &output){
    for(int i = 0; i < dMax; i++){
        if(database[i] != NULL){
            output << database[i]->nome << " " << database[i]->cognome << " " << database[i]->matricola << " " << database[i]->media << endl;
        }
    }
    cout << "database salvato correttamente" << endl;
}

int main(int argc, char * argv[]){
    if(argc != 2){
        cout << "errore." << endl;
        exit(1);
    }
    int DimMax = stoi(argv[1]);

    char nomeFile[30], note[30];
    fstream file, output;
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

    Studente **database = creaDatabase(file, length, DimMax);
    char n[15] = "oscar";
    char c[15] = "farina";
    Studente *s = genera_studente(n,c, 9999, 100);
    aggiungiUtente(database, s, DimMax);
    modificaUtente(database, "", "", 0, 90, DimMax, 1);
    for(int i = 0; i < DimMax; i++){
        stampa_studente(database[i]);
    }

    cout << "Inserisci file di output: ";
    cin >> note;
    output.open(note, ios::out);
    if(output.fail()){
        cout << "errore nell'apertura o file inestistente";
        output.close();
        exit(1);
    }else{
        salva(database, DimMax, output);
        output.close();
    }

    file.close();
    for(int i = 0; i < length; i++){
        delete database[i];
    }
    delete [] database;
    return 0;
}