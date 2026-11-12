#include <iostream> 
#include <cstring>
#include <cctype>

using namespace std;

int distanza(char str[]){
    for(int i=0; i<strlen(str); i++){
        if(!isalpha(str[i])){
            return -1;
        }
    }

    int d = 0;
    for(int i=0; i<strlen(str)-1; i++){
        int diff = tolower(str[i]) - tolower(str[i+1]);
        if (diff < 0){
            diff = -1 * diff;
        }
        d += diff;;
    }
    return d;
}

int main(){
    char str[32];
    char scelta;
    int punteggio = 0;
    do{
        cout<< "inserisci str: ";
        cin >> str;

        punteggio += distanza(str);
        
        cout << "inserisci ancora? s/n: ";
        cin >> scelta;
    }while(tolower(scelta) != 'n');
   
    cout << "totale: " << punteggio;

    return 0; 
}