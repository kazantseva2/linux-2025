BINARIES = prog prog-a prog-so
OBJS = fun.o const.o prog.o

STATIC_LIB = liboutput_static.a
SHARED_LIB = liboutput.so

all: $(BINARIES)

prog: $(OBJS)

%.o: %.c
	cc -c -fPIC -o $@ $<

prog-a: $(STATIC_LIB) prog.o
	cc -L. prog.o -loutput_static -o $@

prog-so: $(SHARED_LIB) prog.o
	cc -L. prog.o -loutput -Wl,-rpath,. -o $@

fun.o: outlib.h

$(STATIC_LIB): fun.o const.o
	ar rcs $@ $^

$(SHARED_LIB): fun.o const.o
	cc -shared -fPIC $^ -o $@

test: prog prog-a prog-so
	@echo "Running tests..."

	./prog > prog.out0 2>&1
	./prog-a > prog-a.out0 2>&1
	./prog-so > prog-so.out0 2>&1

	cmp prog.out0 prog-a.out0
	cmp prog.out0 prog-so.out0

	./prog 1 > prog.out1 2>&1
	./prog-a 1 > prog-a.out1 2>&1
	./prog-so 1 > prog-so.out1 2>&1

	cmp prog.out1 prog-a.out1
	cmp prog.out1 prog-so.out1

	./prog 1 2 3 > prog.out2 2>&1
	./prog-a 1 2 3 > prog-a.out2 2>&1
	./prog-so 1 2 3 > prog-so.out2 2>&1

	cmp prog.out2 prog-a.out2
	cmp prog.out2 prog-so.out2

	@echo "All tests passed!"

clean:
	rm -f $(BINARIES) $(OBJS) $(STATIC_LIB) $(SHARED_LIB) *.out*