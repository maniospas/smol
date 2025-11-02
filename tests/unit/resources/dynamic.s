@include std.core 
    return Number, range, fail
@include std.math
@include std.mem


def Circle(nominal, f64 radius) 
    return @args

def Square(nominal, f64 side) 
    return @args

def area(Circle self) 
    return pi(self.radius*self.radius)

def area(Square self) 
    return self.side*self.side

union Shape = Circle or Square

def is(Shape, Shape)

def volume(Shape base, f64 height) 
    return base.area()*height

def Shapes(nominal)
    @mut squares = Square[]
    @mut circles = Circle[]
    @mut types = tag[]
    @mut lookups = u64[]
    return @args, squares, circles, types, lookups

def at(@access Shapes shapes, Shape, u64 pos)
    type = shapes.types[pos]
    if type != Shape.tag() 
        fail("Trying to access a different shape")
    lookup = shapes.lookups[pos]
    case Shape.is(Square) ret = shapes.squares[lookup]
    case Shape.is(Circle) ret = shapes.circles[lookup]
    qed

    return ret

def push(@access @mut Shapes shapes, Shape shape)
    shapes.lookups.push(shapes.squares.len())
    shapes.types.push(shape.tag())
    case shapes.squares.push(shape)
    case shapes.circles.push(shape)
    qed

def len(@access Shapes shapes)
    return shapes.types.len()

service main()
    @access @mut shapes = nominal.Shapes()
    shapes.push(nominal.Square(1.0))
    shapes.push(nominal.Circle(1.0))
    shapes.push(nominal.Circle(2.0))
    shapes.push(nominal.Square(5.0))

    print("=== Volumes ===")
    shapes
    .len()
    .range()
    .while next(@mut u64 i)
        if shapes.types[i]==:Square
            printin("Square: ")
            shapes.at(Square, i).volume(1.0).print()
        elif shapes.types[i]==:Circle 
            printin("Circle: ")
            shapes.at(Circle, i).volume(1.0).print()
        else 
            fail("Invalid type")
