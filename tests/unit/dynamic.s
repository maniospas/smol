@include std.core return Number, range, fail
@include std.math

// ----- Circle -----

def Circle(nominal, f64 radius)
    return @args

def area(Circle self)
    return pi(self.radius*self.radius)/2.0

// ----- Square -----

def Square(nominal, f64 side)
    return @args

def area(Square self)
    return self.side*self.side

// ----- Shape -----

union Shape
    Circle
    Square
    --

def volume(Shape base, f64 height)
    return base:area*height

def Shapes(nominal)
    @mut squares = Square[]
    @mut circles = Circle[]
    @mut types = u64[]
    @mut lookups = u64[]
    return @args, squares, circles, types, lookups

def is(@access Shapes self, u64 pos, Circle)
    type = self.types[pos]
    return type == 0

def is(@access Shapes self, u64 pos, Square)
    type = self.types[pos]
    return type == 1

def at(@access Shapes self, u64 pos, Circle)
    type = self.types[pos]
    if type != 0
        return fail("Trying to access a non-circle")
    lookup = self.lookups[pos]
    return self.circles[lookup]

def at(@access Shapes shapes, u64 pos, Square)
    type = shapes.types[pos]
    if type != 1 
        return fail("Trying to access a non-square")
    lookup = shapes.lookups[pos]
    return shapes.squares[lookup]

def push(@access @mut Shapes shapes, Square square)
    shapes.lookups:push(shapes.squares:len)
    shapes.types:push(0)
    shapes.squares:push(square)
    return shapes

def push(@access @mut Shapes shapes, Circle circle)
    shapes.lookups:push(shapes.circles:len)
    shapes.types:push(1)
    shapes.circles:push(circle)
    return shapes

def len(@access Shapes shapes)
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
    end