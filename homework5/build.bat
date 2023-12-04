g++ -std=c++20 -fmodules-ts -c module1.cppm -o module1.o
g++ -std=c++20 -fmodules-ts -c module2.cppm -o module2.o
g++ -std=c++20 -fmodules-ts -c module3.cppm -o module3.o
g++ -std=c++20 -fmodules-ts -c main.cpp -o main.o
g++ module1.o module2.o module3.o main.o -o program
pause