#include <iostream> 
#include <fstream>

using namespace std;

void sostitusci(fstream &input, char lettera){
    char c;
    input.get(c);
    while(!input.eof() && !input.fail()){
        if(c == lettera){
            cout.put('?');
        }else{
            cout.put(c);
        }
        input.get(c);
    }
}

int main(int argc, char * argv []){
    if(argc != 3){
        cout << "utilizzo: " << argv[0] << "<nome_file> <lettera>" << endl;
        exit(1);
    }

    fstream input;

    input.open(argv[1], ios::in);
    if(input.fail()){
        cout << "!!! file nn può essere aperto o nn esiste" << endl;
        input.close();
        exit(1);
    }
        
    sostitusci(input, argv[2][0]);
    input.close();

    return 0; 
}