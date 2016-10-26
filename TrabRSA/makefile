# http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# http://www.gnu.org/software/make/manual/make.html

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

all:
	$(info $$OBJ_FILES is [$(OBJ_FILES)])
	$(info $$CPP_FILES is [${CPP_FILES}])


$(OBJDIR)/mainGenerateKeys.o: mainGenerateKeys.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

# Object recipes
$(OBJDIR)/%.o: rsa/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LDFLAGS)

generate_keys.out: $(OBJDIR)/mainGenerateKeys.o $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)



# encrypt: $(OBJS)
# 	$(CXX) mainEncrypt.cpp $(CPP_FILES) $(CXXFLAGS) -o encrypt.out
#
# decrypt: $(OBJS)
# 	$(CXX) mainDecrypt.cpp $(CPP_FILES) $(CXXFLAGS) -o decrypt.out
#
# genkeys: $(OBJ_FILES)
# 	$(CXX) mainGenerateKeys.cpp $(CPP_FILES) $(CXXFLAGS) -o generate_keys.out

clean:
	$(RM) *.out
	$(RM) *.o
	$(RM) obj/*.o
	$(RM) *.d
	$(RM) obj/*.d
	$(RM) *.gch
	$(RM) rsa/*.gch
