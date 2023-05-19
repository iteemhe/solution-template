CC = clang
CXX = clang++

CXXFLAGS = -std=c++20 \
		   -Wall -Wextra -Wpedantic -Werror=pedantic -Wno-unknown-pragmas \
		   -Wconversion -Wsign-conversion -Wfloat-equal \
		   -Wshadow -Wunreachable-code -D LOCAL -pipe

RELEASE_CXXFLAGS = -flto=thin -march=native -O3 -funroll-loops -ffast-math -D NDEBUG

DEBUG_CXXFLAGS = -g3 -glldb -fsanitize=address -fsanitize=undefined -fsanitize=leak \
				 -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow

SOURCES = solution.cpp
EXECUTABLE = solution lc
OBJS = solution.o

.PHONY: all debug release clean cppcheck clang-tidy static

all: debug

debug: CXXFLAGS += $(DEBUG_CXXFLAGS)
debug:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

release: CXXFLAGS += $(RELEASE_CXXFLAGS)
release:
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE)

lc: CXXFLAGS += $(DEBUG_CXXFLAGS)
lc: lc.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

cppcheck:
	cppcheck --enable=all --inconclusive --std=c++20 --suppress=missingIncludeSystem $(SOURCES)

clang-tidy:
	clang-tidy $(SOURCES) -- -std=c++20 -I ./include -D LOCAL

static: cppcheck clang-tidy

clean:
	@ rm -rfv $(OBJS) $(EXECUTABLE)
