# Based on Makefile found here: https://www.norwegiancreations.com/2018/08/makefiles-part-3-test-lint-deploy/

.PHONY: deploy test clean
 
LIB_DIR=.
TEST_DIR=test
CPP_FLAGS=-std=c++11 -Wall
 
INCLUDES=\
	-I$(LIB_DIR)\
	-I$(TEST_DIR)
 
SRCS=\
	$(TEST_DIR)/tests-main.cpp\
	*.cpp

TEST_SRCS=\
	$(TEST_DIR)/tests-main.cpp\
	grid.cpp\
	update.cpp
 
OBJS=$(SRCS:.cpp=.o)

TEST_OBJS=$(TEST_SRCS:.cpp=.o)

test: $(TEST_OBJS)
	g++ $(CPP_FLAGS) $(INCLUDES) -o $(TEST_DIR)/run_test $(TEST_OBJS) $(TEST_SRC)
	$(TEST_DIR)/run_test
 
%.o : %.cpp
	g++ $(CPP_FLAGS) $(INCLUDES) -c $< -o $@
 
clean:
	rm $(OBJS)
	# -f option means this command will pass whether there exists a file there or not
	rm -f $(TEST_DIR)/run_test