#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#include "disciplinas.h"
#include "geral.h"

int qtdDisciplinas = 0;

int menuDisciplina(){
    
    int opcao, sair = 0;

    while (!sair) {
    printf("Modulo de disciplinas\n\n");
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
    cadastrarDisciplina();
    break;
    case 2:
    excluirDisciplina();
    break;
    case 3:
    atualizarDisciplina();
    break;
    default:
    printf("Opcao Invalida!\n");
    break;
}
    }   
}

void cadastrarDisciplina(){
    printf("Cadastro de disciplina\n\n");
    if(qtdDisciplinas < MAX_DISCIPLINAS){
        printf("Informe o codigo da disciplina:\n");
        scanf("%d", &listaDisciplinas[qtdDisciplinas].codigo);
        getchar();
        limparTela();
        printf("Informe o nome da disciplina:\n");
        fgets(listaDisciplinas[qtdDisciplinas].nome, MAX_LETRAS, stdin);
        listaDisciplinas[qtdDisciplinas].nome[strcspn(listaDisciplinas[qtdDisciplinas].nome, "\n")] = '\0';
        limparTela();
        printf("Informe o semestre da disciplina:\n");
        scanf("%d", &listaDisciplinas[qtdDisciplinas].semestre);
        getchar();
        limparTela();
        printf("Cadastrada com sucesso!\n");
        qtdDisciplinas++;
    } else {
        printf("Lista de disciplinas completa\n");
    }
}

void excluirDisciplina(){
    int codigo;
    int achou = 0;
    printf("Exclusao de Disciplina\n\n");
    if(qtdDisciplinas == 0){
        printf("Nao ha disciplina para exclusao!\n");
    } else {
        printf("Informe o codigo da disciplina que deseja excluir:\n");
        scanf("%d", &codigo);
        getchar();
    }
    for(int i = 0; i < qtdDisciplinas; i++){
        if (listaDisciplinas[i].codigo == codigo){
            achou = 1;
            for(int j = i; j < qtdDisciplinas - 1; j++){
                listaDisciplinas[j] = listaDisciplinas[j+1];
            }
            qtdDisciplinas--;
            printf("Disciplina excluida com sucesso!\n");
            break;
        }
    }
    if(!achou){
        printf("Codigo de disciplina nao localizado!\n");
    }
}

void atualizarDisciplina(){
    int codigo;
    int achou = 0;
    printf("Atualizacao de Disciplina\n\n");
    if(qtdDisciplinas == 0){
        printf("Nao existe disciplinas para atualizacao!\n");
    } else {
        printf("Informe o codigo da disciplina que deseja atualizar:\n");
        scanf("%d", &codigo);
        getchar();
    }
    for(int i = 0; i < qtdDisciplinas; i++){
        if(listaDisciplinas[i].codigo == codigo){
        achou = 1;
        printf("Informe o nome da disciplina atualizado:\n");
        fgets(listaDisciplinas[i].nome, MAX_LETRAS, stdin);
        listaDisciplinas[i].nome[strcspn(listaDisciplinas[i].nome, "\n")] = '\0';
        limparTela();
        printf("Atualizada com sucesso!\n");
    }
    if(!achou){
        printf("Codigo de disciplina nao localizado!\n");
    }
    break;
    }
}