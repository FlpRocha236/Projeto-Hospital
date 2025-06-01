
# 🏥 Sistema de Atendimento para Unidade de Saúde (C++ Estruturado)

Este é um sistema simples de gerenciamento de atendimentos para uma unidade de saúde, desenvolvido em **C++ estruturado**, aplicando os conceitos da aula de **estruturas de dados (Fila e Pilha)**, sem uso da STL.

---

## 🚀 Funcionalidades

- ✅ **Cadastro de Pacientes**
  - Nome
  - CPF
  - Tipo de atendimento: **Comum** ou **Prioritário**

- ✅ **Gerenciamento de Filas**
  - Fila **prioritária** (idosos, gestantes, etc.)
  - Fila **comum**
  - A fila prioritária tem preferência no atendimento.

- ✅ **Atendimento**
  - Chama o próximo paciente (priorizando os prioritários).
  - Registra o atendimento no **histórico do paciente** (pilha).

- ✅ **Visualização de Filas**
  - Lista todos os pacientes aguardando nas filas (prioritária e comum).

- ✅ **Histórico de Atendimentos**
  - Consulta o histórico de atendimentos por CPF.
  - O histórico segue o padrão de uma **pilha (LIFO)**: mostra do atendimento mais recente ao mais antigo.

- ✅ **Gerenciamento de Memória**
  - Ao encerrar o sistema, toda a memória alocada é liberada corretamente.

---

## 🧱 Estruturas de Dados Utilizadas

- 🔗 **Fila (FIFO)**
  - Gerencia a ordem de chegada dos pacientes.
  - Implementada com ponteiros (`inicio` e `fim`).

- 🗂️ **Pilha (LIFO)**
  - Armazena o histórico de atendimentos de cada paciente.
  - Implementada manualmente, sem STL.

---

## 📜 Funcionalidades do Menu

| Opção | Funcionalidade                                    |
|-------|---------------------------------------------------|
| 1     | Cadastrar Paciente                                |
| 2     | Atender Próximo Paciente                          |
| 3     | Visualizar Filas de Espera                        |
| 4     | Visualizar Histórico de Atendimentos (por CPF)    |
| 5     | Sair e Liberar Memória                            |

---

## 🔧 Tecnologias e Regras

- **Linguagem:** C++
- **Paradigma:** Programação Estruturada

---

## 📦 Estrutura do Projeto

```
/Projeto Hospital
│
├── ProjetoHosp.dev    → Arquivo de configuração do projeto do Dev-C++
├── ProjetoHosp.exe    → Arquivo executável final
├── ProjetoHosp.layout → Layout do Projeto
├── README.md          → Documentação do projeto
├── mainHosp.cpp       → Código fonte principal
└── mainHosp.o         → Arquivo objeto

```

---

## 🧠 Como Funciona

### ✔️ Cadastro de Pacientes
- O usuário informa:
  - Nome
  - CPF
  - Tipo de atendimento (`Comum` ou `Prioritario`)
- O paciente é inserido na fila correspondente.

### ✔️ Atendimento
- O sistema prioriza a fila **prioritária**.
- Após atender, registra-se uma descrição do atendimento no histórico (pilha).

### ✔️ Histórico
- Para cada paciente, os atendimentos são armazenados em pilhas separadas.
- Consulta exibida em **ordem reversa**, mostrando primeiro o atendimento mais recente.

### ✔️ Memória
- Toda a memória alocada dinamicamente é liberada corretamente ao encerrar o programa.

---

## 🧑‍💻 Desenvolvido por

- **Felipe Rocha**
- 🔗 *[https://github.com/FlpRocha236]*
