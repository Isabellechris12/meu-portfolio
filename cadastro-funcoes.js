const prompt = require('prompt-sync')();

let time = []; // esse array armazena objetos (jogadores).
let continuar = true;

function mostrarMenu() {
    console.log("\n===========================");
    console.log("    Bem-vindo ao sistema de gerenciamento de time!     ");
    console.log("Digite 1 para CADASTRAR um(a) jogador(a).");
    console.log("Digite 2 para REMOVER um(a) jogador(a).");
    console.log("Digite 3 para MOSTRAR o time.");
    console.log("Digite 4 para CALCULAR A MÉDIA da equipe.");
    console.log("Digite 5 para SAIR do programa.");
    console.log("----------------------------------------------------");
}

function mostrarTime() {
    if (time.length === 0) {
        console.log("Seu time está vazio!");
        return;
    }

    for (let i = 0; i < time.length; i++) {
        let jogador = time[i]; // mostra o jogador e a sua posição no array.
        console.log(`(${i + 1}) ${jogador.nome} | Função: ${jogador.funcao} | Pontuação: ${jogador.pontuacao}`);
    }
}

function cadastrarJogador() {
    let nomeJogador = prompt("Digite o nome do(a) jogador(a): ");
    let funcaoJogador = prompt("Digite a função do(a) jogador(a): ");
    let pontuacaoJogador = Number(prompt("Digite a pontuação do(a) jogador(a): ")); // transforma a pontuação em número.

    if (isNaN(pontuacaoJogador) || pontuacaoJogador < 0) {
        console.log("Pontuação inválida! Digite um número válido.");
        return;
    }

    // cria um objeto para armazenar todas as informações do jogador.
    let jogador = {
        nome: nomeJogador,
        funcao: funcaoJogador,
        pontuacao: pontuacaoJogador
    };

    time.push(jogador); // adiciona o objeto no array time (apenas uma vez).
    console.log(`Jogador(a) ${nomeJogador} cadastrado(a) com sucesso!`);
}

function removerJogador() {
    if (time.length === 0) {
        console.log("Seu time está vazio!");
        return;
    }

    let nomeDeletado = prompt("Digite o nome do(a) jogador(a) que deseja deletar: ");
    let indexDeletado = -1;

    // procura o jogador pelo nome dentro do time.
    for (let i = 0; i < time.length; i++) {
        if (time[i].nome === nomeDeletado) {
            indexDeletado = i;
            break;
        }
    }

    if (indexDeletado === -1) {
        console.log("Jogador(a) não encontrado(a)!");
        return;
    }

    time.splice(indexDeletado, 1);
    console.log("Jogador(a) removido(a) com sucesso!");
    console.log("---------------------------------------------------");
}

function calcularMedia() {
    if (time.length === 0) {
        console.log("Nenhum(a) jogador(a) cadastrado(a)!");
        return;
    }

    let totalPontos = 0;

    for (let i = 0; i < time.length; i++) {
        totalPontos += time[i].pontuacao;
    }

    let mediaPontos = totalPontos / time.length;
    console.log("Média de pontuação: " + mediaPontos);
    console.log("O time possui uma pontuação total de " + totalPontos + " pontos.");
}

while (continuar) {
    mostrarMenu();
    let opcao = prompt("Digite sua opção: ");

    if (opcao === "1") {
        cadastrarJogador();
    } else if (opcao === "2") {
        removerJogador();
    } else if (opcao === "3") {
        mostrarTime();
    } else if (opcao === "4") {
        calcularMedia();
    } else if (opcao === "5") {
        console.log("Saindo do programa...");
        continuar = false;
    } else {
        console.log("Opção inválida, tente novamente!");
    }
}

