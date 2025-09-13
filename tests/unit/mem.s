@include std.builtins
@include std.mem -> Heap

service main()
   @mut memory = Heap:arena(1024)
   s = memory:copy("MYSTRING":str)
   print(s)
    --