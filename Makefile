all:
	+$(MAKE) -C src

clean:
	rm -rf bin/*
	rm -rf src/*.o

.PHONY: clean
