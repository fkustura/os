CFLAGS = -Wall -MMD
LDFLAGS = -O
LDLIBS = -lgmp -lm

OBJEKTI = signali.o
PROGRAM = sig

$(PROGRAM): $(OBJEKTI)
	$(CC) $(LDFLAGS) $(OBJEKTI) $(LDLIBS) -o $(PROGRAM)

.PHONY: pokreni obrisi
pokreni: $(PROGRAM)
	-@./$(PROGRAM)

H_VEZE := $(OBJEKTI:.o=.d)

obrisi:
	-rm -rf $(OBJEKTI) $(H_VEZE) $(PROGRAM)

-include $(H_VEZE)
