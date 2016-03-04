.PHONY: all, $(NAME), clean, fclean, re, norme
SRC_PATH = ./sources/

SRC_NAME = main.cpp \

SRC_CLASS_NAME = Lexer.cpp \
                 Operand.cpp \
                 OperandFactory.cpp \
                 OperandStackController.cpp \
                 Parser.cpp \

SRC_CLASS_OPERANDS_NAME = Double.cpp \
                           Float.cpp \
                           Int16.cpp \
                           Int32.cpp \
                           Int8.cpp \

INC_NAME = AbstractVM.hpp \
           IOperand.hpp \


INC_CLASS_NAME = operands/Double.hpp \
                 operands/Float.hpp \
                 operands/Int16.hpp \
                 operands/Int32.hpp \
                 operands/Int8.hpp \
                 Lexer.hpp \
                 Operand.hpp \
                 OperandFactory.hpp \
                 OperandStackController.hpp \
                 Parser.hpp \

CLASS_PATH = classes/
OPERANDS_PATH = operands/
CLASS_OPERANDS_PATH = $(addprefix $(CLASS_PATH), $(OPERANDS_PATH))
OBJ_PATH = ./obj/
INC_PATH = ./includes/

NAME = AbstractVM

CC = clang++
VERSION = -std=c++11
CFLAGS = -Werror -Wall -Wextra

SRC_CLASS_OPERANDS_MID_NAME = $(addprefix $(OPERANDS_PATH), $(SRC_CLASS_OPERANDS_NAME))
INC_CLASS_FULL_NAME = $(addprefix $(CLASS_PATH), $(INC_CLASS_NAME))
SRC_CLASS_FULL_NAME = $(addprefix $(CLASS_PATH), $(SRC_CLASS_NAME)) $(addprefix $(CLASS_PATH), $(SRC_CLASS_OPERANDS_MID_NAME))
OBJ_NAME = $(SRC_NAME:.cpp=.o) $(SRC_CLASS_FULL_NAME:.cpp=.o)

CLASS_NAME = $(SRC_NAME:.cpp=.o) $(SRC_CLASS_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME)) $(addprefix $(SRC_PATH), $(SRC_CLASS_FULL_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix $(INC_PATH), $(INC_NAME)) $(addprefix $(INC_PATH), $(INC_CLASS_FULL_NAME))

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(VERSION) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\033[32m\033[4m$(NAME):\033[0m\033[1m executable has been compiled successfully\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp $(INC)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(addprefix $(OBJ_PATH), $(CLASS_OPERANDS_PATH))
	$(CC) $(VERSION) $(CFLAGS) -I$(INC_PATH) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@echo "\033[32m\033[4m$(NAME):\033[0m\033[1m object files have been removed successfully\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32m\033[4m$(NAME):\033[0m\033[1m executable file has been removed succesully\033[0m"

re: fclean all
