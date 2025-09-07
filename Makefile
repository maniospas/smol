CXX := g++
CXXFLAGS := -std=c++23 -Wall -m64
TARGET := smol

SRC := $(shell find src -type f -name '*.cpp')
OBJ := $(patsubst src/%.cpp, build/%.o, $(SRC))

# Default is release
all: release

release: CXXFLAGS += -O3
release: $(TARGET)

debug: CXXFLAGS += -g -O0 -rdynamic -DDEBUG -fsanitize=address,undefined
debug: LDFLAGS += -fsanitize=address,undefined -rdynamic
debug: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

# Compile .cpp -> .o into build/ (mirror src/ hierarchy)
build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET)

# Always use parallel jobs
MAKEFLAGS += -j$(shell nproc)
