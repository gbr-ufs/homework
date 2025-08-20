import { arredondarCasasDecimais, soma, somaDeTodos, aoQuadrado, numeroDeElementos, intervalo, ePrimo, stringificar, inFull } from "./helpers.js"

// Contexto.

const carrinho = [
    { nome: 'Caneta', qtde: 10, preco: 7.99, fragil: true },
    { nome: 'Impressora', qtde: 1, preco: 649.50, fragil: true },
    { nome: 'Caderno', qtde: 4, preco: 27.10, fragil: false },
    { nome: 'Lapis', qtde: 3, preco: 5.82, fragil: false },
    { nome: 'Tesoura', qtde: 1, preco: 19.20, fragil: true },
]

const pessoas = [
    'Ana',
    'Bia',
    'Carla',
    'Danta',
    'Eduarda',
    'Fernanda',
    'Gislaine',
    'Helena'
]

// Questão 1.

const taxaDeCambioParaTodos = (lista, taxa) => lista.map((item) => ({
    ...item,
    preco: arredondarCasasDecimais((item.preco * taxa), 2)
}))

console.log(`Itens do carrinho com uma taxa de câmbio de 5.5 vezes:`)
console.log(taxaDeCambioParaTodos(carrinho, 5.5))

const valorTotal = (lista) => arredondarCasasDecimais((lista.map((item) => item.preco).reduce(soma)), 2)

console.log(`Valor total dos itens no carrinho: ${valorTotal(carrinho)}.`)

const desconto = (valor, descontoDecimal) => arredondarCasasDecimais(((1 - descontoDecimal) * valor), 2)

const descontoParaTodos = (lista, descontoDecimal) => desconto(valorTotal(lista), descontoDecimal)

console.log(`Com 50% (0,5) de desconto, o total fica por: ${descontoParaTodos(carrinho, 0.5)}.`)

// "É frágil?".
const eFragil = (item) => {
    if (item.fragil) {
        return item;
    }
}

const valorTotalDosFrageis = (lista) => valorTotal(lista.filter(eFragil))

console.log(`Sendo somente os itens frágeis, fica por: ${valorTotalDosFrageis(carrinho)}.`)

const temComoPrimeiraLetra = (item, letra) => {
    if (item.nome[0] === letra) {
        return item.nome;
    }
}

const temComoPrimeiraLetraParaTodos = (lista, letra) => lista.filter((item) => temComoPrimeiraLetra(item, letra))

const valorTotalPorLetra = (lista, letra) => valorTotal(temComoPrimeiraLetraParaTodos(lista, letra))

console.log(`Indo pelos items tendo letra "C" como inicial, o valor total fica: ${valorTotalPorLetra(carrinho, "C")}.`)

const precoPorProduto = (item) => arredondarCasasDecimais((item.preco * item.qtde), 2)

console.log(`O gasto total nesta compra em relação à somente as canetas foi de ${precoPorProduto(carrinho[0])}.`)

// Questão 2.

const ultimoElemento = (lista) => lista.at(-1)

const penultimoElemento = (lista) => lista.at(-2)

console.log(`Temos a seguinte lista de pessoas:
${pessoas.join(", ")}`)
console.log(`Agora, máquina, me diga qual é a última pessoa dessa lista.
Máquina: "${ultimoElemento(pessoas)}".
Esplêndido! Agora, a penúltima pessoa.
Máquina: "${penultimoElemento(pessoas)}".`)

// Questão 3.

console.log(`Máquina, em relação à última lista, diga-me, quantos elementos ela tem?
Máquina: "${numeroDeElementos(pessoas)}".`)

// Questão 4.

const elementosIguais = (primeiraLista, segundaLista) => {
    return numeroDeElementos(primeiraLista.filter((item) => {
        if (segundaLista.indexOf(item) != -1) {
            return item;
        }
    }))
}

console.log(`Máquina, temos as seguintes listas: ${[1, 5, 2, 7].join(", ")} e ${[1, 2, 3, 4].join(", ")}. Diga-me quantos elementos iguais elas têm.
Máquina: "${elementosIguais([1, 5, 2, 7], [1, 2, 3, 4])}".`)

// Questão 5.

const divisivelPor3 = (numero) => {
    if ((numero % 3) === 0) {
        return numero;
    }
}

const divisivelPor5 = (numero) => {
    if ((numero % 5) === 0) {
        return numero;
    }
}

const divisivelPor3e5 = (numero) => {
    if (divisivelPor3(numero) && divisivelPor5(numero)) {
        return numero;
    }
}

const somaDosMultiplosDe3e5 = (lista) => lista.filter(divisivelPor3e5).reduce(soma)

console.log(`Máquina, agora diga-me qual o resultado da soma de todos os múltiplos de 3 e 5 menores que 1000.
Máquina: "${somaDosMultiplosDe3e5(intervalo(1, 999))}".`)

// Questão 6.

const quadradoDaSoma = (lista) => aoQuadrado(lista.reduce(soma))

const somaDosQuadrados = (lista) => lista.map((item) => aoQuadrado(item)).reduce(soma)

// Eu odeio camelCase.
const diferencaEntreOQuadradoDaSomaEDaSomaDosQuadrados = (lista) => quadradoDaSoma(lista) - somaDosQuadrados(lista)

console.log(`Máquina, por favor, me responda, qual o resultado da diferença
entre o quadrado da soma e a soma dos quadrados dos primeiros 10 números
naturais?
Máquina: "${diferencaEntreOQuadradoDaSomaEDaSomaDosQuadrados(intervalo(1, 10))}".`)

// Questão 7.

const primosMenoresQueUmNumero = (numero) => {

    if (numero < 2) {
        throw new RangeError('primosMenoresQueUmNumero() espera apenas números maiores ou iguais a 2')
    }

    return intervalo((numero - 1), 2).filter(ePrimo)
}

console.log(`Máquina, quais são os números primos menores que dez?
Máquina: ${primosMenoresQueUmNumero(10).join(", ")}.`)

// Questão 8.

const algarismo = (intervalo, numero) => {
    const numeroStringificado = stringificar(numero);
    const algarismos = [...numeroStringificado].filter((valor, indice) => {
        if (indice <= intervalo) {
            return valor;
        }
    })

    // soma também concatena.
    return algarismos.reduce(soma);
}

console.log(`Os primeiros dois algarismos do número 200000 são ${algarismo(1, 200000)}.`)

// Questão 9.

const numeroDeLetras = (numero) => {
    const porExtenso = inFull(numero);
    // O filter é usado para remover os espaços.
    const letras = [...porExtenso].filter((letra) => letra !== " ");

    return numeroDeElementos(letras);
}

console.log(`225 por extenso em inglês tem ${numeroDeLetras(225)} letras.`)

// Questão 10.

const repetirElementos = (lista, vezes) => {
    // Usa a função "intervalo" para criar uma lista contendo sublistas com o
    // tamanho certo.
    const listaComTamanho = lista.map((item) => {
        return item = intervalo(item, item + (vezes - 1));
    });
    // Itera por todas as sublistas e "conserta" o valor delas, que seria o
    // primeiro elemento, pois queremos repitir.
    const listaComValorCerto = listaComTamanho.map((sublista) => {
        return sublista.map((item) => item = sublista[0]);
        });

    return listaComValorCerto.join();
}

console.log(repetirElementos([1, 2, 3], 4))
