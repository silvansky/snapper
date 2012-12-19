CC=clang
TARGET=snapperd
OBJECTS=snapper.o
SOURCES=snapper.c

PLIST=snapper.plist
TARGET_INSTALL_PATH=/usr/local/bin/
PLIST_INSTALL_PATH=~/Library/LaunchAgents/

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES)

install:
	cp $(TARGET) $(TARGET_INSTALL_PATH)
	cp $(PLIST) $(PLIST_INSTALL_PATH)
	chown root $(PLIST_INSTALL_PATH)$(PLIST)
	chmod 644 $(PLIST_INSTALL_PATH)$(PLIST)

register:
	launchctl load $(PLIST_INSTALL_PATH)$(PLIST)

unregister:
	launchctl unload $(PLIST_INSTALL_PATH)$(PLIST)

clean:
	rm -rf snapperd snapper.o
