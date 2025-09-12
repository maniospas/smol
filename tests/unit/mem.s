@include std.builtins
@include std.mem

service main() 
   @mut arena = Heap:arena(1024)
   s = arena:copy("MYSTRING":str)
   print(s)
    --