/**
 * @file exp_reg.cpp
 * @author Carlos Henrique Barreto Mareco
 */
#include <iostream>
#include <regex>
using namespace std;

//Mostra as palavras que se encaixam na expressão regular
void exibirPalavras(string str, regex reg){
    sregex_iterator pos(str.begin(), str.end(), reg);
    sregex_iterator fim;

    while(pos != fim){
        smatch match = *pos;
        cout << match.str() << endl;
        pos++;
    }
}

int main(){
    //expressão regular validador de e-mail
    string str = "tes_te@unifap.br         carlosmareco@gmail.com      @mil.gov.br";
    regex reg ("[\\w._%+-]{1,20}@[\\w.-]{2,20}.[A-Za-z]{2,3}");
    // a-z A-Z 0-9 
    exibirPalavras(str, reg);
    return 0;
}