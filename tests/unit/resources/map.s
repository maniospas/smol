@include std.core
@include std.map

def run()
    @mut keys = nominal.StringHash(100)
    @mut values = u64[].expect(keys.size)
    @on Heap.dynamic()
    values.put(keys["a".copy()], 1)
    values.put(keys["b"], 2)
    values.put(keys[""], 3)
    return keys, values

service main()
    @access map = run()
    if map.keys.contains("a".str(), @mut u64 pos)
        print(map.values[pos])
    