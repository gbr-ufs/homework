const carrinho = [
    { nome: 'Pastel de frango', qtde: 1, preco: 4.00, fragil: true },
    { nome: 'Banana prata', qtde: 7, preco: 6.75, fragil: true },
    { nome: 'Pão integral', qtde: 20, preco: 0.3745, fragil: true },
    { nome: 'Coxinha', qtde: 1, preco: 6.00, fragil: true },
    { nome: 'Guaraná Antártica Zero', qtde: 1, preco: 5.50, fragil: false },
    { nome: 'Geladinho de mousse de maracujá', qtde: 1, preco: 3.00, fragil: true },
    { nome: 'Prato feito', qtde: 1, preco: 17.60, fragil: false },
    { nome: 'Presunto', qtde: 1, preco: 5.14, fragil: true },
    { nome: 'Queijo', qtde: 1, preco: 5.99, fragil: true },
    { nome: 'Ouro Branco', qtde: 2, preco: 1.35, fragil: true },
    { nome: 'Pizza de frango com catupiry', qtde: 1, preco: 40.99, fragil: true },
    { nome: 'Abafador de ruídos', qtde: 1, preco: 40.91, fragil: false },
    { nome: 'Cereal matinal Flakes Nestlé moça', qtde: 1, preco: 5.59, fragil: true },
    { nome: 'Cheetos Lua Parmesão', qtde: 3, preco: 3.35, fragil: true },
    { nome: 'Elma Chips Batata Lays Clássico', qtde: 2, preco: 4.99, fragil: true },
    { nome: 'Fandangos Presunto', qtde: 3, preco: 2.49, fragil: true },
    { nome: 'Bolinho recheado Bauducco morango', qtde: 5, preco: 1.95, fragil: true },
    { nome: 'Chocobiscuit Bauducco chocolate ao leite', qtde: 3, preco: 3.89, fragil: true },
    { nome: 'Bolacha diversas', qtde: 1, preco: 5.25, fragil: true },
    { nome: 'Torta salgada', qtde: 4, preco: 6.75, fragil: true },
    { nome: 'Fralda Cremer Jumbinho P', qtde: 18, preco: 1.01, fragil: true },
    { nome: 'Refinata frango à passarinho', qtde: 1, preco: 4.19, fragil: true },
    { nome: 'Refinata picanha', qtde: 1, preco: 4.19, fragil: true },
    { nome: 'Chamyto vitamina de frutas', qtde: 1, preco: 4.19, fragil: true },
    { nome: `Capa bolsa à prova d'água`, qtde: 2, preco: 12.81, fragil: false },
    { nome: 'Camisa gola polo', qtde: 1, preco: 49.90, fragil: false },
    { nome: 'Camisa polo Malwee', qtde: 1, preco: 54.90, fragil: false },
    { nome: 'Calça masculina esporte fino estilo social', qtde: 1, preco: 79.99, fragil: false },
    { nome: 'Regata longline MXD', qtde: 1, preco: 27.90, fragil: false },
    { nome: 'Garrafa térmica em aço inox com termômetro', qtde: 1, preco: 23.99, fragil: false },
    { nome: 'Camisa xadrez', qtde: 1, preco: 45.99, fragil: false },
    { nome: 'Capas protetoras para bancos Fiat', qtde: 1, preco: 54.00, fragil: false },
    { nome: 'Bucket hat', qtde: 1, preco: 19.00, fragil: false },
    { nome: 'Kit microfone sem fio', qtde: 1, preco: 37.00, fragil: true },
    { nome: 'Controle remoto', qtde: 1, preco: 19.00, fragil: true },
    { nome: 'Espelho interno Palio Siena Strada 2004', qtde: 1, preco: 128.62, fragil: true },
    { nome: 'Camiseta banda Dio', qtde: 1, preco: 44.90, fragil: false },
    { nome: `Camiseta banda Rainbow (Long Live Rock 'n' Roll)`, qtde: 1, preco: 59.90, fragil: false },
    { nome: 'Travisseiro latex natural importado da Tailândia', qtde: 1, preco: 9.31, fragil: true },
    { nome: 'Ring light 8 polegadas 20cm com tripé', qtde: 1, preco: 25.89, fragil: true },
    { nome: 'Ferro de passar 2 em 1', qtde: 1, preco: 74.90, fragil: false },
    { nome: 'Sanduicheira Grill Cadence', qtde: 1, preco: 127.92, fragil: true },
    { nome: 'Botina', qtde: 1, preco: 48.01, fragil: false },
    { nome: 'Guarda-chuva', qtde: 1, preco: 28.00, fragil: true },
    { nome: 'Capa protetora Notebook 15,6"', qtde: 1, preco: 36.99, fragil: false },
    { nome: 'Máquina de cortar cabelo Mondial', qtde: 1, preco: 67.90, fragil: true },
    { nome: 'Varal de chão', qtde: 1, preco: 95.00, fragil: false },
    { nome: 'Biscoito Laka', qtde: 1, preco: 6.49, fragil: true },
    { nome: 'Frisco abacaxi', qtde: 2, preco: 0.79, fragil: false },
    { nome: 'Frisco guaraná', qtde: 2, preco: 0.79, fragil: false },
]

const todos = (p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,p41,p42,p43,p44,p45,p46,p47,p48,p49) => {
    return p0.qtde * p0.preco + p1.qtde * p1.preco + p2.qtde * p2.preco +
        p3.qtde * p3.preco + p4.qtde * p4.preco +
        p5.qtde * p5.preco +
        p6.qtde * p6.preco + p7.qtde * p7.preco +
        p8.qtde * p8.preco +
        p9.qtde * p9.preco + p10.qtde * p10.preco +
        p11.qtde * p11.preco +
        p12.qtde * p12.preco + p13.qtde * p13.preco +
        p14.qtde * p14.preco +
        p15.qtde * p15.preco + p16.qtde * p16.preco +
        p17.qtde * p17.preco +
        p18.qtde * p18.preco + p19.qtde * p19.preco +
        p20.qtde * p20.preco +
        p21.qtde * p21.preco + p22.qtde * p22.preco +
        p23.qtde * p23.preco +
        p24.qtde * p24.preco + p25.qtde * p25.preco +
        p26.qtde * p26.preco +
        p27.qtde * p27.preco + p28.qtde * p28.preco +
        p29.qtde * p29.preco +
        p30.qtde * p30.preco + p31.qtde * p31.preco +
        p32.qtde * p32.preco +
        p33.qtde * p33.preco + p34.qtde * p34.preco +
        p35.qtde * p35.preco +
        p36.qtde * p36.preco + p37.qtde * p37.preco +
        p38.qtde * p38.preco +
        p39.qtde * p39.preco + p40.qtde * p40.preco +
        p41.qtde * p41.preco +
        p42.qtde * p42.preco + p43.qtde * p43.preco +
        p44.qtde * p44.preco +
        p45.qtde * p45.preco + p46.qtde * p46.preco +
        p47.qtde * p47.preco +
        p48.qtde * p48.preco + p49.qtde * p49.preco
}

const frageis = (p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,p41,p42,p43,p44,p45,p46,p47,p48,p49) => {
    const parcial0 = p0.fragil ? p0.qtde * p0.preco : 0
    const parcial1 = p1.fragil ? p1.qtde * p1.preco : 0
    const parcial2 = p2.fragil ? p2.qtde * p2.preco : 0
    const parcial3 = p3.fragil ? p3.qtde * p3.preco : 0
    const parcial4 = p4.fragil ? p4.qtde * p4.preco : 0
    const parcial5 = p5.fragil ? p5.qtde * p5.preco : 0
    const parcial6 = p6.fragil ? p6.qtde * p6.preco : 0
    const parcial7 = p7.fragil ? p7.qtde * p7.preco : 0
    const parcial8 = p8.fragil ? p8.qtde * p8.preco : 0
    const parcial9 = p9.fragil ? p9.qtde * p9.preco : 0
    const parcial10 = p10.fragil ? p10.qtde * p10.preco : 0
    const parcial11 = p11.fragil ? p11.qtde * p11.preco : 0
    const parcial12 = p12.fragil ? p12.qtde * p12.preco : 0
    const parcial13 = p13.fragil ? p13.qtde * p13.preco : 0
    const parcial14 = p14.fragil ? p14.qtde * p14.preco : 0
    const parcial15 = p15.fragil ? p15.qtde * p15.preco : 0
    const parcial16 = p16.fragil ? p16.qtde * p16.preco : 0
    const parcial17 = p17.fragil ? p17.qtde * p17.preco : 0
    const parcial18 = p18.fragil ? p18.qtde * p18.preco : 0
    const parcial19 = p19.fragil ? p19.qtde * p19.preco : 0
    const parcial20 = p20.fragil ? p20.qtde * p20.preco : 0
    const parcial21 = p21.fragil ? p21.qtde * p21.preco : 0
    const parcial22 = p22.fragil ? p22.qtde * p22.preco : 0
    const parcial23 = p23.fragil ? p23.qtde * p23.preco : 0
    const parcial24 = p24.fragil ? p24.qtde * p24.preco : 0
    const parcial25 = p25.fragil ? p25.qtde * p25.preco : 0
    const parcial26 = p26.fragil ? p26.qtde * p26.preco : 0
    const parcial27 = p27.fragil ? p27.qtde * p27.preco : 0
    const parcial28 = p28.fragil ? p28.qtde * p28.preco : 0
    const parcial29 = p29.fragil ? p29.qtde * p29.preco : 0
    const parcial30 = p30.fragil ? p30.qtde * p30.preco : 0
    const parcial31 = p31.fragil ? p31.qtde * p31.preco : 0
    const parcial32 = p32.fragil ? p32.qtde * p32.preco : 0
    const parcial33 = p33.fragil ? p33.qtde * p33.preco : 0
    const parcial34 = p34.fragil ? p34.qtde * p34.preco : 0
    const parcial35 = p35.fragil ? p35.qtde * p35.preco : 0
    const parcial36 = p36.fragil ? p36.qtde * p36.preco : 0
    const parcial37 = p37.fragil ? p37.qtde * p37.preco : 0
    const parcial38 = p38.fragil ? p38.qtde * p38.preco : 0
    const parcial39 = p39.fragil ? p39.qtde * p39.preco : 0
    const parcial40 = p40.fragil ? p40.qtde * p40.preco : 0
    const parcial41 = p41.fragil ? p41.qtde * p41.preco : 0
    const parcial42 = p42.fragil ? p42.qtde * p42.preco : 0
    const parcial43 = p43.fragil ? p43.qtde * p43.preco : 0
    const parcial44 = p44.fragil ? p44.qtde * p44.preco : 0
    const parcial45 = p45.fragil ? p45.qtde * p45.preco : 0
    const parcial46 = p46.fragil ? p46.qtde * p46.preco : 0
    const parcial47 = p47.fragil ? p47.qtde * p47.preco : 0
    const parcial48 = p48.fragil ? p48.qtde * p48.preco : 0
    const parcial49 = p49.fragil ? p49.qtde * p49.preco : 0

    return parcial0 + parcial1 + parcial2 + parcial3 + parcial4 + parcial5 + parcial6 + parcial7 + parcial8 + parcial9 + parcial10 + parcial11 + parcial12 + parcial13 + parcial14 + parcial15 + parcial16 + parcial17 + parcial18 + parcial19 + parcial20 + parcial21 + parcial22 + parcial23 + parcial24 + parcial25 + parcial26 + parcial27 + parcial28 + parcial29 + parcial30 + parcial31 + parcial32 + parcial33 + parcial34 + parcial35 + parcial36 + parcial37 + parcial38 + parcial39 + parcial40 + parcial41 + parcial42 + parcial43 + parcial44 + parcial45 + parcial46 + parcial47 + parcial48 + parcial49
}

const desconto = (valorDescontado = 0) => (valor) => (1 - valorDescontado) * valor

const descontoDe10 = desconto(0.1)

const calcular = (desconto) => (operacao) => (p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,p41,p42,p43,p44,p45,p46,p47,p48,p49) => desconto(operacao(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32,p33,p34,p35,p36,p37,p38,p39,p40,p41,p42,p43,p44,p45,p46,p47,p48,p49))

const resultadoDeTodos = todos(carrinho[0],carrinho[1],carrinho[2],carrinho[3],carrinho[4],carrinho[5],carrinho[6],carrinho[7],carrinho[8],carrinho[9],carrinho[10],carrinho[11],carrinho[12],carrinho[13],carrinho[14],carrinho[15],carrinho[16],carrinho[17],carrinho[18],carrinho[19],carrinho[20],carrinho[21],carrinho[22],carrinho[23],carrinho[24],carrinho[25],carrinho[26],carrinho[27],carrinho[28],carrinho[29],carrinho[30],carrinho[31],carrinho[32],carrinho[33],carrinho[34],carrinho[35],carrinho[36],carrinho[37],carrinho[38],carrinho[39],carrinho[40],carrinho[41],carrinho[42],carrinho[43],carrinho[44],carrinho[45],carrinho[46],carrinho[47],carrinho[48],carrinho[49])

const resultadoDosFrageis = frageis(carrinho[0],carrinho[1],carrinho[2],carrinho[3],carrinho[4],carrinho[5],carrinho[6],carrinho[7],carrinho[8],carrinho[9],carrinho[10],carrinho[11],carrinho[12],carrinho[13],carrinho[14],carrinho[15],carrinho[16],carrinho[17],carrinho[18],carrinho[19],carrinho[20],carrinho[21],carrinho[22],carrinho[23],carrinho[24],carrinho[25],carrinho[26],carrinho[27],carrinho[28],carrinho[29],carrinho[30],carrinho[31],carrinho[32],carrinho[33],carrinho[34],carrinho[35],carrinho[36],carrinho[37],carrinho[38],carrinho[39],carrinho[40],carrinho[41],carrinho[42],carrinho[43],carrinho[44],carrinho[45],carrinho[46],carrinho[47],carrinho[48],carrinho[49])

const resultadoDescontoDe10 = calcular(descontoDe10)(todos)(carrinho[0],carrinho[1],carrinho[2],carrinho[3],carrinho[4],carrinho[5],carrinho[6],carrinho[7],carrinho[8],carrinho[9],carrinho[10],carrinho[11],carrinho[12],carrinho[13],carrinho[14],carrinho[15],carrinho[16],carrinho[17],carrinho[18],carrinho[19],carrinho[20],carrinho[21],carrinho[22],carrinho[23],carrinho[24],carrinho[25],carrinho[26],carrinho[27],carrinho[28],carrinho[29],carrinho[30],carrinho[31],carrinho[32],carrinho[33],carrinho[34],carrinho[35],carrinho[36],carrinho[37],carrinho[38],carrinho[39],carrinho[40],carrinho[41],carrinho[42],carrinho[43],carrinho[44],carrinho[45],carrinho[46],carrinho[47],carrinho[48],carrinho[49])

console.log(`O valor total é de R$ ${resultadoDeTodos}.`)
console.log(`O valor total dos itens frágeis é de R$ ${resultadoDosFrageis}.`)
console.log(`O valor total com 10% de desconto é de R$ ${resultadoDescontoDe10}.`)
