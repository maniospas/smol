@include std.core
@include std.mem


@about is_zero 
"Check that an str is non-empty or a u64 is non-zero"

@about Hashable
"A string or number"

@about hash
"Converts and str or u64 to a u64 hash code."

@about to_hash_base
"Converts any String or Number to corresponding str or u64 for which is_zero and hash are called."

@about StringHash
"A container that converts String instances to integer indexes of a given range."

@about NumberHash
"A container that converts any Number to integer indexes of a given range."

@about Hash
"A union between StringHash and NumberHash"

@about find
"Searches for corresponding contents in a Hash and returns whether they exist or "
"not. The search also admits a mutable number that stores the found position. "
"If the entry is not found, the index remain unchanged. "
"Empty strings and zero numbers are always present at the 0 index. Example:"
"<pre>@include std.core"
"\n@include std.map"
"\n"
"\ndef my_map()"
"\n    @mut keys = new.StringHash(100)"
"\n    @mut values = u64[].expect(keys.size)"
"\n    @on Heap.dynamic()"
"\n    values.put(keys[\"a\".copy()], 1)"
"\n    values.put(keys[\"b\"], 2)"
"\n    values.put(keys[\"\"], 3)"
"\n    return keys, values"
"\n"
"\nservice main()"
"\n    @access map = my_map()"
"\n    if map.keys.find(\"a\".str(), @mut u64 pos)"
"\n        print(map.values[pos])</pre>"

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

def StringHash(new, u64 size)
    @mut entries = str[].expect(size)
    return @args, entries

def NumberHash(new, u64 size)
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

def find(@access @mut Hash self, Hashable _k, @mut u64 idx)
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
