@include std.builtins
@include std.mem

service main() 
   &arena = Heap:allocate_arena(1024)
   s = arena:copy("MYSTRING":str)
   print(s)
    --