@include std.core
@include std.mem

union Hashable = String or Number

def hash(str k, u64 size)
    @mut h = 5381
    k.len().range()
    .while next(@mut u64 i)
        h = h.lshift(5).add(h) + k[i].u64()
    return h.mod(size)

def hash(u64 k, u64 size)
    @mut x = k
    x = x.xor(x.rshift(33))
    x = x.mul(0xff51afd7ed558ccd)
    x = x.xor(x.rshift(33))
    x = x.mul(0xc4ceb9fe1a85ec53)
    x = x.xor(x.rshift(33))
    return x.mod(size)

def to_hash_base(String k)
    return k.str()

def to_hash_base(u64 k)
    return k

def to_hash_base(i64 k)
    return k.u64()

def to_hash_base(f64 k)
    return k.bits()

def StringHash(nominal, u64 size)
    @mut entries = str[].expect(size)
    return @args, entries

def NumberHash(nominal, u64 size)
    @mut entries = u64[].expect(size)
    return @args, entries

def to_hash_base(StringHash)
    return str("")

def to_hash_base(NumberHash)
    return u64(0)

union Hash = StringHash or NumberHash

def is_zero(str k)
    return k.len().bool().not()
    
def is_zero(u64 k)
    return k==0

def contains(@access @mut Hash self, Hashable _k, @mut u64 idx)
    k = _k.to_hash_base()
    case k.is(Hash.to_hash_base()) qed
    if k.is_zero()
        return true
    pos = hash(k, self.size)
    range(0, self.size)
    .while next(@mut u64 i)
        idx = (pos+i).mod(self.size)
        if idx.bool() and self.entries[idx].is_zero().not() and self.entries[idx]==k 
            return true
    return false

def at(@access @mut Hash self, String _k)
    k = _k.to_hash_base()
    case k.is(Hash.to_hash_base()) qed
    if k.is_zero()
        return 0
    idx = hash(k, self.size)
    range(0, self.size)
    .while next(@mut u64 i)
        i = (i+idx).mod(self.size)
        if i.bool() and self.entries[i].is_zero()
            self.entries[i] = k
        if self.entries[i]==k
            return i
    fail("Cannot add more hash elements")
