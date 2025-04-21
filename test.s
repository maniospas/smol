sm Point(int x, int y) => @pack(x,y)

Poi


smo add(int x, int y) => @code(x+y)

smo Point(int x, int y)
    add z(x,1)
    => @pack(x,z)

smo norm(Point point) => point.x+point.y


smo main()
    A a(1,2)
    norm x(a)
    print(a.x,a.y,a.z)
    print(norm a)

// smoλ


smo main()
    int i(0)
    loop i(0,10)
        add i(i, 1)
        print(i)
    )
