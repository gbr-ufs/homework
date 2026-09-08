from typing import Annotated

from fastapi import APIRouter, Depends, status
from valkey.asyncio import Valkey

from atividade_2.lib.models import Professor, ProfessorCreate

valkey: str = "valkey://valkey:6379/0"
engine: Valkey = Valkey.from_url(valkey)


async def get_session():
    yield engine


SessionDependency = Annotated[Valkey, Depends(get_session)]


router: APIRouter = APIRouter()


@router.post("/professor", status_code=status.HTTP_201_CREATED)
async def create_professor(
    professor: ProfessorCreate, session: SessionDependency
) -> Professor:
    novo_professor: Professor = Professor(**professor.model_dump())
    key: str = f"professor:{novo_professor.id}"

    await session.set(key, novo_professor.model_dump_json())

    return novo_professor
