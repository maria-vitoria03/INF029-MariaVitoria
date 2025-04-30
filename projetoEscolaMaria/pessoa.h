#ifndef PESSOA_H
#define PESSOA_H

#define MAX_STUDENTS 3
#define MAX_PROFS 3
#define MAX_LETRAS 81

extern int qtdAlunos;
extern int qtdProfs;

int menuAluno();
void cadastrarAluno();
void excluirAluno();
void atualizarAluno();
int menuProfessor();
void cadastrarProfessor();
void excluirProfessor();
void atualizarProfessor();

typedef struct {
    int matricula;
    char nome[MAX_LETRAS];
    char sexo;
} Pessoa;

Pessoa listaAlunos[MAX_STUDENTS];
Pessoa listaProf[MAX_PROFS];


#endif // PESSOA_H