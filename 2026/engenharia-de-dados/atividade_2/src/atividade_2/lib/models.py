from uuid import uuid7

from pydantic import UUID7, BaseModel, Field, PositiveInt
from sqlmodel import Field as SQLField
from sqlmodel import SQLModel


class Usuario(BaseModel):
    nome: str
    ano_ingresso: PositiveInt
    periodo_ingresso: PositiveInt


class Aluno(Usuario, SQLModel, table=True):
    matricula: str = SQLField(primary_key=True)
    tipo_discente: str
    status_discente: str
    nivel_ensino: str
    nome_curso: str
    modalidade_educacao: str | None = None
    nome_unidade: str | None = None
    nome_unidade_gestora: str | None = None


class ProfessorCreate(Usuario):
    departamento: str


class Professor(ProfessorCreate):
    id: UUID7 = Field(default_factory=uuid7)
