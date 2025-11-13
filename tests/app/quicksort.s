@include std.core
@include std.mem
@include std.time

def SortRange(nominal, u64 lo, u64 hi)
    return @args

def swap(@mut f64[] arr, u64 i, u64 j)
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp

def partition(@mut f64[] arr, u64 lo, u64 hi)
    pivot = arr[hi]
    @mut i = lo
    @mut j = lo
    while j < hi
        if arr[j] < pivot
            swap(arr, i, j)
            i = i + 1
        j = j + 1
    swap(arr, i, hi)
    return i

def quicksort(@mut SortRange[] stack, @mut f64[] arr)
    r = stack.pop()
    if r.lo < r.hi
        p = partition(arr, r.lo, r.hi)

        @mut left_valid = false
        @mut left_lo = 0
        @mut left_hi = 0
        if p > r.lo
            left_lo = r.lo
            left_hi = p - 1
            left_valid = true

        @mut right_valid = false
        @mut right_lo = 0
        @mut right_hi = 0
        if p < r.hi
            right_lo = p + 1
            right_hi = r.hi
            right_valid = true

        left_size = algorithm
            if left_valid 
                return (left_hi+1) - left_lo
            return 0

        right_size = algorithm
            if right_valid
                return (right_hi + 1) - right_lo
            return 0

        if left_size < right_size
            if right_valid stack = stack.push(nominal.SortRange(right_lo, right_hi))
            if left_valid stack = stack.push(nominal.SortRange(left_lo, left_hi))
        else
            if left_valid stack = stack.push(nominal.SortRange(left_lo, left_hi))
            if right_valid stack = stack.push(nominal.SortRange(right_lo, right_hi))

service main()
    @mut arr = f64[]
    .push(9.f64())
    .push(2.f64())
    .push(7.f64())
    .push(3.f64())
    .push(1.f64())
    .push(8.f64())
    .push(6.f64())
    .push(5.f64())
    tic = time()

    @mut stack = SortRange[].push(nominal.SortRange(0, arr.len() - 1))
    while stack.len().bool()
        stack.quicksort(arr)
     
    // results
    print(time() - tic)
    range(arr.len())
    .while next(@mut u64 i)
        print(arr[i])
