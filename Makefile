.PHONY: all clean test s21_math.a gcov_report

CC = gcc
CFLAGS = -O3 -Wall -Wextra -Werror -std=c11 -g
EXEC = main
TESTEXEC = test

SOURCES= s21_*.c helpers/*.c helpers/dec_str/*.c helpers/num_str/*.c
OBJECTS= *.o

SUITE_CASES_C = tests.c
SUITE_CASES_O = tests.o

ALLPROJECT = *.c *.h tests/*.c helpers/*.c helpers/dec_str/*.c helpers/num_str/*.c

all: clean s21_decimal.a

s21_decimal.a:
	rm -f *.o
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar rcs s21_decimal.a $(OBJECTS)
	rm -f *.o

run_main:
	$(CC) $(CFLAGS) -c $(SOURCES) main.c 
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJECTS) -lm
	./$(EXEC)

test: clean s21_decimal.a
	$(CC) $(CFLAGS) -c tests/s21_tests.c
	$(CC) $(CFLAGS) --coverage -o $(TESTEXEC) -L. s21_decimal.a s21_tests.o $(SOURCES) -lcheck -lm
	./$(TESTEXEC)

gcov_report: clean test
	gcov test-s21_*.gcda	
	gcovr -b 
	gcovr
	gcovr --html-details -o tests/report.html

check:
	cppcheck --enable=all --force --check-config for details *.c *.h $(ALLPROJECT)
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c $(ALLPROJECT)
#	CK_FORK=no leaks --atExit -- ./tests
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./$(TESTEXEC)

clean:
	find . -name '*.gcno' -type f -delete
	find . -name '*.gcda' -type f -delete
	find . -name '*.gcov' -type f -delete
	find . -name '*.a' -type f -delete
	find . -name '*.o' -type f -delete
	find . -name '*.info' -type f -delete
	find . -name '*.html' -type f -delete
	find . -name '*.css' -type f -delete
	rm -f CPPLINT.cfg
	rm -f $(EXEC)
	rm -f $(TESTEXEC)
	rm -f RESULT_VALGRIND.txt
	rm -rf report
	rm -rf s21_decimal