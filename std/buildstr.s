@include std.builtins
@include std.mem -> allocate, memory

smo buildstr(nom type, u64 size)
    contents = nom:allocate(memory.heap, size, char)
    &length = 0
    first = 0:char
    -> type, contents, length
smo push(buildstr& self, str other)
    if self.contents.size <= self.length + other.length -> fail("String builder ran out of space")
    if self.length==0 first = other.first --
    @body{std::memcpy((char*)self__contents__mem+self__length, (char*)other__contents, sizeof(char)*other__length);}
    self.length = self.length + other.length
    --
smo push(buildstr& self, Number other) -> self:push(other:str)
smo push(buildstr& self, cstr other) -> self:push(other:str)
smo str(buildstr self) -> nom:str(self.contents.mem, self.length, self.first)