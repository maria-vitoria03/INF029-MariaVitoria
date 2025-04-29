#include <stdio.h>

#include "pessoa.h"

int main(){
    int sair = 0;
    int opcao;

    while(!sair){
    printf("****** Escola Maria ******\n\n");
    printf("0 - Sair\n");
    printf("1 - Modulo de alunos\n");
    printf("2 - Modulo de professores\n");
    printf("3 - Modulo de disciplinas\n");
    printf("4 - Emissao de relatorios\n");
    printf("Digite sua opcao:\n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
    case 0:
    return 0;
    break;
    case 1:
        menuAluno();
        break;  
    default:
        printf("Opcao Invalida!\n");
        break;
    }

    }  
    return 0;
}