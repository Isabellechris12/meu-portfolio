const prompt = require('prompt-sync')();


console.log("---------Cadastro de Novo Recruta---------");
let novoNome = prompt("Digite o nome completo do novo jogador: ");
let pontuacao = Number(prompt("Digite a pontuação desse jogador: "));




 //verificar se o sistema está funcionando corretamente
console.log("Sucesso!! O jogador " + novoNome + " foi cadastrado com sucesso!! E sua pontuação é: "
    + pontuacao + " pontos!");


console.log("O nome completo do novo jogador é:  ", novoNome);
console.log("A sua pontuação é:  ", pontuacao);
