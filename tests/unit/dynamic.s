@include std.core -> Number, range, fail
@include std.math

// ----- Circle -----

smo Circle(nominal, f64 radius)
    -> @args

smo area(Circle self)
    -> pi(self.radius*self.radius)/2.0

// ----- Square -----

smo Square(nominal, f64 side)
    -> @args

smo area(Square self)
    -> self.side*self.side

// ----- Shape -----

union Shape
    Circle
    Square
    --

smo volume(Shape base, f64 height)
    -> base:area*height

smo Shapes(nominal)
    @mut squares = Square[]
    @mut circles = Circle[]
    @mut types = u64[]
    @mut lookups = u64[]
    -> @args, squares, circles, types, lookups

smo is(@access Shapes self, u64 pos, Circle)
    type = self.types[pos]
    -> type == 0

smo is(@access Shapes self, u64 pos, Square)
    type = self.types[pos]
    -> type == 1

smo at(@access Shapes self, u64 pos, Circle)
    type = self.types[pos]
    if type != 0
        -> fail("Trying to access a non-circle")
    lookup = self.lookups[pos]
    -> self.circles[lookup]

smo at(@access Shapes shapes, u64 pos, Square)
    type = shapes.types[pos]
    if type != 1 
        -> fail("Trying to access a non-square")
    lookup = shapes.lookups[pos]
    -> shapes.squares[lookup]

smo push(@access @mut Shapes shapes, Square square)
    shapes.lookups.push(shapes.squares:len)
    shapes.types.push(0)
    shapes.squares:push(square)
    -> shapes

smo push(@access @mut Shapes shapes, Circle circle)
    shapes.lookups.push(shapes.circles:len)
    shapes.types.push(1)
    shapes.circles:push(circle)
    -> shapes

smo len(@access Shapes shapes)
    -> shapes.types:len


service main()
    @mut shapes = nominal:Shapes
    shapes:push(nominal:Square(1.0))
    shapes:push(nominal:Circle(1.0))

    shapes
    :len
    :range
    :while next(@mut u64 i) 
        if shapes:is(i, Square)
            shapes
            :at(i, Square)
            :volume(1.0)
            :print
        --
    --