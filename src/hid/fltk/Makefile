DESTDIR =
PREFIX = /usr/local

pcb_fltk = pcb_fltk
pcb_fltkd = pcb_fltkd

CXX ?= g++
LD = $(CXX)
RM = rm -rf

srcdir = .
resdir = res
tmpdir = tmp
debugdir = tmp/debug
bindir = bin

CXXFLAGS = -std=c++17 -I$(srcdir) -I$(resdir) $(shell fltk-config --use-images --cxxflags)
LDFLAGS = $(shell fltk-config --use-images --ldflags) $(shell pkg-config --libs libpng xpm)

RELEASEFLAGS = -DNDEBUG -O3 -flto -march=native
DEBUGFLAGS = -DDEBUG -D_DEBUG -O0 -g -ggdb3 -Wall -Wextra -pedantic -Wno-unknown-pragmas -Wno-sign-compare -Wno-unused-parameter

COMMON = $(wildcard $(srcdir)/*.h) $(wildcard $(resdir)/*.xpm)
SOURCES = $(wildcard $(srcdir)/*.cpp)
OBJECTS = $(SOURCES:$(srcdir)/%.cpp=$(tmpdir)/%.o)
DEBUGOBJECTS = $(SOURCES:$(srcdir)/%.cpp=$(debugdir)/%.o)
TARGET = $(bindir)/$(pcb_fltk)
DEBUGTARGET = $(bindir)/$(pcb_fltkd)
DESKTOP = "$(DESTDIR)$(PREFIX)/share/applications/pcb_fltk.desktop"

.PHONY: all $(pcb_fltk) $(pcb_fltkd) release debug clean install uninstall

.SUFFIXES: .o .cpp

all: $(pcb_fltk)

$(pcb_fltk): release
$(pcb_fltkd): debug

release: CXXFLAGS += $(RELEASEFLAGS)
release: $(TARGET)

debug: CXXFLAGS += $(DEBUGFLAGS)
debug: $(DEBUGTARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(LD) -o $@ $^ $(LDFLAGS)

$(DEBUGTARGET): $(DEBUGOBJECTS)
	@mkdir -p $(@D)
	$(LD) -o $@ $^ $(LDFLAGS)

$(tmpdir)/%.o: $(srcdir)/%.cpp $(COMMON)
	@mkdir -p $(@D)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(debugdir)/%.o: $(srcdir)/%.cpp $(COMMON)
	@mkdir -p $(@D)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	$(RM) $(TARGET) $(DEBUGTARGET) $(OBJECTS) $(DEBUGOBJECTS)

install: release
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(pcb_fltk)
	mkdir -p $(DESTDIR)$(PREFIX)/share/pixmaps
	cp $(resdir)/app.xpm $(DESTDIR)$(PREFIX)/share/pixmaps/pcb_fltk48.xpm
	cp $(resdir)/app-icon.xpm $(DESTDIR)$(PREFIX)/share/pixmaps/pcb_fltk16.xpm
	mkdir -p $(DESTDIR)$(PREFIX)/share/applications
	echo "[Desktop Entry]" > $(DESKTOP)
	echo "Name=pcb_fltk" >> $(DESKTOP)
	echo "Comment=Interactive layout editor" >> $(DESKTOP)
	echo "Icon=$(PREFIX)/share/pixmaps/pcb_fltk48.xpm" >> $(DESKTOP)
	echo "Exec=$(PREFIX)/bin/$(pcb_fltk)" >> $(DESKTOP)
	echo "Type=Application" >> $(DESKTOP)
	echo "Terminal=false" >> $(DESKTOP)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(pcb_fltk)
	rm -f $(DESTDIR)$(PREFIX)/share/pixmaps/pcb_fltk48.xpm
	rm -f $(DESTDIR)$(PREFIX)/share/pixmaps/pcb_fltk16.xpm
	rm -f $(DESKTOP)
