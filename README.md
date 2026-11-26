# 💻 Projeto Final: Sistema de Cadastro em C

Projeto Final desenvolvido por **mim** e pelo meu grupo, aluno(a) do curso de **ADS**, na disciplina **Coding**.

---

## 📖 Sobre o projeto

Este projeto é um **sistema de cadastro** feito em **linguagem C**, executado no **terminal** por meio de um menu interativo.

O tema escolhido pelo grupo é **Cadastro de Alunos**. O sistema permite cadastrar, listar, buscar, editar e remover registros, que ficam armazenados em um vetor de structs com alocação dinâmica de memória.

## 🎯 Objetivo

Integrar em um único programa o conteúdo da disciplina: **condicionais**, **laços**, **funções**, **vetores**, **strings**, **ponteiros**, **structs** e **alocação dinâmica**.

## 🚀 Funcionalidades

- **Cadastrar:** adiciona um novo registro, com validação dos dados digitados.
- **Listar:** exibe todos os registros cadastrados.
- **Buscar:** localiza um registro a partir de um critério (ex.: nome ou código).
- **Editar:** altera os dados de um registro existente.
- **Remover:** exclui um registro e desloca os seguintes uma posição para preencher o espaço.
- **Sair:** encerra o programa e libera a memória alocada.

## 🛠️ Conceitos aplicados

| Conceito | Uso no projeto |
|---|---|
| **do-while + switch** | Menu que roda até o usuário escolher sair |
| **struct** | Representa o registro, com pelo menos 4 campos (texto, inteiro e real) |
| **malloc** | Alocação inicial do vetor de structs |
| **realloc** | Ampliação do vetor quando ele enche |
| **Funções** | Mínimo de 5, cada uma com responsabilidade clara |
| **fgets** | Leitura de textos, tratando o `\n` final |
| **Validação e boas práticas** | Validação de entrada, teste de retorno `NULL` e `free` ao final |

## ⚙️ Como compilar e executar

```bash
gcc main.c -o cadastro
./cadastro
```

No Windows, execute `cadastro.exe` no lugar de `./cadastro`.

## ✅ Requisitos da atividade

- [x] Menu com `do-while` + `switch`, rodando até o usuário escolher sair
- [x] `struct` com pelo menos 4 campos (um texto, um inteiro e um real)
- [x] Vetor de structs alocado com `malloc` e ampliado com `realloc` quando encher
- [x] Operações: cadastrar, listar, buscar, editar e remover
- [x] Mínimo de 5 funções com responsabilidade clara
- [x] Textos lidos com `fgets`, tratando o `\n` final
- [x] Validação de entrada, teste de retorno `NULL` e `free` ao final
- [x] Nome de todos os integrantes em comentário no início do código

### ⭐ Opcionais

- [ ] Salvar e carregar os registros em arquivo
- [ ] Console formatado (limpar tela, bordas, alinhamento)
- [ ] Separação do código em arquivos `.h` e `.c`

## 👥 Integrantes

- Iarlley
- [Integrante 2]
- [Integrante 3]
- [Integrante 4]

## 👤 Autor

**Iarlley**
/ GitHub: [@Patinhokkjj](https://github.com/Patinhokkjj)

---

📚 Projeto desenvolvido para fins acadêmicos.
