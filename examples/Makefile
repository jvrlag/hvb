# Hvb makefile

hvb=../hvb/

FLAGS=-pedantic -Wall -g -I$(hvb) -O3 
LIBS=-llapack -lblas -lm -L/usr/X11R6/lib -lX11 -lImlib2 

HVBS= $(hvb)Matrix.o $(hvb)Common.o $(hvb)EX.o $(hvb)Postscript.o $(hvb)Graph.o  $(hvb)MatrixC.o $(hvb)Image.o $(hvb)Optimize.o $(hvb)Manybody.o $(hvb)Text.o

OBJECTS = 

objects: $(HVBS) $(OBJECTS)

%.o: %.cc
	g++ -c $< $(FLAGS) -o $@

x%: x%.o objects
	g++ $(FLAGS) -o $@ $< $(OBJECTS) $(HVBS) $(LIBS)

clean:
	ls x* | grep -v "\." | xargs rm -f
	rm *.o 

mrproper: 	
	rm *.o $(hvb)/*.o

