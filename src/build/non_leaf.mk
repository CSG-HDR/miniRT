include $(BASE_PATH)/build/common.mk

all: test
.PHONY: all test clean fclean re build dev

test clean fclean build dev:
	$(Q2)find . -depth 1 -type d | xargs -L1 -I {} $(MAKE) -C {} $@
