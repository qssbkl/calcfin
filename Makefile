CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11 -D_GNU_SOURCE -lm
SRCS = calculation.c mystack.c parsing_in_polish_notation.c

all: graph

graph: mystack.o parsing_in_polish_notation.o calculation.o graph.o
	$(CC) $(CFLAGS) mystack.o graph.o parsing_in_polish_notation.o calculation.o -o graph

calculation.o: calculation.c calculation.h
	$(CC) $(CFLAGS)	calculation.c -c

graph.o: graph.c
	$(CC) $(CFLAGS) graph.c -c

polish_notation.o: polish_notation.c
	$(CC) $(CFLAGS) polish_notation.c -c

parsing_in_polish_notation.o: parsing_in_polish_notation.c
	$(CC) $(CFLAGS) parsing_in_polish_notation.c -c

mystack.o: mystack.c mystack.h
	$(CC) $(CFLAGS) mystack.c -c

s21_calc.a: ${SRCS}
	${CC} ${CFLAGS} -c ${SRCS}
	@ar rcs s21_calc.a ${OBJS}
	@ranlib s21_calc.a

check:
	cppcheck --enable=all --suppress=missingIncludeSystem --check-config *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h

clean:
	rm -rf *.o graph *.gcda *.gcno *.info unit-test Test
	rm -rf report

test:
	gcc tests.c ${SRCS} -lcheck -lm -lpthread -o Test
	./Test

unit_test:
	${CC} ${CFLAGS} -c tests.c
	${CC} tests.o s21_calc.a -lcheck -o test
	./test

gcov_report: test
	@gcc --coverage tests.c -lcheck ${SRCS} -o unit-test
	@./unit-test
	@lcov -t "test" -o test.info -c -d .
	@genhtml -o report test.info


rebuild: clean all