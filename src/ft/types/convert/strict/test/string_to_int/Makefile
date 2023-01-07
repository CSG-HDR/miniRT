BASE_PATH := ../../../../../..

include $(BASE_PATH)/build/common.mk

test:
	$(Q2)sh "$(BASE_PATH)/build/script/inout.sh" "ft/types/convert/string_to_int"

INCS_FILE := incs.txt
SRCS_FILE := srcs.txt

COMMON_FLAGS := -fsanitize=undefined

include $(BASE_PATH)/build/test.mk
