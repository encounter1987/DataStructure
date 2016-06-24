CC=g++
INCLUDE=../DsUtils
CPP=../DsUtils
OBJ=*.o
OP=binary


exec: \
	compile
	@echo "OUTPUT OF THE PROGRAM:"
	@./binary <$(INPUT)

compile: \
	makeobjectfiles
	@echo "COMPILING"
	@$(CC) -o $(OP) $(SRC) *.o  -I $(INCLUDE)

makeobjectfiles:
	@echo "MAKING OBJECT FILES"
	@$(CC) -c $(CPP)/*.cpp -I $(INCLUDE)

clean:
	@rm *.o $(OP)
