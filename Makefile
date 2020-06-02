CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 -O3\
	-Iinclude/ \
	-Iinclude/data-structures/ \
	-Iinclude/specifiers/

VPATH=src/:src/data-structures/:src/specifiers:test/

OBJS_QUEUE= queue.o
OBJS_LIST= list.o
OBJS_STACK= stack.o
OBJS_ALLOC_LIST_STRING= specifier-list-string.o

OBJS_TEST= test-suite.o \
		test-queue.o \
		test-stack.o \
		test-list.o \
		test-specifier-list-string.o


all: test



doc:
	doxygen doc.doxygen
	cd latex; make

test-suite: ${OBJS_TEST} ${OBJS_QUEUE} \
		${OBJS_LIST} \
		${OBJS_STACK} \
		${OBJS_ALLOC_LIST_STRING}

clean:
	${RM} ${OBJS_QUEUE}
	${RM} ${OBJS_LIST}
	${RM} ${OBJS_STACK}
	${RM} ${OBJS_ALLOC_LIST_STRING}
	${RM} ${OBJS_TEST} test-suite
	${RM} -r html latex
