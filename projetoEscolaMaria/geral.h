#ifndef GERAL_C
#define GERAL_C

#include <stdbool.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} DataNascimento;

bool eBissexto();
bool validaDataNascimento();

DataNascimento nascimento;

void limparTela();

#endif // GERAL_C