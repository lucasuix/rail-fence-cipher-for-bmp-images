# rail-fence-cipher-for-bmp-images
Using an algorithm that doesn't require a matrix is possible to quickly apply the rail fence cipher to each byte of an image.

*Note: This application supports only .bmp images*

## Usage

**After compiling the railfencer.c file do the following:**

1. Move the .bmp image to the same folder as the compiled program.
2. Make sure the image is named to 'imagem.bmp'
3. Run `./railfencer`
4. Type the desired number of lines, which is the 'key' for the encryption, and hit enter.

*If you don't know what 'number of lines' means here as a key, check out about the rail fence cipher first!*

**The resulting image will be a .bmp file called "result.bmp"**

## Discussing results

To check results before running the application, here's a video showing the weird effects of this cipher in an image:

* https://www.youtube.com/watch?v=Sj_tgX1YuBE


Regardless of the "encryption" part not really being effective, the algorithm reveals an interisting fractal behavior, which may be useful in some other context.

Currently working on another version that applies the cipher in the binary level of the image.
