#include <iostream> 
#include <fstream>

using namespace std;

void copia(fstream &input, fstream &output){
    char c;
    input.get(c);
    while(!input.eof() && !input.fail()){
        output.put(c);
        input.get(c);
    }
}

int main(int argc, char * argv []){
    if(argc != 3){
        cout << "utilizzo: " << argv[0] << "<nome_file> <nome_file_copia>" << endl;
        exit(1);
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    if(input.fail()){
        cout << "!!! file nn può essere aperto o nn esiste" << endl;
        input.close();
        exit(1);
    }

    output.open(argv[2], ios::out);
    if(output.fail()){
        cout << "!!errore, file nn esistente o nn apribile" << endl;
        input.close();
        output.close();
        exit(1);
    }
        
    copia(input,output);
    input.close();
    output.close();

    return 0; 
}