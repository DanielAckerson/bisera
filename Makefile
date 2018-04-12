all:
	+$(MAKE) -C src

.PHONY: clean
clean:
	rm -rf bin/*
	rm -rf src/*.o
