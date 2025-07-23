// Written in 2018 by David Blackman and Sebastiano Vigna (vigna@acm.org)
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
// IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. */
// 
// Edited in 2025 by Emmanouil Krasanakis (maniospas@hotmail.com) 
// to include in smoλ's standard library:
// - converted to smoλ implementation
// - added seed function
// The same license is applied to changes.

@unsafe
@about "Standard library porting Xoshiro256plusInitializer random numbers from https://prng.di.unimi.it/. These and are NOT cryptographically secure."
@about Rand "This a structural type for storing the progress of random number generators on four u64 state fields. "
            "It can be initialized with an optional seed, which defaults to a time-based initialization if not provided. "
            "For safety against sharing random implementations between services or repeatedly initializating them, state "
            "variables are marked as a leaking resource. The whole data type as a whole is marked as @noborrow. "
            "These safety mechanisms are not mandatory but help safeguard speed by preventing common mistakes, such as directly re-initializing Rand "
            "in each loop to get a next number."

smo __rotl(u64 x, u64 k)
    @body{u64 z = (x << k) | (x >> (64 - k));}
    -> z

smo __splitmix64(u64& x)
    @body {
        u64 z = (x += 0x9E3779B97F4A7C15ULL);
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
        z = z ^ (z >> 31);
    }
    -> z

smo Rand(u64 seed)
    &modifying_seed = seed
    &s0 = __splitmix64(modifying_seed)
    &s1 = __splitmix64(modifying_seed)
    &s2 = __splitmix64(modifying_seed)
    &s3 = __splitmix64(modifying_seed)
    @finally s0 {}
    @finally s1 {}
    @finally s2 {}
    @finally s3 {}
    -> s0,s1,s2,s3

smo Rand() 
    @head{#include <time.h>}
    @head{#include <stdlib.h>}
    @body {
        ptr ts = (struct timespec *)alloca(sizeof(struct timespec));
        clock_gettime(CLOCK_REALTIME, (struct timespec*)ts);
        u64 seed = (u64)((struct timespec*)ts)->tv_sec * (u64)1000000000 + ((struct timespec*)ts)->tv_nsec;
    }
    -> Rand(seed)

smo next(Rand &self)
    @body{
        u64 result = self__s0 + self__s3;
        u64 t = self__s1 << 17;
        self__s2 ^= self__s0;
        self__s3 ^= self__s1;
        self__s1 ^= self__s2;
        self__s0 ^= self__s3;
        self__s2 ^= t;
    }
    self.s3 = __rotl(self.s3, 45)
    @body{f64 value = ((f64)(result >> 11)) / ((f64)((unsigned long long)(1) << 53));}
    -> value

