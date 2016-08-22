CC=g++
CPPFLAGS=-Wall -Wextra -Wpedantic -ggdb
LIBS=
LDFAGS=
SOURCES=Color.h \
	ColorGray.cpp ColorGray.h \
	ColorRgb.cpp ColorRgb.h \
	File.cpp File.h \
	Image.cpp Image.h \
	Main.cpp \
	Tga.cpp Tga.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=viola-jones


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o$@ $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o$@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
