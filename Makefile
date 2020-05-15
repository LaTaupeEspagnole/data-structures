CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 -Iinclude/

VPATH=src/:test/

OBJS_QUEUE= queue.o
OBJS_QUEUE_TEST= test-queue.o

OBJS_LIST= list.o
OBJS_LIST_TEST= test-list.o

OBJS_STACK= stack.o
OBJS_STACK_TEST= test-stack.o

OBJS_ALLOC_LIST_STRING= alloc-list-string.o
OBJS_ALLOC_LIST_STRING_TEST= test-alloc-list-string.o


all: test



doc:
	doxygen doc.doxygen
	cd latex; make


test: test-queue test-list test-stack test-alloc-list-string

test-queue: ${OBJS_QUEUE} ${OBJS_QUEUE_TEST}

test-list: ${OBJS_LIST} ${OBJS_LIST_TEST}

test-stack: ${OBJS_STACK} ${OBJS_STACK_TEST}

test-alloc-list-string: ${OBJS_LIST} ${OBJS_ALLOC_LIST_STRING} ${OBJS_ALLOC_LIST_STRING_TEST}



clean: clean-doc clean-queue clean-list clean-stack clean-alloc-list-string

clean-doc:
	${RM} -r html latex

clean-queue:
	${RM} ${OBJS_QUEUE} ${OBJS_QUEUE_TEST} test-queue

clean-list:
	${RM} ${OBJS_LIST} ${OBJS_LIST_TEST} test-list

clean-stack:
	${RM} ${OBJS_STACK} ${OBJS_STACK_TEST} test-stack

clean-alloc-list-string:
	${RM} ${OBJS_ALLOC_LIST_STRING} ${OBJS_ALLOC_LIST_STRING_TEST} test-alloc-list-string
