# C++ compiler
CXX = g++
# compiler flags:
CXXFLAGS  = -std=c++11 -Wall
RM = rm -f
COMMON_SRCS = bigint/bigint.cpp
OBJS = $(subst .cpp, .o, $(SRCS))


# all: encrypt

encrypt: $(OBJS)
	$(CXX) mainEncrypt.cpp $(COMMON_SRCS) $(CXXFLAGS) -o encrypt.out $(OBJS)

decrypt: $(OBJS)
	$(CXX) mainDecrypt.cpp $(COMMON_SRCS) $(CXXFLAGS) -o decrypt.out $(OBJS)

genkeys: $(OBJS)
		$(CXX) mainGenerateKeys.cpp $(COMMON_SRCS) $(CXXFLAGS) -o generate_keys.out $(OBJS)
