PROJECT=generic
CONFIGURATION=Debug
EMBUILD=emBuild
CEEDLING=ceedling
TARGET_PATH=Output/$(CONFIGURATION)/Exe
TARGET=$(TARGET_PATH)/$(PROJECT).hex
REQUIREMENTS=$(EMBUILD).req $(CEEDLING).req
SOURCE=src/*

all: $(REQUIREMENTS) $(TARGET)

$(TARGET): $(SOURCE)
	$(EMBUILD) $(PROJECT).emProject -config $(CONFIGURATION)

test:
	@ceedling test

%.req:
	@which $* >/dev/null || echo "Please ensure $* is in the path"

.PHONY: test
.SUFFIXES: req
