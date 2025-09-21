@include std.core
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
    return @args

smo process(@mut Sphere s, f64 dt)
    @mut nx = s.x:add(s.dx * dt)
    @mut ny = s.y:add(s.dy * dt)
    @mut ndx = s.dx
    @mut ndy = s.dy
    if (nx - s.r)< 0.0
        nx = s.r
        ndx = ndx:negative
    elif (nx + s.r) > 800.0
        nx = 800.0 - s.r
        ndx = ndx:negative
        noreturn
    if (ny - s.r) < 0.0
        ny = s.r
        ndy = ndy:negative
    elif (ny + s.r) > 450.0
        ny = 450.0 - s.r
        ndy = ndy:negative
        noreturn
    s = Sphere(nx, ny, s.r, ndx, ndy)

smo draw(Sphere sphere, @mut Window window)
    do window:circ(sphere.x, sphere.y, sphere.r, Color(200, 50, 50))
    
smo process(@mut Sphere[] spheres, f64 dt)
    range(spheres:len)
    :while next(@mut u64 i)
        do spheres[i]::process(dt)

service test()
    @mut spheres = Sphere[]
    :push(Sphere(100.0, 100.0, 30.0, 1000.0, 650.0))
    :push(Sphere(100.0, 100.0, 30.0, 450.0, 600.0))

    @mut dt = 0.0
    @mut window = nominal:Window(800.0, 450.0, "Hello from smoλ+raylib")
    @mut prev_t = time()
    @mut accum_fps = 60.0
    on Heap:volatile(1024)
        do while window:is_open
            start_t = time()
            spheres
            :process(dt)

            window
            :begin
            :clear(Color(50,50,80))

            range(spheres:len)
            :while next(@mut u64 i)
                do spheres[i]:draw(window)

            window
            :text((accum_fps):u64:str+" fps", Position(10.0, 10.0), 20.0, Color(255, 255, 255))
            :end
            
            // time computation
            t = time()
            dt = t-prev_t
            prev_t = t
            accum_fps = add(accum_fps*0.99, 0.01:div(dt))
            exact_sleep(0.015-(t-start_t))
            do ended

service main()
    test()
    //print("running") // services are async, this will be printed