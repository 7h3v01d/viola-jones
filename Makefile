CC=g++
CPPFLAGS=-Wall -Wextra -Wpedantic -ggdb
LIBS=
LDFAGS=
SOURCES=Cascade.cpp \
	CascadeBuilder.cpp \
	ColorGray.cpp \
	ColorRgb.cpp \
	File.cpp \
	Image.cpp \
	IntegralImage.cpp \
	Main.cpp \
	Rectangle.cpp \
	Stage.cpp \
	Tga.cpp \
	ThreeRectangleFeature.cpp \
	TwoRectangleFeature.cpp \
	WeakClassifier.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=viola-jones


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o$@ $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o$@

clean:
	$(RM) *.o $(EXECUTABLE) $(EXECUTABLE).valgrind

valgrind:
	cat /dev/null > $(EXECUTABLE).valgrind
	valgrind --trace-children=yes \
		 --log-file=$(EXECUTABLE).valgrind \
		 --leak-check=full \
		 --show-reachable=yes -v ./$(EXECUTABLE)
