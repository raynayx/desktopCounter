.PHONY = all clean

CCXX = g++
CFLAGS = -fdiagnostics-color -Wall -g


OBJ := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
DEST = build
OUT = stepCounter

all: ${OUT}


$(OUT): $(OBJ)
	$(CCXX) $(CFLAGS) -o $@ $(OBJ)
	rm -vf *.o



clean:
	rm -vf $(DEST)/$(OUT) $(DEST)/*.o *~ *.o $(OUT)