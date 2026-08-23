# /// script
# requires-python = ">=3.14"
# dependencies = [
#     "polars>=1.43.2",
#     "pydantic>=2.13.4",
# ]
# ///

# ATENÇÃO: Esse arquivo utiliza da PEP 723[0] para definir dependências.
#
# Ou seja, para rodar use ou o pipx:
#
# pipx run implementacao_com_arquivos.py
#
# Ou o uv:
#
# uv run implementacao_com_arquivos.py
#
# Eu tentei me basear no Guia de Estilo da Google[1] pras docstrings mas
# deixei tudo em português mesmo porque isso é uma atividade.
#
# [0]: https://peps.python.org/pep-0723/
# [1]: https://google.github.io/styleguide/pyguide.html

"""Módulo para revisão de como trabalhar com arquivos."""

from pathlib import Path
from typing import Optional

import polars as pl
from pydantic import BaseModel, PositiveInt, TypeAdapter, ValidationError
from polars import DataFrame


class Discente(BaseModel):
    """Classe usada para representar um discente."""
    matricula: PositiveInt
    nome_discente: str
    ano_ingresso: PositiveInt
    periodo_ingresso: PositiveInt
    tipo_discente: str
    status_discente: str
    nivel_ensino: str
    nome_curso: str
    # Infelizmente alguns desses valores são nulos.
    modalidade_educacao: Optional[str]
    nome_unidade: Optional[str]
    nome_unidade_gestora: Optional[str]


def gerar_lista_de_discentes() -> list[Discente]:
    """Gera a lista de todos os discentes a partir do arquivo disponibilizado.

    Retorna:
        A lista de todos os discentes encontrados no CSV ("dis-csv-discentes-de-graduacao-de-2025.csv").
    """
    df: DataFrame = pl.read_csv("dis-csv-discentes-de-graduacao-de-2025.csv")
    dicts: list[dict] = df.to_dicts()
    discentes: list[Discente] = [Discente(**d) for d in dicts]

    return discentes


def discente_to_str(discente: Discente) -> str:
    """Gera uma string multilinha a partir dos dados de um discente.

    Args:
        discente: O discente tido como origem dos dados.

    Retorna:
        Uma string no modelo "chave: valor" para cada atributo que um discente tem.
    """
    return "\n".join(f"{key}: {value}" for key, value in discente.model_dump().items())


def imprimir_discente(discente: Discente) -> None:
    """Imprime na tela os dados de um discente.

    Args:
        discente: O discente que terá seus dados impressos.
    """
    print(discente_to_str(discente))


def salvar_discente(discente: Discente) -> None:
    """Salva um arquivo contendo os dados de um discente.

    O arquivo é nomeado com base na matrícula do discente.

    Args:
        discente: O discente tido que terá seus dados salvos.
    """
    conteudo: str = discente_to_str(discente)
    arquivo: Path = Path(f"{discente.matricula}.txt")

    arquivo.write_text(conteudo)


def main() -> None:
    """Ponto de entrada do programa."""
    matricula_prompt: str = input("Matrícula: ")

    # Usando o Pydantic (biblioteca de tipos) para restringir ainda mais a gama
    # de entradas válidas.
    # Basicamente, o tipo PositiveInt só permite valores de 1 pra cima, o que
    # faz sentido para uma matrícula.
    try:
        matricula: PositiveInt = TypeAdapter(PositiveInt).validate_python(matricula_prompt)
    except(ValidationError):
        print("Matrícula inválida. Tente novamente.")

        return

    discentes: list[Discente] = gerar_lista_de_discentes()
    discente: Discente | None = next((d for d in discentes if d.matricula == matricula), None)

    if not discente:
        print("Discente não encontrado. Tente novamente.")

        return

    imprimir_discente(discente)
    print("")
    salvar_discente(discente)

    print("Discente salvo com sucesso.")


if __name__ == "__main__":
    main()
