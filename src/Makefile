Q3 := $(if $(filter 3,$(V) $(VERBOSE)),,@)
Q2 := $(if $(filter 2 3,$(V) $(VERBOSE)),,@)
Q1 := $(if $(filter 1 2 3,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory) $(if $(filter 1,$(NO_ADDITIONAL_J)),,-j $(shell sh build/script/nproc.sh) NO_ADDITIONAL_J=1)

CC := clang
AR := ar
ARFLAGS := cr$(if $(filter 3,$(V) $(VERBOSE)),v,)
CPPFLAGS += $(shell find . -type d -mindepth 1 | grep -v /test/ | sed "s/^/-I /" | xargs)
CFLAGS := -Wall -Wextra -Werror -std=c99 -pedantic $(CPPFLAGS)

# mlx
CFLAGS += -I.cache/mlx/minilibx_opengl_20191021
LDFLAGS += -L.cache/mlx/minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

SRC_DIR := .
OBJ_DIR := .cache

SRCS_MINIRT := ./main.c $(shell find . -name "minirt_*.c" | grep -v /test/ | xargs)
SRCS_LIBWRAP := $(shell find . -name "wrap_*.c" | grep -v /test/ | xargs)
SRCS_LIBT := $(shell find . -name "t_*.c" | grep -v /test/ | xargs)
SRCS_LIBFT := $(shell find . -name "ft_*.c" | grep -v /test/ | xargs)
SRCS_LIBFTO := $(shell find . -name "fto_*.c" | grep -v /test/ | xargs)

NAME := minirt
EXECUTABLE_TARGETS := $(NAME)

all: $(NAME)
bonus: all
clean:
	$(Q1)rm -rf $(OBJ_DIR)
fclean:
	$(Q3)$(MAKE) clean
	$(Q1)rm -f $(EXECUTABLE_TARGETS:=.exe)
re:
	$(Q3)$(MAKE) NO_ADDITIONAL_J=1 fclean
	$(Q3)$(MAKE) NO_ADDITIONAL_J=1 all
test:
	$(Q1)find . -type d -mindepth 1 -name "test" | xargs -L1 -I {} $(MAKE) -C {} test
.PHONY: all bonus clean fclean re test

.cache/mlx:
	mkdir -p .cache/mlx.tmp
	tar xf ../assets/minilibx_opengl.tgz -C .cache/mlx.tmp
	rm -rf .cache/mlx
	mv .cache/mlx.tmp .cache/mlx
.cache/mlx/minilibx_opengl_20191021/libmlx.dylib: .cache/mlx
	make -C .cache/mlx/minilibx_opengl_20191021 -j 1

PROFILE ?= release
ifeq ($(PROFILE),release)
CFLAGS += -O3 -DNDEBUG
else ifeq ($(PROFILE),debug)
CFLAGS += -g3 -DDEBUG
else
$(error Bad profile)
endif

TARGET ?= production
ifeq ($(TARGET),production)
CFLAGS += -DNDEVELOPMENT
else ifeq ($(TARGET),development)
CFLAGS += -DDEVELOPMENT
else
$(error Bad target)
endif

PRECISION ?= 0
ifeq ($(PRECISION),3)
CFLAGS += -DPRECISION=3
else ifeq ($(PRECISION),2)
CFLAGS += -DPRECISION=2
else ifeq ($(PRECISION),1)
CFLAGS += -DPRECISION=1
else ifeq ($(PRECISION),0)
CFLAGS += -DPRECISION=0
else
$(error Bad precision)
endif

SUFFIX := .$(TARGET).$(PROFILE)$(if $(SANITIZER),.$(SANITIZER)).$(PRECISION)
CFLAGS += $(if $(SANITIZER),-fsanitize=$(SANITIZER),)
LDFLAGS += $(if $(SANITIZER),-fsanitize=$(SANITIZER),)

$(OBJ_DIR)/%.a:
	$(Q3)mkdir -p $(@D)
	$(Q2)$(AR) $(ARFLAGS) $@ $^
$(OBJ_DIR)/%.exe: $(OBJ_DIR)/libwrap$(SUFFIX).a $(OBJ_DIR)/libt$(SUFFIX).a $(OBJ_DIR)/libft$(SUFFIX).a $(OBJ_DIR)/libfto$(SUFFIX).a | .cache/mlx/minilibx_opengl_20191021/libmlx.dylib
	$(Q3)mkdir -p $(@D)
	$(Q2)$(CC) $(LDFLAGS) -o $@ $^
$(OBJ_DIR)/%$(SUFFIX).o: %.c | .cache/mlx
	$(Q3)mkdir -p $(@D)
	$(Q2)$(CC) $(CFLAGS) -MJ $@.compile_commands.part.json -MMD -o $@ -c $<

$(OBJ_DIR)/libwrap$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBWRAP))
$(OBJ_DIR)/libt$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBT))
$(OBJ_DIR)/libft$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBFT))
$(OBJ_DIR)/libfto$(SUFFIX).a: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_LIBFTO))
$(OBJ_DIR)/$(NAME)$(SUFFIX).exe: $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).o,$(SRCS_MINIRT))
$(EXECUTABLE_TARGETS): %: $(OBJ_DIR)/%$(SUFFIX).exe
	$(Q1)cp $< $@.exe
.PHONY: $(EXECUTABLE_TARGETS)

.PHONY: run
run: $(OBJ_DIR)/$(NAME)$(SUFFIX).exe
	$QDYLD_LIBRARY_PATH=.cache/mlx/minilibx_opengl_20191021 ./$< $(ARGS)

# dependencies
-include $(patsubst ./%.c,$(OBJ_DIR)/%$(SUFFIX).d,$(SRCS))
