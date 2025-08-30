SRC_DIR = src

OBJ_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
# //FIXME  -I flag
CXX := g++
CXXFLAGS := -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations \
    -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts \
    -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal \
    -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline \
    -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked \
    -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo \
    -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn \
    -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default \
    -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast \
    -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing \
    -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation \
    -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer \
    -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla \
    -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

#SRC_FILES := main.cpp io.cpp equation_solver.cpp logic_functions.cpp my_assert.cpp \
	logic_functions_test.cpp equation_solver_test.cpp global_test.cpp interactive_mode.cpp \
    help.cpp prank.cpp logger.cpp
#OBJ_FILES := $(SRC_FILES:.cpp=.o)

all: SquareSolver

SquareSolver: $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR) SquareSolver


# //ДЕЛО СДЕЛАНО куда ставить @, чтобы не видеть, что делает мейк
