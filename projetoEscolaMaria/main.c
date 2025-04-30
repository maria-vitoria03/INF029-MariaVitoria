#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#include "disciplinas.h"
#include "geral.h"

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
    limparTela();

    switch (opcao) {
    case 0:
    printf("Finalizando aplicacao...\n");
    return 0;
    break;
    case 1:
        menuAluno();
        break;
    case 2:
        menuProfessor();
        break;
    case 3:
        menuDisciplina();
        break;  
    default:
        printf("Opcao Invalida!\n");
        break;
    }

    }  
    return 0;
}