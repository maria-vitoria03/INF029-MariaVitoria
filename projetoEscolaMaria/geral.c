#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "geral.h"

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool eBissexto(int ano){    
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool validaDataNascimento(DataNascimento data){
    if(data.ano < 1 || data.mes < 1 || data.mes > 12 || data.dia < 1){
        return false;
    }

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(data.mes == 2 && eBissexto(data.ano)){
        diasNoMes[2] = 29;
    }

    return data.dia <= diasNoMes[data.mes];
}
