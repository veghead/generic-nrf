SDK=nRF5_SDK
SDK_VER=nRF5_SDK_17.0.2_d674dde
PROJECTS=rakpoc

all: $(SDK) $(PROJECTS)

$(SDK):
	@echo "Unpack or symlink $(SDK_VER) here as $(SDK)" 

rakpoc:
	cd rakpoc && make
