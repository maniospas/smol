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

# ---- Profile target ----
# Optimized build with debug symbols for perf/Flamegraph or gprof
profile: CXXFLAGS += -g -O3 -fno-omit-frame-pointer
# Uncomment the next line if you specifically want gprof:
# profile: CXXFLAGS += -pg
# profile: LDFLAGS  += -pg
profile: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET)

MAKEFLAGS += -j$(shell nproc)
