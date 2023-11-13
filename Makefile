#Rules section for default compilation and linking
all:
	$(MAKE) -C ipc_lib
	$(MAKE) -C speed_generator
	$(MAKE) -C speed_reader
	rm -fr build/src

clean:
	rm -fr build