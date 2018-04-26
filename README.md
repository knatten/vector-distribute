(This isn't acutally used anywhere, it just came up in a discussion, so I wanted to implement it.)

Function to distribute the contents of a vector equally into a given number of other vectors.

The number of elements does not have to be a multiple of the desired number of vectors. In this case the resulting vectors aren't of equal length, the first one(s) will have an extra element.

Examples:

- distributing `[1,2,3,4]` into two vectors results in `[[1,2][3,4]]`.
- distributing `[1,2,3,4,5]` into two vectors results in `[[1,2,3][4,5]]`.

The implementation is in a single header file [distribute.h](distribute.h).

Test that demonstrate usage are found in [tests.cpp](tests.cpp).

Tests are written in [Catch 2](https://github.com/catchorg/Catch).

## License
MIT, see [LICENSE.txt](LICENSE.txt)
