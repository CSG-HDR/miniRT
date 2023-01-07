.PHONY: compile_commands.json
compile_commands.json:
	$(Q2)$(MAKE) -k build ; (printf "[" && find . -name "*.compile_commands.part.json" | xargs cat && printf "]") > $@

.PHONY: clean_compile_commands.json
clean_compile_commands.json:
	$(Q2)find . -name "*.compile_commands.part.json" | xargs rm

.PHONY: fclean_compile_commands.json
fclean_compile_commands.json:
	$(Q2)rm -rf compile_commands.json

dev: compile_commands.json
clean: clean_compile_commands.json
fclean: fclean_compile_commands.json
