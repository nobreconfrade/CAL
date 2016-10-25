# C++ compiler
CXX = g++
# compiler flags:
CXXFLAGS  = -std=c++11 -Wall
RM = rm -f
COMMON_SRCS = bigint/bigint.cpp rsa/keys.cpp
OBJS = $(subst .cpp, .o, $(SRCS))


# all: encrypt

encrypt: $(OBJS)
	$(CXX) mainEncrypt.cpp $(COMMON_SRCS) $(CXXFLAGS) -o encrypt.out

decrypt: $(OBJS)
	$(CXX) mainDecrypt.cpp $(COMMON_SRCS) $(CXXFLAGS) -o decrypt.out

genkeys: $(OBJS)
		$(CXX) mainGenerateKeys.cpp $(COMMON_SRCS) $(CXXFLAGS) -o generate_keys.out
