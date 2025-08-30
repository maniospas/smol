@include std.builtins
@include std.mem
@include std.vec

smo Point(f64 x, f64 y) -> @new

// smo Points(Memory &memory, u64 size)
//     x = memory:new_vector(size)
//     y = memory:new_vector(size)
//     -> x,y

smo Points(Memory &memory, u64 size)
    grid = memory:new_grid(size, 2, f64) // basically points contain subsequent regions
    x = grid[0]
    y = grid[1]
    -> x,y
smo at(Points &points, u64 state) -> Point(points.x[state], points.y[state])
smo iter(Point &points) &state = 0 -> points, state
smo len(Points points) if points.x:len<points.y:len |->points.x:len -> points.y:len
smo put(Points &points, u64 state, Point p) 
    points.x:put(state, p.x)
    points.y:put(state, p.y)
    --
smo next(Points &points, u64 &state, Point& ret)
    ret = points[state]
    state = state+1
    -> state>=points:len

service main()
    &points = Heap:Points(1000)
    range(10)
    :while next(u64& i)
        points:put(i, Point(i:f64, i:f64))
        --
    p = points[5]
    @release points
    print(p.x)
    --
    