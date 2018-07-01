# The top level Makefile
CC::=g++
CFLAGS::=`ncursesw5-config --cflags`
LDFLAGS::=`ncursesw5-config --libs`

.PHONY: all
all: b3 b4
	cd JustForFun 	&& $(MAKE)
	cd basics	&& $(MAKE)
	cd forms	&& $(MAKE)
	cd menus	&& $(MAKE)
	cd panels	&& $(MAKE)
	@echo 
	@echo "*********************************************"
	@echo "alle Dateien gebaut"
	@echo "Please move to demo/exe directory"
	@echo "Execute each file to see examples in action"
	@echo "*********************************************"
	@echo

%: %.c
	echo $(CC) $< -o $@ $(CFLAGS) $(LDFLAGS)
	$(CC) $< -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	cd JustForFun 	&& $(MAKE) clean
	cd basics	&& $(MAKE) clean
	cd forms	&& $(MAKE) clean
	cd menus	&& $(MAKE) clean
	cd panels	&& $(MAKE) clean
