CC = clang
CXX = clang++

CFLAGS = -std=c18 \
		 -Wall -Wextra -Wpedantic -Werror=pedantic -Wno-unknown-pragmas \
		 -Wconversion -Wsign-conversion -Wfloat-equal \
		 -Wshadow -Wunreachable-code -D LOCAL -pipe


RELEASE_CFLAGS = -flto=thin -march=native -O3 -funroll-loops -ffast-math -D NDEBUG

DEBUG_CFLAGS = -g3 -glldb -fsanitize=address -fsanitize=undefined -fsanitize=leak \
				 -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow

SOURCES = solution.c
EXECUTABLE = solution
OBJS = solution.o

.PHONY: all debug release clean cppcheck clang-tidy static

all: debug

debug: CXXFLAGS += $(DEBUG_CFLAGS)
debug:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

release: CXXFLAGS += $(RELEASE_CFLAGS)
release:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

cppcheck:
	cppcheck --enable=all --inconclusive --std=c11 --suppress=missingIncludeSystem $(SOURCES)

clang-tidy:
	clang-tidy $(SOURCES) -- -std=c18 -I ./include -D LOCAL

static: cppcheck clang-tidy

clean:
	@ rm -rfv $(OBJS) $(EXECUTABLE)
