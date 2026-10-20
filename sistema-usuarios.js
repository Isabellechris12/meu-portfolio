const prompt = require('prompt-sync')();

let time = []; // essa array irá trabalhar apenas com strings.
let continuar = true;

while (continuar) {
    let opcao = prompt("Digite sua opção: 1 (Para cadastrar um usuário), 2 (Para remover um jogador) ou 3 (Para sair do programa): ");

    if (opcao == "1") {
        let nomeJogador = prompt("Digite o nome do jogador: ");

        time.push(nomeJogador);
        console.log("Jogador " + nomeJogador + " cadastrado com sucesso!");
        console.log("O seu time atual é: ", time);
        console.log("---------------------------------------------------");
    } else if (opcao === "2") {
        if (time.length === 0) {
            console.log("Seu time está vazio!");
            continue;
        }

        let nomeDeletado = prompt("Digite o nome do jogador que deseja deletar: ");
        let index = time.indexOf(nomeDeletado);

        if (index === -1) {
            console.log("Jogador não encontrado!");
            continue;
        }

        time.splice(index, 1);
        console.log("Jogador " + nomeDeletado + " removido com sucesso!");
        console.log("O seu time atual é: ", time);
        console.log("---------------------------------------------------");
    } else if (opcao == "3") {
        continuar = false;
    } else {
        console.log("Opção inválida, tente novamente!");
    }
}

