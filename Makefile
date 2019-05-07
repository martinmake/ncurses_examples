MAKEFILE_PATHS:=$(dir $(shell find ./*/ -name Makefile))

.PHONY: all
all:
	+$(foreach PATH,$(MAKEFILE_PATHS),make -e -C $(PATH);)

%:
	+$(foreach PATH,$(MAKEFILE_PATHS),make -e -C $(PATH) $@;)
