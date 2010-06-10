SHELL = /bin/sh
NAME ?= cugsim

srcdir = .

cppdir ?= $(srcdir)/src
hppdir ?= $(srcdir)/include
objdir ?= $(srcdir)/obj
outdir ?= $(srcdir)/bin


SRC := $(notdir $(wildcard $(cppdir)/*.cpp))
OBJ := $(SRC:cpp=o)

CPPFLAGS += -DUNIX -DLINUX

CXXFLAGS += -I$(hppdir)
CXXFLAGS += -Wall

DEBUGFLAGS = -g -D_DEBUG
RELEASEFLAGS = -DNDEBUG


default:
	$(info Choose a build: [ debug, release ])
	@exit 0


debug: $(outdir) $(objdir)/debug $(outdir)/$(NAME)-debug

%-debug : $(addprefix $(objdir)/debug/, $(OBJ))
	$(CXX) $(DEBUGFLAGS) $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

$(objdir)/debug/%.o : $(cppdir)/%.cpp $(wildcard $(hppdir)/*.hpp)
	@echo dep $(addprefix $(hppdir)/, $(shell cat $< | grep -o [^\"]*hpp))
	$(CXX) -c $(DEBUGFLAGS) $(CPPFLAGS) $(CXXFLAGS) -o $@ $<


all: release

release: $(outdir) $(objdir)/release $(outdir)/$(NAME)

%$(NAME) : $(addprefix $(objdir)/release/, $(OBJ))
	$(AR) $(ARFLAGS) $@ $^

$(objdir)/release/%.o : $(cppdir)/%.cpp
	$(CXX) -c $(RELEASEFLAGS) $(CPPFLAGS) $(CXXFLAGS) -o $@ $<


$(objdir)/debug : $(objdir)
	-mkdir $@

$(objdir)/release : $(objdir)
	-mkdir $@

$(objdir) :
	-mkdir $@

$(outdir) :
	-mkdir $@

.PRECIOUS : $(objdir)/debug/%.o $(objdir)/release/%.o

TAGS:
	ctags -VR --languages=C++ $(cppdir) $(hppdir)

clean:
	$(RM) -v $(outdir)/$(NAME) $(outdir)/$(NAME)-debug $(addprefix $(objdir)/debug/, $(OBJ)) $(addprefix $(objdir)/release/, $(OBJ))

.PONEY : default debug release clean TAGS

