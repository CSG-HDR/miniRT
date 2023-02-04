Q3 := $(if $(filter 3,$(V) $(VERBOSE)),,@)
Q2 := $(if $(filter 2 3,$(V) $(VERBOSE)),,@)
Q1 := $(if $(filter 1 2 3,$(V) $(VERBOSE)),,@)
MAKE := $(MAKE) $(if $(filter 3,$(V) $(VERBOSE)),,--no-print-directory) $(if $(filter 1,$(NO_ADDITIONAL_J)),,-j $(shell sh src/build/script/nproc.sh) NO_ADDITIONAL_J=1)

export V

all: test
clean:
	$(Q2)rm -rf tmp
	$(Q2)$(MAKE) -C src clean
	$(Q2)$(MAKE) -C assets/leak_test clean
	$(Q2)find src \( -type f \( -name compile_commands.json -o -name "*.part.json" -o -name "*.exe" \) -o -type d -name .cache \) -delete
	$(Q2)find src -type d -empty -delete
	$(Q2)find src -type d -name test | xargs -L1 -I {} $(MAKE) -C {} clean
	@printf "\033[0m"
fclean:
	$(Q2)rm -f compile_commands.json .vscode/launch.json .vscode/tasks.json
	$(Q2)$(MAKE) -C src fclean
	$(Q2)$(MAKE) -C assets/leak_test fclean
	$(Q2)find src \( -type f \( -name compile_commands.json -o -name "*.part.json" -o -name "*.exe" \) -o -type d -name .cache \) -delete
	$(Q2)find src -type d -empty -delete
	$(Q2)find src -type d -name test | xargs -L1 -I {} $(MAKE) -C {} fclean
	@printf "\033[0m"
re:
	$(Q3)$(MAKE) fclean
	$(Q3)$(MAKE) all
test:
	$(Q2)find src -type d -name test | sort | xargs -L1 $(MAKE) -C
	$(Q2)$(MAKE) prepare_publish
	$(Q2)$(MAKE) -C tmp
	$(Q2)$(MAKE) -C test
	@echo "Some test might need manual review"
prepare_publish:
	$(Q2)rm -rf tmp
	$(Q2)mkdir tmp
	$(Q2)sh src/build/script/copy_src_to_tmp_flatten.sh
	$(Q2)cd tmp && sh ../template/template.sh > Makefile
publish_without_test: prepare_publish
ifndef GIT_REMOTE_URL
	$(error GIT_REMOTE_URL is undefined)
endif
	$(Q2)(cd tmp && git init && git add . && git commit -m "Initial commit" && git push "$(GIT_REMOTE_URL)" HEAD:master) || (echo "Failed to publish" && false)
	$(Q2)rm -rf tmp
	$(Q2)git push "$(GIT_REMOTE_URL)" HEAD:source || echo "Failed to push HEAD to source"
publish:
	$(Q1)$(MAKE) test
	$(Q1)$(MAKE) publish_without_test
.PHONY: all clean fclean re init deinit reinit refresh test publish publish_without_test prepare_publish

.PHONY: pre_dev
pre_dev:
	$(Q2)find src -type d -name test | xargs -L1 -I {} $(MAKE) -C {} dev
.PHONY: compile_commands.json
compile_commands.json: pre_dev
	$(Q2)$(MAKE) -C src -k PROFILE=debug TARGET=development PRECISION=0 all bonus ; (printf "[" && find src/.cache -name "*.development.debug.0.o.compile_commands.part.json" | xargs cat && printf "]") > $@
.PHONY: .vscode/launch.json
.vscode/launch.json: pre_dev
	$(Q2)(cat template/launch.json.before.txt && find src -name launch.part.json | xargs cat && cat template/launch.json.after.txt) > $@
.PHONY: .vscode/tasks.json
.vscode/tasks.json: pre_dev
	$(Q2)(cat template/tasks.json.before.txt && find src -name tasks.part.json | xargs cat && cat template/tasks.json.after.txt) > $@
.PHONY: dev
dev: compile_commands.json .vscode/launch.json .vscode/tasks.json
.PHONY: norm
norm:
	$(Q2)$(MAKE) -C src norm

.PHONY: run
run:
	$(Q3)$(MAKE) -C src run
