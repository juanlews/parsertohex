#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>

#include <String.h>

using namespace std;

char hexCodeParser(char * code) {

    if(!strcmp(code, "An;")){
       //cout << "An\n";
       return '0';
    }
    else if(!strcmp(code, "nAoB;")){
       //cout << "nAoB\n";
       return '1';
    }
    else if(!strcmp(code, "AnB;")){
       //cout << "AnB\n";
       return '2';
    }
    else if(!strcmp(code, "zeroL;")){
       //cout << "zeroL\n";
       return '3';
    }
    else if(!strcmp(code, "nAeB;")){
       //cout << "nAeB\n";
       return '4';
    }
    else if(!strcmp(code, "Bn;")){
       //cout << "Bn\n";
       return '5';
    }
    else if(!strcmp(code, "AxB;")){
       //cout << "AxB\n";
       return '6';
    }
    else if(!strcmp(code, "ABn;")){
       //cout << "ABn\n";
       return '7';
    }
    else if(!strcmp(code, "AnoB;")){
       //cout << "AnoB\n";
       return '8';
    }
    else if(!strcmp(code, "nAxB;")){
       //cout << "nAxB\n";
       return '9';
    }
    else if(!strcmp(code, "B;")){
       //cout << "B\n";
       return 'A';
    }
    else if(!strcmp(code, "AB;")){
       //cout << "AB\n";
       return 'B';
    }
    else if(!strcmp(code, "umL;")){
       //cout << "umL\n";
       return 'C';
    }
    else if(!strcmp(code, "AoBn;")){
       //cout << "AoBn\n";
       return 'D';
    }
    else if(!strcmp(code, "AoB;")){
       //cout << "AoB\n";
       return 'E';
    }
    else if(!strcmp(code, "A;")){
       //cout << "A\n";
       return 'F';
    }
    else { cout << "\nHá um problema de sintaxe no arquivo: "<<code; }
    return '\n';
}

void getValuesFromFile(){
    int num = 0;
    char * a;
    bool Mnemonico = true;
    int cont = 0;

    a = ( char * ) malloc(sizeof(char) * 8);
    string b[1];
    FILE * arq = fopen("test.alu", "r");
    FILE * arqHex = fopen("test.hex", "a+");
    if (arqHex == NULL) {
        cout<<"\n\tErro na Leitura/Gravacao do arquivo!";
        return ;
    }else{
        fclose(arqHex);
        arqHex = fopen("test.hex", "a+");
    }
    if(arq){
        cout<<"\tLendo arquivo...\n";
        while(!feof(arq)){
            if(!feof(arq)){
                fscanf(arq, "%[^\n]\n", a);
                while(strcmp(a, "inicio:") && strcmp(a, "fim.")){
                    Mnemonico = true;
                    for(int i = 0; i < 8; i++){
                        if(a[i] == '='){
                            Mnemonico = false;
                            if(a[i - 1] == 'A' || a[i - 1] == 'B'){
                                //TODO: Grava no arquivo hex
                                fprintf(arqHex, "%c", a[i + 1]);
                                cont++;
                                if(cont == 3){
                                    //TODO: pula linha
                                    fprintf(arqHex, "\n");
                                    cont = 0;
                                }
                            }
                        }
                    }
                    if(Mnemonico){
                        fprintf(arqHex,"%c", hexCodeParser(a));
                        cont++;
                        if(cont == 3){
                            fprintf(arqHex, "\n");
                            cont = 0;
                        }
                    }
                    fscanf(arq, "%s[^\n]\n ", a);
                }
            }
        }
        if(cont >= 1){
            fprintf(arqHex, "\n");
        }
        fclose(arq);
        fclose(arqHex);
    }
}

int main(){

    int A, B, An, Bn, ABn;
    getValuesFromFile();
    return 0;
}
