CC=clang
FLAGS=-Wall -Wextra -Werror -pedantic -g

PROGRAMMES=crgen court #long

all: $(PROGRAMMES)

######################################################################
#                       Règles de compilation                        #
######################################################################

%.o: %.c
	$(CC) $(FLAGS) -c $<

main_crgen.o: main_crgen.c main_crgen.h display.h

display.o: display.c display.h core.h

######################################################################
#                       Règles d'édition de liens                    #
######################################################################

crgen: main_crgen.o display.o
	$(CC) $(FLAGS) $^ -o $@

clean_o:
	rm -f *.o

clean:
	rm -f $(PROGRAMMES) *.o