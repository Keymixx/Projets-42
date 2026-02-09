VENV			=	maze_env
PYTHON			=	$(VENV)/bin/python3
PIP				=	$(VENV)/bin/pip
RM				=	rm -rf
FLAKE8			=	$(VENV)/bin/flake8
FLAKE8_FLAGS	=	--exclude=$(VENV),__pycache__,.mypy_cache
MYPY			=	$(VENV)/bin/mypy
MYPY_FLAG		=	$(MYPY) --warn-return-any --warn-unused-ignores \
				--ignore-missing-imports --disallow-untyped-defs --check-untyped-defs

install:		
				python3 -m venv $(VENV)
				$(PIP) install flake8 mypy mazegen-1.0.0-py3-none-any.whl

run:			
				$(PYTHON) a_maze_ing.py config.txt

debug:			
				$(PYTHON) -m pdb a_maze_ing.py config.txt

clean:			
				$(RM) __pycache__ .mypy_cache *.tar.gz output_maze.txt
				$(RM) $(VENV)

lint:			
				$(FLAKE8) $(FLAKE8_FLAGS).
				$(MYPY_FLAG) .

lint-strict:	$(FLAKE8) .
				$(MYPY) . --strict

.PHONY:	install run debug clean lint lint-strict
