#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pessoa.h"
#include "disciplinas.h"
#include "relatorios.h"
#include "geral.h"

int qtdAlunos = 0;
int qtdProfs = 0;

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
    case 3:
    atualizarAluno();
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
        getchar();
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

void atualizarAluno(){
    int matAluno;
    int achou = 0;
    printf("Atualizacao de aluno\n\n");
    if(qtdAlunos == 0){
        printf("Nao existe alunos para atualizacao!\n");
    } else {
        printf("Informe a matricula do aluno que deseja atualizar:\n");
        scanf("%d", &matAluno);
        getchar();
    }
    for(int i = 0; i < qtdAlunos; i++){
        if(listaAlunos[i].matricula == matAluno){
        achou = 1;
        printf("Informe o nome do aluno atualizado:\n");
        fgets(listaAlunos[i].nome, MAX_LETRAS, stdin);
        listaAlunos[i].nome[strcspn(listaAlunos[i].nome, "\n")] = '\0';
        limparTela();
        printf("Informe o sexo do aluno atualizado:\n");
        scanf(" %c", &listaAlunos[i].sexo);
        getchar();
        limparTela();
        printf("Atualizado com sucesso!\n"); 
        }
        if(!achou){
            printf("Matricula nao localizada!\n");
        }
        break;
    }
}

int menuProfessor(){
    
    int opcao, sair = 0;

    while (!sair) {
    printf("Modulo de professores\n\n");
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
    cadastrarProfessor();
    break;
    case 2:
    excluirProfessor();
    break;
    case 3:
    atualizarProfessor();
    break;
    default:
    printf("Opcao Invalida!\n");
    break;
}
    }   
}

void cadastrarProfessor(){
    printf("Cadastro de Professor\n\n");
    if(qtdProfs < MAX_PROFS){
        printf("Informe a matricula do professor:\n");
        scanf("%d", &listaProf[qtdProfs].matricula);
        getchar();
        limparTela();
        printf("Informe o nome do professor:\n");
        fgets(listaProf[qtdProfs].nome, MAX_LETRAS, stdin);
        listaProf[qtdProfs].nome[strcspn(listaProf[qtdProfs].nome, "\n")] = '\0';
        limparTela();
        printf("Informe o sexo:\n");
        scanf(" %c", &listaProf[qtdProfs].sexo);
        getchar();
        limparTela();
        printf("Cadastrado com sucesso!\n");
        qtdProfs++;
    } else {
        printf("Lista de professores completa\n");
    }
}

void excluirProfessor(){
    int matProf;
    int achou = 0;
    printf("Exclusao de Professor\n\n");
    if(qtdProfs == 0){
        printf("Nao ha professor para exclusao!\n");
    } else {
        printf("Informe a matricula do professor que deseja excluir:\n");
        scanf("%d", &matProf);
        getchar();
    }
    for(int i = 0; i < qtdProfs; i++){
        if (listaProf[i].matricula == matProf){
            achou = 1;
            for(int j = i; j < qtdProfs - 1; j++){
                listaProf[j] = listaProf[j+1];
            }
            qtdProfs--;
            printf("Professor excluido com sucesso!\n");
            break;
        }
    }
    if(!achou){
        printf("Matricula nao localizada!\n");
    }
}

void atualizarProfessor(){
    int matProf;
    int achou = 0;
    printf("Atualizacao de professor\n\n");
    if(qtdProfs == 0){
        printf("Nao existe professores para atualizacao!\n");
    } else {
        printf("Informe a matricula do professor que deseja atualizar:\n");
        scanf("%d", &matProf);
        getchar();
    }
    for(int i = 0; i < qtdProfs; i++){
        if(listaProf[i].matricula == matProf){
        achou = 1;
        printf("Informe o nome do professor atualizado:\n");
        fgets(listaProf[i].nome, MAX_LETRAS, stdin);
        listaProf[i].nome[strcspn(listaProf[i].nome, "\n")] = '\0';
        limparTela();
        printf("Informe o sexo do professor atualizado:\n");
        scanf(" %c", &listaProf[i].sexo);
        getchar();
        limparTela();
        printf("Atualizado com sucesso!\n"); 
        }
        if(!achou){
            printf("Matricula nao localizada!\n");
        }
        break;
    }
}