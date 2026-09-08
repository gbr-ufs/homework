from contextlib import asynccontextmanager
from typing import Annotated, Any

from fastapi import APIRouter, Depends, status
from sqlalchemy import Engine
from sqlmodel import Session, SQLModel, create_engine

from atividade_2.lib.models import Aluno

postgres: str = "postgresql+psycopg://atividade_2:atividade_2@postgres:5432/atividade_2"
engine: Engine = create_engine(postgres)


def create_db_and_tables() -> None:
    SQLModel.metadata.create_all(engine)


def get_session():
    with Session(engine) as session:
        yield session


SessionDependency = Annotated[Session, Depends(get_session)]


@asynccontextmanager
async def lifespan(_: Any):
    create_db_and_tables()
    yield


router: APIRouter = APIRouter(lifespan=lifespan)


@router.post("/aluno", status_code=status.HTTP_201_CREATED)
async def create_aluno(aluno: Aluno, session: SessionDependency) -> Aluno:
    session.add(aluno)
    session.commit()
    session.refresh(aluno)

    return aluno
