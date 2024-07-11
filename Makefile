CXX = g++
CXXFLAGS = -std=c++11 -Iinclude -I/opt/homebrew/opt/mysql-client/include
LDFLAGS = -L/opt/homebrew/opt/mysql-client/lib -lmysqlclient
SOURCES = src/database.cpp src/student.cpp src/student_management_system.cpp src/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = StudentManagementSystem

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
