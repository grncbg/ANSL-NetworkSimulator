COMPILER = g++
CFLAGS   = -g -Wall -O2 -MMD -MP -std=c++1z
LDFLAGS  =
LIBS     =
INCLUDE  = -Iinclude
BINDIR   = bin
TARGET   = main
OBJDIR   = obj
SRCDIR   = source
SOURCES  = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS  = $(subst $(SRCDIR),$(OBJDIR), $(SOURCES:.cpp=.o))
DEPENDS  = $(OBJECTS:.o=.d)

.PHONY: $(TARGET)
$(TARGET): $(BINDIR)/$(TARGET);
$(BINDIR)/$(TARGET): $(OBJECTS) $(LIBS)
	mkdir -p bin
	$(COMPILER) -o $@ $^ $(LDFLAGS)

.PHONY: %.o
%.o: $(OBJDIR)/%.o;
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p obj
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

.PHONY: all
all: clean $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/* $(BINDIR)/*

-include $(DEPENDS)