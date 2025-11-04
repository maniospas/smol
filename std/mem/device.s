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

@include std.core.num
@include std.core.err
@unsafe
@about 
"Standard library implementation of memory management that accounts for the "
"stack and heap and depends on the runtime.h implementation of heap memory, "
"and GCC implementation of alloca. Stack allocations cannot be returned from "
"services, as the stack is pruned when programming function calls end. "
"Def-based functions are inlined within services, so it is fine to return "
"stack allocations from them."

@about Stack
"Represents call stack memory. Allocating on this is near-zero cost by being "
"just an arithmetic addition. But its total size is limited - typically up to "
"a few megabytes. Prefer this for small localized data that need to be processed "
"exceedingly fast. Arena allocators are a close second in terms in performance."

@about Heap
"Random access memory (RAM) that can be allocated with __runtime_alloc. Writing "
"to it and reading from it can be slow for programs that keep. Modern processors "
"optimize heap usage by prefetching and caching nearby areas as the ones you "
"access. For this reason, prefer creating Arena regions when you have a sense of "
"the exact amount of data you will need. Allocating on the heap can leak memory "
"under certain conditions, but the language's safety mechanism prevents this. Use "
"other allocators in those cases. The standard library provides a Dynamic type "
"that also accesses several heap allocations, though with an additional level of "
"indirection. "

@about MemoryDevice
"Refers to either stack or heap memory."

@about allocate
"Allocates memory on a predetermined device given a number of entries. Other "
"standard library overloads implement allocation for more memory types, derived from "
"the devices. Allocations throughout the standard library track the raw allocated "
"memory so that usage is finally released only when the last dependent variable "
"(e.g., the last string allocated on a heap arena) is no longer used. See "
"ContiguousMemory."

@about ContiguousMemory 
"Represents allocated memory management. It keeps track of both currently used pointer "
"addresses, for example if these are offsets of allocated base pointers with finally "
"segments calling __runtime_free on those, and the underlying pointer addresses. "
"Importantly, not all this information is retained after compilation, as most of it "
"-perhaps all- is optimized away. But this structure still helps the compiler organize "
"where to place memory releases, if needed. Users of the standard library will not "
"generally work with this type, as it is highly unsafe to get its pointer fields and "
"requires annotation for the language to allow that."

def Stack(nominal)
    return @args 

def Heap(nominal)
    return @args

union MemoryDevice = Stack or Heap

def MB(u64 value)
    return 1048576*value

def KB(u64 value)
    return 1024*value

def ContiguousMemory (
    nominal type,
    u64 size,
    ptr mem,
    ptr underlying
)
    //@noassign
    @buffer mem size underlying
    return @args

def allocate(@access Heap, u64 size)
    if size==0 
        fail("Cannot allocate zero size")
    @head{#include <stdlib.h>}
    @body{ptr mem=__runtime_alloc(size);}
    if mem.bool().not() 
        fail("Failed a Heap allocation")
    @finally mem {
        if(mem)
            __runtime_free(mem);
        mem=0;
    }
    return nominal.ContiguousMemory(size, mem, mem)

def allocate(@access Stack, u64 size)
    @head{#include <stdlib.h>}
    @body{
        u64 size_bytes = size; // also serves as a position pointer to check stack size (use >= to create error for zero size too)
        ptr mem=(size_bytes+__service_stack_floor>=(char*)&size_bytes)?0:alloca(size_bytes);
    }
    if mem.bool().not() 
        fail("Insufficient stack for allocation (too much recursion or stack allocation, or zero size requested)")
    @noshare mem
    return nominal.ContiguousMemory(size, mem, mem)

def __device_file_end() // TODO: find why imports fail without this
