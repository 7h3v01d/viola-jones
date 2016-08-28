CC=g++
CPPFLAGS=-Wall -Wextra -Wpedantic -ggdb
LIBS=
LDFAGS=
SOURCES=ColorGray.cpp \
	ColorRgb.cpp \
	File.cpp \
	Image.cpp \
	Main.cpp \
	Tga.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=viola-jones


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o$@ $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o$@

clean:
	$(RM) *.o $(EXECUTABLE)
