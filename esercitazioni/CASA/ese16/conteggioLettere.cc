#include <iostream>
#include <fstream>

using namespace std;

int * conteggio(fstream &file, char alfabeto []){
    int * array = new (nothrow) int[26];
    if(array == NULL){
        delete [] array;
        exit(1);
    }
    for(int i = 0; i < 26; i++){
        array[i] = 0;
    }
    char c;
    file.get(c);
    while(!file.eof() && !file.fail()){
        c = tolower(c);
        for(int i = 0; i < 26; i++){
            if(c == alfabeto[i]){
                array[i] ++;
                break;
            }
        }
        file.get(c);
    }
    return array;
}


int main(int argc, char * argv[]){
    if(argc != 2){
        cout << "errore!!! " << endl;
        cout << "utilizzo: " << argv[0] << " <file>" << endl;
        exit(1);
    }
    fstream file;
    file.open(argv[1], ios::in);
    if(file.fail()){
        cout << "errore nell'apertura o file inesistente" << endl;
        file.close();
        exit(1);
    }
    char alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int * c = conteggio(file, alfabeto);
    if(c==NULL){
        cout << "errore memoria" << endl;
        file.close();
        exit(1);
    }
    for(int i = 0; i < 26; i++){
        cout << alfabeto[i] << " = " << c[i] << endl;
    }

    file.close();
    delete [] c;
    return 0;
}