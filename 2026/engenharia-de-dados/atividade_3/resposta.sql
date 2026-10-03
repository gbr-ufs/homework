-- Seção 1
-- 1.1
SELECT
    cpf
FROM
    universidade.professor
WHERE
    departamento = 'DMA';

-- 1.2
SELECT
    cod_disc
FROM
    universidade.cursa
WHERE
    mat_estudante = 'E101';

-- 1.3
SELECT
    primeiro_nome,
    cpf
FROM
    universidade.usuario
WHERE
    telefone IS NOT NULL;

-- 1.4
SELECT
    nome,
    cod_disc
FROM
    universidade.disciplina
WHERE
    pre_req IS NOT NULL
    AND creditos > 2;

-- 1.5
SELECT
    AVG(nota)
FROM
    universidade.cursa;

-- 1.6
SELECT
    COUNT(DISTINCT mat_professor)
FROM
    universidade.plano
WHERE
    mat_estudante IS NOT NULL;

-- 1.7
SELECT
    mat_professor
FROM
    universidade.plano
WHERE
    mat_estudante IS NOT NULL
UNION
SELECT
    chefe
FROM
    universidade.departamento;

-- 1.8
SELECT
    mat_professor
FROM
    universidade.plano
WHERE
    mat_estudante IS NOT NULL
INTERSECT
SELECT
    chefe
FROM
    universidade.departamento;

-- 1.9
SELECT
    mat_professor
FROM
    universidade.plano
WHERE
    mat_estudante IS NOT NULL
EXCEPT
SELECT
    chefe
FROM
    universidade.departamento;

-- 2.1
SELECT
    *
FROM
    hospital.usuario;

-- 2.2
SELECT
    primeiroNome,
    sobrenome
FROM
    hospital.usuario;

-- 2.3
SELECT
    *
FROM
    hospital.usuario
WHERE
    sexo = 'M';

-- 2.4
SELECT
    login
FROM
    hospital.perfil
WHERE
    ativo = 'S';

-- 2.5
SELECT DISTINCT
    cidade
FROM
    hospital.endereco;

-- 2.6
SELECT DISTINCT
    bairro
FROM
    hospital.endereco
WHERE
    cidade = 'Aracaju';

-- 2.7
SELECT
    primeiroNome,
    sobrenome
FROM
    hospital.usuario
ORDER BY
    primeiroNome,
    sobrenome;

-- 2.8
SELECT DISTINCT
    sobrenome
FROM
    hospital.usuario
WHERE
    sexo = 'F'
ORDER BY
    sobrenome;

-- 2.9
SELECT
    MAX(salario),
    MIN(salario)
FROM
    hospital.medico;

-- 2.10
SELECT
    MAX(salario)
FROM
    hospital.medico
WHERE
    especialidade = 'Clínico Geral';

-- 2.11
SELECT
    AVG(salario)
FROM
    hospital.medico
WHERE
    especialidade = 'Cirurgião';

-- 2.12
SELECT
    COUNT(sexo)
FROM
    hospital.usuario
WHERE
    sexo = 'M';

-- 2.13
SELECT
    COUNT(*)
FROM
    hospital.usuario
WHERE
    sexo = 'M'
    AND EXTRACT(YEAR FROM dataNasc) >= 1980;

-- Seção 2
-- 1.1
SELECT DISTINCT
    d.nome
FROM
    universidade.disciplina d
    INNER JOIN universidade.cursa c ON d.cod_disc = c.cod_disc;

-- 1.2
SELECT
    u.primeiro_nome,
    d.nome
FROM
    universidade.usuario u
    INNER JOIN universidade.estudante e ON u.cpf = e.cpf
    INNER JOIN universidade.cursa c ON e.mat_estudante = c.mat_estudante
    INNER JOIN universidade.disciplina d ON c.cod_disc = d.cod_disc;

-- 1.3
SELECT
    u_aluno.primeiro_nome,
    u_prof.primeiro_nome
FROM
    universidade.plano pl
    INNER JOIN universidade.estudante e ON pl.mat_estudante = e.mat_estudante
    INNER JOIN universidade.usuario u_aluno ON e.cpf = u_aluno.cpf
    INNER JOIN universidade.professor p ON pl.mat_professor = p.mat_professor
    INNER JOIN universidade.usuario u_prof ON p.cpf = u_prof.cpf;

-- 1.4
SELECT
    u_prof.primeiro_nome,
    d.nome,
    u_aluno.primeiro_nome
FROM
    universidade.professor p
    INNER JOIN universidade.usuario u_prof ON p.cpf = u_prof.cpf
    INNER JOIN universidade.disciplina d ON p.departamento = d.depto_responsavel
    INNER JOIN universidade.cursa c ON d.cod_disc = c.cod_disc
    INNER JOIN universidade.estudante e ON c.mat_estudante = e.mat_estudante
    INNER JOIN universidade.usuario u_aluno ON e.cpf = u_aluno.cpf;

-- 1.5
SELECT
    d.nome,
    p.nome
FROM
    universidade.disciplina d
    INNER JOIN universidade.disciplina p ON d.pre_req = p.cod_disc;

-- 1.6
SELECT
    u_prof.primeiro_nome,
    u_chefe.primeiro_nome
FROM
    universidade.professor prof
    INNER JOIN universidade.usuario u_prof ON prof.cpf = u_prof.cpf
    INNER JOIN universidade.departamento dpt ON prof.departamento = dpt.cod_depto
    INNER JOIN universidade.professor p_chefe ON dpt.chefe = p_chefe.mat_professor
    INNER JOIN universidade.usuario u_chefe ON p_chefe.cpf = u_chefe.cpf;

-- 1.7
SELECT
    d.nome,
    u_prof.primeiro_nome
FROM
    universidade.disciplina d
    LEFT JOIN universidade.disciplina dependente ON d.cod_disc = dependente.pre_req
    LEFT JOIN universidade.professor prof ON d.depto_responsavel = prof.departamento
    LEFT JOIN universidade.usuario u_prof ON prof.cpf = u_prof.cpf
WHERE
    dependente.pre_req IS NULL;

-- 1.8
SELECT
    u_aluno.primeiro_nome,
    u_prof.primeiro_nome
FROM
    universidade.estudante e
    INNER JOIN universidade.usuario u_aluno ON e.cpf = u_aluno.cpf
    LEFT JOIN universidade.plano pl ON e.mat_estudante = pl.mat_estudante
    LEFT JOIN universidade.professor p ON pl.mat_professor = p.mat_professor
    LEFT JOIN universidade.usuario u_prof ON p.cpf = u_prof.cpf;

-- 1.9
SELECT
    u_prof.primeiro_nome,
    u_aluno.primeiro_nome
FROM
    universidade.professor p
    INNER JOIN universidade.usuario u_prof ON p.cpf = u_prof.cpf
    LEFT JOIN universidade.plano pl ON p.mat_professor = pl.mat_professor
    LEFT JOIN universidade.estudante e ON pl.mat_estudante = e.mat_estudante
    LEFT JOIN universidade.usuario u_aluno ON e.cpf = u_aluno.cpf;

-- 1.10
SELECT
    u_aluno.primeiro_nome,
    u_prof.primeiro_nome
FROM
    universidade.estudante e
    INNER JOIN universidade.usuario u_aluno ON e.cpf = u_aluno.cpf
    FULL JOIN universidade.plano pl ON e.mat_estudante = pl.mat_estudante
    FULL JOIN universidade.professor p ON pl.mat_professor = p.mat_professor
    LEFT JOIN universidade.usuario u_prof ON p.cpf = u_prof.cpf;

-- 1.11
SELECT DISTINCT
    u_prof.primeiro_nome
FROM
    universidade.professor p
    INNER JOIN universidade.usuario u_prof ON p.cpf = u_prof.cpf
    LEFT JOIN universidade.disciplina d ON p.departamento = d.depto_responsavel
    LEFT JOIN universidade.cursa c ON d.cod_disc = c.cod_disc
WHERE
    c.cod_disc IS NULL;

-- 1.12
SELECT
    d.nome
FROM
    universidade.disciplina d
    LEFT JOIN universidade.cursa c ON d.cod_disc = c.cod_disc
WHERE
    c.cod_disc IS NULL;

-- 2.1
SELECT
    cpf,
    sobrenome
FROM
    hospital.usuario
WHERE
    sobrenome LIKE '%sa%';

-- 2.2
SELECT
    COUNT(sobrenome)
FROM
    hospital.usuario
WHERE
    sobrenome LIKE 'S%';

-- 2.3
SELECT
    u.primeiroNome,
    p.cpf
FROM
    hospital.paciente p
    INNER JOIN hospital.usuario u ON p.cpf = u.cpf;

-- 2.4
SELECT
    SUM(m.salario)
FROM
    hospital.medico m
    INNER JOIN hospital.usuario u ON m.cpf = u.cpf
    INNER JOIN hospital.perfil p ON u.idPerfil = p.idPerfil
WHERE
    p.ativo = 'S';

-- 2.5
SELECT
    u_pac.primeiroNome,
    pac.cpf,
    u_acomp.primeiroNome,
    pac.cpfAcomp
FROM
    hospital.paciente pac
    INNER JOIN hospital.usuario u_pac ON pac.cpf = u_pac.cpf
    INNER JOIN hospital.acompanhante acomp ON pac.cpfAcomp = acomp.cpf
    INNER JOIN hospital.usuario u_acomp ON acomp.cpf = u_acomp.cpf;

-- 2.6.
SELECT DISTINCT
    u.primeiroNome,
    p.cpf
FROM
    hospital.paciente p
    INNER JOIN hospital.consulta c ON p.numProntuario = c.numProntuario
    INNER JOIN hospital.usuario u ON p.cpf = u.cpf;

-- 2.7
SELECT DISTINCT
    u.primeiroNome,
    p.cpf,
    p.numProntuario
FROM
    hospital.paciente p
    INNER JOIN hospital.consulta c ON p.numProntuario = c.numProntuario
    INNER JOIN hospital.usuario u ON p.cpf = u.cpf
    LEFT JOIN hospital.prescricao pr ON c.idConsulta = pr.idConsultaPrescricao
WHERE
    pr.idConsultaPrescricao IS NULL;

-- 2.8
SELECT
    u.primeiroNome,
    p.cpf,
    p.numProntuario,
    m.nome
FROM
    hospital.paciente p
    INNER JOIN hospital.consulta c ON p.numProntuario = c.numProntuario
    INNER JOIN hospital.usuario u ON p.cpf = u.cpf
    LEFT OUTER JOIN hospital.prescricao pr ON c.idConsulta = pr.idConsultaPrescricao
    LEFT OUTER JOIN hospital.medicamento m ON pr.idMedicamento = m.idMedicamento
WHERE
    pr.idConsultaPrescricao IS NOT NULL;

-- Seção 3
-- 1.1
SELECT
    p.mat_professor,
    MAX(c.nota),
    MIN(c.nota),
    AVG(c.nota)
FROM
    universidade.professor p
    INNER JOIN universidade.disciplina d ON p.departamento = d.depto_responsavel
    INNER JOIN universidade.cursa c ON d.cod_disc = c.cod_disc
GROUP BY
    p.mat_professor;

-- 1.2
SELECT
    d.nome,
    AVG(c.nota)
FROM
    universidade.disciplina d
    INNER JOIN universidade.cursa c ON d.cod_disc = c.cod_disc
WHERE
    c.nota IS NOT NULL
    AND d.cod_disc IN (
        SELECT
            pre_req
        FROM
            universidade.disciplina
        WHERE
            pre_req IS NOT NULL)
GROUP BY
    d.cod_disc,
    d.nome;

-- 1.3
SELECT
    d.nome,
    d.pre_req,
    COUNT(c.mat_estudante)
FROM
    universidade.disciplina d
    INNER JOIN universidade.cursa c ON d.cod_disc = c.cod_disc
GROUP BY
    d.cod_disc,
    d.nome,
    d.pre_req;

-- 1.4
SELECT
    dpt.nome,
    AVG(c.nota)
FROM
    universidade.departamento dpt
    INNER JOIN universidade.disciplina d ON dpt.cod_depto = d.depto_responsavel
    INNER JOIN universidade.cursa c ON d.cod_disc = c.cod_disc
GROUP BY
    dpt.cod_depto,
    dpt.nome;

-- 1.5
SELECT
    d.nome,
    MAX(p.salario),
    MIN(p.salario)
FROM
    universidade.professor p
    INNER JOIN universidade.departamento d ON p.departamento = d.cod_depto
GROUP BY
    d.cod_depto,
    d.nome;

-- 1.6
SELECT DISTINCT
    p.mat_professor,
    p.departamento
FROM
    universidade.professor p
    INNER JOIN universidade.disciplina d ON p.departamento = d.depto_responsavel
    INNER JOIN universidade.cursa c ON d.cod_disc = c.cod_disc
GROUP BY
    p.mat_professor,
    p.departamento,
    d.cod_disc
HAVING
    COUNT(c.mat_estudante) < 7;

-- 1.7
SELECT
    u.primeiro_nome,
    u.sobrenome,
    AVG(c.nota)
FROM
    universidade.usuario u
    INNER JOIN universidade.estudante e ON u.cpf = e.cpf
    INNER JOIN universidade.cursa c ON e.mat_estudante = c.mat_estudante
    INNER JOIN universidade.disciplina d ON c.cod_disc = d.cod_disc
WHERE
    d.depto_responsavel IN ('COMP')
GROUP BY
    e.mat_estudante,
    u.primeiro_nome,
    u.sobrenome;

-- 2.1.
SELECT
    especialidade,
    SUM(salario)
FROM
    hospital.medico
GROUP BY
    especialidade
HAVING
    SUM(salario) > 20000;

-- 2.2.
SELECT
    m.especialidade,
    SUM(m.salario)
FROM
    hospital.medico m
    INNER JOIN hospital.medico_docente md ON m.idRegistro = md.idRegistro
GROUP BY
    m.especialidade
HAVING
    SUM(m.salario) > 15000;

-- 2.3
SELECT
    especialidade,
    COUNT(*) AS total_medicos
FROM
    hospital.medico
GROUP BY
    especialidade;

-- Seção 4
-- 1.1
SELECT
    mat_estudante
FROM
    universidade.estudante
WHERE
    mat_estudante IN (
        SELECT
            mat_estudante
        FROM
            universidade.plano
        WHERE
            mat_professor = 'P200')
    AND mat_estudante IN (
        SELECT
            mat_estudante
        FROM
            universidade.cursa
        WHERE
            cod_disc IN (
                SELECT
                    cod_disc
                FROM
                    universidade.disciplina
                WHERE
                    depto_responsavel = (
                        SELECT
                            departamento
                        FROM
                            universidade.professor
                        WHERE
                            mat_professor = 'P500')));

-- 1.2
SELECT
    mat_professor
FROM
    universidade.professor
WHERE
    mat_professor NOT IN (
        SELECT
            mat_professor
        FROM
            universidade.plano
        WHERE
            mat_professor IS NOT NULL)
    OR mat_professor IN (
        SELECT
            chefe
        FROM
            universidade.departamento
        WHERE
            chefe IS NOT NULL);

-- 1.3
SELECT
    mat_professor
FROM
    universidade.professor
WHERE
    mat_professor IN (
        SELECT
            mat_professor
        FROM
            universidade.plano)
    AND mat_professor IN (
        SELECT
            chefe
        FROM
            universidade.departamento);

-- 1.4
SELECT
    mat_professor
FROM
    universidade.professor
WHERE
    mat_professor NOT IN (
        SELECT
            mat_professor
        FROM
            universidade.plano
        WHERE
            mat_professor IS NOT NULL)
    AND mat_professor NOT IN (
        SELECT
            chefe
        FROM
            universidade.departamento
        WHERE
            chefe IS NOT NULL);

-- 1.5
SELECT
    MIN(media_salario)
FROM (
    SELECT
        AVG(salario) AS media_salario
    FROM
        universidade.professor
    GROUP BY
        departamento) medias_por_depto;

-- 1.6
SELECT
    p.mat_professor,
    AVG(c.nota),
    p.departamento,
    (
        SELECT
            AVG(c2.nota)
        FROM
            universidade.disciplina d2
            INNER JOIN universidade.cursa c2 ON d2.cod_disc = c2.cod_disc
        WHERE
            d2.depto_responsavel = p.departamento)
FROM
    universidade.professor p
    INNER JOIN universidade.disciplina d ON p.departamento = d.depto_responsavel
    INNER JOIN universidade.cursa c ON d.cod_disc = c.cod_disc
GROUP BY
    p.mat_professor,
    p.departamento;

-- 1.7
SELECT
    u.primeiro_nome,
    u.sobrenome
FROM
    universidade.usuario u
    INNER JOIN universidade.professor p ON u.cpf = p.cpf
WHERE
    p.salario = (
        SELECT
            MIN(salario)
        FROM
            universidade.professor);

-- 1.8
SELECT
    u.primeiro_nome,
    u.sobrenome
FROM
    universidade.usuario u
    INNER JOIN universidade.estudante e ON u.cpf = e.cpf
    INNER JOIN universidade.cursa c ON e.mat_estudante = c.mat_estudante
WHERE
    c.nota IS NOT NULL
GROUP BY
    e.mat_estudante,
    u.primeiro_nome,
    u.sobrenome
HAVING
    AVG(c.nota) = (
        SELECT
            MIN(media_aluno)
        FROM (
            SELECT
                AVG(nota) AS media_aluno
            FROM
                universidade.cursa
            WHERE
                nota IS NOT NULL
            GROUP BY
                mat_estudante) medias);

-- 1.9
SELECT
    u.primeiro_nome,
    u.sobrenome,
    (
        -- Subconsulta 1: quantidade de disciplinas com nota >= 5.0
        SELECT
            COUNT(*)
        FROM
            universidade.cursa c
        WHERE
            c.mat_estudante = e.mat_estudante
            AND c.nota >= 5.0),
        (
            SELECT
                COUNT(*)
            FROM
                universidade.cursa c
            WHERE
                c.mat_estudante = e.mat_estudante
                AND c.nota < 5.0)
    FROM
        universidade.usuario u
        INNER JOIN universidade.estudante e ON u.cpf = e.cpf;

-- 1.10
SELECT
    d.nome,
    AVG(c.nota)
FROM
    universidade.disciplina d
    INNER JOIN universidade.cursa c ON d.cod_disc = c.cod_disc
WHERE (
    SELECT
        AVG(c1.nota)
    FROM
        universidade.cursa c1
    WHERE
        c1.cod_disc = d.cod_disc) < (
    SELECT
        AVG(c2.nota)
    FROM
        universidade.cursa c2
        INNER JOIN universidade.disciplina d2 ON c2.cod_disc = d2.cod_disc
    WHERE
        d2.depto_responsavel = d.depto_responsavel)
GROUP BY
    d.cod_disc,
    d.nome;

-- 2.1
SELECT
    m.numCRM,
    u.primeiroNome,
    m.especialidade
FROM
    hospital.medico m
    INNER JOIN hospital.usuario u ON m.cpf = u.cpf
WHERE
    m.salario >= (
        SELECT
            AVG(m2.salario)
        FROM
            hospital.medico m2
        WHERE
            m2.especialidade = m.especialidade)
ORDER BY
    m.salario ASC;

-- 2.2
SELECT
    u.primeiroNome,
    p.numProntuario
FROM
    hospital.paciente p
    INNER JOIN hospital.usuario u ON p.cpf = u.cpf
WHERE
    p.numProntuario IN (
        SELECT
            c.numProntuario
        FROM
            hospital.consulta c
        WHERE
            c.idRegistroMedico IN (
                SELECT
                    m.idRegistro
                FROM
                    hospital.medico m
                WHERE
                    m.especialidade = 'Clínico Geral'));

-- 2.3
SELECT
    u.primeiroNome,
    p.cpf,
    p.numProntuario
FROM
    hospital.paciente p
    INNER JOIN hospital.usuario u ON p.cpf = u.cpf
WHERE
    p.numProntuario IN (
        SELECT
            c.numProntuario
        FROM
            hospital.consulta c
        WHERE
            EXTRACT(MONTH FROM c.dataConsulta) = 6
            AND EXTRACT(YEAR FROM c.dataConsulta) = 2018);

-- 2.4
SELECT
    idExame,
    nome
FROM
    hospital.exame
WHERE
    idExame IN (
        SELECT
            idExame
        FROM
            hospital.solicitacao_exame
        WHERE
            dataRealizacao IS NOT NULL);

-- 2.5
SELECT
    idExame,
    nome
FROM
    hospital.exame
WHERE
    idExame IN (
        SELECT
            idExame
        FROM
            hospital.solicitacao_exame
        WHERE
            dataRealizacao IS NOT NULL)
    AND idExame IN (
        SELECT
            idExame
        FROM
            hospital.laudo
        WHERE
            statusLaudo = 'Entregue');

-- 2.6
SELECT
    especialidade,
    SUM(salario)
FROM
    hospital.medico
WHERE
    idRegistro IN (
        SELECT
            idRegistro
        FROM
            hospital.medico_docente)
GROUP BY
    especialidade
HAVING
    SUM(salario) > 15000;

-- 2.7
SELECT
    u.primeiroNome,
    m.numCRM,
    m.especialidade,
    m.salario * 1.05
FROM
    hospital.medico m
    INNER JOIN hospital.usuario u ON m.cpf = u.cpf
WHERE
    m.idRegistro IN (
        SELECT
            idRegistroMedico
        FROM
            hospital.consulta
        GROUP BY
            idRegistroMedico
        HAVING
            COUNT(*) > 9);

