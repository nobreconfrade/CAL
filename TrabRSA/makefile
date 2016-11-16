## References
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# http://www.gnu.org/software/make/manual/make.html
# http://stackoverflow.com/questions/2908057/can-i-compile-all-cpp-files-in-src-to-os-in-obj-then-link-to-binary-in#2908351
##

# C++ compiler
CXX = g++
# Compiler and dynamic link flags:
CXXFLAGS  = -g -std=c++11 -Wall -MMD
LDFLAGS   = -lgmpxx -lgmp
# Directories
OBJDIR = obj

# Files
CPP_FILES := $(wildcard rsa/*.cpp)
OBJ_FILES := $(addprefix $(OBJDIR)/, $(notdir $(CPP_FILES:.cpp=.o)))
RM = -rm -f

# This prints out variables OBJ_FILES and CPP_FILES
all: generate_keys.out encrypt.out decrypt.out bruteforce.out

print:
	$(info $$OBJ_FILES is [$(OBJ_FILES)])
	$(info $$CPP_FILES is [${CPP_FILES}])

# Object recipe for .cpp in root folder
$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

# Object recipe for .cpp inside the RSA folder
$(OBJDIR)/%.o: rsa/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

generate_keys.out: $(OBJDIR)/mainGenerateKeys.o $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

encrypt.out: $(OBJDIR)/mainEncrypt.o $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

decrypt.out: $(OBJDIR)/mainDecrypt.o $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

bruteforce.out: $(OBJDIR)/mainBruteforce.o $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


clean:
	$(RM) *.out
	$(RM) *.o
	$(RM) $(OBJDIR)/*.o
	$(RM) *.d
	$(RM) $(OBJDIR)/*.d
	$(RM) *.gch
	$(RM) rsa/*.gch
	$(RM) *.pub
	$(RM) *.pri
