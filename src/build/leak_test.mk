all: test

include $(BASE_PATH)/build/compile_commands.mk

build: .cache/Makefile

.cache/Makefile:
	$(Q3)mkdir -p .cache
	$(Q2)sh $(BASE_PATH)/build/script/leak_test_build.sh $(BASE_PATH) $(SRCS_FILE) $(INCS_FILE)

clean:
	$(Q2)rm -rf .cache

fclean: clean
	$(Q2)rm -f launch.part.json tasks.part.json

test: build

build:
	$(Q2)$(MAKE) COMMON_FLAGS=$(COMMON_FLAGS) -C .cache

launch.part.json:
	$(Q2)printf '    {\n      "type": "lldb",\n      "request": "launch",\n      "name": "Debug leak test %s",\n      "program": "%s/.cache/test.exe",\n      "cwd": "%s",\n      "preLaunchTask": "build leak test %s",\n    },\n' "$$(basename "$$(pwd)")" "$$(pwd)" "$$(pwd)" "$$(basename "$$(pwd)")" > $@

tasks.part.json:
	$(Q2)printf '    {\n      "label": "build leak test %s",\n      "type": "shell",\n      "command": "$(MAKE) build",\n      "options": {\n        "cwd": "%s",\n      },\n      "problemMatcher": ["$$gcc"]\n    },\n' "$$(basename "$$(pwd)")" "$$(pwd)" > $@

dev: launch.part.json tasks.part.json
