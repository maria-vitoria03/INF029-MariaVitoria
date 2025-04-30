#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#define MAX_DISCIPLINAS 3
#define MAX_LETRAS 81

extern int qtdDisciplinas;

int menuDisciplina();
void cadastrarDisciplina();
void excluirDisciplina();
void atualizarDisciplina();

typedef struct {
    int codigo;
    char nome[MAX_LETRAS];
    int semestre;
} Disciplina;

Disciplina listaDisciplinas[MAX_DISCIPLINAS];

#endif // DISCIPLINA_H