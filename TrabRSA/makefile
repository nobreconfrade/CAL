## References
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# http://www.gnu.org/software/make/manual/make.html
# http://stackoverflow.com/questions/2908057/can-i-compile-all-cpp-files-in-src-to-os-in-obj-then-link-to-binary-in#2908351
##

# C++ compiler
CXX = g++
# Compiler and dynamic link flags:
CXXFLAGS  = -std=c++11 -Wall -MMD
LDFLAGS   = -lgmpxx -lgmp
# Directories
OBJDIR = obj

# Files
CPP_FILES := $(wildcard rsa/*.cpp)
OBJ_FILES := $(addprefix $(OBJDIR)/, $(notdir $(CPP_FILES:.cpp=.o)))
RM = -rm -f

# This prints out variables OBJ_FILES and CPP_FILES
all:
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

clean:
	$(RM) *.out
	$(RM) *.o
	$(RM) obj/*.o
	$(RM) *.d
	$(RM) obj/*.d
	$(RM) *.gch
	$(RM) rsa/*.gch
