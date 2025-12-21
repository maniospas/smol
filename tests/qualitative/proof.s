// This file uses the smol compiler's types as a proof verifier.
//
// - This is not a proof assistant. Which rule, i.e., def function
//   applies on each step is deterministic based on argument types.
// - Only new typing is applied to ensure that distinct properties
//   keep track of their nature.

def x(new) return @args
def y(new) return @args
def z(new) return @args
def zero(new) return @args

union Var = x or y or z
union Number = Var or zero
union Number2 = Number

def neg(new,Var) return @args
def neg(new,neg arg) return arg.Var
def neg(new,zero) return new.zero()

def add(new,Var,neg) 
    case 
        @mut equals=Var 
        equals=neg.Var 
        qed
    return new.zero() 

def add(new,Var,zero) return Var

def sub(new,Number,Number2) 
    case 
        result = new.add(Number,new.neg(Number2)) 
        qed
    return result

service main() 
    @mut equals = new.sub(new.neg(new.neg(x)), zero) // (0-(0-x))-zero == x
    equals = new.x() // this would have an error if we used new.z