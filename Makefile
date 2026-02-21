clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

test:
	@for src in *_test.c; do \
		bin=$${src%.c}; \
		gcc -Wall -Wextra -Werror $$src -o $$bin; \
	done
	@for test in *_test; do \
		echo "$$test"; \
		./$$test; \
	done