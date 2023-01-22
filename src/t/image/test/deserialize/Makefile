BASE_PATH := ../../../..

include $(BASE_PATH)/build/common.mk

test:
	$(Q2)sh "$(BASE_PATH)/build/script/out_one.sh" "t/image/deserialize" "result.bmp"

INCS_FILE := incs.txt
SRCS_FILE := srcs.txt

COMMON_FLAGS := -fsanitize=address

include $(BASE_PATH)/build/test.mk
