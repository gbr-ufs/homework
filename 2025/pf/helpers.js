const raizQuadrada = (numero) => numero ** 0.5

const aoQuadrado = (numero) => numero ** 2

const arredondarCasasDecimais = (numero, casas) => numero.toFixed(casas)

const soma = (primeiro, segundo) => primeiro + segundo

const somaDeTodos = (numeros) => numeros.reduce(soma)

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

// Associa um número a uma letra do alfabeto.
const numeroParaLetraDoAlfabeto = n => {
    const alfabeto = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"]
    const letra = alfabeto.filter((item, indice) => {
        if (n === (indice + 1)) {
            return item
        }
    })

    // "letra" é uma lista de um elemento. Só retornar ele.
    return letra[0]
}

/** Veja: <https://github.com/hendrikdcomp/pf>.
 * Obrigado Hendrik Macedo <https://github.com/hendrikdcomp>.
 *
 * composite()
 *
 * Função para compor um pipeline de funções.
 */
const composite = (...fns) => (value) => fns.reduce((acc,fn) => fn(acc), value)

export { raizQuadrada, aoQuadrado, arredondarCasasDecimais, soma, somaDeTodos, numeroDeElementos, intervalo, ePrimo, stringificar, inFull, numeroParaLetraDoAlfabeto, composite }
