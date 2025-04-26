#include <stdio.h>

#define TAM 3

typedef struct {
    int idade;
    char sexo;
} Animais;

int menu(){
    int opcao;

    printf("*** Sistema de cadastro de animais ***\n\n");
    printf("0 - Sair\n");
    printf("1 - Cadastrar\n");
    printf("2 - Excluir\n");
    printf("3 - Atualizar\n");
    printf("4 - Mais opcoes...\n");
    printf("Digite sua opcao:\n");
    scanf("%d", &opcao);
    return opcao;
}


int main(){
    int opcao = 0, qtdAnimais = 0;

    Animais  listaAnimais[TAM];

    opcao = menu();

    switch (opcao)
    {
    case 0:
        return 0;
        break;
    case 1:
        printf("*** Cadastro do animal ***\n");
        if(qtdAnimais < TAM){
            printf("Informe a idade:\n");
            scanf("%d", &listaAnimais[qtdAnimais].idade);
            getchar();
            printf("Informe o sexo:\n");
            scanf("%c", &listaAnimais[qtdAnimais].sexo);
            qtdAnimais++;
            printf("Cadastro realizado com sucesso!\n");
        } else {
            printf("Lista de animais cheia!\n");
        }
        break;
    case 2:
        printf("*** Exclusao do animal ***\n");
        break;
    case 3:
        printf("*** Atualizacao do animal ***\n");
        break;
    case 4:
        printf("*** Mais opcoes... ***\n");
        break;   
    default:
    printf("Opcao Invalida!\n");
        break;
    }  
    return 0;
}