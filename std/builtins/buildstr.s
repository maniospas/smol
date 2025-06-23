@include std.builtins.num
@include std.builtins.err
@include std.builtins.str
@include std.mem -> allocate, memory

smo buildstr(nom type, u64 size)
    contents = nom:allocate(memory.heap, size, char)
    length = 0
    first = 0:char
    -> type, contents, length
smo buildstr(u64 size) -> nom:buildstr(size)
smo len(buildstr self) -> self.length
smo push(buildstr& self, str other)
    if self.contents.size <= self.length + other.length -> fail("String builder ran out of space")
    if self.length==0 first = other.first --
    @body{std::memcpy((char*)self__contents__mem+self__length, (char*)other__contents, sizeof(char)*other__length);}
    @body{self__length = self__length + other__length;}
    --
smo push(buildstr& self, Number other) -> self:push(other:str)
smo push(buildstr& self, cstr other) -> self:push(other:str)
smo str(buildstr& self) -> nom:str(self.contents.mem, self.length, self.first, self.contents.mem)

smo read(buildstr& self)
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
            }
            self__length = self__length+length;
        }
        else {_contents = 0;}
    }
    if _contents:exists:not -> fail("Did not have enough memory to read on buildstr")
    --