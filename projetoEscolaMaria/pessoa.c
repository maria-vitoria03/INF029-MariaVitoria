#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "pessoa.h"
#include "disciplinas.h"
#include "relatorios.h"
#include "geral.h"

int qtdAlunos = 0;
int qtdProfs = 0;

int menuAluno(){
    
    int opcao, sair = 0;

    while (!sair) {
    printf("****** Modulo de alunos ******\n\n");
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

void cadastrarAluno() {
    printf("****** Cadastro de Alunos ******\n\n");

    if (qtdAlunos < MAX_STUDENTS) {
        int matriculaTemp;
        printf("Informe a matricula do aluno:\n");
        if (scanf("%d", &matriculaTemp) != 1 || matriculaTemp <= 0) {
        printf("Matricula invalida! Use um numero inteiro positivo.\n");
        getchar();
        return;
        }
        getchar(); 
        limparTela();

        listaAlunos[qtdAlunos].matricula = matriculaTemp;

        printf("Informe o nome do aluno:\n");
        fgets(listaAlunos[qtdAlunos].nome, MAX_LETRAS, stdin);
        listaAlunos[qtdAlunos].nome[strcspn(listaAlunos[qtdAlunos].nome, "\n")] = '\0';
        limparTela();

        char tempSexo;
        printf("Informe o sexo (M/F):\n");
        if (scanf(" %c", &tempSexo) != 1) {
            printf("Sexo invalido!\n");
            getchar();
            return;
        }

        if (tempSexo == 'f' || tempSexo == 'F' || tempSexo == 'm' || tempSexo == 'M') {
            listaAlunos[qtdAlunos].sexo = tempSexo;
        } else {
            printf("Sexo invalido!\n");
            getchar();
            return;
        }

        getchar();
        limparTela();

        printf("Digite a data de nascimento (dia mes ano, separados por espaco): \n");
        if (scanf("%d %d %d", &listaAlunos[qtdAlunos].nascimento.dia, &listaAlunos[qtdAlunos].nascimento.mes, &listaAlunos[qtdAlunos].nascimento.ano) == 3) {
            if (validaDataNascimento(listaAlunos[qtdAlunos].nascimento)) {
                printf("Aluno cadastrado com sucesso!\n");
                getchar();
                qtdAlunos++;
                return;
            } else {
                printf("Data de nascimento invalida!\n");
                getchar();
                return;
            }
        } else {
            printf("Formato de data invalido!\n");
            getchar();
            return;
        }

        limparTela();
    } else {
        printf("Lista de Alunos completa\n");
    }
}

void excluirAluno(){
    int matAluno;
    int achou = 0;
    printf("Exclusao de aluno\n\n");
    if(qtdAlunos == 0){
        printf("Nao ha aluno para exclusao!\n");
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
        printf("Digite a data de nascimento atualizada (dia mes ano, separados por espaco): \n");
        scanf("%d %d %d", &listaAlunos[qtdAlunos].nascimento.dia, &listaAlunos[qtdAlunos].nascimento.mes, &listaAlunos[qtdAlunos].nascimento.ano);
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
    printf("****** Modulo de professores ******\n\n");
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

void cadastrarProfessor() {
    printf("Cadastro de Professores\n\n");

    if (qtdProfs < MAX_PROFS) {
        int matriculaTemp;
        printf("Informe a matricula do professor:\n");
        if (scanf("%d", &matriculaTemp) != 1 || matriculaTemp <= 0) {
        printf("Matricula invalida! Use um numero inteiro positivo.\n");
        getchar();
        return;
        }
        getchar(); 
        limparTela();

        listaProf[qtdProfs].matricula = matriculaTemp;

        printf("Informe o nome do professor:\n");
        fgets(listaProf[qtdProfs].nome, MAX_LETRAS, stdin);
        listaProf[qtdProfs].nome[strcspn(listaProf[qtdProfs].nome, "\n")] = '\0';
        limparTela();

        char tempSexo;
        printf("Informe o sexo (M/F):\n");
        if (scanf(" %c", &tempSexo) != 1) {
            printf("Sexo invalido!\n");
            getchar();
            return;
        }

        if (tempSexo == 'f' || tempSexo == 'F' || tempSexo == 'm' || tempSexo == 'M') {
            listaProf[qtdProfs].sexo = tempSexo;
        } else {
            printf("Sexo invalido!\n");
            getchar();
            return;
        }

        getchar();
        limparTela();

        printf("Digite a data de nascimento (dia mes ano, separados por espaco): \n");
        if (scanf("%d %d %d", &listaProf[qtdProfs].nascimento.dia, &listaProf[qtdProfs].nascimento.mes, &listaProf[qtdProfs].nascimento.ano) == 3) {
            if (validaDataNascimento(listaProf[qtdProfs].nascimento)) {
                printf("Professor cadastrado com sucesso!\n");
                getchar();
                qtdProfs++;
                return;
            } else {
                printf("Data de nascimento invalida!\n");
                getchar();
                return;
            }
        } else {
            printf("Formato de data invalido!\n");
            getchar();
            return;
        }

        limparTela();
    } else {
        printf("Lista de Professores completa\n");
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
        printf("Digite a data de nascimento atualizada (dia mes ano, separados por espaco): \n");
        scanf("%d %d %d", &listaProf[qtdProfs].nascimento.dia, &listaProf[qtdProfs].nascimento.mes, &listaProf[qtdProfs].nascimento.ano);
        printf("Atualizado com sucesso!\n"); 
        }
        if(!achou){
            printf("Matricula nao localizada!\n");
        }
        break;
    }
}