CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =
BINDIR = bin
SRCDIR = src

all: $(BINDIR)/soru1 $(BINDIR)/soru2

$(BINDIR)/soru1: $(SRCDIR)/soru1.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BINDIR)/soru2: $(SRCDIR)/soru2.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(SRCDIR)/soru1.o: $(SRCDIR)/soru1.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCDIR)/soru2.o: $(SRCDIR)/soru2.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCDIR)/*.o $(BINDIR)/soru1 $(BINDIR)/soru2
