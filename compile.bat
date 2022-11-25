g++ -c matrix.cpp -o matrix.o
ar rcs libmatrix.a matrix.o

g++ -c cnn.cpp -o cnn.o
ar rcs libcnn.a cnn.o

g++ -c main.cpp -o main.o
g++ -o esercitazione1-denisparolari.exe main.o -L. -lmatrix -lcnn
g++ -o esercitazione1-denisparolari.out main.o -L. -lmatrix -lcnn