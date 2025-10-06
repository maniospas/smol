@include std.core return Number, range, fail
@include std.math
@include std.mem

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

union Shape = Circle or Square

def volume(Shape base, f64 height)
    return base.area()*height

def Shapes(nominal)
    @mut squares = Square[]
    @mut circles = Circle[]
    @mut types = tag[]
    @mut lookups = u64[]
    return @args, squares, circles, types, lookups

def Shapes(nominal, @mut Memory memory, u64 size)
    @mut squares = Square[memory.allocate(size*4)]
    @mut circles = Circle[memory.allocate(size*4)]
    @mut types = tag[memory.allocate(size*8)]
    @mut lookups = u64[memory.allocate(size*8)]
    return @args, squares, circles, types, lookups

def is(@access Shapes self, u64 pos, Circle)
    type = self.types[pos]
    return type == :circle

def is(@access Shapes self, u64 pos, Square)
    type = self.types[pos]
    return type == :square

def at(@access Shapes self, u64 pos, Circle)
    type = self.types[pos]
    if type != :circle then fail("Trying to access a non-circle")
    lookup = self.lookups[pos]
    return self.circles[lookup]

def at(@access Shapes shapes, u64 pos, Square)
    type = shapes.types[pos]
    if type != :square then fail("Trying to access a non-square")
    lookup = shapes.lookups[pos]
    return shapes.squares[lookup]

def push(@access @mut Shapes shapes, Square square)
    shapes.lookups.push(shapes.squares.len())
    shapes.types.push(:square)
    shapes.squares.push(square)
    return nothing

def push(@access @mut Shapes shapes, Circle circle)
    shapes.lookups.push(shapes.circles.len())
    shapes.types.push(:circle)
    shapes.circles.push(circle)
    return nothing

def len(@access Shapes shapes)
    return shapes.types.len()

service main()
    @mut shapes = nominal.Shapes()
    shapes.push(nominal.Square(1.0))
    shapes.push(nominal.Circle(1.0))
    shapes.push(nominal.Circle(2.0))
    shapes.push(nominal.Square(5.0))
    
    shapes
    .len()
    .range()
    .while next(@mut u64 i) 
        then if shapes.is(i, Square)
            shapes
            .at(i, Square)
            .volume(1.0)
            .print()
        else 
            shapes
            .at(i, Circle)
            .volume(1.0)
            .print()
            then nothing
