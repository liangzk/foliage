.SUFFIXES: .ml .cmo

.ml.cmo: 
	ocamlc -c $@  $<

LDFLAGS=-custom unix.cma -cclib -lunix

PROGS=envvar ls fork

all: $(PROGS)

envvar: envvar.cmo
	ocamlc $(LDFLAGS) -o $@ $<

ls: ls.cmo
	ocamlc $(LDFLAGS) -o $@ $<

fork: fork.cmo
	ocamlc $(LDFLAGS) -o $@ $<

clean: 
	rm -f *.cmi *.cmo $(PROGS)
