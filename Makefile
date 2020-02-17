default:
	g++ -c -o driver.o driver.cpp -std=c++11
	g++ -o driver driver.o -std=c++11
	
driver.run: driver.o stu_database.o
	g++ driver.run driver.o stu.o
driver.o: driver.cpp stu_database.h
	g++ -c -o driver.o driver.cpp
stu_database.o: stu_database.cpp stu_database.h
	g++ -c -o stu_database.o stu_database.cpp
	
run:
	./driver
	
