CXX = g++
CXXFLAGS = -Wall -pthread
LDFLAGS =

MKDIR = mkdir 

EXEC= affectation
EXT = .cpp

SRCDIR = src
BUILDDIR= out/build
BINDIR= out/bin

SRC = $(wildcard $(SRCDIR)/*$(EXT)) 
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)


all: $(EXEC) run


$(EXEC): $(OBJ)
	@$(MKDIR) -p $(BINDIR)
	@$(CXX) $(CXXFLAGS) -o $(BINDIR)/$@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%$(EXT)
	@$(MKDIR) -p $(BUILDDIR)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)

mrproper: clean
	rm -rf $(BINDIR)

build: $(EXEC)

run: $(EXEC)
	@./$(BINDIR)/$(EXEC)
