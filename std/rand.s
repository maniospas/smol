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

@unsafe
@about "Standard library wrapping of C++ Xoshiro256plusInitializer random numbers. These and are NOT cryptographically secure."

smo rand() 
    // https://prng.di.unimi.it/
    // the version used here is only suitable for floating point generation
    @head{#include "std/xoshiro256plus.cpp"}
    @head{#include <chrono>}
    @head{struct __Xoshiro256plusInitializer {__Xoshiro256plusInitializer(){xoshiro256plus::seed((uint64_t)std::chrono::high_resolution_clock::now().time_since_epoch().count());}}; __Xoshiro256plusInitializer __xoshiro256plusInitializer;}
    @body{f64 value = static_cast<f64>(xoshiro256plus::next() >> 11) / static_cast<f64>(static_cast<unsigned long long>(1) << 53);}
    -> value
