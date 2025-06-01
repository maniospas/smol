@include std.builtins
@include std.file
@include std.mem

union Number(u64,i64,f64)

smo iterate(chunks iterator) 
    iterator:while next(str chunk) print(chunk) --
    --

service main()
    f = file("README.md")
    nom:chunks(f, 4096, heap):iterate
    --
