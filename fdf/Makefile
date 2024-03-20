NAME = 	fdf

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES) -I$(MLX_DIR)

EXT_FLAGS = -lX11 -lm -lz -lXext

DFLAGS = -MMD -MP

MLX_DIR = minilib

MLX = libmlx.a

SRC_DIR = srcs

BUILD_DIR = .build

SRC_FILES = main.c \
			print_image.c \
			get_next_line.c \
			get_next_line_utils.c\

			

INCLUDES = includes

SRC = $(addprefix $(SRC_DIR)/, SRC_FILES)

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))

DEPS = $(OBJ:.o=.d)

.PHONY: all
all : $(NAME)


$(NAME) :  $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_DIR)/$(MLX) $(EXT_FLAGS)
.PHONY: mlx
$(MLX_DIR)/$(MLX): FORCE
	$(MAKE) -C $(MLX_DIR)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c | $(BUILD_DIR) $(MLX_DIR)/$(MLX)
	$(CC) $(CFLAGS) $(DFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEPS)

.PHONY: clean
clean :
	$(MAKE) -C $(MLX_DIR)/ clean
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean : clean
	$(RM) $(NAME)

.PHONY: re
re : fclean
	$(MAKE) all

.PHONY: FORCE
FORCE:
