import { composite } from "./helpers.js"

// Questão 1.

const sequenciaComeca3 = n => {
    if (n === 1) {
        return 3
    } else {
        return sequenciaComeca3(n - 1) * 2
    }
}

console.log(sequenciaComeca3(5))

// Questão 2.

const fibonacci = n => {
    if (n === 1) {
        return 0
    } else if (n === 2) {
        return 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2)
    }
}

console.log(fibonacci(11))

// Questão 3.

const somaDosNaturais = n => {
    if (n === 0) {
        return n
    } else {
        return n + somaDosNaturais(n - 1)
    }
}

console.log(somaDosNaturais(5))

// Questão 4.

const fatorial = n => {
    if (n === 1) {
        return 1
    } else {
        return n * fatorial(n - 1)
    }
}

console.log(fatorial(4))

// Questão 5.

const potenciaNaturalDo2 = n => {
    if (n === 1) {
        return 2
    } else {
        return 2 * potenciaNaturalDo2(n - 1)
    }
}

console.log(potenciaNaturalDo2(11))

// Questão 6.

const resto = (n, m) => {
    const divisaoPorZero = new RangeError("Não é possível dividir por zero")

    if (m === 0) {
        throw divisaoPorZero
    }
    if (n < m) {
        return n
    } else {
        return resto((n - m), m)
    }
}

console.log(resto(6, 3))

// Questão 7.

const quociente = (n, m) => {
    const divisaoPorZero = new RangeError("Não é possível dividir por zero")

    if (m === 0) {
        throw divisaoPorZero
    } else if (n < m) {
        return 0
    } else {
        return 1 + quociente((n - m), m)
    }
}

console.log(quociente(10, 5))

// Questão 8.

// Máximo Divisor Comum.
const mdc = (n, m) => {
    if (resto(n, m) == 0) {
        return m
    } else {
        return mdc(m, resto(n, m))
    }
}

console.log(mdc(6, 12))

// Questão 9.

// Mínimo Múltiplo Comum.
const mmc = (n, m) => {
    const restoDosDois = resto(n, m)

    if (restoDosDois === 0) {
        return n
    } else {
        return quociente((n * mmc(m, restoDosDois)), restoDosDois)
    }
}

// Questão 10.

const tamanho = texto => {
    // Se texto não for uma string, ele é convertido em uma.
    const textoNormalizado = texto + ""
    // O filter é usado para remover os espaços.
    const letrasDoTexto = [...textoNormalizado].filter((letra) => letra !== " ")

    if (letrasDoTexto[0] === undefined) {
        return 0
    } else {
        return 1 + tamanho(textoNormalizado.substring(1))
    }
}

console.log(tamanho("lasanha"))

// Questão 11.

// Obrigado Tarcisio Almeida Mascarenhas.
const multiSoma = n => {
    if (n === 0) {
        return n
    }

    const multiSomaAux = (multiplicador) => {
        if (multiplicador === 0) {
            return 0
        } else {
            return (n * multiplicador) + multiSomaAux(multiplicador - 1)
        }
    }

    return multiSomaAux(10)
}

console.log(multiSoma(2))

// Questão 12.

const inverte = texto => {
    const inverteAux = (textoOriginal, contador) => {
        const incremento = contador + 1
        const primeiraLetra = textoOriginal[0]

        if (contador === (tamanho(texto) - 1)) {
            return textoOriginal
        } else {
            return inverteAux(textoOriginal.substring(1), incremento) + primeiraLetra
        }
    }

    return inverteAux(texto, 0)
}

console.log(inverte("lasanha"))

// Questão 13.

const somaQuadrados = n => {
    if (n === 0) {
        return n
    } else if (n > 0) {
        return n ** 2 + somaQuadrados(n - 1)
    } else {
        return n ** 2 + somaQuadrados(n + 1)
    }
}

console.log(somaQuadrados(5))


// Questão 14.

const repita = (txt, n, separador=" ") => {
    if (n === 0) {
        return txt
    } else {
        return `${txt}${separador}${repita(txt, n - 1)}`
    }
}

console.log(repita("repete", 4))

// Questão 15.

// TODO: Deixar recursivo.
// const caminhos = n => fatorial(n)

// Questão 16.

const dec2 = n => base => {
    const nStringado = n + ""
    const nArrayzado = nStringado.split("")
    const len = tamanho(nStringado)

    const dec2Aux = ([x, ...xs], tam, base) => {
        if (tam === 0) {
             return 0
        } else {
            return x * base ** (tam - 1) + dec2Aux(xs, (tam - 1))
        }
    }

    return dec2Aux(nArrayzado, len, base)
}

console.log(dec2(10)(2))

// Questão 17.

const collatz = n => {
    // "É par?".
    const ePar = n => {
        if (n % 2 === 0) {
            return true
        }
    }

    const par = n => {
        return n / 2
    }

    const impar = n => {
        return n * 3 + 1
    }

    if (n === 1) {
        return 0
    }

    if (ePar(n)) {
        return 1 + collatz(par(n))
    } else {
        return 1 + collatz(impar(n))
    }
}

console.log(collatz(10))

// Questão 18.

const palindromo = texto => {
    const textoMinusculo = texto.toLowerCase()
    const alfabeto = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    const textoSemEspacos = [...textoMinusculo].filter((letra) => alfabeto.includes(letra)).join("")
    const acentosDeA = ["á", "ã", "â", "à"]
    const acentosDeE = ["é", "ê"]
    const acentosDeI = ["í"]
    const acentosDeO = ["ó", "ô", "õ"]
    const acentosDeU = ["u"]

    const substituirAcentos = (acentos, semAcento) => texto => {
        const textoArrayzado = [...texto]
        const letraSubstituida = textoArrayzado.map((item) => {
            if (acentos.indexOf(item) !== -1) {
                return item = semAcento
            } else {
                return item
            }
        })

        return letraSubstituida.join("")
    }

    const substituirAcentosDeA = substituirAcentos(acentosDeA, "a")
    const substituirAcentosDeE = substituirAcentos(acentosDeE, "e")
    const substituirAcentosDeI = substituirAcentos(acentosDeI, "i")
    const substituirAcentosDeO = substituirAcentos(acentosDeO, "o")
    const substituirAcentosDeU = substituirAcentos(acentosDeU, "u")

    const textoNormalizado = composite(substituirAcentosDeA, substituirAcentosDeE, substituirAcentosDeI, substituirAcentosDeO, substituirAcentosDeU)(textoSemEspacos)

    if (tamanho(textoNormalizado) < 2) {
        return true
    } else {
        const primeiro = textoNormalizado.slice(0, 1)
        const ultimo = textoNormalizado.slice(-1)
        const meio = textoNormalizado.slice(1, -1)

        return (primeiro === ultimo) && palindromo(meio)
    }
}

console.log(palindromo("Socorram-me, subi no ônibus em marrocos!"))

// Questão 19

// TODO: Deixar recursivo.
// const ndigitospermut = n => tamanho(fatorial(n))

// Questão 20

