.PHONY = all clean

CCXX = g++
CFLAGS = -fdiagnostics-color -Wall -g
LINKFLAGS = -c -ggdb


OBJ := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
DEST = build
OUT = stepCounter

all: ${OUT}


$(OUT): $(OBJ)
	$(CCXX) $(CFLAGS) -o $@ $(OBJ)

%.o:%.cpp
	$(CCXX) $(LINKFLAGS) $<



clean:
	rm -vf $(DEST)/$(OUT) $(DEST)/*.o *~ *.o $(OUT)