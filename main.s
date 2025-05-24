@include std.builtins
@include std.math

service main()
    x = f64:read
    y = 
        if x<0.0    -> "negative" 
        elif x<1.0  -> "unit"
        elif x<10.0 -> "smol"
        else        -> "big"
    print(y)
    --