FROM python:3.14.6-slim-bookworm as builder
COPY --from=ghcr.io/astral-sh/uv:0.12.5 /uv /uvx /bin/

ENV UV_PYTHON_DOWNLOADS=0

WORKDIR /app

RUN --mount=type=cache,target=/root/.cache/uv \
    --mount=type=bind,source=uv.lock,target=uv.lock \
    --mount=type=bind,source=pyproject.toml,target=pyproject.toml \
    uv sync --locked --no-install-project --no-editable

COPY . /app

RUN --mount=type=cache,target=/root/.cache/uv \
    uv sync --locked --no-editable

FROM python:3.14.6-slim-bookworm

WORKDIR /app

COPY --from=builder /app/.venv /app/.venv

EXPOSE 8000

CMD ["/app/.venv/bin/fastapi", "dev", "src/atividade_2/main.py", "--host", "0.0.0.0"]
