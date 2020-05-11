
CXX=g++
INC=
LIBS=
CFLAGS = -W -static
TARGET = bfloat16_app
OBJS=   main.o \
		bfloat16_add.o\
		bfloat16_mul.o\



OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

${TARGET}: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ $^

${OBJS}: %.o : %.c
	${CXX} ${CXXFLAGS} -o $@ -c $< 

%.d : %.c
	@${CXX} -MM $< > $@

.PHONY: clean

clean:
	rm -f *.o *.d ${TARGET}

