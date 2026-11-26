/*Iarlley Couto - 04203707 | Igor Lira - 04202039 | Joaquim Conceição - 04212732*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
    int idade;
    float nota;
} Aluno;

void Texto(char *texto, int tamanho) {
    int c;
    size_t comprimento;
    if (fgets(texto, tamanho, stdin) == NULL) {
        printf("\nEntrada encerrada!\n");
        exit(0);
    }
    comprimento = strlen(texto);
    if (comprimento > 0 && texto[comprimento - 1] == '\n') {
        texto[comprimento - 1] = '\0';
    } 
}

void Nome(char *mensagem, char *nome) {
    do {
        printf("%s", mensagem);
        Texto(nome, 50);
        if (nome[0] == '\0') {
            printf("O nome nao pode ser vazio!\n");
        }
    } while (nome[0] == '\0');
}

int n1(char *mensagem, int minimo, int maximo) {
    char linha[20];
    int numero;
    int ok;
    do {
        printf("%s", mensagem);
        Texto(linha, 20);
        ok = (sscanf(linha, "%d", &numero) == 1 && numero >= minimo && numero <= maximo);
        if (!ok) {
            printf("Valor invalido! Digite um numero de %d a %d.\n", minimo, maximo);
        }
    } while (!ok);
    return numero;
}

float Nota(char *mensagem) {
    char linha[20];
    float nota;
    int ok;

    do {
        printf("%s", mensagem);
        Texto(linha, 20);
        ok = (sscanf(linha, "%f", &nota) == 1 && nota >= 0 && nota <= 10);
        if (!ok) {
            printf("Nota invalida! Digite um valor de 0 a 10.\n");
        }
    } while (!ok);
    return nota;
}

int Posicao(Aluno *alunos, int total, int matricula) {
    int i;
    for (i = 0; i < total; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

Aluno *cadastrar(Aluno *alunos, int *total, int *capacidade) {
    int matricula;
    if (*total == *capacidade) {
        Aluno *novo = realloc(alunos, *capacidade * 2 * sizeof(Aluno));
        if (novo == NULL) {
            printf("Erro!\n");
            return alunos;
        }
        alunos = novo;
        *capacidade = *capacidade * 2;
    }
    printf("Cadastrar\n");
    matricula = n1("Matricula: ", 1, 999);
    if (Posicao(alunos, *total, matricula) != -1) {
        printf("Ja existe aluno com essa matricula!\n");
        return alunos;
    }
    alunos[*total].matricula = matricula;
    Nome("Nome: ", alunos[*total].nome);
    alunos[*total].idade = n1("Idade: ", 1, 100);
    alunos[*total].nota = Nota("Nota: ");
    (*total)++;
    printf("Aluno cadastrado!\n");
    return alunos;
}

void listar(Aluno *alunos, int total) {
    int i;
    printf("Listar\n");
    if (total == 0) {
        printf("Nenhum aluno cadastrado.\n");
    }
    for (i = 0; i < total; i++) {
        printf("Matricula: %d | Nome: %s | idade: %d  | nota: %.1f\n", alunos[i].matricula, alunos[i].nome, alunos[i].idade, alunos[i].nota);
    }
}

void buscar(Aluno *alunos, int total) {
    int matricula, posicao;
    printf("Buscar\n");
    matricula = n1("Matricula: ", 1, 999);
    posicao = Posicao(alunos, total, matricula);
    if (posicao == -1) {
        printf("Aluno nao encontrado.\n");
    } else {
        printf("Matricula: %d | Nome: %s | idade: %d  | nota: %.1f\n", alunos[posicao].matricula, alunos[posicao].nome, alunos[posicao].idade, alunos[posicao].nota);
    }
}

void editar(Aluno *alunos, int total) {
    int matricula, posicao;
    printf("Editar\n");
    matricula = n1("Matricula do aluno: ", 1, 999);
    posicao = Posicao(alunos, total, matricula);
    if (posicao == -1) {
        printf("Aluno nao encontrado.\n");
    } else {
        Nome("Novo nome: ", alunos[posicao].nome);
        alunos[posicao].idade = n1("Nova idade: ", 1, 100);
        alunos[posicao].nota = Nota("Nova nota: ");
        printf("dados atualizados!\n");
    }
}

void remover(Aluno *alunos, int *total) {
    int matricula, posicao, i;
    printf("Remover\n");
    matricula = n1("Matricula do aluno: ", 1, 999);
    posicao = Posicao(alunos, *total, matricula);
    if (posicao == -1) {
        printf("Aluno nao encontrado.\n");
    } else {
        for (i = posicao; i < *total - 1; i++) {
            alunos[i] = alunos[i + 1];
        }
        (*total)--;
        printf("Aluno removido!\n");
    }
}

int main() {
    int menu;
    int total = 0;
    int capacidade = 1;
    Aluno *alunos = malloc(capacidade * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro!\n");
        return 1;
    }
    do {
        printf("\n1- Cadastrar\n2- Listar\n3- Buscar\n4- Editar\n5- Remover\n0- Sair\n");
        menu = n1("Escolha: ", 0, 5);

        switch (menu) {
            case 1:
                alunos = cadastrar(alunos, &total, &capacidade);
                break;
            case 2:
                listar(alunos, total);
                break;
            case 3:
                buscar(alunos, total);
                break;
            case 4:
                editar(alunos, total);
                break;
            case 5:
                remover(alunos, &total);
                break;
            case 0:
                printf("Obrigado por usar nosso servico!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (menu != 0);

    free(alunos);
    return 0;
}