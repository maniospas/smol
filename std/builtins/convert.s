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

@include std.builtins.num
@include std.builtins.str
@unsafe
@about "Standard library wrapping and simplification of C console commands."
@about read "Reads several string and primitive types from console text input given by the user; they need to press enter after entering the input. String reading is restricted to 1024 bytes allocated on the heap. You can have more control of string reading on alternatives. Non-string variations of this method are restricted to local variables. Invalid inputs create service failures."

smo read(i64)
    @acquire "std.terminal.read"
    @head{#include <stdio.h>}
    @body{
        i64 number = 0;
        char ch = 0;
        i64 result = scanf("%ld%c", &number, &ch);
        bool success = (result == 2 && (ch == 13 || ch == 10));
    }
    if success:not 
        @fail{printf("Error: invalid integer read\n");} 
    ---> number

smo read(u64)
    @acquire "std.terminal.read"
    @head{#include <stdio.h>}
    @body{
        u64 number = 0;
        char ch = 0;
        bool success = false;
        char first = getchar();
        if(first != "-"[0] && first != EOF) {
            ungetc(first, stdin);
            i64 result = scanf("%lu%c", &number, &ch);
            success = (result == 2 && (ch == 13 || ch == 10));
        }
    }
    if success:not 
        @fail{printf("Error: invalid unsigned integer read\n");} 
    ---> number

smo read(f64)
    @acquire "std.terminal.read"
    @head{#include <stdio.h>}
    @body{
        f64 number = 0;
        char ch = 0;
        i64 result = scanf("%lf%c", &number, &ch);
        bool success = (result == 2 && (ch == 13 || ch == 10));
    }
    if success:not 
        @fail{printf("Error: invalid number read\n");} 
    ---> number

smo convert(i64, String _s)
    s = _s:str
    @body{
        i64 number = 0;
        bool success = true;
        bool negative = false;
        if (s__length == 0) success = false;
        else {
            u64 i = 0;
            char *chars = (char*)s__contents;
            if (chars[0] == '-') {
                negative = true;
                i++;
                if (i == s__length) success = false;
            } else if (chars[0] == '+') {
                i++;
                if (i == s__length) success = false;
            }
            for (; i < s__length && success; i++) {
                char c = chars[i];
                if (c >= '0' && c <= '9') {
                    number = number * 10 + (c - '0');
                } else {
                    success = false;
                }
            }
            if (negative) 
                number = -number;
        }
    }
    if success:not 
        @fail{printf("Error: invalid integer conversion from string\n");} 
    ---> number


smo convert(u64, String _s)
    s = _s:str
    @body{
        u64 number = 0;
        bool success = true;

        if (s__length == 0) 
            success = false;
        else {
            char *chars = (char*)s__contents;
            for (u64 i = 0; i < s__length && success; i++) {
                char c = chars[i];
                if (c >= '0' && c <= '9') {
                    number = number * 10 + (c - '0');
                } 
                else {
                    success = false;
                }
            }
        }
    }
    if success:not 
        @fail{printf("Error: invalid unsigned integer conversion from string\n");} 
    ---> number


smo convert(f64, String _s)
    s = _s:str
    @body{
        f64 number = 0.0;
        bool success = true;
        bool negative = false;

        if(s__length == 0) 
            success = false;
        else {
            char *chars = (char*)s__contents;
            u64 i = 0;
            if (chars[0] == '-') {
                negative = true;
                i++;
                if(i == s__length) success = false;
            } else if (chars[0] == '+') {
                i++;
                if(i == s__length) success = false;
            }
            for (; i < s__length && success; i++) {
                char c = chars[i];
                if(c >= '0' && c <= '9') {number = number * 10.0 + (c - '0');} 
                else if(c == '.') {i++;break;} 
                else {success = false; }
            }
            if (success && i < s__length) {
                f64 frac = 0.0;
                f64 base = 0.1;
                for (; i < s__length && success; i++) {
                    char c = chars[i];
                    if (c >= '0' && c <= '9') {
                        frac += (c - '0') * base;
                        base *= 0.1;
                    } else if (c == 'e' || c == 'E') {
                        i++;
                        break;
                    } else { success = false; }
                }
                number += frac;
            }
            if(success && i < s__length) {
                bool expNeg = false;
                if(chars[i] == '-') {expNeg = true; i++;} 
                else if(chars[i] == '+') {i++;}
                if(i == s__length) success = false;
                i64 expVal = 0;
                for (; i < s__length && success; i++) {
                    char c = chars[i];
                    if(c >= '0' && c <= '9') {expVal = expVal * 10 + (c - '0');} 
                    else { success = false; }
                }
                if(expNeg) expVal = -expVal;
                number *= pow(10.0, expVal);
            }
            if(negative) number = -number;
        }
    }
    if success:not 
        @fail{printf("Error: invalid floating-point conversion from string\n");} 
    ---> number
