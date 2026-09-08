"""Módulo principal do programa."""

from fastapi import FastAPI

from atividade_2.routers.aluno import router as aluno_router
from atividade_2.routers.professor import router as professor_router

app: FastAPI = FastAPI()

app.include_router(aluno_router)
app.include_router(professor_router)
