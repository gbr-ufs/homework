// Helpers.

const raizQuadrada = (numero) => numero ** 0.5

const aoQuadrado = (numero) => numero ** 2

// Verifica se duas entre três condições são verdadeiras.
const checkDuasCondicoes = (primeira, segunda, terceira) => {
    const primeiraESegunda = primeira && segunda;
    const segundaETerceira = segunda && terceira;
    const primeiraETerceira = primeira && terceira;

    if (primeiraESegunda || segundaETerceira || primeiraETerceira) {
        return true;
    } else {
        return false;
    }
}

const modulo = (numero) => {
    if (numero < 0) {
        return -numero;
    } else {
        return numero;
    }
}

// Questão 1.

const areaRetangulo = (base, altura) => base * altura

console.log("Questão 1");
console.log(`A área de um retângulo de 5x4cm é igual a
${areaRetangulo(5, 4)}cm².`);

// Questão 2.

const areaCirculo = (raio) => {
    const PI = 3.14;

    return PI * aoQuadrado(raio);
}

console.log("Questão 2");
console.log(`A área de uma circunferência com 10cm de raio é aproximadamente
igual a ${areaCirculo(10)}cm².`);

// Questão 3.

// Podemos determinar se um polígono é um triângulo por seus lados.
// Se a soma de dois lados for maior que um terceiro lado, é um triângulo.
// Nome: "é Triângulo?" ou "isTriangle".
const eTriangulo = (lado1, lado2, lado3) => {
    const checkLados =
          (primeiro, segundo, terceiro) => primeiro + segundo >= terceiro;
    const umMaisDois = checkLados(lado1, lado2, lado3);
    const doisMaisUm = checkLados(lado2, lado1, lado3);
    const umMaisTres = checkLados(lado1, lado3, lado2);

    return (umMaisDois) && (doisMaisUm) && (umMaisTres);  
}

console.log("Questão 3");
console.log(`Máquina, podendo responder "true" para verdadeiro, e "false" para
falso, diga-me se um polígono de lados de tamanhos 45, 60 e 75 é um triângulo.
Máquina: ${eTriangulo(45, 60, 75)}.`);

// Questão 4.

const classifiqueTriangulo = (lado1, lado2, lado3) => {
    // Todos os lados iguais.
    const condicaoEquilatero = lado1 === lado2 && lado2 === lado3;

    // Isso não funciona:
    // const condicaoEquilatero = lado1 === lado2 === lado3;

    // Quaisquer dois lados iguais.
    const condicaoIsosceles =
          lado1 === lado2 || lado1 === lado3 || lado2 === lado3;

    if (condicaoEquilatero) {
        return "equilátero";
    } else if (condicaoIsosceles) {
        return "isósceles";
    } else {
        // Todos os lados são diferentes.
        return "escaleno";
    }
}

console.log("Questão 4");
console.log(`Um triângulo de lados 30cm, 40cm, 40cm é classificado, em relação
aos lados, como um triângulo ${classifiqueTriangulo(30, 40, 40)}.`);

// Questão 5.

const distanciaEntreDoisPontos = (xDoPonto1, yDoPonto1, xDoPonto2, yDoPonto2) => {
    const diferencaDeX = modulo(xDoPonto2 - xDoPonto1);
    const diferencaDeY = modulo(yDoPonto2 - yDoPonto1);

    // Paralela à ordenada.
    if (xDoPonto1 === xDoPonto2) {
        return diferencaDeY;
    } else if (yDoPonto1 === yDoPonto2) {
        return diferencaDeX;
    } else {
        return raizQuadrada(diferencaDeX ** 2 + diferencaDeY ** 2);
    }
}

console.log("Questão 5");
console.log(`A diferença entre os pontos A(3, 5) e B(6, 1) é igual a
${distanciaEntreDoisPontos(3, 5, 6, 1)}.`);

// Questão 6.

const quantosIguais = (primeiro, segundo, terceiro) => {
    const todosIguais = primeiro === segundo && segundo === terceiro;
    const apenasUmDiferente =
          primeiro === segundo || segundo === terceiro || primeiro === terceiro;

    if (todosIguais) {
        return 3;
    } else if (apenasUmDiferente) {
        return 2;
    } else {
        return 0;
    }
}

console.log("Questão 6");
console.log(`Máquina, os números:

- 7;
- 7;
- 7;

São todos iguais? Se sim, retorne 3:
Máquina: ${quantosIguais(7, 7, 7)}.`);

// Questão 7.

const qualOMenor = (primeiro, segundo) => {
    if (primeiro <= segundo) {
        return primeiro;
    } else {
        return segundo;
    }
}

console.log("Questão 7");
console.log(`Máquina, entre 24, 3 e 129, qual é o menor número?
Máquina: ${qualOMenor(24, qualOMenor(3, 129))}.`);

// Questão 8.

const aQuartaPotencia = (numero) => {
    const elevadoAoQuadrado = aoQuadrado(numero);

    return aoQuadrado(elevadoAoQuadrado);
}

console.log("Questão 8");
console.log(`5 elevado à quarta potência é igual a ${aQuartaPotencia(5)}.`);

// Questão 9.

// XOR.
const ouExclusivo = (primeiro, segundo) => {

    return (primeiro || segundo) && !(primeiro && segundo);
}

console.log("Questão 9");
console.log(`Máquina, dados os seguintes pares de booleanos, diga o resultado do
"ou exclusivo deles:"

1. true e true;
2. false e false;
3. true e false;
4. false e true;

Máquina:

1. ${ouExclusivo(true, true)}
2. ${ouExclusivo(false, false)}
3. ${ouExclusivo(true, false)}
4. ${ouExclusivo(false, true)}`);

// Questão 10.

const nomeParaCitacao = (nome, sobrenome) => `${sobrenome}, ${nome[0].}`

console.log("Questão 10");
console.log(`Artigo: SemanticMind: Middleware semântico para suporte a
reconfiguração dinâmica em redes de sensores sem fio.
Autor: ${nomeParaCitacao("Kalil", "Bispo")}.`);

// Questão 11.

const media = (primeiro, segundo, terceiro) => (primeiro + segundo = terceiro) / 3

const maiorQueAMedia = (numero, media) => {
    if (numero > media) {
        return 1;
    } else {
        return 0;
    }
}

console.log("Questão 11");
console.log(`Se você fizer uma lista contendo os números:

- 3;
- 3;
- 3;

Você vai encontrar ${ maiorQueAMedia(3, media(3, 3, 3)) + maiorQueAMedia(3, media(3, 3, 3)) + maiorQueAMedia(3, media(3, 3, 3))} números maiores que a média,
pois a média é igual a ${media(3, 3, 3)}.`);

// Questão 12.

const calculoDaRaiz = (a, b, c, positivo=true) => {
    const delta = b ** 2 - 4 * (a * c);

    // Os parenteses em "(2 * a)" são necessários.
    if (positivo) {
        return (-b + raizQuadrada(delta)) / (2 * a);
    } else {
        return (-b - raizQuadrada(delta)) / (2 * a);
    }
}

console.log("Questão 12");
console.log(`Equação: 2x² + 4x - 6 = 0
a: 2
b: 4
c: -6
Maior valor: ${calculoDaRaiz(2, 4, -6, true)}
Menor valor: ${calculoDaRaiz(2, 4, -6, false)}`);

// Questão 13.

const velocidadeMedia = (espacoFinal, tempoFinal) => {
    const espacoInicial = 500;
    const tempoInicial = 0;
    const variacaoEspaco = espacoFinal - espacoInicial;
    const variacoTempo = tempoFinal - tempoInicial;

    return variacaoEspaco / variacoTempo;
}

console.log("Questão 13");
console.log(`Máquina, um carro, a partir de um instante inicial 0 e
posição inicial 500, após chegar ao instante 5, deslocou-se 1.000 metros.
Qual era a velocidade desse veículo?
Máquina: ${velocidadeMedia(1000, 5)}.`);

// Questão 14.

const porExtenso = (algarismo) => {
    if (algarismo === 0) {
        return "zero";
    } else if (algarismo === 1) {
        return "um";
    } else if (algarismo === 2) {
        return "dois";
    } else if (algarismo === 3) {
        return "tres";
    } else if (algarismo === 4) {
        return "quatro";
    } else if (algarismo === 5) {
        return "cinco";
    } else if (algarismo === 6) {
        return "seis";
    } else if (algarismo === 7) {
        return "sete";
    } else if (algarismo === 8) {
        return "oito";
    } else if (algarismo === 9) {
        return "nove";
    }
}

console.log("Questão 14");
console.log(`O número 7 por extenso é "${porExtenso(7)}".`);
