#include <stdio.h>
#define MAX_PLANTOES 100
int main() {
int ids[MAX_PLANTOES];
int matriculas[MAX_PLANTOES];
int setores[MAX_PLANTOES];
char turnos[MAX_PLANTOES];
int totalPlantoes = 0;
int proximoId = 1;
int opcao;
do {
printf("\n=== CONTROLE DE PLANTOES ===\n");
printf("1. Cadastrar Plantao\n");
printf("2. Listar Plantoes\n");
printf("3. Atualizar Plantao\n");
printf("4. Excluir Plantao\n");
printf("5. Sair\n");
printf("Escolha uma opcao: ");
scanf("%d", &opcao);
if (opcao == 1) {
// CREATE
if (totalPlantoes < MAX_PLANTOES) {
ids[totalPlantoes] = proximoId;
printf("Matricula do profissional: ");
scanf("%d", &matriculas[totalPlantoes]);
// Validação do Setor
do {
printf("Setor (1-UTI, 2-Emergencia, 3-Triagem): ");
scanf("%d", &setores[totalPlantoes]);
if (setores[totalPlantoes] < 1 || setores[totalPlantoes] > 3) {
printf("-> ERRO: Setor invalido! Digite apenas 1, 2 ou 3.\n");
}
} while (setores[totalPlantoes] < 1 || setores[totalPlantoes] > 3);
// Validação do Turno (Linhas corrigidas aqui)
do {

printf("Turnos disponiveis:\n");
printf(" D - Diurno-SD (7h as 19h)\n");
printf(" N - Noturno-SN (19h as 7h)\n");
printf(" M - Manha (7h as 13h)\n");
printf(" T - Tarde (13h as 19h)\n");
printf("Digite a letra correspondente: ");
scanf(" %c", &turnos[totalPlantoes]);
if (turnos[totalPlantoes] != 'D' && turnos[totalPlantoes] != 'd' &&
turnos[totalPlantoes] != 'N' && turnos[totalPlantoes] != 'n' &&
turnos[totalPlantoes] != 'M' && turnos[totalPlantoes] != 'm' &&
turnos[totalPlantoes] != 'T' && turnos[totalPlantoes] != 't') {
printf("-> ERRO: Turno invalido! Use apenas D, N, M ou T.\n");
}
} while (turnos[totalPlantoes] != 'D' && turnos[totalPlantoes] != 'd' &&
turnos[totalPlantoes] != 'N' && turnos[totalPlantoes] != 'n' &&
turnos[totalPlantoes] != 'M' && turnos[totalPlantoes] != 'm' &&
turnos[totalPlantoes] != 'T' && turnos[totalPlantoes] != 't');
totalPlantoes++;
proximoId++;
printf("Plantao cadastrado com sucesso!\n");
} else {
printf("Erro: Capacidade maxima atingida.\n");
}
} else if (opcao == 2) {
// READ
if (totalPlantoes == 0) {
printf("Nenhum plantao cadastrado no momento.\n");
} else {
printf("\n--- LISTA DE PLANTOES ---\n");
for (int i = 0; i < totalPlantoes; i++) {
printf("ID: %d | Matricula: %d | Cod. Setor: %d | Turno: ",
ids[i], matriculas[i], setores[i]);
if (turnos[i] == 'D' || turnos[i] == 'd') {
printf("SD (7h as 19h)\n");
} else if (turnos[i] == 'N' || turnos[i] == 'n') {
printf("SN (19h as 7h)\n");
} else if (turnos[i] == 'M' || turnos[i] == 'm') {
printf("Manha (7h as 13h)\n");
} else if (turnos[i] == 'T' || turnos[i] == 't') {
printf("Tarde (13h as 19h)\n");

}
}
}
} else if (opcao == 3) {
// UPDATE
int idBusca, encontrado = 0;
printf("Digite o ID do plantao que deseja atualizar: ");
scanf("%d", &idBusca);
for (int i = 0; i < totalPlantoes; i++) {
if (ids[i] == idBusca) {
printf("Nova matricula do profissional: ");
scanf("%d", &matriculas[i]);
// Validação do Novo Setor
do {
printf("Novo setor (1-UTI, 2-Emergencia, 3-Triagem): ");
scanf("%d", &setores[i]);
if (setores[i] < 1 || setores[i] > 3) {
printf("-> ERRO: Setor invalido!\n");
}
} while (setores[i] < 1 || setores[i] > 3);
// Validação do Novo Turno
do {
printf("Novos turnos disponiveis:\n");
printf(" D - Diurno-SD (7h as 19h)\n");
printf(" N - Noturno-SN (19h as 7h)\n");
printf(" M - Manha (7h as 13h)\n");
printf(" T - Tarde (13h as 19h)\n");
printf("Digite a letra correspondente: ");
scanf(" %c", &turnos[i]);
if (turnos[i] != 'D' && turnos[i] != 'd' &&
turnos[i] != 'N' && turnos[i] != 'n' &&
turnos[i] != 'M' && turnos[i] != 'm' &&
turnos[i] != 'T' && turnos[i] != 't') {
printf("-> ERRO: Turno invalido!\n");
}
} while (turnos[i] != 'D' && turnos[i] != 'd' &&
turnos[i] != 'N' && turnos[i] != 'n' &&
turnos[i] != 'M' && turnos[i] != 'm' &&
turnos[i] != 'T' && turnos[i] != 't');

encontrado = 1;
printf("Plantao atualizado com sucesso!\n");
break;
}
}
if (!encontrado) {
printf("ID nao encontrado.\n");
}
} else if (opcao == 4) {
// DELETE
int idBusca, encontrado = 0;
printf("Digite o ID do plantao que deseja excluir: ");
scanf("%d", &idBusca);
for (int i = 0; i < totalPlantoes; i++) {
if (ids[i] == idBusca) {
encontrado = 1;
for (int j = i; j < totalPlantoes - 1; j++) {
ids[j] = ids[j + 1];
matriculas[j] = matriculas[j + 1];
setores[j] = setores[j + 1];
turnos[j] = turnos[j + 1];
}
totalPlantoes--;
printf("Plantao excluido com sucesso!\n");
break;
}
}
if (!encontrado) {
printf("ID nao encontrado.\n");
}
} else if (opcao == 5) {
printf("Encerrando o sistema...\n");
} else {
printf("Opcao invalida. Tente novamente.\n");
}
} while (opcao != 5);
return 0;
}