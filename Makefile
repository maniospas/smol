CXX := g++
CXXFLAGS := -O3 -std=c++23 -Wall -m64
TARGET := smol

SRC := $(shell find src -type f -name '*.cpp')
OBJ := $(patsubst src/%.cpp, build/%.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp -> .o into build/ (mirror src/ hierarchy)
build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET)

# Always use parallel jobs
MAKEFLAGS += -j$(shell nproc)
