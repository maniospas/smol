// Written in 2025 by Emmanouil Krasanakis (maniospas@hotmail.com)
//
// To the extent possible under law, the author has dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide.
// 
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
// 
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 
//
// Raylib is free and unencumbered software released into the public domain.
// See <http://unlicense.org/> for more details.

@include std.core.num
@include std.core.str
@include std.core.err
@include std.mem
//@install std.ray

@unsafe

@about
"Raylib wrapper for smoλ providing window, input and drawing primitives."

@about open
"Opens a raylib Window"

@about is_open
"Checks if a raylib Window is open"

@about Color   
"Ensure that a tuple of four u64 RGBA values form an existing color by being "
"in the range 0..255. An RGB variation with three inputs creates a non-opaque "
"color (with 255 alpha)."

@about Position
"Packs a 2D position of f64 coordinates"

@about Size
"Packs a 2D size of f64 dimensions"
@about text
"Draw at given position a String of given size and color"
@about draw
"Draws a texture at specific coordinates and size"
@about begin
"Begin drawing a new scene instance - must be followed by an end"
@about end
"End drawing of a new scene instance"
@about clear
"Clears the window's contents with given color"
@about circ
"Draws at given position a circle of given f64 radius"
@about rect
"Draws at given position a rectangle of given size"
@about circ_line 
"Draws at given position a circle's outline for given f64 radius and thickness"
@about rect_line 
"Draws at given position a rectangle's outline for a given size and f64 thickness"

def Color(u64 r, u64 g, u64 b, u64 a)
    if r>255 
        fail("Color r greater than 255")
    if g>255 
        fail("Color g greater than 255")
    if b>255 
        fail("Color b greater than 255")
    if a>255 
        fail("Color a greater than 255")
    return @args

def Position(f64 x, f64 y)
    return @args

def Size(f64 w, f64 h)
    return @args

def Window(new, Size size, cstr title)
    @unique "std.ray.Window" // exactly one window per program
    @c_nozero // always require an instantiated window
    @c_noborrow
    @c_head{#include "raylib.h"}
    @c_link{-Istd/raylib/raylib-5.5_linux_amd64/include}
    @c_link{-Lstd/raylib/raylib-5.5_linux_amd64/lib}
    @c_link{-lraylib}
    @c_link{-ldl}
    @c_link{-lpthread}
    @c_link{-lGL}
    @c_link{-lX11}
    @c_body{SetTraceLogLevel(LOG_WARNING); InitWindow(size__w, size__h, (char*)title); }
    @mut ready = bool
    return @args, ready

def is_open(@mut Window)
    @c_body{ bool ret = WindowShouldClose(); }
    return ret.not()

def draw(@access @mut Window window)
    if window.ready
        fail("Window.begin() already called without closing it with Window.end()")
    is_drawing = true
    @c_body{ BeginDrawing(); }
    @c_finally is_drawing { EndDrawing(); }
    return is_drawing

def clear(@mut Window window, Color color)
    @c_body{ ClearBackground((Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a}); }
    return window

def text(@mut Window window, CString _txt, Position pos, f64 size, Color color)
    txt = _txt.nstr()
    @c_body{
        DrawText(
            (char*)txt__contents, 
            pos__x, 
            pos__y, 
            size, 
            (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a}
        ); 
    }
    return window

def Color(u64 r, u64 g, u64 b)
    return Color(r, g, b, 255)

def Texture(new, u64 id, u64 width, u64 height, ptr mipmaps, ptr format)
    return @args

def open(Texture, CString _path)
    path = _path.nstr()
    @c_head{#define __smolambda_ray_texture(id,width,height,mipmaps,format) {Texture2D ret = LoadTexture((char*)path__contents);id=ret.id;width=ret.width;height=ret.height;mipmaps=ret.mimpas;format=ret.format;}}
    @c_body{
        u64 id = 0;
        u64 width = 0;
        u64 height = 0;
        ptr mipmaps = 0;
        ptr format = 0;
        __smolambda_ray_texture(id,width,heigh,mipmaps,format);
    }
    @c_finally mipmaps {UnloadTexture((Texture2D){id, width, height, mipmaps, format});}
    return new.Texture(id, width, height, mipmaps, format)

def draw(@mut Window window, Texture tex, Position pos, Color color)
    @c_body{ 
        DrawTexture(
            (Texture2D){tex__id, tex__width, tex__height, tex__mipmaps, tex__format},
            pos__x, pos__y,
            (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a}
        ); 
    }
    return window

def circ(@mut Window window, Position pos, f64 radius, Color color)
    @c_body{
        DrawCircleV(
            (Vector2){(float)pos__x, (float)pos__y}, 
            (float)radius,
            (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a}
        );
    }
    return window

def rect(@mut Window window, Position pos, Size size, Color color)
    @c_body{
        DrawRectangle(
            pos__x, pos__y,
            size__w, size__h,
            (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a}
        );
    }
    return window

def rect_line(@mut Window window, Position pos, Size size, u64 thickness, Color color)
    @c_body{DrawRectangleLinesEx((Rectangle){(float)pos__x, (float)pos__y, (float)size__w, (float)size__h}, (int)thickness, (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a});}
    return window

def circ_line(@mut Window window, Position pos, u64 radius, u64 thickness, Color color)
    @c_body{
        f64 inner = (radius > thickness) ? (float)(radius - thickness) : 0.0f;
        f64 outer = (float)radius;
        DrawRing(
            (Vector2){(float)pos__x, 
            (float)pos__y}, 
            inner, 
            outer, 
            0, 
            360, 
            64, 
            (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a}
        );
    }
    return window
