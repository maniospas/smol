@include std.builtins
@include std.file
@include std.os
@include std.ray
@include std.mem
@include std.time

service test()
    &x = 100.0
    &y = 100.0
    &dx = 1000.0
    &dy = 600.0
    &dt = 0.0
    &prev_t = time()
    radius = 30.0

    Window
    :open(800.0, 450.0, "Hello from smoλ+raylib")
    :while is_open
        time = time()
        dt = time-prev_t
        prev_t = time
        x = x + (dx*dt)
        y = y + (dy*dt)
        if (0.0>x-radius)or(800.0<x + radius) 
            dx = dx:negative
            --
        if (0.0>y-radius)or(450.0<y + radius) 
            dy = dy:negative
            --
        Window
        :begin_drawing
        :clear_background(Color(50,50,80))
        :draw_text("Hi!", Position(190.0, 200.0), 20.0, Color(255, 255, 255))
        :draw_circle(Position(x,y), radius, Color(200, 50, 50))
        :end_drawing
        --
    --

service main()
    test()
    print("running") // services are async, this will be printed
    --
