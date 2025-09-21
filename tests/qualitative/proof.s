// This file uses the smol compiler's types as a proof verifier.
//
// - This is not a proof assistant. Which rule, i.e., smo runtype
//   applies on each step is deterministic based on argument types.
// - Only nominal typing is applied to ensure that distinct properties
//   keep track of their nature.

smo x(nominal) 
    return @args
    
smo y(nominal) 
    return @args

smo z(nominal) 
    return @args

smo zero(nominal) 
    return @args

union Var
    x
    y
    z

union Number
    Var
    zero

union Number2
    Number

smo neg(nominal,Var) 
    return @args

smo neg(nominal,neg arg) 
    return arg.Var

smo neg(nominal,zero) 
    return nominal:zero

smo add(nominal,Var,neg) 
    with 
        @mut equals=Var 
        equals=neg.Var 
        --
    return nominal:zero

smo add(nominal,Var,zero) 
    return Var
smo sub(nominal,Number,Number2) 
    with 
        result = nominal:add(Number,nominal:neg(Number2)) 
        --
    return result

service main() 
    @mut equals = nominal:sub(nominal:neg(nominal:neg(x)), zero) // (0-(0-x))-zero == x
    equals = nominal:x // this would have an error if we used nominal:z