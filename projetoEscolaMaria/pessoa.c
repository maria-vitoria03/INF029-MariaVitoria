#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#include "geral.h"

int qtdAlunos = 0;

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
    limparTela();
    
    switch(opcao){     
    case 0:
    printf("Voltando ao menu principal...\n");
    sair = 1;
    break;
    case 1:
    cadastrarAluno();
    break;
    case 2:
    excluirAluno();
    break;
    default:
    printf("Opcao Invalida!\n");
    break;
}
    }   
}

void cadastrarAluno(){
    printf("Cadastro de Aluno\n\n");
    if(qtdAlunos < MAX_STUDENTS){
        printf("Informe a matricula do aluno:\n");
        scanf("%d", &listaAlunos[qtdAlunos].matricula);
        getchar();
        limparTela();
        printf("Informe o nome do aluno:\n");
        fgets(listaAlunos[qtdAlunos].nome, MAX_LETRAS, stdin);
        listaAlunos[qtdAlunos].nome[strcspn(listaAlunos[qtdAlunos].nome, "\n")] = '\0';
        limparTela();
        printf("Informe o sexo:\n");
        scanf(" %c", &listaAlunos[qtdAlunos].sexo);
        getchar();
        limparTela();
        printf("Cadastrado com sucesso!\n");
        qtdAlunos++;
    } else {
        printf("Lista de alunos completa\n");
    }
}

void excluirAluno(){
    int matAluno;
    int achou = 0;
    printf("Exclusao de aluno\n\n");
    if(qtdAlunos == 0){
        printf("Nao a aluno para exclusao!\n");
    } else {
        printf("Informe a matricula do aluno que deseja excluir:\n");
        scanf("%d", &matAluno);
    }
    for(int i = 0; i < qtdAlunos; i++){
        if (listaAlunos[i].matricula == matAluno){
            achou = 1;
            for(int j = i; j < qtdAlunos - 1; j++){
                listaAlunos[j] = listaAlunos[j+1];
            }
            qtdAlunos--;
            printf("Aluno excluido com sucesso!\n");
            break;
        }
    }
    if(!achou){
        printf("Matricula nao localizada!\n");
    }
}