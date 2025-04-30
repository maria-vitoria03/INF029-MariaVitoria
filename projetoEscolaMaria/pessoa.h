#ifndef PESSOA_H
#define PESSOA_H

#define MAX_STUDENTS 3
#define MAX_LETRAS 81

extern int qtdAlunos;

int menuAluno();
void cadastrarAluno();
void excluirAluno();
void atualizarAluno();

typedef struct {
    int matricula;
    char nome[MAX_LETRAS];
    char sexo;
} Pessoa;

Pessoa listaAlunos[MAX_STUDENTS];


#endif // PESSOA_H