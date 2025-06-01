#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// =========================
// Structs
// =========================
struct Paciente {
    char nome[100];
    char cpf[15];
    char tipoAtendimento[20];
    Paciente *prox;
};

struct Atendimento {
    char descricao[200];
    Atendimento *prox;
};

struct Historico {
    char cpf[15];
    Atendimento *topo;
    Historico *prox;
};

// =========================
// Filas
// =========================
Paciente *inicioComum = NULL;
Paciente *fimComum = NULL;

Paciente *inicioPrioritario = NULL;
Paciente *fimPrioritario = NULL;

// =========================
// Histórico
// =========================
Historico *historicos = NULL;

// =========================
// Funções da Fila
// =========================
void inserirNaFila(Paciente **inicio, Paciente **fim, Paciente *novo) {
    novo->prox = NULL;
    if (*fim == NULL) {
        *inicio = novo;
        *fim = novo;
    } else {
        (*fim)->prox = novo;
        *fim = novo;
    }
}

Paciente *removerDaFila(Paciente **inicio, Paciente **fim) {
    if (*inicio == NULL) return NULL;
    Paciente *removido = *inicio;
    *inicio = (*inicio)->prox;
    if (*inicio == NULL) {
        *fim = NULL;
    }
    return removido;
}

void listarFila(Paciente *inicio) {
    Paciente *aux = inicio;
    while (aux != NULL) {
        cout << "Nome: " << aux->nome << ", CPF: " << aux->cpf
             << ", Tipo: " << aux->tipoAtendimento << endl;
        aux = aux->prox;
    }
}

// =========================
// Funções da Pilha
// =========================
Historico *buscarOuCriarHistorico(const char *cpf) {
    Historico *aux = historicos;
    while (aux != NULL) {
        if (strcmp(aux->cpf, cpf) == 0) {
            return aux;
        }
        aux = aux->prox;
    }

    // Se não encontrou, cria
    Historico *novo = (Historico *)malloc(sizeof(Historico));
    strcpy(novo->cpf, cpf);
    novo->topo = NULL;
    novo->prox = historicos;
    historicos = novo;
    return novo;
}

void adicionarAtendimento(const char *cpf, const char *descricao) {
    Historico *h = buscarOuCriarHistorico(cpf);
    Atendimento *novo = (Atendimento *)malloc(sizeof(Atendimento));
    strcpy(novo->descricao, descricao);
    novo->prox = h->topo;
    h->topo = novo;
}

void listarHistorico(const char *cpf) {
    Historico *h = historicos;
    while (h != NULL) {
        if (strcmp(h->cpf, cpf) == 0) {
            cout << "Historico de atendimentos do CPF " << cpf << ":" << endl;
            Atendimento *a = h->topo;
            if (a == NULL) {
                cout << "Nenhum atendimento registrado." << endl;
            }
            while (a != NULL) {
                cout << "- " << a->descricao << endl;
                a = a->prox;
            }
            return;
        }
        h = h->prox;
    }
    cout << "CPF nao encontrado no historico." << endl;
}

// =========================
// Funções principais
// =========================
void cadastrarPaciente() {
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    cout << "Nome: ";
    cin.ignore();
    cin.getline(novo->nome, 100);
    cout << "CPF: ";
    cin.getline(novo->cpf, 15);
    cout << "Tipo de atendimento (Comum/Prioritario): ";
    cin.getline(novo->tipoAtendimento, 20);

    if (strcmp(novo->tipoAtendimento, "Prioritario") == 0) {
        inserirNaFila(&inicioPrioritario, &fimPrioritario, novo);
    } else {
        inserirNaFila(&inicioComum, &fimComum, novo);
    }

    cout << "Paciente cadastrado com sucesso!" << endl;
}

void atenderPaciente() {
    Paciente *atendido = NULL;
    if (inicioPrioritario != NULL) {
        atendido = removerDaFila(&inicioPrioritario, &fimPrioritario);
    } else if (inicioComum != NULL) {
        atendido = removerDaFila(&inicioComum, &fimComum);
    }

    if (atendido == NULL) {
        cout << "Nenhum paciente na fila." << endl;
    } else {
        cout << "Atendendo paciente: " << atendido->nome << " (CPF: " << atendido->cpf << ")" << endl;
        char descricao[200];
        cout << "Descricao do atendimento: ";
        cin.ignore();
        cin.getline(descricao, 200);
        adicionarAtendimento(atendido->cpf, descricao);
        free(atendido);
    }
}

void visualizarFilas() {
    cout << "\nFila Prioritaria:\n";
    listarFila(inicioPrioritario);
    cout << "\nFila Comum:\n";
    listarFila(inicioComum);
}

// =========================
// Função de limpeza
// =========================
void liberarMemoria() {
    // Limpa filas
    Paciente *aux;
    while (inicioPrioritario != NULL) {
        aux = removerDaFila(&inicioPrioritario, &fimPrioritario);
        free(aux);
    }
    while (inicioComum != NULL) {
        aux = removerDaFila(&inicioComum, &fimComum);
        free(aux);
    }

    // Limpa históricos
    Historico *h = historicos;
    while (h != NULL) {
        Atendimento *a = h->topo;
        while (a != NULL) {
            Atendimento *temp = a;
            a = a->prox;
            free(temp);
        }
        Historico *tempH = h;
        h = h->prox;
        free(tempH);
    }
}

// =========================
// Main
// =========================
int main() {
    int opcao;
    char cpf[15];

    do {
        cout << "\n===== Sistema de Atendimento =====\n";
        cout << "1. Cadastrar paciente\n";
        cout << "2. Atender paciente\n";
        cout << "3. Visualizar filas de espera\n";
        cout << "4. Visualizar historico de atendimentos\n";
        cout << "5. Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarPaciente();
                break;
            case 2:
                atenderPaciente();
                break;
            case 3:
                visualizarFilas();
                break;
            case 4:
                cout << "Digite o CPF: ";
                cin.ignore();
                cin.getline(cpf, 15);
                listarHistorico(cpf);
                break;
            case 5:
                liberarMemoria();
                cout << "Encerrando...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }

    } while (opcao != 5);

    return 0;
}

