@include std.builtins.num
@include std.builtins.err
@include std.builtins.str
@include std.mem -> allocate, memory, Memory, Primitive

smo arena(nom type, Memory, u64 size)
    contents = nom:allocate(Memory, size, char)
    length = 0
    first = 0:char
    -> type, contents, length
smo arena(Memory, u64 size) -> nom:arena(Memory, size)
smo len(arena self) -> self.length
smo push(arena& self, str other)
    if self.contents.size <= self.length + other.length -> fail("String builder ran out of space")
    if self.length==0 first = other.first --
    @body{std::memcpy((char*)self__contents__mem+self__length, (char*)other__contents, sizeof(char)*other__length);}
    @body{self__length = self__length + other__length;}
    --
smo push(arena& self, Number other) -> self:push(other:str)
smo push(arena& self, cstr other) -> self:push(other:str)   

smo read(arena& self)
    @head{#include <stdio.h>}
    @head{#include <stdlib.h>}
    @body{
        ptr _contents = (ptr)((char*)self__contents__mem+self__length*sizeof(char));
        if(fgets((char*)_contents, self__contents__size-self__length, stdin)) {
            u64 length = strlen((char*)_contents);
            if(length > 0 && ((char*)_contents)[length - 1] == '\n') {
                length -= 1;
                ((char*)_contents)[length] = '\0';
                char first = ((char*)_contents)[0];
                self__length = self__length+length;
            }
            else if(length) {_contents = 0;}
        }
    }
    if _contents:exists:not -> fail("Tried to read more elements than arena size")
    -> nom:str(_contents, length, first, self__contents__mem)

smo str(arena& self) -> nom:str(self.contents.mem, self.length, self.first, self.contents.mem)