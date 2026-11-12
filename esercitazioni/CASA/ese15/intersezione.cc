#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_PAROLE = 1000;
const int MAX_LUN = 101;

void intersezioneFile(char paroleA [MAX_PAROLE][MAX_LUN], int a, char paroleB [MAX_PAROLE][MAX_LUN],int b, fstream &output){
    for(int i = 0; i < a; i++){
        bool trovatoInB = false;
        for(int j = 0; j < b; j++){
            if(strcmp(paroleA[i], paroleB[j]) == 0){
                trovatoInB = true;
                break;
            }
        }
        if(trovatoInB){
            bool check = false;
            for(int k = 0; k<i; k++){
                if(strcmp(paroleA[i], paroleA[k]) == 0){
                    check = true;
                    break;
                }
            }
            if(!check){
                output << paroleA[i] << endl;
            }
        }
    }
}

int main(int argc, char * argv []){
    fstream inputA, inputB;
    if(argc != 4){
        cout << "errore";
        exit(1);
    }

    inputA.open(argv[1], ios::in);
    inputB.open(argv[2], ios::in);
    if(inputA.fail() && inputB.fail()){
        cout << "1 o entrambi i file nn esistono o nn possono essere aperti";
        inputA.close();
        inputB.close();
        exit(1);
    }

    char paroleA[MAX_PAROLE][MAX_LUN];
    int countA = 0;
    while(countA < MAX_PAROLE && (inputA >> paroleA[countA])) {
        countA++;
    }
    inputA.close();

    char paroleB[MAX_PAROLE][MAX_LUN];
    int countB = 0;
    while(countB < MAX_PAROLE && (inputB >> paroleB[countB])) {
        countB++;
    }
    inputB.close();

    fstream output; 
    output.open(argv[3], ios::out);
    if(output.fail()){
        cout << "il file nn esiste o nn si apre";
        output.close();
        exit(1);
    }

    intersezioneFile(paroleA, countA, paroleB, countB, output);

    output.close();
    return 0;
}