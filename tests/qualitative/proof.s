// This file uses the smol compiler's types as a proof verifier.
//
// - This is not a proof assistant. Which rule, i.e., def function
//   applies on each step is deterministic based on argument types.
// - Only nominal typing is applied to ensure that distinct properties
//   keep track of their nature.

def x(nominal) return @args
def y(nominal) return @args
def z(nominal) return @args
def zero(nominal) return @args

union Var = x or y or z
union Number = Var or zero
union Number2 = Number

def neg(nominal,Var) return @args
def neg(nominal,neg arg) return arg.Var
def neg(nominal,zero) return nominal.zero()

def add(nominal,Var,neg) 
    with 
        @mut equals=Var 
        equals=neg.Var 
        qed
    return nominal.zero() 

def add(nominal,Var,zero) return Var

def sub(nominal,Number,Number2) 
    with 
        result = nominal.add(Number,nominal.neg(Number2)) 
        qed
    return result

service main() 
    @mut equals = nominal.sub(nominal.neg(nominal.neg(x)), zero) // (0-(0-x))-zero == x
    equals = nominal.x() // this would have an error if we used nominal.z