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
@install std.rayget

@unsafe
@about "Raylib wrapper for smoλ providing window, input and drawing primitives."

smo Color(u64 r, u64 g, u64 b, u64 a)
    if r>255 
        -> fail("Color r greater than 255")
    if g>255 
        -> fail("Color g greater than 255")
    if b>255 
        -> fail("Color b greater than 255")
    if a>255 
        -> fail("Color a greater than 255")
    -> @args

smo Position(f64 x, f64 y)
    -> @args

smo Size(f64 w, f64 h)
    -> @args

smo Window(nominal, Size size, cstr title)
    @nozero // always require an instantiated window
    @noother "std.ray.Window" // exactly one window per program
    @noborrow
    @head{#include "raylib.h"}
    @link{-Istd/raylib/raylib-5.5_linux_amd64/include}
    @link{-Lstd/raylib/raylib-5.5_linux_amd64/lib}
    @link{-lraylib}
    @link{-lm}
    @link{-ldl}
    @link{-lpthread}
    @link{-lGL}
    @link{-lX11}
    @body{ SetTraceLogLevel(LOG_WARNING); InitWindow(size__w, size__h, (char*)title); }
    -> @args

smo close(@mut Window window)
    --

smo is_open(@mut Window)
    @body{ bool ret = WindowShouldClose(); }
    -> ret:not

smo begin(@mut Window window)
    @body{ BeginDrawing(); }
    -> window

smo end(@mut Window window)
    @body{ EndDrawing(); }
    -> window

smo clear(@mut Window window, Color color)
    @body{ ClearBackground((Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a}); }
    -> window

smo text(@mut Window window, CString _txt, Position pos, f64 size, Color color)
    txt = _txt:nstr
    @body{
        DrawText(
            (char*)txt__contents, 
            pos__x, 
            pos__y, 
            size, 
            (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a}
        ); 
    }
    -> window

smo Color(u64 r, u64 g, u64 b)
    -> Color(r, g, b, 255)

smo Texture(nominal, u64 id, u64 width, u64 height, ptr mipmaps, ptr format)
    -> @args

smo open(Texture, CString _path)
    path = _path:nstr
    @head{#define __smolambda_ray_texture(id,width,height,mipmaps,format) {Texture2D ret = LoadTexture((char*)path__contents);id=ret.id;width=ret.width;height=ret.height;mipmaps=ret.mimpas;format=ret.format;}}
    @body{
        u64 id = 0;
        u64 width = 0;
        u64 height = 0;
        ptr mipmaps = 0;
        ptr format = 0;
        __smolambda_ray_texture(id,width,heigh,mipmaps,format);
    }
    @finally mipmaps {UnloadTexture((Texture2D){id, width, height, mipmaps, format});}
    -> nominal:Texture(id, width, height, mipmaps, format)

smo draw(@mut Window window, Texture tex, Position pos, Color color)
    @body{ 
        DrawTexture(
            (Texture2D){tex__id, tex__width, tex__height, tex__mipmaps, tex__format},
            pos__x, pos__y,
            (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a}
        ); 
    }
    -> window

smo circ(@mut Window window, Position pos, f64 radius, Color color)
    @body{
        DrawCircleV(
            (Vector2){(float)pos__x, (float)pos__y}, 
            (float)radius,
            (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a});
    }
    -> window

smo rect(@mut Window window, Position pos, Size size, Color color)
    @body{
        DrawRectangle(
            pos__x, pos__y,
            size__w, size__h,
            (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a}
        );
    }
    -> window

smo rect_line(@mut Window window, Position pos, Size size, u64 thickness, Color color)
    @body{DrawRectangleLinesEx((Rectangle){(float)pos__x, (float)pos__y, (float)size__w, (float)size__h}, (int)thickness, (Color){(unsigned char)color__r,(unsigned char)color__g,(unsigned char)color__b,(unsigned char)color__a});}
    -> window

smo circ_line(@mut Window window, Position pos, u64 radius, u64 thickness, Color color)
    @body{
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
    -> window
