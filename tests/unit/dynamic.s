@include std.core return Number, range, fail
@include std.math

// ----- Circle -----

smo Circle(nominal, f64 radius)
    return @args

smo area(Circle self)
    return pi(self.radius*self.radius)/2.0

// ----- Square -----

smo Square(nominal, f64 side)
    return @args

smo area(Square self)
    return self.side*self.side

// ----- Shape -----

union Shape
    Circle
    Square
    --

smo volume(Shape base, f64 height)
    return base:area*height

smo Shapes(nominal)
    @mut squares = Square[]
    @mut circles = Circle[]
    @mut types = u64[]
    @mut lookups = u64[]
    return @args, squares, circles, types, lookups

smo is(@access Shapes self, u64 pos, Circle)
    type = self.types[pos]
    return type == 0

smo is(@access Shapes self, u64 pos, Square)
    type = self.types[pos]
    return type == 1

smo at(@access Shapes self, u64 pos, Circle)
    type = self.types[pos]
    if type != 0
        return fail("Trying to access a non-circle")
    lookup = self.lookups[pos]
    return self.circles[lookup]

smo at(@access Shapes shapes, u64 pos, Square)
    type = shapes.types[pos]
    if type != 1 
        return fail("Trying to access a non-square")
    lookup = shapes.lookups[pos]
    return shapes.squares[lookup]

smo push(@access @mut Shapes shapes, Square square)
    shapes.lookups:push(shapes.squares:len)
    shapes.types:push(0)
    shapes.squares:push(square)
    return shapes

smo push(@access @mut Shapes shapes, Circle circle)
    shapes.lookups:push(shapes.circles:len)
    shapes.types:push(1)
    shapes.circles:push(circle)
    return shapes

smo len(@access Shapes shapes)
    return shapes.types:len


service main()
    @mut shapes = nominal:Shapes
    shapes:push(nominal:Square(1.0))
    shapes:push(nominal:Circle(1.0))

    shapes
    :len
    :range
    :while next(@mut u64 i) do
        if shapes:is(i, Square) do
            shapes
            :at(i, Square)
            :volume(1.0)
            :print
    noreturn