# Ulam-spiral-generator
Generate Ulam spirals in C

This utility can generate [Ulam spirals](https://en.wikipedia.org/wiki/Ulam_spiral) of
a given size and saving them as a PPM image.

![Ulam spiral](https://upload.wikimedia.org/wikipedia/commons/6/69/Ulam_1.png)

### Building

```
make
```

### Running

```
./ulam SIZE OUTFILE
./ulam 199 img.ppm
```

SIZE should be an odd positive integer.

