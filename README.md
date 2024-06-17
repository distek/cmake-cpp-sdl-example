# Cmake MACOS (or any unix-like OS?) SDL example

Because there wasn't enough!

## Why

I just wanted to draw a fucking box on the screen.

This is the culmination of 4 hours of poking at build errors, missing libraries, and _intense_ searching.

## Usage

Have the following installed:

- `cmake` (from [kitware directly](https://cmake.org/download/) if on macos)
- `vcpkg` (I had to git clone from Microsoft's repo directly and add that path as `$VCPKG_ROOT`)
- `ninja`

Then just:

```
./init.sh
cd build
ninja
./something
```

Many wow. Such box.

## Credits

The `main.cpp` code was lifted from sjr here:
https://discourse.libsdl.org/t/sdl-2-26-not-rendering-on-macos/40842/6
