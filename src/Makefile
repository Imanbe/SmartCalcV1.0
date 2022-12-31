OS := $(shell uname -s)
SRC =  s21_valid.c s21_parser.c s21_stack.c 
SRC_FOR_TEST =   s21_valid.c s21_parser.c s21_stack.c  
OBJ = $(SRC:%.c=%.o)
MAIN = main.c

CC = gcc -std=c11

CFLAGS	= -Wall -Wextra -Werror
FLAGS_PLATFORM = -lcheck

TEST = s21_test.c
FLAGS_PLATFORM = -lcheck

GCOVFLAGS = -fprofile-arcs -ftest-coverage
REPORT = GcovReport

ifeq ($(OS), Darwin)
	FLAGS_PLATFORM = -lcheck
else
	FLAGS_PLATFORM = -lcheck -lsubunit -lrt -lm -lpthread -g
endif

all: install

.PHONY: all, install, uninstall, clean, dvi, dist, tests, gcov_report

dvi:
	open readme.html

tests:
	@$(CC) $(CFLAGS) $(TEST) $(SRC_FOR_TEST) $(FLAGS_PLATFORM) -o tests.out
	@./tests.out

clean:
	@rm -rf *.{a,o,dSYM,out}
	@rm -rf $(EXECUTABLE)
	@rm -rf GcovReport
	@rm -rf report
	@rm -rf CPPLINT.cfg
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf test
	@rm -rf ../Archive_SmartCalc_v1.0
	@rm -rf *tgz
	@rm -rf gcov_test

check:
	@cp ../materials/linters/.clang-format ./
	
	@clang-format -i ./*.c ./*.h
	clang-format -n ./*.c ./*.h

	@clang-format -i ../SmartCalc/*.cpp ../SmartCalc/*.h
	clang-format -n ../SmartCalc/*.cpp ../SmartCalc/*.h

	@rm -rf .clang-format

leaks:
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(TEST) $(SRC) $(FLAGS_PLATFORM) -o unit.out
	CK_FORK=no leaks --atExit -- ./unit.out

gcov_report:
	gcc $(GCOVFLAGS) $(TEST) $(SRC) $(FLAGS_PLATFORM) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	# rm -rf ./*.gcno ./*.gcda ./$(REPORT).*
	open ./report/index.html
	# rm $(REPORT)
	# rm -rf *.dSYM


install:
	make clean
	mkdir ../build
	cd ../SmartCalc && qmake && make && make clean && rm Makefile && cd ../ && mv SmartCalc/SmartCalc.app build
	cd ../build && open SmartCalc.app

open:
	cd ../build/&& open SmartCalc.app

uninstall:
	@rm -rf ../build*
dist:
	@rm -rf Archive_SmartCalc_v1.0/
	@mkdir Archive_SmartCalc_v1.0/
	@mkdir Archive_SmartCalc_v1.0/src
	@mv ../build/SmartCalc.app Archive_SmartCalc_v1.0/src/
	@tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	@rm -rf Archive_SmartCalc_v1.0/
	@echo ==Archive was created==

bist:
	rm -rf Archive_SmartCalc_v1.0.tgz