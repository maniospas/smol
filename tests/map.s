@include std.builtins
@include std.map

service main() 
    &map = Heap:Map(100,cstr,cstr)
    map:put("123", "456")
    map:put("123", "456")
    print(map:at("123"))
    --