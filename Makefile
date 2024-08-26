# !!! Save .o to build folder

CC = g++
CFLAGS = -c -Wall -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual\
-Wchar-subscripts -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2 -Winline\
-Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo\
-Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros\
-Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -Wsuggest-override\
-Wlong-long -Wopenmp -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -fno-omit-frame-pointer\
-Wlarger-than=8192 -Wstack-protector -fPIE -Werror=vla
LDFLAGS =
SOURCES = $(addprefix source/, double_arithmetics.cpp equation.cpp input_output.cpp main.cpp tester.cpp flagging.cpp)
OBJECTS = $(addprefix build/, $(notdir $(SOURCES:.cpp=.o)) )
EXECUTABLE = qdr_run

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

build/%.o: source/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	del /f /s *.o

echo:
	@echo $(OBJECTS)
	@echo $(notdir *.cpp) a
