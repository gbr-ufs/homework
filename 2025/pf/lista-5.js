// Helpers.

const arredondarCasasDecimais = (numero, casas) => numero.toFixed(casas)

const soma = (primeiro, segundo) => primeiro + segundo

const somaDeTodos = (numeros) => numeros.reduce(soma)

const aoQuadrado = (numero) => numero ** 2

const numeroDeElementos = (lista) => lista.map((valor) => valor = 1).reduce(soma)

/** Veja: <https://github.com/hendrikdcomp/pf>.
 * Obrigado Hendrik Macedo <https://github.com/hendrikdcomp>.
 * (Adaptada)
 *
 * intervalo()
 *
 * Retorna um conjunto de números entre um número inicial e um número final incrementado
 * sequencialmente por um número fixo (passo), começando com o número inicial ou
 * o número final, dependendo de qual é menor.
 * Exemplo: intervalo(3,9) ---> [3,4,5,6,7,8,9]
 * Exemplo: intervalo(8,0,2) ---> [8,6,4,2,0]
 * Exemplo: intervalo(1,5,0.5) ---> [1,1.5,2,2.5,3,3.5,4,4.5,5]
 */
const intervalo = (inicio, fim, incremento = 1) => {

    // Testa se os 3 primeiros argumentos são números finitos.
    const todosOsNumeros = [inicio, fim, incremento].every(Number.isFinite)

    if (!todosOsNumeros) {
        throw new TypeError('intervalo() espera apenas números finitos como argumentos')
    }

    if (incremento <= 0) {
        throw new RangeError('incremento dever ser um número maior que zero')
    }

    // Quando o número inicial for maior que o final, modifica a direção da
    // função.
    if (inicio > fim) {
        incremento = -incremento
    }

    // Deixa a seleção de valores inclusiva.
    const comprimento = Math.floor(Math.abs((fim - inicio) / incremento)) + 1

    return Array.from(Array(comprimento), (x, indice) => inicio + indice * incremento)
}

/** "É primo?".
 * Cria uma lista a partir do número dois (um não conta pois divide todos) e
 * verifica, número por número, quais dividem NUMERO. Se a lista possuir mais
 * de um item, quer dizer que o número não é primo.
 */
const ePrimo = (numero) => {
    const de2AteONumero = intervalo(2, numero)
    const divisores = de2AteONumero.filter((item) => {
        if (numero % item === 0) {
            return numero;
        } else {
            return false;
        }
    })

    if (numeroDeElementos(divisores) > 1) {
        return false;
    } else {
        return true;
    }
}

const stringificar = (numero) => numero + ""

/** Veja: <https://medium.com/@alecgilchrist/converting-numbers-to-english-using-javascript-3967af74db0b>.
 * Obrigado Alec Gilchrist <https://medium.com/@alecgilchrist>.
* (Adaptada)
 *
* inFull()
 *
* "Por extenso" em inglês. Retorna um número por extenso.
 */
const inFull = (number) => {
    const numberToFull = {
        0: 'zero',
        1: 'one',
        2: 'two',
        3: 'three',
        4: 'four',
        5: 'five',
        6: 'six',
        7: 'seven',
        8: 'eight',
        9: 'nine',
        10: 'ten',
        11: 'eleven',
        12: 'twelve',
        13: 'thirteen',
        14: 'fourteen',
        15: 'fifteen',
        16: 'sixteen',
        17: 'seventeen',
        18: 'eighteen',
        19: 'nineteen',
        20: 'twenty',
        30: 'thirty',
        40: 'forty',
        50: 'fifty',
        60: 'sixty',
        70: 'seventy',
        80: 'eighty',
        90: 'ninety'
    };

    const numberToPlace = {
        10: 'ten',
        100: 'hundred',
        1000: 'thousand'
    };

    const recursive = (number) => {
        if (numberToFull[number]) {
            return numberToFull[number];
        } else if (number < 100) {
            // Divide 21, por exemplo, em 20 e 1.
            const placeValueNumber = Math.floor(number / 10) * 10;
            const toBeRecursed = number % 10;

            return numberToFull[placeValueNumber] + " " + numberToFull[toBeRecursed];
        } else {
            if (number < 1000) {
                const place = 100;
                const placeValueNumber = Math.floor(number / place);
                const toBeRecursed = number % place;
                const restOfNumber = recursive(toBeRecursed);

                if (restOfNumber !== "zero") {
                    return recursive(placeValueNumber) + " " + numberToPlace[place] + " " + restOfNumber;
                } else {
                    return recursive(placeValueNumber) + " " + numberToPlace[place]
                }
            } else {
                const increasePlace = (number, place) => {
                    const placeTimesAThousand = place * 1000;

                    if (placeTimesAThousand <= number) {
                        increasePlace(number, placeTimesAThousand);
                    } else {
                        return place;
                    }
                }
                const place = increasePlace(number, 1000);
                const placeValueNumber = Math.floor(number / place);
                const toBeRecursed = number % place;
                const restOfNumber = recursive(toBeRecursed);

                if (restOfNumber !== "zero") {
                    return recursive(placeValueNumber) + " " + numberToPlace[place] + " " + restOfNumber;
                } else {
                    return recursive(placeValueNumber) + " " + numberToPlace[place]
                }
            }
        }
    }

    return recursive(number);
}

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

console.log(`Temos a seguinte lista de pessoas:`)
console.log(`${pessoas.join(", ")}.`)
console.log(`Agora, máquina, me diga qual é a última pessoa dessa lista.`)
console.log(`Máquina: "${ultimoElemento(pessoas)}".`)
console.log(`Esplêndido! Agora, a penúltima pessoa.`)
console.log(`Máquina: "${penultimoElemento(pessoas)}".`)

// Questão 3.

console.log(`Máquina, em relação à última lista, diga-me, quantos elementos ela tem?`)
console.log(`Máquina: "${numeroDeElementos(pessoas)}".`)

// Questão 4.

const elementosIguais = (primeiraLista, segundaLista) => {
    return numeroDeElementos(primeiraLista.filter((item) => {
        if (segundaLista.indexOf(item) != -1) {
            return item;
        }
    }))
}

console.log(`Máquina, temos as seguintes listas: ${[1, 2, 3, 4].join(", ")} e ${[1, 2, 3, 4].join(", ")}. Diga-me quantos elementos iguais elas têm.`)
console.log(`Máquina: "${elementosIguais([1, 5, 2, 7], [1, 2, 3, 4])}".`)

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

console.log(`Máquina, agora diga-me qual o resultado da soma de todos os múltiplos de 3 e 5 menores que 1000.`)
console.log(`Máquina: "${somaDosMultiplosDe3e5(intervalo(1, 999))}".`)

// Questão 6.

const quadradoDaSoma = (lista) => aoQuadrado(lista.reduce(soma))

const somaDosQuadrados = (lista) => lista.map((item) => aoQuadrado(item)).reduce(soma)

// Eu odeio camelCase.
const diferencaEntreOQuadradoDaSomaEDaSomaDosQuadrados = (lista) => quadradoDaSoma(lista) - somaDosQuadrados(lista)

console.log(`Máquina, por favor, me responda, qual o resultado da diferença
entre o quadrado da soma e a soma dos quadrados dos primeiros 10 números
naturais?`)
console.log(`Máquina: "${diferencaEntreOQuadradoDaSomaEDaSomaDosQuadrados(intervalo(1, 10))}".`)

// Questão 7.

const primosMenoresQueUmNumero = (numero) => {

    if (numero < 2) {
        throw new RangeError('primosMenoresQueUmNumero() espera apenas números maiores ou iguais a 2')
    }

    return intervalo((numero - 1), 2).filter(ePrimo)
}

console.log(`Máquina, quais são os números primos menores que dez?`)
console.log(`Máquina: ${primosMenoresQueUmNumero(10).join(", ")}.`)

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
