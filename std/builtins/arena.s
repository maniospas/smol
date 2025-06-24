// DEPRECATED 
smo push(arena& self, str other)
    if self.contents.size <= self.length + other.length -> fail("String builder ran out of space")
    if self.length==0 first = other.first --
    @body{std::memcpy((char*)self__contents__mem+self__length, (char*)other__contents, sizeof(char)*other__length);}
    @body{self__length = self__length + other__length;}
    --
smo push(arena& self, Number other) -> self:push(other:str)
smo push(arena& self, cstr other) -> self:push(other:str)   
