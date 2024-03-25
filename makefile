CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =
BINDIR = bin
SRCDIR = src

all: $(BINDIR)/soru1 $(BINDIR)/soru2

$(BINDIR)/soru1: $(SRCDIR)/soru1.o | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BINDIR)/soru2: $(SRCDIR)/soru2.o | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BINDIR)/%.o: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR):
	mkdir $(BINDIR)

clean:
	rm -f $(SRCDIR)/*.o $(BINDIR)/soru1 $(BINDIR)/soru2
