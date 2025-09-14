@include std.core
@include std.mem
@include std.vec

smo Point(f64 x, f64 y) -> @args

// smo Points(@mut Memorymemory, u64 size)
//     x = memory:vector(size)
//     y = memory:vector(size)
//     -> x,y

smo Points(@mut Memory memory, u64 size)
    grid = memory:grid(size, 2, f64) // basically points contain subsequent regions
    x = grid[0]
    y = grid[1]
    -> x,y

smo at(@mut Points points, u64 state) 
    -> Point(points.x[state], points.y[state])

smo iter(@mut Point points) 
    @mut state = 0 
    -> points, state

smo len(Points points) 
    if points.x:len<points.y:len 
        |->points.x:len 
    -> points.y:len

smo put(@mut Points points, u64 state, Point p) 
    points.x:put(state, p.x)
    points.y:put(state, p.y)
    --

smo next(@mut Points points, @mut u64 state, @mut Point ret)
    ret = points[state]
    state = state+1
    -> state>=points:len

service main()
    @mut points = Heap:Points(1000)
    range(10)
    :while next(u64& i)
        points:put(i, Point(i:f64, i:f64))
        --
    p = points[5]
    @release points
    print(p.x)
    --
    