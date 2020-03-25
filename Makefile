CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 -Iinclude/

VPATH=src/:test/

OBJS_QUEUE= queue.o
OBJS_QUEUE_TEST= test-queue.o

OBJS_LIST= list.o
OBJS_LIST_TEST= test-list.o

OBJS_STACK= stack.o
OBJS_STACK_TEST= test-stack.o


all: test



test: test-queue test-list test-stack

test-queue: ${OBJS_QUEUE} ${OBJS_QUEUE_TEST}

test-list: ${OBJS_LIST} ${OBJS_LIST_TEST}

test-stack: ${OBJS_STACK} ${OBJS_STACK_TEST}



clean: clean-queue clean-list clean-stack

clean-queue:
	${RM} ${OBJS_QUEUE} ${OBJS_QUEUE_TEST} test-queue

clean-list:
	${RM} ${OBJS_LIST} ${OBJS_LIST_TEST} test-list

clean-stack:
	${RM} ${OBJS_STACK} ${OBJS_STACK_TEST} test-stack
