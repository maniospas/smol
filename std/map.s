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

smo __unsafe_cstr(ptr contents)
    @body{cstr temp_cast = reinterpret_cast<cstr>(contents);}
    -> temp_cast
smo __unsafe_cstr(u64 contents)
    @body{cstr temp_cast = reinterpret_cast<cstr>(contents);}
    -> temp_cast
smo __unsafe_u64(ptr contents)
    @body{u64 temp_cast = reinterpret_cast<u64>(contents);}
    -> temp_cast

smo hash(String _s)
    // djb2
    s = _s:str
    u64 &hash = 5381
    range(s:len):while next(u64& i) 
        @body{hash = ((hash << 5) + hash)+(unsigned char)((char*)s__contents)[i];}
    ---> hash

smo Map(nom, Memory &memory, u64 size, cstr key_type, cstr value_type) 
    mem = memory:allocate(size*2, u64)
    range(size*2):while next(u64& i) mem:put(i, 0)
    ---> @new, mem
smo Map(Memory &memory, u64 size, cstr, cstr) -> nom:Map(memory, size, cstr, cstr)

smo put(Map &map, cstr _key, cstr _val)
    key = _key:str
    val = _val:str
    &idx = (key:hash % map.size)*2
    while(map.mem[idx]!=0)and((map.mem[idx]:__unsafe_cstr)!=(key.contents:__unsafe_cstr)) 
        idx = idx + 2 
        if idx>=map.mem.size -> fail("Map out of space")
        --
    map.mem:put(idx, key.contents:__unsafe_u64)
    map.mem:put(idx+1, val.contents:__unsafe_u64)
    -- // TODO: find why, if we return map here, we get a double free error (regardless of whether it's mutable)

smo del(Map &map, cstr _key)
    key = _key:str
    &idx = (key:hash % map.size)*2
    while(map.mem[idx]!=0)and((map.mem[idx]:__unsafe_cstr)!=(key.contents:__unsafe_cstr))
        idx = idx + 2 
        if idx>=map.mem.size -> fail("Map has no such entry")
        --
    map.mem:put(idx, 0)
    map.mem:put(idx+1, 0)
    --


smo at(Map map, cstr _key)
    key = _key:str
    &idx = (key:hash % map.size)*2
    while(map.mem[idx]!=0)and((map.mem[idx]:__unsafe_cstr)!=(key.contents:__unsafe_cstr))
        idx = idx + 2 
        if idx>=map.mem.size -> fail("Map has no such entry")
        --
    if map.mem[idx] == 0 -> fail("Map has no such entry")
    -> map.mem:at(idx+1):__unsafe_cstr:str
    --