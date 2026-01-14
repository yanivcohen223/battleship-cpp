#WROTE BY YANIV COHEN && ROEE BURD
# ----------------------------
# Battleship - Makefile
# ----------------------------

CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g
LDFLAGS  :=

TARGET    := battleship
BUILD_DIR := build

# Source directories
SRC_DIRS := . Players Ships

# All cpp files
SRCS := $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.cpp))
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Include paths
INCLUDES := $(addprefix -I,$(SRC_DIRS))
CXXFLAGS += $(INCLUDES) -MMD -MP

.PHONY: all clean run dirs

all: $(TARGET)

# Link executable
$(TARGET): dirs $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Create build directories
dirs:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/Players
	@mkdir -p $(BUILD_DIR)/Ships

# Compile source files
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	@rm -rf $(BUILD_DIR) $(TARGET)

-include $(DEPS)