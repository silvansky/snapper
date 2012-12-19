# snapperd - simple OS X daemon with configuration plist file

Usage:

    make
    sudo make install
    sudo make register

To disable daemon:

    sudo make unregister

snapperd uses [imagesnap](http://iharder.sourceforge.net/current/macosx/imagesnap/) to capture images from camera, it should be in your PATH.

After registering, snapperd will capture an image from your camera every five minutes. Resulting images are placed in `/usr/local/snapper/snap_*.png`.