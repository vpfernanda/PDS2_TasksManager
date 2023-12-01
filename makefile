CXX := g++
CXXFLAGS := -std=c++17 -Wall -fPIC

INCLUDE := -I include/
DOCTEST += -I test/
SRC_DIR := src
TEST_DIR := test

BIN_DIR := bin
BUILD_DIR := build

SRC_FILES := $(wildcard $(SRC_DIR)/*/*.cpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp $(TEST_DIR)/*/*.cpp)

DEP_FILES := $(SRC_FILES:.cpp=.d)
DEP_FILES += $(TEST_FILES:.cpp=.d)

OBJ_SRC_FILES := $(SRC_FILES:.cpp=.o)
OBJ_TEST_FILES := $(OBJ_SRC_FILES)
OBJ_TEST_FILES += $(TEST_FILES:.cpp=.o)

-include $(addprefix $(BUILD_DIR)/,$(DEP_FILES))

build: $(BUILD_DIR)/taskmanager.so

$(BUILD_DIR)/taskmanager.so: $(addprefix $(BUILD_DIR)/,$(OBJ_SRC_FILES))
	@echo "🔧 Preparing library ..."
	@mkdir -p $(BUILD_DIR)
	@$(CXX) -shared $^ -o $(BUILD_DIR)/taskmanager.so

test: $(BIN_DIR)/test
	@$(BIN_DIR)/test

$(BIN_DIR)/test: $(addprefix $(BUILD_DIR)/,$(OBJ_TEST_FILES))
	@echo "🔧 Preparing test suite ..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "🏛️ Building $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@
$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@echo "🏛️ Building $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@
clean:
	@echo "🧹 Cleaning ..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)