NAME        = call_me_maybe

# Configuration des chemins pour économiser l'espace disque (Goinfre)
USER        ?= $(shell whoami)
GOINFRE     = /goinfre/$(USER)
VENV_PATH   = $(GOINFRE)/call_me_maybe_venv
CMM_DIR		= "CMM"
VENV_DIR	= venv_CMM
CACHE_DIR	= "cache_CMM"

CMM_LOCATION="/goinfre/$USER/$CMM_DIR"

# Export des variables d'environnement pour rediriger les caches
export UV_CACHE_DIR = $(GOINFRE)/uv_cache
export HF_HOME = $(GOINFRE)/hf_cache
export TRANSFORMERS_CACHE = $(GOINFRE)/hf_cache

# Commandes
UV = uv
PYTHON = $(UV) run python
LINT_FLAGS = --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

SDK_SRC = attachments_project_ai/attachments_project_ai/llm_sdk
DATA_SRC = attachments_project_ai/attachments_project_ai/data/exercise_input

all: install

install:

run:
	uv --cache-dir "$CMM_LOCATION/$CACHE_DIR" --project llm_sdk run --active python3 -m src

debug:
	@echo "Lancement en mode debug..."
	$(PYTHON) -m pdb -m src

lint:
	@echo "Vérification du code (flake8 & mypy)..."
	$(UV) run flake8 src
	$(UV) run mypy src $(LINT_FLAGS)

lint-strict:
	@echo "🔍 Vérification stricte (optionnelle)..."
	$(UV) run flake8 src
	$(UV) run mypy src --strict

clean:
	@echo "Nettoyage..."
	rm -rf __pycache__ src/__pycache__ .mypy_cache .pytest_cache
	rm -rf data/output

fclean: clean
	@echo "Suppression de l'environnement virtuel et des caches..."
	rm -rf .venv
	rm -rf $(VENV_PATH)
	rm -rf $(UV_CACHE_DIR)
	rm -rf $(HF_HOME)

re: fclean install

.PHONY: all install run debug lint lint-strict clean fclean re
