#!/bin/bash

echo "Nombre del ejecutable (por defecto: a.out):"
read EXEC_NAME
EXEC_NAME=${EXEC_NAME:-a.out}

echo "Archivos a compilar (separados por espacio, por defecto: main.cpp):"
read FILES
FILES=${FILES:-main.cpp}

echo "¿Archivos .hpp adicionales a crear en include/ (separados por espacio)? [Deja vacío si no]:"
read EXTRA_HPP

SRC_DIR="src"
INCLUDE_DIR="include"
OBJ_DIR="${EXEC_NAME}_objects"
mkdir -p $SRC_DIR $INCLUDE_DIR $OBJ_DIR

# include.hpp con referencia a ../exec.hpp
cat > $INCLUDE_DIR/include.hpp <<EOL
#ifndef INCLUDE_HPP
# define INCLUDE_HPP

# include <iostream>
# include <string>
# include "../$EXEC_NAME.hpp"

#endif
EOL

# extra .hpp dentro de include/
for hpp in $EXTRA_HPP; do
  cat > $INCLUDE_DIR/$hpp <<EOL
#ifndef ${hpp%.*}_HPP
# define ${hpp%.*}_HPP

// contenido de $hpp

#endif
EOL
done

# exec.hpp en la raíz, que incluye include/include.hpp
cat > $EXEC_NAME.hpp <<EOL
#ifndef ${EXEC_NAME^^}_HPP
# define ${EXEC_NAME^^}_HPP

# include "$INCLUDE_DIR/include.hpp"

#endif
EOL

# generar archivos fuente mínimos
for src in $FILES; do
  cat > $SRC_DIR/$src <<EOL
#include "../include/$EXEC_NAME.hpp"

EOL
done

# construir la lista SRC con barras invertidas
SRC_LIST=""
for src in $FILES; do
  SRC_LIST="$SRC_LIST    $SRC_DIR/$src \\
"
done

# Makefile
cat > Makefile <<EOL
NAME = $EXEC_NAME
CC = g++
CFLAGS = -g3 -Wall -Wextra -Werror -std=c++98

SRC = \\
$SRC_LIST

OBJS = \$(notdir \$(SRC:.cpp=.o))
OBJDIR = $OBJ_DIR

all: \$(OBJDIR) \$(NAME)

\$(NAME): \$(addprefix \$(OBJDIR)/, \$(OBJS))
	\$(CC) \$(CFLAGS) -o \$@ \$(addprefix \$(OBJDIR)/, \$(OBJS))

\$(OBJDIR)/%.o: src/%.cpp | \$(OBJDIR)
	\$(CC) \$(CFLAGS) -c \$< -o \$@

\$(OBJDIR):
	mkdir -p \$(OBJDIR)

clean:
	rm -rf \$(OBJDIR)

fclean: clean
	rm -f \$(NAME)

re: fclean all

.PHONY: all clean fclean re
EOL

# .gitignore
cat > .gitignore <<EOL
.vscode
$EXEC_NAME
$OBJ_DIR/
EOL

rm -- "$0"