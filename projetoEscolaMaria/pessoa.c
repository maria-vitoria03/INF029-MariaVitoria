#include <stdio.h>

#include "pessoa.h"

int menuAluno(){
    
    int opcao, sair = 0;

    while (!sair) {
    printf("Modulo de alunos\n\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar\n");
    printf("2 - Excluir\n");
    printf("3 - Atualizar\n");
    printf("Informe sua opcao:\n");
    scanf("%d", &opcao);
    getchar();
    
    switch(opcao){     
    case 0:
    printf("Voltando ao menu principal...\n");
    sair = 1;
    break;
    case 1:
    cadastrarAluno();
    break;
    default:
    printf("Opcao Invalida!\n");
    break;
}
    }   
}

void cadastrarAluno(){
    printf("Cadastro de Aluno\n\n");
}