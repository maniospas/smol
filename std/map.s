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

@include std.builtins
@include std.mem

union Keys(str,u64)
union Values(str,u64,f64,i64)

smo __unsafe_cast(str, cstr value) -> value
smo __unsafe_cast(str, ptr value) @body{cstr temp_cast = reinterpret_cast<cstr>(value);} -> temp_cast
smo __unsafe_cast(str, u64 value) @body{cstr temp_cast = reinterpret_cast<cstr>(value);} -> temp_cast
smo __unsafe_cast(u64, cstr value) @body{u64 temp_cast = reinterpret_cast<u64>(value);} -> temp_cast
smo __unsafe_cast(u64, ptr value) @body{u64 temp_cast = reinterpret_cast<u64>(value);} -> temp_cast
smo __unsafe_cast(u64, u64 value) -> value
smo __unsafe_cast(u64, i64 value) @body{u64 temp_cast = static_cast<u64>(value);} -> temp_cast
smo __unsafe_cast(u64, f64 value) @body{u64 temp_cast = static_cast<u64>(value);} -> temp_cast
smo __unsafe_ret(u64, u64 value) -> value
smo __unsafe_ret(f64, u64 value) @body{f64 temp_cast = static_cast<f64>(value);} -> temp_cast
smo __unsafe_ret(i64, u64 value) @body{i64 temp_cast = static_cast<i64>(value);} -> temp_cast
smo __unsafe_ret(str, u64 value) 
    @head{#include <string.h>}
    @body{cstr raw = reinterpret_cast<cstr>(value);} 
    @body{
        u64 length=strlen(raw);
        ptr contents=(ptr)raw;
        char first=raw[0];
    }
    -> nom:str(contents, length, first, contents)

smo __map_prepare_key(str value, ptr memory) 
    if(value.memory:bool)and(value.memory!=memory) -> fail("String key is not allocated on the same common memory region as map")
    -> value.contents
smo __map_prepare_key(cstr value, ptr memory) -> value
smo __map_prepare_key(f64 value, ptr memory) -> value
smo __map_prepare_key(i64 value, ptr memory) -> value
smo __map_prepare_key(u64 value, ptr memory) -> value

smo __map_prepare_key(str value) -> value.contents
smo __map_prepare_key(cstr value) -> value
smo __map_prepare_key(f64 value) -> value
smo __map_prepare_key(i64 value) -> value
smo __map_prepare_key(u64 value) -> value

smo __map_prepare_value(str value, ptr memory) 
    if(value.memory:bool)and(value.memory!=memory) -> fail("String key is not allocated on the same common memory region as map")
    -> value.contents
smo __map_prepare_value(cstr value, ptr memory) -> value
smo __map_prepare_value(f64 value, ptr memory) -> value
smo __map_prepare_value(i64 value, ptr memory) -> value
smo __map_prepare_value(u64 value, ptr memory) -> value

smo hash(String _s)
    // djb2
    s = _s:str
    u64 &hash = 5381
    range(s:len):while next(u64& i) 
        @body{hash = ((hash << 5) + hash)+(unsigned char)((char*)s__contents)[i];}
    ---> hash

smo hash(u64 _x)
    // xorshift64
    &x = _x
    @body {
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
    }
    -> x

// class Map
smo Map(nom type, Memory &memory, u64 size, Keys, Values) 
    mem = memory:allocate(size*2, u64)
    range(size*2):while next(u64& i) mem:put(i, 0)
    length = 0
    ---> type, size, mem, length, memory
smo Map(Memory &memory, u64 size, Keys, Values) 
    -> nom:Map(memory, size, Keys, Values)
smo len(Map self) 
    -> self.length
smo has(Map self, Keys _key)
    with 
        _key:is(self.Keys) 
        --
    key = _key:__map_prepare_key
    &idx = (_key:hash % self.size)*2
    on self.Keys
        while(self.mem[idx]!=0)and((self.mem[idx]:__unsafe_cast)!=(key:__unsafe_cast))
            idx = idx + 2 
            if idx>=self.mem.size |||-> false
    -----> self.mem[idx] != 0
smo put(Map &self, Keys _key, Values _val)
    with 
        _key:is(self.Keys)
        _val:is(self.Values)
        --
    key = _key:__map_prepare_key(self.mem.underlying)
    val = _val:__map_prepare_value(self.mem.underlying)
    &idx = (_key:hash % self.size)*2
    on self.Keys
        while(self.mem[idx]!=0)and((self.mem[idx]:__unsafe_cast)!=(key:__unsafe_cast)) 
            idx = idx + 2 
            if idx>=self.mem.size -> fail("Map out of space")
        ----
    if self.mem[idx] == 0 
        @body{self__length = self__length+1;} 
        --
    on u64 
        self.mem:put(idx, key:__unsafe_cast)
        self.mem:put(idx+1, val:__unsafe_cast)
    ---- // TODO: find why, if we return self here, we get a double free error (regardless of whether it's mutable)
smo at(Map self, Keys _key)
    with _key:is(self.Keys) --
    key = _key:__map_prepare_key
    &idx = (_key:hash % self.size)*2
    on self.Keys
        while(self.mem[idx]!=0)and((self.mem[idx]:__unsafe_cast)!=(key:__unsafe_cast))
            idx = idx + 2
            if idx>=self.mem.size 
                -> fail("Map has no such entry")
        ----
    if self.mem[idx] == 0 
        -> fail("Map has no such entry")
    -> on self.Values -> self.mem:at(idx+1):__unsafe_ret

smo put(Map &self, cstr _mkey, Values _val) 
    with put(self, _mkey:str, _val) 
    ----
smo put(Map &self, cstr _mkey, cstr _mval) 
    with put(self, _mkey:str, _mval:str) 
    ----
smo put(Map &self, Keys _key, cstr _mval) 
    with put(self, _key, _mval:str) 
    ----
smo at(Map self, cstr _mkey) 
    with ret = at(self, _mkey:str) 
    ---> ret