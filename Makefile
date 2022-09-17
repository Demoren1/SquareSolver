all : sq_solver

CFLAGS = -Wall
sq_solver : SquareSolver.o is_zero_test.o solver.o input_output.o square_test.o linear_test.o
	g++ $(CFLAGS) SquareSolver.o is_zero_test.o solver.o input_output.o square_test.o linear_test.o -o sq_solver

SquareSolver.o : SquareSolver.cpp
	g++ $(CFLAGS) SquareSolver.cpp -c

is_zero_test.o : is_zero_test.cpp
	g++ $(CFLAGS) is_zero_test.cpp -c

input_output.o : SquareSolver.cpp
	g++ $(CFLAGS) input_output.cpp -c

square_test.o : square_test.cpp
	g++ $(CFLAGS) square_test.cpp -c

linear_test.o : linear_test.cpp
	g++ $(CFLAGS) linear_test.cpp -c

clean :
	del *.o sq_solver