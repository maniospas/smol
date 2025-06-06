// This file uses the smol compiler's types as a proof verifier.
//
// - This is not a proof assistant. Which rule, i.e., smo runtype
//   applies on each step is deterministic based on argument types.
// - Only nominal typing is applied to ensure that distinct properties
//   keep track of their nature.

smo x(nom) -> @new
smo y(nom) -> @new
smo z(nom) -> @new
smo zero(nom) -> @new
union Var(x,y,z)       // one of x,y,z
union Number(Var,zero) // all members of Var plus zero
union Number2(Number)

smo neg(nom,Var) -> @new
smo neg(nom,neg arg) -> arg.Var
smo neg(nom,zero) -> nom:zero
smo add(nom,Var,neg) 
    with 
        equals=Var 
        equals=neg.Var 
    ---> nom:zero
smo add(nom,Var,zero) -> Var
smo sub(nom,Number,Number2) with result = nom:add(Number,nom:neg(Number2)) ---> result

service main() 
    equals = nom:sub(nom:neg(nom:neg(x)), zero) // (0-(0-x))-zero == x
    equals = nom:x // this would have an error if we used nom:z
    --