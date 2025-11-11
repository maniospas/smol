// // Written in 2025 by Emmanouil Krasanakis (maniospas@hotmail.com)
// //
// // To the extent possible under law, the author has dedicated all copyright
// // and related and neighboring rights to this software to the public domain
// // worldwide.
// // 
// // Permission to use, copy, modify, and/or distribute this software for any
// // purpose with or without fee is hereby granted.
// // 
// // THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// // WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// // MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// // ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// // WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// // ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
// // IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. 

// @include std.core
// @include std.mem
// @unsafe
// @about "Standard library implementation of maps that requires unsafe entry casts to u64."
// @about put "Inserts an element to a Map."
// @about has "Checks if an element key exists in a Map."
// @about put "Computes hash values for several primitive and string types to be used by maps."
// @about len "Tracks the number of elements stored in each Map. Elements cannot be removed but can be replaced. Several variations exist for different map variations. "
// @about len "Tracks the number of elements stored in each Map. Elements cannot be removed but can be replaced. Several variations exist for different map variations. "
// @about at  "Gets an element from a Map given that it is the same type as its key. This overloads the bracket operator. Will cause service failure if the element is missing; check for its existence first. "
//            "\n<br><br>Here is example usage that obtains a key's value:"
//            "\n<pre>map = Dynamic:Map(100, str, str)  // str to str map on dynamic memory with 100 max size"
//            "\nmap:put(\"hello\", \"world\")"
//            "\nprint(map[\"hello\"])</pre>"
// @about Map "Constructs a map data type given a memory allocator, a maximum number of map elements that can be stored on it, and the types of keys and values. "
//            "The maximum number of elements cannot be increased and is reserved as space beforehand for security. Str is used as a storage type for both all String values. "
//            "Memory is reserved beforehand for the map's entries so that implementation is performant and can conform to any allocator. For string keys or values, "
//            "the base allocator is also used to reserve space later for string copying to maintain lifetimes. Element insertion may fail if the map or base memory is out of space. "
//            "<br><br>Here is an example of a string-based map, where known constant string (cstr) elements are placed by hand "
//            "to prevent any additional memory allocation for them."
//            "\n<pre>map = Stack:arena(32):Map(10, 1, u64) // do everything in 32 bytes with up to 10 entries"
//            "\n@on map // open context to add the map as first argument when needed"
//            "\n1:put(\"entry 1\")"
//            "\n2:put(\"entry 2\")"
//            "\n3:put(\"entry 3\")"
//            "\nprint(map[3])"
//            "\n</pre>"
// @about List "Constructs a list given a memory allocator, a maximum capacity, and the type of its elements."

// union Keys
//     str
//     u64
//     --

// union Values
//     str
//     u64
//     f64
//     i64
//     --

// def __unsafe_cast(str, str value) return value
// def __unsafe_cast(str, cstr value) return value
// def __unsafe_cast(str, ptr value) 
//     @head{#include <string.h>}
//     @body{
//         cstr temp_cast = 0;
//         memcpy(&temp_cast, &value, sizeof(temp_cast));
//     } return temp_cast

// def __unsafe_cast(str, u64 value) 
//     @head{#include <string.h>}
//     @body{
//         cstr temp_cast = 0;
//         memcpy(&temp_cast, &value, sizeof(temp_cast));
//     } return temp_cast

// def __unsafe_cast(u64, cstr value) 
//     @head{#include <string.h>}
//     @body{
//         u64 temp_cast = 0;
//         memcpy(&temp_cast, &value, sizeof(temp_cast));
//     } return temp_cast

// def __unsafe_cast(u64, ptr value) 
//     @head{#include <string.h>}
//     @body{
//         u64 temp_cast = 0;
//         memcpy(&temp_cast, &value, sizeof(temp_cast));
//     } return temp_cast

// def __unsafe_cast(u64, u64 value) return value
// def __unsafe_cast(u64, i64 value) @body{u64 temp_cast = static_cast<u64>(value);} return temp_cast
// def __unsafe_cast(u64, f64 value) @body{u64 temp_cast = static_cast<u64>(value);} return temp_cast
// def __unsafe_ret(u64, u64 value, ptr context) return value
// def __unsafe_ret(f64, u64 value, ptr context) @body{f64 temp_cast = static_cast<f64>(value);} return temp_cast
// def __unsafe_ret(i64, u64 value, ptr context) @body{i64 temp_cast = static_cast<i64>(value);} return temp_cast
// def __unsafe_ret(str, u64 value, ptr context) 
//     @head{#include <string.h>}
//     @body{cstr raw = (cstr)(value);} 
//     @body{
//         u64 length=strlen(raw);
//         ptr contents=(ptr)raw;
//         char first=raw[0];
//     }
//     return nominal:str(contents, length, first, context)

// def __map_prepare_key(nstr value, @mut Memorymemory) 
//     with memory:is(Heap) fail("Error: Cannot directly allocate `Heap` memory for map strings, use anything else (a heap Arena, Dynamic, Stack)") 
//     --else--
//     //if value.memory:exists:not |return value.contents  // cstr wrappers
//     mem = memory:allocate(value.length+1, char)
//     @body{
//         if(mem__mem) {
//             memcpy((char*)mem__mem, value__contents, value__length);
//             ((char*)mem__mem)[value__length] = '\0';
//         }
//     }
//     return mem.mem
// def __map_prepare_key(cstr value, @mut Memorymemory) return value
// def __map_prepare_key(f64 value, @mut Memorymemory) return value
// def __map_prepare_key(i64 value, @mut Memorymemory) return value
// def __map_prepare_key(u64 value, @mut Memorymemory) return value+1
// def __map_prepare_key(str value) return value
// def __map_prepare_key(cstr value) return value
// def __map_prepare_key(f64 value) return value
// def __map_prepare_key(i64 value) return value
// def __map_prepare_key(u64 value) return value+1
// def __map_prepare_value(nstr value, @mut Memorymemory)
//     //if value.memory:exists:not |return value.contents  // cstr wrappers
//     mem = memory:allocate(value.length+1, char)
//     @body{
//         if(mem__mem) {
//             memcpy((char*)mem__mem, (char*)value__contents, value__length);
//             ((char*)mem__mem)[value__length] = '\0';
//         }
//     }
//     return mem.mem
// def __map_prepare_value(cstr value, @mut Memorymemory) return value
// def __map_prepare_value(f64 value, @mut Memorymemory) return value
// def __map_prepare_value(i64 value, @mut Memorymemory) return value
// def __map_prepare_value(u64 value, @mut Memorymemory) return value

// def hash(String _s)
//     // djb2
//     s = _s:str
//     u64 &hash = 5381
//     range(s:len):while next(u64& i) 
//         @body{hash = ((hash << 5) + hash)+(unsigned char)((char*)s__contents)[i];}
//     --return hash

// def hash(u64 _x)
//     // xorshift64
//     &x = _x
//     @body {
//         x ^= x >> 12;
//         x ^= x << 25;
//         x ^= x >> 27;
//     }
//     return x

// // class Map
// def Map(
//         nominal type, 
//         @mut Memorymemory, 
//         u64 size,
//         Keys,
//         Values
//     )
//     mem = memory:allocate(size*2, u64)
//     range(size*2):while next(u64& i) 
//         mem:__unsafe_put(i, 0)
//         --
//     length = 0
//     return type, size, mem, length, memory

// def map(@mut Memorymemory, u64 size, Keys, Values) 
//     return nominal:Map(memory, size, Keys, Values)

// def len(Map &self) 
//     return self.length

// def has(Map &self, Keys _key)
//     with 
//         _key:is(self.Keys) 
//         --
//     key = _key:__map_prepare_key
//     &idx = (_key:hash % self.size)*2
//     on self.Keys
//         while(self.mem[idx]!=0)and((self.mem[idx]:__unsafe_cast)!=(key:__unsafe_cast))
//             idx = idx + 2 
//             if idx>=self.mem.size 
//                 |||return false
//     ----return self.mem[idx] != 0

// def put(Map &self, Keys _key, Values _val)
//     with 
//         _key:is(self.Keys)
//         _val:is(self.Values)
//         --
//     key = _key:__map_prepare_key
//     &idx = (_key:hash % self.size)*2
//     on self.Keys
//         while(self.mem[idx]!=0)and((self.mem[idx]:__unsafe_cast)!=(key:__unsafe_cast)) 
//             idx = idx + 2 
//             if idx>=self.mem.size 
//                 return fail("Error: Map out of space")
//         ----
//     if self.mem[idx] == 0 
//         @body{self__length = self__length+1;} 
//         on u64 
//             self.mem:__unsafe_put(idx, _key:__map_prepare_key(self.memory):__unsafe_cast) // copy strings only if no entry there
//         ----
//     on u64 
//         self.mem:__unsafe_put(idx+1, _val:__map_prepare_value(self.memory):__unsafe_cast)
//     ---- // TODO: find why, if we return self here, we get a double free error (regardless of whether it's mutable)

// def at(Map self, Keys _key)
//     with 
//         _key:is(self.Keys) 
//         --
//     key = _key:__map_prepare_key
//     &idx = (_key:hash % self.size)*2
//     on self.Keys
//         while(self.mem[idx]!=0)and((self.mem[idx]:__unsafe_cast)!=(key:__unsafe_cast))
//             idx = idx + 2
//             if idx>=self.mem.size 
//                 return fail("Error: Map has no such entry")
//         ----
//     if self.mem[idx] == 0 
//         return fail("Error: Map has no such entry")
//     return on self.Values return self.mem:at(idx+1):__unsafe_ret(self.mem.underlying)

// def put(Map &self, CString _mkey, Values _val) 
//     with 
//         put(self, _mkey:str, _val) 
//     ----
// def put(Map &self, CString _mkey, CString _mval) 
//     with 
//         put(self, _mkey:str, _mval:str) 
//     ----
// def put(Map &self, Keys _key, CString _mval) 
//     with 
//         put(self, _key, _mval:str) 
//     ----
// def at(Map self, CString _mkey) 
//     with 
//         ret = at(self, _mkey:str)  
//     --return ret


// // def List(nominal, @mut Memorymemory, u64 capacity, Values)
// //     mem = memory:allocate(capacity, u64)
// //     //range(capacity):while next(u64& i) mem:__unsafe_put(i, 0)
// //     length = 0
// //     --return capacity, mem, length, memory, Values

// // def List(@mut Memorymemory, u64 capacity, Values)
// //     return nominal:List(memory, capacity, Values)

// // def len(List self) return self.length

// // def push(List &self, Values value)
// //     if self.length >= self.capacity return fail("List out of space")
// //     on u64 
// //         self.mem:__unsafe_put(self.length, value:__map_prepare_value(self.memory):__unsafe_cast)
// //         @body{self__length = self__length + 1;}
// //     --return self

// // def push(List &self, cstr value)
// //    return self:push(value:str)

// // def at(List self, u64 index)
// //     if index >= self.length return fail("Index out of bounds")
// //     return on self.Values return self.mem:at(index):__unsafe_ret(self.mem.underlying)

// // def set(List &self, u64 index, Values value)
// //     with value:is(self.Values) --
// //     if index >= self.length return fail("Index out of bounds")
// //     on u64 
// //         self.mem:__unsafe_put(index, value:__map_prepare_value(self.memory):__unsafe_cast)
// //     ----

// // def iter(List self) 
// //     &pos = 0
// //     return self, pos

// // def next(List self, u64 &pos, Values &value)
// //     with Values:is(List.Values) 
// //         if pos >= self.length |return false
// //         value = self[pos]
// //         pos = pos+1
// //     --return true
