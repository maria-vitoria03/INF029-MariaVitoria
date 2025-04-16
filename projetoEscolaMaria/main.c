#include <stdio.h>

int main(void){
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

    switch (opcao) {
    case 0:
    return;
    case 1:
        //moduloAluno();
        break;  
    default:
        printf("Opcao Invalida!\n");
        break;
    }

    }
    

    return 0;
}