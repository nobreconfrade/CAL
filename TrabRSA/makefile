## References
# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# http://www.gnu.org/software/make/manual/make.html
# http://stackoverflow.com/questions/2908057/can-i-compile-all-cpp-files-in-src-to-os-in-obj-then-link-to-binary-in#2908351
##

# C++ compiler
CXX = g++
# compiler flags:
CXXFLAGS  = -std=c++11 -Wall -MMD
LDFLAGS   = -lgmpxx -lgmp
# Directories
OBJDIR = obj

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

## OLD STUFF | Ignore me, please ##
# encrypt: $(OBJS)
# 	$(CXX) mainEncrypt.cpp $(CPP_FILES) $(CXXFLAGS) -o encrypt.out
#
# decrypt: $(OBJS)
# 	$(CXX) mainDecrypt.cpp $(CPP_FILES) $(CXXFLAGS) -o decrypt.out
#
# genkeys: $(OBJ_FILES)
# 	$(CXX) mainGenerateKeys.cpp $(CPP_FILES) $(CXXFLAGS) -o generate_keys.out
##

clean:
	$(RM) *.out
	$(RM) *.o
	$(RM) obj/*.o
	$(RM) *.d
	$(RM) obj/*.d
	$(RM) *.gch
	$(RM) rsa/*.gch
