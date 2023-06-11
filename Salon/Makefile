Salon_Managerment.exe : Employee.o SalonManagerment.o salon_main.o
	g++ -o Salon_Managerment.exe Employee.o SalonManagerment.o salon_main.o

SalonManagerment.o : SalonManagerment.cpp SalonManagerment.hpp Employee.hpp
	g++ -g -c SalonManagerment.cpp

Employee.o : Employee.cpp Employee.hpp 
	g++ -g -c Employee.cpp

salon_main.o : salon_main.cpp
	g++ -g -c salon_main.cpp

clean: 
	rm *.o