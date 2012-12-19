# snapperd - simple OS X daemon with configuration plist file

Usage:

    make
    sudo make install
    sudo make register

To disable daemon:

    sudo make unregister

snapperd uses [imagesnap](http://iharder.sourceforge.net/current/macosx/imagesnap/) to capture images from camera, it should be in your PATH.

Resulting images are placed in /usr/local/snapper/snap_*.png.