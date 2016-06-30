CC=gcc
CFLAGS = -g
LIBS= -lcheck -lm -lpthread -lrt


OBJ = romanNumeralLib.o

#%.o: %.c
#		$(CC) -g -c -o $@ $< $(CFLAGS)
		
all:  romanNumeralLib.o romanNumeralLib_test

#romanNumeralLib.o: $(OBJ) romanNumeralLib.h

romanNumeralLib_test: romanNumeralLib_test.o $(OBJ)
	$(CC) -o ./bin/$@ $^ $(CFLAGS) $(LIBS)
			
.PHONY: clean
			
clean:
	rm -f *.o core  
				
