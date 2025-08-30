@include std.builtins
@include std.file
@include std.os
@include std.ray
@include std.mem
@include std.time

smo Sphere(f64 x, f64 y, f64 r, f64 dx, f64 dy) 
    -> @new

smo process(Sphere &s, f64 dt)
    dx = if (s.r > s.x) or (800.0 < s.x+s.r) -> s.dx:negative else -> s.dx
    dy = if (s.r > s.y) or (450.0 < s.y+s.r) -> s.dy:negative else -> s.dy
    s = Sphere(
        s.x:add(dx*dt),
        s.y:add(dy*dt),
        s.r, dx, dy
    )
    --

smo draw(Sphere sphere, Window &window)
    window:circ(sphere.x, sphere.y, sphere.r, Color(200, 50, 50))
    --

service test()
    &spheres = Sphere:buffer
    spheres:push(Sphere(100.0, 100.0, 30.0, 1000.0, 650.0))
    spheres:push(Sphere(100.0, 100.0, 30.0, 450.0, 600.0))

    &dt = 0.0

    &window = Window:open(800.0, 450.0, "Hello from smoλ+raylib")
    &prev_t = time()
    &accum_fps = 3600.0
    on Heap:new_volatile(1024)
        while window:is_open
            // time computation
            t = time()
            dt = t-prev_t
            accum_fps = (0.0001/dt)+(accum_fps*0.9999)
            prev_t = t

            // prepare
            window
            :begin
            :clear(Color(50,50,80))

            // process and draw
            spheres
            :iterate
            :while next(Sphere& sphere)
                sphere:process(dt)
                sphere:draw(window)
                --

            // finalize loop
            window
            :text(tostr((accum_fps/60.0):u64)+" fps", Position(10.0, 10.0), 20.0, Color(255, 255, 255))
            :end
            exact_sleep(0.015-dt)
            --
    ----

service main()
    test()
    print("running") // services are async, this will be printed
    --
