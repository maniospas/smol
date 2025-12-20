@include std.core
@include std.mem

def Hash(nominal type, str, u64 size)
    @mut entries = str[].expect(size)
    return type, entries, size

def hash(str k, u64 size)
    @mut h = 5381
    k.len().range()
    .while next(@mut u64 i)
        h = h.lshift(5).add(h) + k[i].u64()
    return h.mod(size)

def contains(@access @mut Hash self, String _k, @mut u64 idx)
    k = _k.str()
    if k.len().bool().not()
        idx = 0
        return true
    pos = hash(k, self.size)
    range(0, self.size)
    .while next(@mut u64 i)
        idx = (pos+i).mod(self.size)
        if idx.bool() and self.entries[idx].len().bool() and self.entries[idx]==k 
            return true
    return false

def at(@access @mut Hash self, String _k)
    k = _k.str()
    if k.len().bool().not()
        return 0
    idx = hash(k, self.size)
    range(0, self.size)
    .while next(@mut u64 i)
        i = (i+idx).mod(self.size)
        if i.bool() and self.entries[i].len()==0
            self.entries[i] = k
        if self.entries[i]==k
            return i
    fail("Cannot add more hash elements")

service main()
    @mut keys = Hash(nominal, str, 100)
    @mut values = u64[].expect(keys.size)
    
    @on Heap.dynamic()
    values.put(keys["a".copy()], 1)
    values.put(keys["b"], 2)
    values.put(keys[""], 3)

    if keys.contains("a", @mut u64 pos)
        print(values[pos])
    