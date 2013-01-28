# snapperd - simple OS X camera capturing daemon with configuration plist file

Usage:

    make
    sudo make install
    sudo make register

To disable daemon:

    sudo make unregister

snapperd uses [imagesnap](http://iharder.sourceforge.net/current/macosx/imagesnap/) to capture images from camera, it should be locaten in `/usr/local/bin/`.

After registering, snapperd will capture an image from your camera every five minutes. Resulting images are placed in `/usr/local/snapper/snap_*.png`.

snapperd comes with "makevideo" script, which can be used to make stop-motion video with ffmpeg utility.

You can give an access to last image snapperd made with [Snapper-Web](https://github.com/silvansky/snapper-web) PHP based utility.
