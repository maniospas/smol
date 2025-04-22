// keywords: smo, dyn


smo print(i64 x)
    @head{#include <stdio.h>}
    @body{printf("%ld\n", x);}
    => true

smo add(num x, @any y)

smo add(i64 x, i64 y) @body{i64 z=x+y;} => z
smo sub(i64 x, i64 y) @body{i64 z=x-y;} => z
smo mul(i64 x, i64 y) @body{i64 z=x*y;} => z
smo div(i64 x, i64 y) @body{i64 z=x/y;} => z

smo alloc(i64 size) @body{i64 z = (i64)(char*)malloc(size);} => z

smo Point(@safe, i64 x, i64 y) => @new
smo Field(@safe, Point start, Point end) => @new


env foo()  // envs can run on any green thread, can only have stream inputs and outputs (List by synchronized, they attempt to read but go into sleep if they encounter invalid)
    @handler{}
    Point p1(@safe, 1,2)
    Point p2(@safe, 3,4)
    List mem(@safe) // pushes and pops by bytecasting, requires the @safe argument so it's impossible to crash because to read a List we need to first read a list type and then actually read it. pushing a list onto a list puts @safe, and the memory address. can only push lists to those that have been previously created (removes circular references)
    push(mem, p1)
    push(mem, p2)
    Point p1(mem)
    List mem2(@safe)
    push(mem, mem2)
    Heap mem3(mem)
    => true

env main() // being an env basically means a function, difference is that occurring errors are returned as
    foo result()




    Field f(@safe, 1, p1, 3, 2) // correct number of arguments, but will create an error thanks to structurally checking for @safe
    print(f.start.x)
    print(f.end.y)
    add i(f.start.x, f.start.y)
    print(i)


