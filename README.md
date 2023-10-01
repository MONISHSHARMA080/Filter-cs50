# Filter-cs50
# Image Filtering Program
This repository contains a program that applies various filters to BMP images. The program is designed to read an input BMP image, apply the selected filter, and save the modified image as a new BMP file.

## Problem Statement
The original problem for this program can be found on [CS50 Problem Set 4 - Filter](https://cs50.harvard.edu/x/2023/psets/4/filter/less/).

## Technical Details
Headers
A BMP file contains metadata at the beginning, stored as two headers: BITMAPFILEHEADER and BITMAPINFOHEADER. These headers store information such as image dimensions, color depth, and more.

### Image Representation
Pixels in a BMP image are stored as triples of bytes, representing the color in the order of blue, green, and red (BGR format). The image is represented as a 2D array of pixels, where each row is an array of pixels.

### Available Filters
This program offers several filters for image manipulation:

### Grayscale
The grayscale filter converts an image to black-and-white by averaging the red, green, and blue values for each pixel and setting them to the same value.

### Sepia
The sepia filter gives an image an old-timey appearance with reddish-brown tones. It calculates new red, green, and blue values based on the original values .

### Reflection
The reflection filter mirrors the original image horizontally. Pixels on the left side of the image end up on the right side and vice versa, while all original pixels remain in the reflected image.

### Box Blur
The box blur filter softens the image by averaging the color values of neighboring pixels. For each pixel, it calculates the new color values by averaging the values of the surrounding pixels in a 3x3 box.


## Usage
```
$ ./filter -f reflection input.bmp reflected.bmp
```

