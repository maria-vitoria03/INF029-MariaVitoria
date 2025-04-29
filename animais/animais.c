#include <stdio.h>

#define TAM 3

typedef struct {
    int dia;
    int mes;
    int ano;
} DataNascimento;

typedef struct {
    int matricula;
    int idade;
    char sexo;
    char nome[81];
    DataNascimento dataNascimento;
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

int menuDois(){
    int opcaoDois;

    printf("*** Sistema de cadastro de animais ***\n\n");
    printf("5 - Informacoes de todos\n");
    printf("6 - Maiores ou iguais a media\n");
    printf("7 - voltar\n");
    printf("Digite sua opcao:\n");
    scanf("%d", &opcaoDois);
    return opcaoDois;
}

int main(){
    int sair = 0;
    int opcao = 0, opcaoDois = 0, qtdAnimais = 0, contIdade = 0, media = 0;

    Animais  listaAnimais[TAM];

    while(!sair){
    
    opcao = menu();
    
    switch (opcao){
    case 0:
        return 0;
        break;
    case 1:
        printf("*** Cadastro do animal ***\n");
        if(qtdAnimais < TAM){
            printf("Informe a matricula:\n");
            scanf("%d", &listaAnimais[qtdAnimais].matricula);
            printf("Informe a idade:\n");
            scanf("%d", &listaAnimais[qtdAnimais].idade);
            contIdade += listaAnimais[qtdAnimais].idade;
            getchar();
            printf("Informe o sexo:\n");
            scanf("%c", &listaAnimais[qtdAnimais].sexo);
            getchar();
            printf("Informe o nome:\n");
            gets(listaAnimais[qtdAnimais].nome);
            printf("Informe o dia do nascimento:\n");
            scanf("%d", &listaAnimais[qtdAnimais].dataNascimento.dia);
            printf("Informe o mes do nascimento:\n");
            scanf("%d", &listaAnimais[qtdAnimais].dataNascimento.mes);
            printf("Informe o ano do nascimento:\n");
            scanf("%d", &listaAnimais[qtdAnimais].dataNascimento.ano);
            qtdAnimais++;
            printf("Cadastro realizado com sucesso!\n");
        } else { 
            printf("Lista de animais cheia!\n");
            }
        break;
    case 2:
            printf("*** Exclusao do animal ***\n");
            if(qtdAnimais == 0){
                printf("Não há animal para excluir\n");
            } else {
                int matricula;
                int achou = 0;
                printf("Digite a matricula que quer excluir:\n");
                scanf("%d", &matricula);
                for(int k = 0; k < qtdAnimais; k++){
                    if (listaAnimais[k].matricula == matricula) {
                        achou = 1;
                        for(int l = k; l < qtdAnimais - 1; l++) {
                            listaAnimais[l] = listaAnimais[l + 1];  
                        }
                        qtdAnimais--; 
                        printf("Animal excluido com sucesso!\n");
                        break; 
                    }
                }
                if (!achou) {
                    printf("Animal nao localizado!\n");
                }
            }
            break;
    case 3:
        printf("*** Atualizacao do animal ***\n");
        break;
    case 4:
        opcaoDois = menuDois();
        switch (opcaoDois){
        case 5:
            if(qtdAnimais == 0){
                printf("Lista de animais vazia!\n");
            } else {
                for(int i = 0; i < qtdAnimais; i++){
                printf("%d%c%s%d/%d/%d%d\n", listaAnimais[i].idade, listaAnimais[i].sexo, listaAnimais[i].nome, listaAnimais[i].dataNascimento.dia, listaAnimais[i].dataNascimento.mes, listaAnimais[i].dataNascimento.ano, listaAnimais[i].matricula);
            }
            }
            break;
        case 6:
            media = contIdade / qtdAnimais;
            if(qtdAnimais == 0){
                printf("Lista de animais vazia!\n");
            } else {
                for(int j = 0; j < qtdAnimais; j++){
                    if(listaAnimais[j].idade >= media){
                        printf("%d%c%s%d/%d/%d%d\n", listaAnimais[j].idade, listaAnimais[j].sexo, listaAnimais[j].nome, listaAnimais[j].dataNascimento.dia, listaAnimais[j].dataNascimento.mes, listaAnimais[j].dataNascimento.ano, listaAnimais[j].matricula);
                    }
                }              
            }
            break;
        case 7:
        printf("loading...\n");
        break;    
        default:
            printf("Opcao Invalida!\n");
            break;
        }
        break;   
    default:
    printf("Opcao Invalida!\n");
        break;
    }
    }  
    return 0;
}