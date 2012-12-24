#!/bin/bash

ffmpeg -r 12 -y -i "snap_%010d.png" output.m4v
