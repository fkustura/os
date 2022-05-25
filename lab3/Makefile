# Primjer datoteke za prevođenje

CFLAGS = -Wall -MMD
LDFLAGS = -O
LDLIBS = -lm -lpthread

PROGRAM = lab3
OBJEKTI = lab3.o datoteke.o

STATUS = status.txt
OBRADA = obrada.txt

$(PROGRAM): $(OBJEKTI)
	$(CC) $(LDFLAGS) $(OBJEKTI) $(LDLIBS) -o $(PROGRAM)

H_VEZE := $(OBJEKTI:.o=.d)

.PHONY: init pokreni obrisi
init:
	@-if [ ! -e $(STATUS) ]; then echo 1 >> $(STATUS); fi;
	@-if [ ! -e $(OBRADA) ]; then echo 1 >> $(OBRADA); fi;

pokreni: $(PROGRAM) init
	@./$(PROGRAM) $(STATUS) $(OBRADA)

obrisi:
	-rm -rf $(OBJEKTI) $(H_VEZE) $(PROGRAM) $(STATUS) $(OBRADA)

-include $(H_VEZE)