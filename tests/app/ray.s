@include std.builtins
@include std.file
@include std.os
@include std.ray
@include std.mem
@include std.time

smo Sphere(
        f64 x, 
        f64 y, 
        f64 r, 
        f64 dx, 
        f64 dy
    ) 
    -> @args

smo process(Sphere &s, f64 dt)
    &nx = s.x:add(s.dx * dt)
    &ny = s.y:add(s.dy * dt)
    &ndx = s.dx
    &ndy = s.dy
    if (nx - s.r)< 0.0 
        nx = s.r
        ndx = ndx:negative
        --
    elif (nx + s.r) > 800.0
        nx = 800.0 - s.r
        ndx = ndx:negative
        --
    if (ny - s.r) < 0.0
        ny = s.r
        ndy = ndy:negative
        --
    elif (ny + s.r) > 450.0
        ny = 450.0 - s.r
        ndy = ndy:negative
        --
    s = Sphere(nx, ny, s.r, ndx, ndy)
    --


smo draw(Sphere sphere, Window &window)
    window:circ(sphere.x, sphere.y, sphere.r, Color(200, 50, 50))
    --

// smo test()
//     s = Sphere[]:new(100.0, 100.0, 30.0, 1000.0, 650.0)
//     --

smo process(Sphere[] &spheres, f64 dt)
    range(spheres:len)
    :while next(u64& i)
        &s = spheres[i]
        s:process(dt)
        spheres:put(i, s)
    ----

service test()
    &spheres = Sphere[]
    :push(Sphere(100.0, 100.0, 30.0, 1000.0, 650.0))
    :push(Sphere(100.0, 100.0, 30.0, 450.0, 600.0))

    &dt = 0.0

    &window = nominal:Window:open(800.0, 450.0, "Hello from smoλ+raylib")
    &prev_t = time()
    &accum_fps = 3600.0
    on Heap:volatile(1024)
        while window:is_open
            spheres
            :process(dt)

            window
            :begin
            :clear(Color(50,50,80))

            range(spheres:len)
            :while next(u64 &i)
                spheres[i]:draw(window)
                --

            window
            :text((accum_fps/60.0):u64:str+" fps", Position(10.0, 10.0), 20.0, Color(255, 255, 255))
            :end
            
            // time computation
            t = time()
            dt = t-prev_t
            prev_t = t
            accum_fps = (0.0001/dt)+(accum_fps*0.9999)
            exact_sleep(0.015-dt)
            --
    ----

service main()
    test()
    print("running") // services are async, this will be printed
    --
