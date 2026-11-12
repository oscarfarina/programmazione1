#include <iostream> 
#include <fstream>

using namespace std;

void lettura(fstream &input){
    char c;
    input.get(c);
    while(!input.eof() && !input.fail()){
        cout.put(c);
        input.get(c);
    }
}

int main(int argc, char * argv []){
    if(argc != 2){
        cout << "utilizzo: " << argv[0] <<" <nome_file>" << endl;
        exit(1);
    }

    fstream input;
    input.open(argv[1], ios::in);
    if(input.fail()){
        cout << "!!! file nn può essere aperto o nn esiste" << endl;
        input.close();
        exit(1);
    }
        
    lettura(input);
    input.close();

    return 0; 
}