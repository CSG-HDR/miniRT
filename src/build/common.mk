Q3 := $(if $(filter 3,$(V) $(VERBOSE)),,@)
Q2 := $(if $(filter 2 3,$(V) $(VERBOSE)),,@)
Q1 := $(if $(filter 1 2 3,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory)

CC := clang
ARFLAGS := cr$(if $(filter 3,$(V) $(VERBOSE)),v,)

default: all
.PHONY: default all test clean fclean re build dev

re:
	$(Q3)$(MAKE) fclean
	$(Q3)$(MAKE) all
