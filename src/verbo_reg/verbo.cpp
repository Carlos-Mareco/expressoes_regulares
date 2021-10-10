/**
 * @file exp_reg.cpp
 * @author Carlos Henrique Barreto Mareco
 */
#include <iostream>
#include <string>
#include <regex>
#include <iterator>
#include <fstream>

using namespace std;

int contarPalavras(string str, regex reg, int tempos[], string sufixo);
string lerArquivo(string nomeArquivo);
int tempoVerbal(string s, int tempos[], string sufixo);
string verifVerbo(char *str, int op);

int main(int argc, char *argv[]){
    string str = lerArquivo("texto.txt");
    if(argc > 1 && str.size() != 0){
        if(verifVerbo(argv[1], 1).size() != 0){
            int temposVerbais[3] = {0, 0, 0};
            regex reg ("("+verifVerbo(argv[1], 0)+")([A-Za-záàâãéèêíóôõúç]{1,7})");
            cout << "Verbo: " << argv[1] << endl;
            cout << "Palavras encontradas: " << contarPalavras(str, reg, temposVerbais, verifVerbo(argv[1], 1)) << endl;
            cout << "  Presente: " << temposVerbais[0] << endl;
            cout << "  Pretérito " << temposVerbais[1] << endl;
            cout << "  Futuro: " << temposVerbais[2] << endl;
        } else {
            cout << "ERRO: Verbo inválido!\n";
        }
    } else {
        cout << "ERRO: Argumentos inválidos.\n";
    }
    return 0;
}
string verifVerbo(char *str, int op){
    string aux;
    string radical = str;
    regex r("([A-Za-záàâãéèêíóôõú]{1,10})([aei]r)");
    sregex_iterator pos(radical.begin(), radical.end(), r);
    smatch match = *pos;
    if(op == 0){
        aux = match[1].str();
    } else {
        aux = match[2].str();
    }
    return aux;
}
int contarPalavras(string str, regex reg, int tempos[], string sufixo){
    int cont = 0;
    sregex_iterator pos(str.begin(), str.end(), reg);
    sregex_iterator fim;

    while(pos != fim){
        smatch match = *pos;
        if(tempoVerbal(match[2].str(), tempos, sufixo) >= 0)
            cont++;
        pos++;
    }
    return cont;
}

string lerArquivo(string nomeArquivo){
    string aux, temp;
    ifstream arquivo;
    arquivo.open(nomeArquivo);

    if(arquivo.is_open()){
        while(!arquivo.eof()){
            getline(arquivo, aux);
            temp += " " + aux;
        }
        arquivo.close();
    } else {
        cout << "ERRO: Não foi possível abrir o arquivo \"" << nomeArquivo << "\".";
        getchar();
    }
    return temp;
}

int tempoVerbal(string s, int tempos[], string sufixo){
    if(sufixo == "er"){
        if(s == "o"||s == "es"||s == "e"||s == "emos"||s == "eis"||s == "em"){
            tempos[0]++;
            return 0;
        } else if(s == "ia"||s == "ias"||s == "iamos"||s == "ieis"||s == "iam"||
                s == "i"||s == "este"||s == "eu"||s == "estes"||s == "eram"||
                s == "era"||s == "eras"||s == "êramos"||s == "êreis"||s == "em"){
            tempos[1]++;
            return 1;
            
        } else if(s == "erei"||s == "erás"||s == "erá"||s == "eremos"||s == "ereis"||s == "erão"||
                s == "eria"||s == "erias"||s == "eríamos"||s == "eríeis"||s == "eriam"){
            tempos[2]++;
            return 2;
        } else if(s == "er"){
            return 3;
        } else {
            return -1;
        }
    } else if(sufixo == "ar"){
        if(s == "o"||s == "as"||s == "a"||s == "amos"||s == "ais"||s == "am"){
            tempos[0]++;
            return 0;
        } else if(s == "ava"||s == "avas"||s == "ávamos"||s == "áveis"||s == "avam"||
                s == "ei"||s == "aste"||s == "ou"||s == "amos"||s == "astes"||
                s == "aram"||s == "ara"||s == "aras"||s == "áreis"){
            tempos[1]++;
            return 1;
            
        } else if(s == "arei"||s == "arás"||s == "ará"||s == "aremos"||s == "areis"||s == "arão"||
                s == "aria"||s == "arias"||s == "aríamos"||s == "aríeis"||s == "ariam"){
            tempos[2]++;
            return 2;
        } else if(s == "ar"){
            return 3;
        } else {
            return -1;
        }
    } else if(sufixo == "ir"){
        if(s == "o"||s == "es"||s == "e"||s == "imos"||s == "is"||s == "em"){
            tempos[0]++;
            return 0;
        } else if(s == "ia"||s == "ias"||s == "íamos"||s == "íeis"||s == "iam"||
                s == "i"||s == "iste"||s == "iu"||s == "imos"||s == "istes"||
                s == "ira"||s == "iras"||s == "íramos"||s == "íreis"||s == "iram"){
            tempos[1]++;
            return 1;
            
        } else if(s == "irei"||s == "irás"||s == "irá"||s == "iremos"||s == "ireis"||s == "irão"||
                s == "iria"||s == "irias"||s == "iríamos"||s == "iríeis"||s == "iriam"){
            tempos[2]++;
            return 2;
        } else if(s == "ir"){
            return 3;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}